#pragma once
#include "CoreMinimal.h"
#include "GenericPlatform/GenericPlatformMisc.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Materials/MaterialRenderProxy.h"
#include "NoiseShader.generated.h"

struct COMPUTEMODULE_API FNoiseShaderDispatchParams
{
	//HOLY SMOKES LOOK AT ALL THOSE PARAMETERS EVER HEARD OF A STRUCT MORON
	int X;
	int Y;
	int Z;
	int numOctaves;
	float noiseStrength;
	float scale;
	float persistence;
	float lacunarity;
	float baseFrequency;
	float normalCalculationEpsilon;
	float ridgeStrength; 
	float detailNoiseStrength; 
	float detailScale; 
	float fineDetailStrength; 
	float fineDetailScale; 
	float ultraFineStrength; 
	float ultraFineScale; 
	TArray<FVector> inputVertices;
	TArray<FVector> inputNormals;  
	TArray<FVector> outputVertices;
	TArray<FVector> outputNormals;

	FNoiseShaderDispatchParams(int x, int y, int z)
		: X(x)
		, Y(y)
		, Z(z)
		, normalCalculationEpsilon(0.01f) 
	{
	}
};

// This is a public interface that we define so outside code can invoke our compute shader.
class COMPUTEMODULE_API FNoiseShaderInterface {
public:
	// Executes this shader on the render thread
	static void DispatchRenderThread(
		FRHICommandListImmediate& RHICmdList,
		FNoiseShaderDispatchParams Params,
		TFunction<void(TArray<FVector> OutputVertices, TArray<FVector> OutputNormals)> AsyncCallback
	);

	// Executes this shader on the render thread from the game thread via EnqueueRenderThreadCommand
	static void DispatchGameThread(
		FNoiseShaderDispatchParams Params,
		TFunction<void(TArray<FVector> OutputVertices, TArray<FVector> OutputNormals)> AsyncCallback
	)
	{
		ENQUEUE_RENDER_COMMAND(SceneDrawCompletion)(
			[Params, AsyncCallback](FRHICommandListImmediate& RHICmdList)
			{
				DispatchRenderThread(RHICmdList, Params, AsyncCallback);
			});
	}

	// Dispatches this shader. Can be called from any thread
	static void Dispatch(
		FNoiseShaderDispatchParams Params,
		TFunction<void(TArray<FVector> OutputVertices, TArray<FVector> OutputNormals)> AsyncCallback
	)
	{
		if (IsInRenderingThread()) {
			DispatchRenderThread(GetImmediateCommandList_ForRenderCommand(), Params, AsyncCallback);
		}
		else {
			DispatchGameThread(Params, AsyncCallback);
		}
	}
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNoiseShaderLibrary_AsyncExecutionCompleted, const TArray<FVector>&, Vertices, const TArray<FVector>&, Normals);

UCLASS() // Change the _API to match your project
class COMPUTEMODULE_API UNoiseShaderLibrary_AsyncExecution : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	TArray<FVector> inVert;
	TArray<FVector> inNorm; 
	int outSize;
	int numOc;
	float noiseS;
	float s;
	float pers;
	float lacu;
	float bF;
	float normalEps;

	float rS;
	float dNS;
	float dS;
	float fDS;
	float fDScale;
	float uFS;
	float uFScale;

	// Execute the actual load
	virtual void Activate() override {
		// Create a dispatch parameters struct and fill it the input array with our args
		FNoiseShaderDispatchParams Params(1, 1, 1);
		Params.inputVertices = inVert;
		Params.inputNormals = inNorm;  
		Params.outputVertices.SetNum(outSize);
		Params.outputNormals.SetNum(outSize);
		Params.numOctaves = numOc;
		Params.noiseStrength = noiseS;
		Params.scale = s;
		Params.persistence = pers;
		Params.lacunarity = lacu;
		Params.baseFrequency = bF;
		Params.ridgeStrength = rS;
		Params.detailNoiseStrength = dNS;
		Params.detailScale = dS;
		Params.fineDetailStrength = fDS;
		Params.fineDetailScale = fDScale;
		Params.ultraFineStrength = uFS;
		Params.ultraFineScale = uFScale;
		Params.normalCalculationEpsilon = normalEps;

		// Dispatch the compute shader and wait until it completes
		FNoiseShaderInterface::Dispatch(Params, [this](TArray<FVector> OutputVertices, TArray<FVector> OutputNormals) {
			this->Completed.Broadcast(OutputVertices, OutputNormals);
			});
	}

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "ComputeShader", WorldContext = "WorldContextObject"))
	static UNoiseShaderLibrary_AsyncExecution* ExecuteBaseComputeShader(UObject* WorldContextObject, TArray<FVector>& vs, TArray<FVector>& ns, int Arg2, int arg3, float arg4, float arg5, float arg6, float arg7, float arg8, float arg9, float arg10, float arg11, float arg12, float arg13, float arg14, float arg15, float normalEpsilon = 0.01f) {
		UNoiseShaderLibrary_AsyncExecution* Action = NewObject<UNoiseShaderLibrary_AsyncExecution>();
		Action->inVert = vs;
		Action->inNorm = ns; 
		Action->outSize = Arg2;
		Action->numOc = arg3;
		Action->noiseS = arg4;
		Action->s = arg5;
		Action->pers = arg6;
		Action->lacu = arg7;
		Action->bF = arg8;
		Action->rS = arg9;
		Action->dNS = arg10;
		Action->dS = arg11;
		Action->fDS = arg12;
		Action->fDScale = arg13;
		Action->uFS = arg14;
		Action->uFScale = arg15;
		Action->normalEps = normalEpsilon;
		Action->RegisterWithGameInstance(WorldContextObject);
		return Action;
	}

	UPROPERTY(BlueprintAssignable)
	FOnNoiseShaderLibrary_AsyncExecutionCompleted Completed;
};