#include "SphereGenerationShader.h"
#include "ComputeModule/Public/SphereGenerationShader/SphereGenerationShader.h"
#include "PixelShaderUtils.h"
#include "MeshPassProcessor.inl"
#include "StaticMeshResources.h"
#include "DynamicMeshBuilder.h"
#include "RenderGraphResources.h"
#include "GlobalShader.h"
#include "UnifiedBuffer.h"
#include "CanvasTypes.h"
#include "MeshDrawShaderBindings.h"
#include "RHIGPUReadback.h"
#include "MeshPassUtils.h"
#include "MaterialShader.h"

DECLARE_STATS_GROUP(TEXT("SphereGenerationShader"), STATGROUP_SphereGenerationShader, STATCAT_Advanced);
DECLARE_CYCLE_STAT(TEXT("SphereGenerationShader Execute"), STAT_SphereGenerationShader_Execute, STATGROUP_SphereGenerationShader);

// This class carries our parameter declarations and acts as the bridge between cpp and HLSL.
class COMPUTEMODULE_API FSphereGenerationShader : public FGlobalShader
{
public:

    DECLARE_GLOBAL_SHADER(FSphereGenerationShader);
    SHADER_USE_PARAMETER_STRUCT(FSphereGenerationShader, FGlobalShader);

    class FSphereGenerationShader_Perm_TEST : SHADER_PERMUTATION_INT("TEST", 1);
    using FPermutationDomain = TShaderPermutationDomain<
        FSphereGenerationShader_Perm_TEST
    >;

    BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
        SHADER_PARAMETER(int32, latitudeSegments)
        SHADER_PARAMETER(int32, longitudeSegments)
        SHADER_PARAMETER(float, radius)
        SHADER_PARAMETER(uint32, maxVertices)
        SHADER_PARAMETER(uint32, maxTriangles)

        //Output buffers
        SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<float>, verticesBuffer)
        SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<int>, trianglesBuffer)
        SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<float>, normalsBuffer)
        SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<float>, UVsBuffer)

        //tempo debug
        SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<int>, countersBuffer)
    END_SHADER_PARAMETER_STRUCT()

public:
    static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
    {
        return true;
    }

    static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
    {
        FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);

        OutEnvironment.SetDefine(TEXT("THREADS_X"), NUM_THREADS_SphereGenerationShader_X);
        OutEnvironment.SetDefine(TEXT("THREADS_Y"), NUM_THREADS_SphereGenerationShader_Y);
        OutEnvironment.SetDefine(TEXT("THREADS_Z"), NUM_THREADS_SphereGenerationShader_Z);
    }
};

IMPLEMENT_GLOBAL_SHADER(FSphereGenerationShader, "/ComputeModuleShaders/SphereGenerationShader/SphereGenerationShader.usf", "SphereGenerationShader", SF_Compute);

void FSphereGenerationShaderInterface::DispatchRenderThread(FRHICommandListImmediate& RHICmdList, FSphereGenerationShaderDispatchParams Params, TFunction<void(const FSphereGeometryData&)> AsyncCallback)
{
    FRDGBuilder GraphBuilder(RHICmdList);

    {
        SCOPE_CYCLE_COUNTER(STAT_SphereGenerationShader_Execute);
        DECLARE_GPU_STAT(SphereGenerationShader)
        RDG_EVENT_SCOPE(GraphBuilder, "SphereGenerationShader");
        RDG_GPU_STAT_SCOPE(GraphBuilder, SphereGenerationShader);

        typename FSphereGenerationShader::FPermutationDomain PermutationVector;
        TShaderMapRef<FSphereGenerationShader> ComputeShader(GetGlobalShaderMap(GMaxRHIFeatureLevel), PermutationVector);

        bool bIsShaderValid = ComputeShader.IsValid();

        if (bIsShaderValid)
        {
            FSphereGenerationShader::FParameters* PassParameters = GraphBuilder.AllocParameters<FSphereGenerationShader::FParameters>();

            // Calculate buffer sizes
            uint32 numVertices = (Params.latitudeSegments + 1) * (Params.longitudeSegments + 1);
            uint32 numTriangles = Params.latitudeSegments * Params.longitudeSegments * 2 * 3;

            PassParameters->latitudeSegments = Params.latitudeSegments;
            PassParameters->longitudeSegments = Params.longitudeSegments;
            PassParameters->radius = Params.radius;
            PassParameters->maxVertices = numVertices;
            PassParameters->maxTriangles = numTriangles;

            // Create output buffers
            FRDGBufferRef verticesBuffer = GraphBuilder.CreateBuffer(
                FRDGBufferDesc::CreateBufferDesc(sizeof(float), numVertices * 3), 
                TEXT("SphereVerticesBuffer"));

            FRDGBufferRef trianglesBuffer = GraphBuilder.CreateBuffer(
                FRDGBufferDesc::CreateBufferDesc(sizeof(int32), numTriangles),
                TEXT("SphereTrianglesBuffer"));

            FRDGBufferRef normalsBuffer = GraphBuilder.CreateBuffer(
                FRDGBufferDesc::CreateBufferDesc(sizeof(float), numVertices * 3), 
                TEXT("SphereNormalsBuffer"));

            FRDGBufferRef UVsBuffer = GraphBuilder.CreateBuffer(
                FRDGBufferDesc::CreateBufferDesc(sizeof(float), numVertices * 2), 
                TEXT("SphereUVsBuffer"));

            FRDGBufferRef TangentsBuffer = GraphBuilder.CreateBuffer(
                FRDGBufferDesc::CreateBufferDesc(sizeof(float), numVertices * 3), 
                TEXT("SphereTangentsBuffer"));

            FRDGBufferRef countersBuffer = GraphBuilder.CreateBuffer(
                FRDGBufferDesc::CreateBufferDesc(sizeof(int32), 2), 
                TEXT("SphereCountersBuffer"));

            PassParameters->verticesBuffer = GraphBuilder.CreateUAV(FRDGBufferUAVDesc(verticesBuffer, PF_R32_FLOAT));
            PassParameters->trianglesBuffer = GraphBuilder.CreateUAV(FRDGBufferUAVDesc(trianglesBuffer, PF_R32_SINT));
            PassParameters->normalsBuffer = GraphBuilder.CreateUAV(FRDGBufferUAVDesc(normalsBuffer, PF_R32_FLOAT));
            PassParameters->UVsBuffer = GraphBuilder.CreateUAV(FRDGBufferUAVDesc(UVsBuffer, PF_R32_FLOAT));
            PassParameters->countersBuffer = GraphBuilder.CreateUAV(FRDGBufferUAVDesc(countersBuffer, PF_R32_SINT));

            //Calculateing Group count and adding compute pass
            FIntVector DispatchSize(
                FMath::DivideAndRoundUp(Params.longitudeSegments + 1, 16),
                FMath::DivideAndRoundUp(Params.latitudeSegments + 1, 16),
                1
            );


            GraphBuilder.AddPass(
                RDG_EVENT_NAME("ExecuteSphereGenerationShader"),
                PassParameters,
                ERDGPassFlags::AsyncCompute,
                [&PassParameters, ComputeShader, DispatchSize](FRHIComputeCommandList& RHICmdList)
                {
                    FComputeShaderUtils::Dispatch(RHICmdList, ComputeShader, *PassParameters, DispatchSize);
                });

            //Buffer Readbacks
            FRHIGPUBufferReadback* VerticesReadback = new FRHIGPUBufferReadback(TEXT("SphereVerticesReadback"));
            FRHIGPUBufferReadback* TrianglesReadback = new FRHIGPUBufferReadback(TEXT("SphereTrianglesReadback"));
            FRHIGPUBufferReadback* NormalsReadback = new FRHIGPUBufferReadback(TEXT("SphereNormalsReadback"));
            FRHIGPUBufferReadback* UVsReadback = new FRHIGPUBufferReadback(TEXT("SphereUVsReadback"));
            FRHIGPUBufferReadback* CountersReadback = new FRHIGPUBufferReadback(TEXT("SphereCountersReadback"));

            AddEnqueueCopyPass(GraphBuilder, VerticesReadback, verticesBuffer, 0u);
            AddEnqueueCopyPass(GraphBuilder, TrianglesReadback, trianglesBuffer, 0u);
            AddEnqueueCopyPass(GraphBuilder, NormalsReadback, normalsBuffer, 0u);
            AddEnqueueCopyPass(GraphBuilder, UVsReadback, UVsBuffer, 0u);
            AddEnqueueCopyPass(GraphBuilder, CountersReadback, countersBuffer, 0u);

            auto RunnerFunc = [VerticesReadback, TrianglesReadback, NormalsReadback, UVsReadback, CountersReadback, AsyncCallback, numVertices, numTriangles](auto&& RunnerFunc) -> void {
                if (VerticesReadback->IsReady() && TrianglesReadback->IsReady() && NormalsReadback->IsReady() &&
                    UVsReadback->IsReady() && CountersReadback->IsReady())
                {
                    FSphereGeometryData GeometryData;

                    //Reading data
                    int32* CountersData = (int32*)CountersReadback->Lock(sizeof(int32) * 2);
                    uint32 ActualVertexCount = CountersData[0];
                    uint32 ActualTriangleCount = CountersData[1];
                    CountersReadback->Unlock();

                    float* VerticesData = (float*)VerticesReadback->Lock(sizeof(float) * numVertices * 3);
                    GeometryData.Vertices.Reserve(ActualVertexCount);
                    for (uint32 i = 0; i < ActualVertexCount; ++i)
                    {
                        //Convert float data to vector
                        GeometryData.Vertices.Add(FVector(
                            VerticesData[i * 3 + 0],
                            VerticesData[i * 3 + 1],
                            VerticesData[i * 3 + 2]
                        ));
                    }
                    VerticesReadback->Unlock();

                    int32* TrianglesData = (int32*)TrianglesReadback->Lock(sizeof(int32) * numTriangles);
                    GeometryData.Triangles.Reserve(ActualTriangleCount);
                    for (uint32 i = 0; i < ActualTriangleCount; ++i)
                    {
                        GeometryData.Triangles.Add(TrianglesData[i]);
                    }
                    TrianglesReadback->Unlock();

                    float* NormalsData = (float*)NormalsReadback->Lock(sizeof(float) * numVertices * 3);
                    GeometryData.Normals.Reserve(ActualVertexCount);
                    for (uint32 i = 0; i < ActualVertexCount; ++i)
                    {
                        GeometryData.Normals.Add(FVector(
                            NormalsData[i * 3 + 0],
                            NormalsData[i * 3 + 1],
                            NormalsData[i * 3 + 2]
                        ));
                    }
                    NormalsReadback->Unlock();

                    float* UVsData = (float*)UVsReadback->Lock(sizeof(float) * numVertices * 2);
                    GeometryData.UVs.Reserve(ActualVertexCount);
                    for (uint32 i = 0; i < ActualVertexCount; ++i)
                    {
                        GeometryData.UVs.Add(FVector2D(
                            UVsData[i * 2 + 0],
                            UVsData[i * 2 + 1]
                        ));
                    }
                    UVsReadback->Unlock();

                    AsyncTask(ENamedThreads::GameThread, [AsyncCallback, GeometryData]() {
                        AsyncCallback(GeometryData);
                        });

                    //Cleanup
                    delete VerticesReadback;
                    delete TrianglesReadback;
                    delete NormalsReadback;
                    delete UVsReadback;
                    delete CountersReadback;
                }
                else
                {
                    AsyncTask(ENamedThreads::ActualRenderingThread, [RunnerFunc]() {
                        RunnerFunc(RunnerFunc);
                        });
                }
                };

            AsyncTask(ENamedThreads::ActualRenderingThread, [RunnerFunc]() {
                FPlatformProcess::Sleep(0.001f); //fuck knows
                RunnerFunc(RunnerFunc);
                });

        }
        else
        {
#if WITH_EDITOR
            GEngine->AddOnScreenDebugMessage((uint64)42145125184, 6.f, FColor::Red, FString(TEXT("The sphere generation compute shader has a problem.")));
#endif
        }
    }

    GraphBuilder.Execute();
}