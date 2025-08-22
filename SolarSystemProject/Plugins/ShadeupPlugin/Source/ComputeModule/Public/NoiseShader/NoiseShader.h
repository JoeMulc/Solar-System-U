#pragma once
#include "CoreMinimal.h"
#include "GenericPlatform/GenericPlatformMisc.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Materials/MaterialRenderProxy.h"
#include "NoiseShader.generated.h"

struct COMPUTEMODULE_API FNoiseShaderDispatchParams
{
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
	TArray<FVector> inputVertices;
	TArray<FVector> inputNormals;  // Add input normals
	TArray<FVector> outputVertices;
	TArray<FVector> outputNormals;

	FNoiseShaderDispatchParams(int x, int y, int z)
		: X(x)
		, Y(y)
		, Z(z)
		, normalCalculationEpsilon(0.01f) // Default epsilon for normal calculation
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
	TArray<FVector> inNorm;  // Add input normals
	int outSize;
	int numOc;
	float noiseS;
	float s;
	float pers;
	float lacu;
	float bF;
	float normalEps;

	// Execute the actual load
	virtual void Activate() override {
		// Create a dispatch parameters struct and fill it the input array with our args
		FNoiseShaderDispatchParams Params(1, 1, 1);
		Params.inputVertices = inVert;
		Params.inputNormals = inNorm;  // Set input normals
		Params.outputVertices.SetNum(outSize);
		Params.outputNormals.SetNum(outSize);
		Params.numOctaves = numOc;
		Params.noiseStrength = noiseS;
		Params.scale = s;
		Params.persistence = pers;
		Params.lacunarity = lacu;
		Params.baseFrequency = bF;
		Params.normalCalculationEpsilon = normalEps;

		// Dispatch the compute shader and wait until it completes
		FNoiseShaderInterface::Dispatch(Params, [this](TArray<FVector> OutputVertices, TArray<FVector> OutputNormals) {
			this->Completed.Broadcast(OutputVertices, OutputNormals);
			});
	}

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "ComputeShader", WorldContext = "WorldContextObject"))
	static UNoiseShaderLibrary_AsyncExecution* ExecuteBaseComputeShader(UObject* WorldContextObject, TArray<FVector>& vs, TArray<FVector>& ns, int Arg2, int arg3, float arg4, float arg5, float arg6, float arg7, float arg8, float normalEpsilon = 0.01f) {
		UNoiseShaderLibrary_AsyncExecution* Action = NewObject<UNoiseShaderLibrary_AsyncExecution>();
		Action->inVert = vs;
		Action->inNorm = ns;  // Set input normals
		Action->outSize = Arg2;
		Action->numOc = arg3;
		Action->noiseS = arg4;
		Action->s = arg5;
		Action->pers = arg6;
		Action->lacu = arg7;
		Action->bF = arg8;
		Action->normalEps = normalEpsilon;
		Action->RegisterWithGameInstance(WorldContextObject);
		return Action;
	}

	UPROPERTY(BlueprintAssignable)
	FOnNoiseShaderLibrary_AsyncExecutionCompleted Completed;
};