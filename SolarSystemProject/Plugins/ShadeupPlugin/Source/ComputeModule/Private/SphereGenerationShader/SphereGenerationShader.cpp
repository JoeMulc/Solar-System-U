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
        SHADER_PARAMETER(int32, LatitudeSegments)
        SHADER_PARAMETER(int32, LongitudeSegments)
        SHADER_PARAMETER(float, Radius)
        SHADER_PARAMETER(uint32, MaxVertices)
        SHADER_PARAMETER(uint32, MaxTriangles)

        //Output buffers
        SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<float>, VerticesBuffer)
        SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<int>, TrianglesBuffer)
        SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<float>, NormalsBuffer)
        SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<float>, UVsBuffer)

        //Remove this later used for debugging
        SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<int>, CountersBuffer)
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
            uint32 NumVertices = (Params.latitudeSegments + 1) * (Params.longitudeSegments + 1);
            uint32 NumTriangles = Params.latitudeSegments * Params.longitudeSegments * 2 * 3; // 2 triangles per quad, 3 indices per triangle

            PassParameters->LatitudeSegments = Params.latitudeSegments;
            PassParameters->LongitudeSegments = Params.longitudeSegments;
            PassParameters->Radius = Params.radius;
            PassParameters->MaxVertices = NumVertices;
            PassParameters->MaxTriangles = NumTriangles;

            // Create output buffers
            FRDGBufferRef VerticesBuffer = GraphBuilder.CreateBuffer(
                FRDGBufferDesc::CreateBufferDesc(sizeof(float), NumVertices * 3), // 3 floats per vertex (x, y, z)
                TEXT("SphereVerticesBuffer"));

            FRDGBufferRef TrianglesBuffer = GraphBuilder.CreateBuffer(
                FRDGBufferDesc::CreateBufferDesc(sizeof(int32), NumTriangles),
                TEXT("SphereTrianglesBuffer"));

            FRDGBufferRef NormalsBuffer = GraphBuilder.CreateBuffer(
                FRDGBufferDesc::CreateBufferDesc(sizeof(float), NumVertices * 3), // 3 floats per normal
                TEXT("SphereNormalsBuffer"));

            FRDGBufferRef UVsBuffer = GraphBuilder.CreateBuffer(
                FRDGBufferDesc::CreateBufferDesc(sizeof(float), NumVertices * 2), // 2 floats per UV
                TEXT("SphereUVsBuffer"));

            FRDGBufferRef TangentsBuffer = GraphBuilder.CreateBuffer(
                FRDGBufferDesc::CreateBufferDesc(sizeof(float), NumVertices * 3), // 3 floats per tangent
                TEXT("SphereTangentsBuffer"));

            FRDGBufferRef CountersBuffer = GraphBuilder.CreateBuffer(
                FRDGBufferDesc::CreateBufferDesc(sizeof(int32), 2), // [VertexCount, TriangleCount]
                TEXT("SphereCountersBuffer"));

            PassParameters->VerticesBuffer = GraphBuilder.CreateUAV(FRDGBufferUAVDesc(VerticesBuffer, PF_R32_FLOAT));
            PassParameters->TrianglesBuffer = GraphBuilder.CreateUAV(FRDGBufferUAVDesc(TrianglesBuffer, PF_R32_SINT));
            PassParameters->NormalsBuffer = GraphBuilder.CreateUAV(FRDGBufferUAVDesc(NormalsBuffer, PF_R32_FLOAT));
            PassParameters->UVsBuffer = GraphBuilder.CreateUAV(FRDGBufferUAVDesc(UVsBuffer, PF_R32_FLOAT));
            PassParameters->CountersBuffer = GraphBuilder.CreateUAV(FRDGBufferUAVDesc(CountersBuffer, PF_R32_SINT));

            //Calculateing Group count and adding compute pass
            auto GroupCount = FComputeShaderUtils::GetGroupCount(FIntVector(NumVertices, 1, 1), FComputeShaderUtils::kGolden2DGroupSize);

            GraphBuilder.AddPass(
                RDG_EVENT_NAME("ExecuteSphereGenerationShader"),
                PassParameters,
                ERDGPassFlags::AsyncCompute,
                [&PassParameters, ComputeShader, GroupCount](FRHIComputeCommandList& RHICmdList)
                {
                    FComputeShaderUtils::Dispatch(RHICmdList, ComputeShader, *PassParameters, GroupCount);
                });

            //Buffer Readbacks
            FRHIGPUBufferReadback* VerticesReadback = new FRHIGPUBufferReadback(TEXT("SphereVerticesReadback"));
            FRHIGPUBufferReadback* TrianglesReadback = new FRHIGPUBufferReadback(TEXT("SphereTrianglesReadback"));
            FRHIGPUBufferReadback* NormalsReadback = new FRHIGPUBufferReadback(TEXT("SphereNormalsReadback"));
            FRHIGPUBufferReadback* UVsReadback = new FRHIGPUBufferReadback(TEXT("SphereUVsReadback"));
            FRHIGPUBufferReadback* CountersReadback = new FRHIGPUBufferReadback(TEXT("SphereCountersReadback"));

            AddEnqueueCopyPass(GraphBuilder, VerticesReadback, VerticesBuffer, 0u);
            AddEnqueueCopyPass(GraphBuilder, TrianglesReadback, TrianglesBuffer, 0u);
            AddEnqueueCopyPass(GraphBuilder, NormalsReadback, NormalsBuffer, 0u);
            AddEnqueueCopyPass(GraphBuilder, UVsReadback, UVsBuffer, 0u);
            AddEnqueueCopyPass(GraphBuilder, CountersReadback, CountersBuffer, 0u);

            auto RunnerFunc = [VerticesReadback, TrianglesReadback, NormalsReadback, UVsReadback, CountersReadback, AsyncCallback, NumVertices, NumTriangles](auto&& RunnerFunc) -> void {
                if (VerticesReadback->IsReady() && TrianglesReadback->IsReady() && NormalsReadback->IsReady() &&
                    UVsReadback->IsReady() && CountersReadback->IsReady())
                {
                    FSphereGeometryData GeometryData;

                    //Reading data
                    int32* CountersData = (int32*)CountersReadback->Lock(sizeof(int32) * 2);
                    uint32 ActualVertexCount = CountersData[0];
                    uint32 ActualTriangleCount = CountersData[1];
                    CountersReadback->Unlock();

                    float* VerticesData = (float*)VerticesReadback->Lock(sizeof(float) * NumVertices * 3);
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

                    int32* TrianglesData = (int32*)TrianglesReadback->Lock(sizeof(int32) * NumTriangles);
                    GeometryData.Triangles.Reserve(ActualTriangleCount);
                    for (uint32 i = 0; i < ActualTriangleCount; ++i)
                    {
                        GeometryData.Triangles.Add(TrianglesData[i]);
                    }
                    TrianglesReadback->Unlock();

                    float* NormalsData = (float*)NormalsReadback->Lock(sizeof(float) * NumVertices * 3);
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

                    float* UVsData = (float*)UVsReadback->Lock(sizeof(float) * NumVertices * 2);
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