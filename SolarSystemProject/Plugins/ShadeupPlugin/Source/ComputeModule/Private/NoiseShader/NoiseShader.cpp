#include "NoiseShader.h"
#include "ComputeModule/Public/NoiseShader/NoiseShader.h"
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

DECLARE_STATS_GROUP(TEXT("NoiseShader"), STATGROUP_NoiseShader, STATCAT_Advanced);
DECLARE_CYCLE_STAT(TEXT("NoiseShader Execute"), STAT_NoiseShader_Execute, STATGROUP_NoiseShader);

// This class carries our parameter declarations and acts as the bridge between cpp and HLSL.
class COMPUTEMODULE_API FNoiseShader : public FGlobalShader
{
public:

	DECLARE_GLOBAL_SHADER(FNoiseShader);
	SHADER_USE_PARAMETER_STRUCT(FNoiseShader, FGlobalShader);


	class FNoiseShader_Perm_TEST : SHADER_PERMUTATION_INT("TEST", 1);
	using FPermutationDomain = TShaderPermutationDomain<
		FNoiseShader_Perm_TEST
	>;

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER(int, numOctaves)
		SHADER_PARAMETER(float, noiseStrength)
		SHADER_PARAMETER(float, scale)
		SHADER_PARAMETER(float, persistence)
		SHADER_PARAMETER(float, lacunarity)
		SHADER_PARAMETER(float, baseFrequency)
		SHADER_PARAMETER(float, normalCalculationEpsilon)
		SHADER_PARAMETER_RDG_BUFFER_SRV(Buffer<float>, inputVertices)
		SHADER_PARAMETER_RDG_BUFFER_SRV(Buffer<float>, inputNormals)
		SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<float>, outputVertices)
		SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<float>, outputNormals)
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
		* Here you define constants that can be used statically in the shader code.
		* Example:
		*/
		// OutEnvironment.SetDefine(TEXT("MY_CUSTOM_CONST"), TEXT("1"));

		/*
		* These defines are used in the thread count section of our shader
		*/
		OutEnvironment.SetDefine(TEXT("THREADS_X"), NUM_THREADS_NoiseShader_X);
		OutEnvironment.SetDefine(TEXT("THREADS_Y"), NUM_THREADS_NoiseShader_Y);
		OutEnvironment.SetDefine(TEXT("THREADS_Z"), NUM_THREADS_NoiseShader_Z);

		// This shader must support typed UAV load and we are testing if it is supported at runtime using RHIIsTypedUAVLoadSupported
		//OutEnvironment.CompilerFlags.Add(CFLAG_AllowTypedUAVLoads);

		// FForwardLightingParameters::ModifyCompilationEnvironment(Parameters.Platform, OutEnvironment);
	}
private:
};

// This will tell the engine to create the shader and where the shader entry point is.
//                            ShaderType                            ShaderPath                     Shader function name    Type
IMPLEMENT_GLOBAL_SHADER(FNoiseShader, "/ComputeModuleShaders/NoiseShader/NoiseShader.usf", "NoiseShader", SF_Compute);

void FNoiseShaderInterface::DispatchRenderThread(FRHICommandListImmediate& RHICmdList, FNoiseShaderDispatchParams Params, TFunction<void(TArray<FVector> OutputVertices, TArray<FVector> OutputNormals)> AsyncCallback) {
	FRDGBuilder GraphBuilder(RHICmdList);

	{
		SCOPE_CYCLE_COUNTER(STAT_NoiseShader_Execute);
		DECLARE_GPU_STAT(NoiseShader)
		RDG_EVENT_SCOPE(GraphBuilder, "NoiseShader");
		RDG_GPU_STAT_SCOPE(GraphBuilder, NoiseShader);

		typename FNoiseShader::FPermutationDomain PermutationVector;

		// Add any static permutation options here
		// PermutationVector.Set<FNoiseShader::FMyPermutationName>(12345);

		TShaderMapRef<FNoiseShader> ComputeShader(GetGlobalShaderMap(GMaxRHIFeatureLevel), PermutationVector);


		bool bIsShaderValid = ComputeShader.IsValid();

		if (bIsShaderValid) {
			FNoiseShader::FParameters* PassParameters = GraphBuilder.AllocParameters<FNoiseShader::FParameters>();

			PassParameters->numOctaves = Params.numOctaves;
			PassParameters->noiseStrength = Params.noiseStrength;
			PassParameters->scale = Params.scale;
			PassParameters->persistence = Params.persistence;
			PassParameters->lacunarity = Params.lacunarity;
			PassParameters->baseFrequency = Params.baseFrequency;
			PassParameters->normalCalculationEpsilon = Params.normalCalculationEpsilon;

			// Create input vertex data
			TArray<float> inputVertexData;
			inputVertexData.Add((float)Params.inputVertices.Num()); // Add vertex count as first element

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

			// Create output buffer for vertices
			FRDGBufferRef OutputVertexBuffer = GraphBuilder.CreateBuffer(
				FRDGBufferDesc::CreateBufferDesc(sizeof(float), Params.inputVertices.Num() * 3),
				TEXT("OutputVertexBuffer"));

			PassParameters->outputVertices = GraphBuilder.CreateUAV(FRDGBufferUAVDesc(OutputVertexBuffer, PF_R32_FLOAT));

			// Create output buffer for normals
			FRDGBufferRef OutputNormalBuffer = GraphBuilder.CreateBuffer(
				FRDGBufferDesc::CreateBufferDesc(sizeof(float), Params.inputVertices.Num() * 3),
				TEXT("OutputNormalBuffer"));

			PassParameters->outputNormals = GraphBuilder.CreateUAV(FRDGBufferUAVDesc(OutputNormalBuffer, PF_R32_FLOAT));

			auto GroupCount = FComputeShaderUtils::GetGroupCount(FIntVector(Params.X, Params.Y, Params.Z), FComputeShaderUtils::kGolden2DGroupSize);
			GraphBuilder.AddPass(
				RDG_EVENT_NAME("ExecuteNoiseShader"),
				PassParameters,
				ERDGPassFlags::AsyncCompute,
				[&PassParameters, ComputeShader, GroupCount](FRHIComputeCommandList& RHICmdList)
				{
					FComputeShaderUtils::Dispatch(RHICmdList, ComputeShader, *PassParameters, GroupCount);
				});


			FRHIGPUBufferReadback* GPUVertexBufferReadback = new FRHIGPUBufferReadback(TEXT("ExecuteNoiseShaderVertexOutput"));
			FRHIGPUBufferReadback* GPUNormalBufferReadback = new FRHIGPUBufferReadback(TEXT("ExecuteNoiseShaderNormalOutput"));

			AddEnqueueCopyPass(GraphBuilder, GPUVertexBufferReadback, OutputVertexBuffer, 0u);
			AddEnqueueCopyPass(GraphBuilder, GPUNormalBufferReadback, OutputNormalBuffer, 0u);

			auto RunnerFunc = [GPUVertexBufferReadback, GPUNormalBufferReadback, AsyncCallback, NumOutputs = Params.inputVertices.Num()](auto&& RunnerFunc) -> void {
				if (GPUVertexBufferReadback->IsReady() && GPUNormalBufferReadback->IsReady()) {

					// Read vertex data
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

					// Read normal data
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

					AsyncTask(ENamedThreads::GameThread, [AsyncCallback, OutputVertices, OutputNormals]() {
						AsyncCallback(OutputVertices, OutputNormals);
						});

					delete GPUVertexBufferReadback;
					delete GPUNormalBufferReadback;
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