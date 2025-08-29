#include "PlanetGenerationShader.h"
#include "ComputeModule/Public/PlanetGenerationShader/PlanetGenerationShader.h"
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

DECLARE_STATS_GROUP(TEXT("PlanetGenerationShader"), STATGROUP_PlanetGenerationShader, STATCAT_Advanced);
DECLARE_CYCLE_STAT(TEXT("PlanetGenerationShader Execute"), STAT_PlanetGenerationShader_Execute, STATGROUP_PlanetGenerationShader);

// This class carries our parameter declarations and acts as the bridge between cpp and HLSL.
class COMPUTEMODULE_API FPlanetGenerationShader : public FGlobalShader
{
public:

	DECLARE_GLOBAL_SHADER(FPlanetGenerationShader);
	SHADER_USE_PARAMETER_STRUCT(FPlanetGenerationShader, FGlobalShader);

	class FPlanetGenerationShader_Perm_TEST : SHADER_PERMUTATION_INT("TEST", 1);
	using FPermutationDomain = TShaderPermutationDomain<
		FPlanetGenerationShader_Perm_TEST
	>;

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER(float, seaLevel)
		SHADER_PARAMETER(float, oceanDepth)
		SHADER_PARAMETER(float, mountainHeight)
		SHADER_PARAMETER(float, continentHeight)
		SHADER_PARAMETER(float, valleyDepth)
		SHADER_PARAMETER(float, grassSlopeThreshold)
		SHADER_PARAMETER(float, rockSlopeThreshold)
		SHADER_PARAMETER(float, snowHeightThreshold)
		SHADER_PARAMETER(float, sandHeightThreshold)
		SHADER_PARAMETER(float, continentScale)
		SHADER_PARAMETER(float, mountainScale)
		SHADER_PARAMETER(float, detailScale)
		SHADER_PARAMETER(float, ridgeScale)
		SHADER_PARAMETER(FVector4f, oceanColor)
		SHADER_PARAMETER(FVector4f, shallowColor)
		SHADER_PARAMETER(FVector4f, sandColor)
		SHADER_PARAMETER(FVector4f, grassColor)
		SHADER_PARAMETER(FVector4f, rockColor)
		SHADER_PARAMETER(FVector4f, snowColor)
		SHADER_PARAMETER(float, continentMin)
		SHADER_PARAMETER(float, continentMax)
		SHADER_PARAMETER_RDG_BUFFER_SRV(Buffer<float>, inputVertices)
		SHADER_PARAMETER_RDG_BUFFER_SRV(Buffer<float>, inputNormals)
		SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<float>, outputVertices)
		SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<float>, outputNormals)
		SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<float>, outputColors)
	END_SHADER_PARAMETER_STRUCT()

public:
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		const FPermutationDomain PermutationVector(Parameters.PermutationId);
		return true;
	}

	static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);

		const FPermutationDomain PermutationVector(Parameters.PermutationId);

		/*
		* These defines are used in the thread count section of our shader
		*/
		OutEnvironment.SetDefine(TEXT("THREADS_X"), NUM_THREADS_PlanetGenerationShader_X);
		OutEnvironment.SetDefine(TEXT("THREADS_Y"), NUM_THREADS_PlanetGenerationShader_Y);
		OutEnvironment.SetDefine(TEXT("THREADS_Z"), NUM_THREADS_PlanetGenerationShader_Z);
	}
private:
};

// This will tell the engine to create the shader and where the shader entry point is.
//                            ShaderType                            ShaderPath                     Shader function name    Type
IMPLEMENT_GLOBAL_SHADER(FPlanetGenerationShader, "/ComputeModuleShaders/PlanetGenerationShader/PlanetGenerationShader.usf", "PlanetGenerationShader", SF_Compute);

void FPlanetGenerationShaderInterface::DispatchRenderThread(FRHICommandListImmediate& RHICmdList, FPlanetGenerationShaderDispatchParams Params, TFunction<void(TArray<FVector> OutputVertices, TArray<FVector> OutputNormals, TArray<FLinearColor> OutputColors)> AsyncCallback) {
	FRDGBuilder GraphBuilder(RHICmdList);

	{
		SCOPE_CYCLE_COUNTER(STAT_PlanetGenerationShader_Execute);
		DECLARE_GPU_STAT(PlanetGenerationShader)
		RDG_EVENT_SCOPE(GraphBuilder, "PlanetGenerationShader");
		RDG_GPU_STAT_SCOPE(GraphBuilder, PlanetGenerationShader);

		typename FPlanetGenerationShader::FPermutationDomain PermutationVector;

		TShaderMapRef<FPlanetGenerationShader> ComputeShader(GetGlobalShaderMap(GMaxRHIFeatureLevel), PermutationVector);

		bool bIsShaderValid = ComputeShader.IsValid();

		if (bIsShaderValid) {
			FPlanetGenerationShader::FParameters* PassParameters = GraphBuilder.AllocParameters<FPlanetGenerationShader::FParameters>();

			//Shader Parameters
			PassParameters->seaLevel = Params.seaLevel;
			PassParameters->oceanDepth = Params.oceanDepth;
			PassParameters->mountainHeight = Params.mountainHeight;
			PassParameters->continentHeight = Params.continentHeight;
			PassParameters->valleyDepth = Params.valleyDepth;
		
			PassParameters->grassSlopeThreshold = Params.grassSlopeThreshold;
			PassParameters->rockSlopeThreshold = Params.rockSlopeThreshold;
			PassParameters->snowHeightThreshold = Params.snowHeightThreshold;
			PassParameters->sandHeightThreshold = Params.sandHeightThreshold;
	
			PassParameters->continentScale = Params.continentScale;
			PassParameters->mountainScale = Params.mountainScale;
			PassParameters->detailScale = Params.detailScale;
			PassParameters->ridgeScale = Params.ridgeScale;

			PassParameters->oceanColor = Params.oceanColor;
			PassParameters->shallowColor = Params.shallowColor;
			PassParameters->sandColor = Params.sandColor;
			PassParameters->grassColor = Params.grassColor;
			PassParameters->rockColor = Params.rockColor;
			PassParameters->snowColor = Params.snowColor;

			PassParameters->continentMin = Params.continentMin;
			PassParameters->continentMax = Params.continentMax;

			// Create input vertex data
			TArray<float> inputVertexData;
			inputVertexData.Add((float)Params.inputVertices.Num()); 

			for (const FVector& vert : Params.inputVertices)
			{
				inputVertexData.Add(vert.X);
				inputVertexData.Add(vert.Y);
				inputVertexData.Add(vert.Z);
			}

			const void* RawVertexData = (void*)inputVertexData.GetData();
			int numVertexInputs = inputVertexData.Num();
			int inputVertexSize = sizeof(float);
			FRDGBufferRef inputVertexBuffer = CreateUploadBuffer(GraphBuilder, TEXT("InputVertexBuffer"), inputVertexSize, numVertexInputs, RawVertexData, inputVertexSize * numVertexInputs);

			PassParameters->inputVertices = GraphBuilder.CreateSRV(FRDGBufferSRVDesc(inputVertexBuffer, PF_R32_FLOAT));

			// Create input normal data
			TArray<float> inputNormalData;
			for (const FVector& norm : Params.inputNormals)
			{
				inputNormalData.Add(norm.X);
				inputNormalData.Add(norm.Y);
				inputNormalData.Add(norm.Z);
			}

			const void* RawNormalData = (void*)inputNormalData.GetData();
			int numNormalInputs = inputNormalData.Num();
			int inputNormalSize = sizeof(float);
			FRDGBufferRef inputNormalBuffer = CreateUploadBuffer(GraphBuilder, TEXT("InputNormalBuffer"), inputNormalSize, numNormalInputs, RawNormalData, inputNormalSize * numNormalInputs);

			PassParameters->inputNormals = GraphBuilder.CreateSRV(FRDGBufferSRVDesc(inputNormalBuffer, PF_R32_FLOAT));

			//Create output buffer for vertices
			FRDGBufferRef OutputVertexBuffer = GraphBuilder.CreateBuffer(
				FRDGBufferDesc::CreateBufferDesc(sizeof(float), Params.inputVertices.Num() * 3),
				TEXT("OutputVertexBuffer"));

			PassParameters->outputVertices = GraphBuilder.CreateUAV(FRDGBufferUAVDesc(OutputVertexBuffer, PF_R32_FLOAT));

			//Create output buffer for normals
			FRDGBufferRef OutputNormalBuffer = GraphBuilder.CreateBuffer(
				FRDGBufferDesc::CreateBufferDesc(sizeof(float), Params.inputVertices.Num() * 3),
				TEXT("OutputNormalBuffer"));

			PassParameters->outputNormals = GraphBuilder.CreateUAV(FRDGBufferUAVDesc(OutputNormalBuffer, PF_R32_FLOAT));

			//Create output buffer for colors 
			FRDGBufferRef OutputColorBuffer = GraphBuilder.CreateBuffer(
				FRDGBufferDesc::CreateBufferDesc(sizeof(float), Params.inputVertices.Num() * 4),
				TEXT("OutputColorBuffer"));

			PassParameters->outputColors = GraphBuilder.CreateUAV(FRDGBufferUAVDesc(OutputColorBuffer, PF_R32_FLOAT));

			auto GroupCount = FComputeShaderUtils::GetGroupCount(FIntVector(Params.X, Params.Y, Params.Z), FComputeShaderUtils::kGolden2DGroupSize);
			GraphBuilder.AddPass(
				RDG_EVENT_NAME("ExecutePlanetGenerationShader"),
				PassParameters,
				ERDGPassFlags::AsyncCompute,
				[&PassParameters, ComputeShader, GroupCount](FRHIComputeCommandList& RHICmdList)
				{
					FComputeShaderUtils::Dispatch(RHICmdList, ComputeShader, *PassParameters, GroupCount);
				});

			FRHIGPUBufferReadback* GPUVertexBufferReadback = new FRHIGPUBufferReadback(TEXT("ExecutePlanetGenerationShaderVertexOutput"));
			FRHIGPUBufferReadback* GPUNormalBufferReadback = new FRHIGPUBufferReadback(TEXT("ExecutePlanetGenerationShaderNormalOutput"));
			FRHIGPUBufferReadback* GPUColorBufferReadback = new FRHIGPUBufferReadback(TEXT("ExecutePlanetGenerationShaderColorOutput"));

			AddEnqueueCopyPass(GraphBuilder, GPUVertexBufferReadback, OutputVertexBuffer, 0u);
			AddEnqueueCopyPass(GraphBuilder, GPUNormalBufferReadback, OutputNormalBuffer, 0u);
			AddEnqueueCopyPass(GraphBuilder, GPUColorBufferReadback, OutputColorBuffer, 0u);

			auto RunnerFunc = [GPUVertexBufferReadback, GPUNormalBufferReadback, GPUColorBufferReadback, AsyncCallback, NumOutputs = Params.inputVertices.Num()](auto&& RunnerFunc) -> void {
				if (GPUVertexBufferReadback->IsReady() && GPUNormalBufferReadback->IsReady() && GPUColorBufferReadback->IsReady()) {

					//Read vertex data - conversion
					float* VertexBuffer = (float*)GPUVertexBufferReadback->Lock(NumOutputs * 3 * sizeof(float));
					TArray<FVector> OutputVertices;
					for (int i = 0; i < NumOutputs; i++)
					{
						OutputVertices.Add(FVector(
							VertexBuffer[i * 3 + 0],
							VertexBuffer[i * 3 + 1],
							VertexBuffer[i * 3 + 2]
						));
					}
					GPUVertexBufferReadback->Unlock();

					//Read normal data - conversion
					float* NormalBuffer = (float*)GPUNormalBufferReadback->Lock(NumOutputs * 3 * sizeof(float));
					TArray<FVector> OutputNormals;
					for (int i = 0; i < NumOutputs; i++)
					{
						OutputNormals.Add(FVector(
							NormalBuffer[i * 3 + 0],
							NormalBuffer[i * 3 + 1],
							NormalBuffer[i * 3 + 2]
						));
					}
					GPUNormalBufferReadback->Unlock();

					//Read color data - conversion
					float* ColorBuffer = (float*)GPUColorBufferReadback->Lock(NumOutputs * 4 * sizeof(float));
					TArray<FLinearColor> OutputColors;
					for (int i = 0; i < NumOutputs; i++)
					{
						OutputColors.Add(FLinearColor(
							ColorBuffer[i * 4 + 0],
							ColorBuffer[i * 4 + 1],
							ColorBuffer[i * 4 + 2],
							ColorBuffer[i * 4 + 3]
						));
					}
					GPUColorBufferReadback->Unlock();

					AsyncTask(ENamedThreads::GameThread, [AsyncCallback, OutputVertices, OutputNormals, OutputColors]() {
						AsyncCallback(OutputVertices, OutputNormals, OutputColors);
						});

					delete GPUVertexBufferReadback;
					delete GPUNormalBufferReadback;
					delete GPUColorBufferReadback;
				}
				else {
					AsyncTask(ENamedThreads::ActualRenderingThread, [RunnerFunc]() {
						RunnerFunc(RunnerFunc);
						});
				}
				};

			AsyncTask(ENamedThreads::ActualRenderingThread, [RunnerFunc]() {
				RunnerFunc(RunnerFunc);
				});

		}
		else {
#if WITH_EDITOR
			GEngine->AddOnScreenDebugMessage((uint64)42145125184, 6.f, FColor::Red, FString(TEXT("The compute shader has a problem.")));
#endif
			// We exit here as we don't want to crash the game if the shader is not found or has an error.
		}
	}

	GraphBuilder.Execute();
}