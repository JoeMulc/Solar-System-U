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

	TArray<FVector> inputVertices;
	TArray<FVector> outputVertices;
	
	

	FNoiseShaderDispatchParams(int x, int y, int z)
		: X(x)
		, Y(y)
		, Z(z)
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
		TFunction<void(TArray<FVector> OutputValues)> AsyncCallback
	);

	// Executes this shader on the render thread from the game thread via EnqueueRenderThreadCommand
	static void DispatchGameThread(
		FNoiseShaderDispatchParams Params,
		TFunction<void(TArray<FVector> OutputValues)> AsyncCallback
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
		TFunction<void(TArray<FVector> OutputValues)> AsyncCallback
	)
	{
		if (IsInRenderingThread()) {
			DispatchRenderThread(GetImmediateCommandList_ForRenderCommand(), Params, AsyncCallback);
		}else{
			DispatchGameThread(Params, AsyncCallback);
		}
	}
};



DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNoiseShaderLibrary_AsyncExecutionCompleted, const TArray<FVector>&, values);


UCLASS() // Change the _API to match your project
class COMPUTEMODULE_API UNoiseShaderLibrary_AsyncExecution : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	TArray<FVector> inVert;
	int outSize;

	// Execute the actual load
	virtual void Activate() override {
		// Create a dispatch parameters struct and fill it the input array with our args
		FNoiseShaderDispatchParams Params(1, 1, 1);
		Params.inputVertices = inVert;
		Params.outputVertices.SetNum(outSize);

		// Dispatch the compute shader and wait until it completes
		FNoiseShaderInterface::Dispatch(Params, [this](TArray<FVector> OutputValues) {
			this->Completed.Broadcast(OutputValues);
		});
	}
	
	
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "ComputeShader", WorldContext = "WorldContextObject"))
	static UNoiseShaderLibrary_AsyncExecution* ExecuteBaseComputeShader(UObject* WorldContextObject, TArray<FVector>& vs, int Arg2) {
		UNoiseShaderLibrary_AsyncExecution* Action = NewObject<UNoiseShaderLibrary_AsyncExecution>();
		Action->inVert = vs;
		Action->outSize = Arg2;
		Action->RegisterWithGameInstance(WorldContextObject);

		return Action;
	}

	UPROPERTY(BlueprintAssignable)
	FOnNoiseShaderLibrary_AsyncExecutionCompleted Completed;

};