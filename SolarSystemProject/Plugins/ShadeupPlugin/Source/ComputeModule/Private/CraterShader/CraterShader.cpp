#include "CraterShader.h"
#include "ComputeModule/Public/CraterShader/CraterShader.h"
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

DECLARE_STATS_GROUP(TEXT("CraterShader"), STATGROUP_CraterShader, STATCAT_Advanced);
DECLARE_CYCLE_STAT(TEXT("CraterShader Execute"), STAT_CraterShader_Execute, STATGROUP_CraterShader);

// This class carries our parameter declarations and acts as the bridge between cpp and HLSL.
class COMPUTEMODULE_API FCraterShader : public FGlobalShader
{
public:

	DECLARE_GLOBAL_SHADER(FCraterShader);
	SHADER_USE_PARAMETER_STRUCT(FCraterShader, FGlobalShader);


	class FCraterShader_Perm_TEST : SHADER_PERMUTATION_INT("TEST", 1);
	using FPermutationDomain = TShaderPermutationDomain<
		FCraterShader_Perm_TEST
	>;

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_RDG_BUFFER_SRV(Buffer<float>, inputVertices)
		SHADER_PARAMETER_RDG_BUFFER_UAV(RWBuffer<float>, outputVertices)
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
		OutEnvironment.SetDefine(TEXT("THREADS_X"), NUM_THREADS_CraterShader_X);
		OutEnvironment.SetDefine(TEXT("THREADS_Y"), NUM_THREADS_CraterShader_Y);
		OutEnvironment.SetDefine(TEXT("THREADS_Z"), NUM_THREADS_CraterShader_Z);

		// This shader must support typed UAV load and we are testing if it is supported at runtime using RHIIsTypedUAVLoadSupported
		//OutEnvironment.CompilerFlags.Add(CFLAG_AllowTypedUAVLoads);

		// FForwardLightingParameters::ModifyCompilationEnvironment(Parameters.Platform, OutEnvironment);
	}
private:
};

// This will tell the engine to create the shader and where the shader entry point is.
//                            ShaderType                            ShaderPath                     Shader function name    Type
IMPLEMENT_GLOBAL_SHADER(FCraterShader, "/ComputeModuleShaders/CraterShader/CraterShader.usf", "CraterShader", SF_Compute);

void FCraterShaderInterface::DispatchRenderThread(FRHICommandListImmediate& RHICmdList, FCraterShaderDispatchParams Params, TFunction<void(TArray<FVector> OutputValues)> AsyncCallback) {
	FRDGBuilder GraphBuilder(RHICmdList);

	{
		SCOPE_CYCLE_COUNTER(STAT_CraterShader_Execute);
		DECLARE_GPU_STAT(CraterShader)
		RDG_EVENT_SCOPE(GraphBuilder, "CraterShader");
		RDG_GPU_STAT_SCOPE(GraphBuilder, CraterShader);

		typename FCraterShader::FPermutationDomain PermutationVector;

		// Add any static permutation options here
		// PermutationVector.Set<FCraterShader::FMyPermutationName>(12345);

		TShaderMapRef<FCraterShader> ComputeShader(GetGlobalShaderMap(GMaxRHIFeatureLevel), PermutationVector);

		bool bIsShaderValid = ComputeShader.IsValid();

		if (bIsShaderValid) {
			FCraterShader::FParameters* PassParameters = GraphBuilder.AllocParameters<FCraterShader::FParameters>();

			// Convert FVector array to FVector3f for shader
			TArray<float> inputData;
			for (const FVector& vert : Params.inputVertices)
			{
				inputData.Add(vert.X);
				inputData.Add(vert.Y);
				inputData.Add(vert.Z);
			}

			const void* RawData = (void*)inputData.GetData();
			int numInputs = inputData.Num();
			int inputSize = sizeof(float);
			FRDGBufferRef inputBuffer = CreateUploadBuffer(GraphBuilder, TEXT("InputBuffer"), inputSize, numInputs, RawData, inputSize * numInputs);

			PassParameters->inputVertices = GraphBuilder.CreateSRV(FRDGBufferSRVDesc(inputBuffer, PF_R32_FLOAT));
			
			FRDGBufferRef OutputBuffer = GraphBuilder.CreateBuffer(
				FRDGBufferDesc::CreateBufferDesc(sizeof(float), Params.inputVertices.Num() * 3),
				TEXT("OutputBuffer"));

			PassParameters->outputVertices = GraphBuilder.CreateUAV(FRDGBufferUAVDesc(OutputBuffer, PF_R32_FLOAT));

			auto GroupCount = FComputeShaderUtils::GetGroupCount(FIntVector(Params.X, Params.Y, Params.Z), FComputeShaderUtils::kGolden2DGroupSize);
			GraphBuilder.AddPass(
				RDG_EVENT_NAME("ExecuteCraterShader"),
				PassParameters,
				ERDGPassFlags::AsyncCompute,
				[&PassParameters, ComputeShader, GroupCount](FRHIComputeCommandList& RHICmdList)
				{
					FComputeShaderUtils::Dispatch(RHICmdList, ComputeShader, *PassParameters, GroupCount);
				});

			FRHIGPUBufferReadback* GPUBufferReadback = new FRHIGPUBufferReadback(TEXT("ExecuteCraterShaderOutput"));
			AddEnqueueCopyPass(GraphBuilder, GPUBufferReadback, OutputBuffer, 0u);

			auto RunnerFunc = [GPUBufferReadback, AsyncCallback, NumOutputs = Params.outputVertices.Num()](auto&& RunnerFunc) -> void {
				if (GPUBufferReadback->IsReady()) {

					float* Buffer = (float*)GPUBufferReadback->Lock(NumOutputs * 3 * sizeof(float));

					TArray<FVector> OutputValues;
					for (int i = 0; i < NumOutputs; i++)
					{
						OutputValues.Add(FVector(
							Buffer[i * 3 + 0],
							Buffer[i * 3 + 1],
							Buffer[i * 3 + 2]
						));
					}

					GPUBufferReadback->Unlock();

					AsyncTask(ENamedThreads::GameThread, [AsyncCallback, OutputValues]() {
						AsyncCallback(OutputValues);
						});

					delete GPUBufferReadback;
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