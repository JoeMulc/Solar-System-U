#pragma once

#include "CoreMinimal.h"
#include "GenericPlatform/GenericPlatformMisc.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Materials/MaterialRenderProxy.h"

#include "PlanetGenerationShader.generated.h"

struct COMPUTEMODULE_API FPlanetGenerationShaderDispatchParams
{
	int X;
	int Y;
	int Z;

	
	TArray<FVector> inputVertices;
	TArray<FVector> inputNormals;
	TArray<FVector> outputVertices;
	TArray<FVector> outputNormals;
	
	

	FPlanetGenerationShaderDispatchParams(int x, int y, int z)
		: X(x)
		, Y(y)
		, Z(z)
	{
	}
};

// This is a public interface that we define so outside code can invoke our compute shader.
class COMPUTEMODULE_API FPlanetGenerationShaderInterface {
public:
	// Executes this shader on the render thread
	static void DispatchRenderThread(
		FRHICommandListImmediate& RHICmdList,
		FPlanetGenerationShaderDispatchParams Params,
		TFunction<void(TArray<FVector> OutputVertices, TArray<FVector> OutputNormals)> AsyncCallback
	);

	// Executes this shader on the render thread from the game thread via EnqueueRenderThreadCommand
	static void DispatchGameThread(
		FPlanetGenerationShaderDispatchParams Params,
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
		FPlanetGenerationShaderDispatchParams Params,
		TFunction<void(TArray<FVector> OutputVertices, TArray<FVector> OutputNormals)> AsyncCallback
	)
	{
		if (IsInRenderingThread()) {
			DispatchRenderThread(GetImmediateCommandList_ForRenderCommand(), Params, AsyncCallback);
		}else{
			DispatchGameThread(Params, AsyncCallback);
		}
	}
};



DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlanetGenerationShaderLibrary_AsyncExecutionCompleted, const TArray<FVector>&, Vertices, const TArray<FVector>&, Normals);


UCLASS() // Change the _API to match your project
class COMPUTEMODULE_API UPlanetGenerationShaderLibrary_AsyncExecution : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	TArray<FVector> inVert;
	TArray<FVector> inNorm;

	// Execute the actual load
	virtual void Activate() override {
		// Create a dispatch parameters struct and fill it the input array with our args
		FPlanetGenerationShaderDispatchParams Params(1, 1, 1);
		Params.inputVertices = inVert;
		Params.inputNormals = inNorm;

		// Dispatch the compute shader and wait until it completes
		FPlanetGenerationShaderInterface::Dispatch(Params, [this](TArray<FVector> OutputVertices, TArray<FVector> OutputNormals) {
			this->Completed.Broadcast(OutputVertices, OutputNormals);
		});
	}
	
	
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "ComputeShader", WorldContext = "WorldContextObject"))
	static UPlanetGenerationShaderLibrary_AsyncExecution* ExecuteBaseComputeShader(UObject* WorldContextObject, TArray<FVector>& vs, TArray<FVector>& ns) {
		UPlanetGenerationShaderLibrary_AsyncExecution* Action = NewObject<UPlanetGenerationShaderLibrary_AsyncExecution>();
		Action->inVert = vs;
		Action->inNorm = ns;
		Action->RegisterWithGameInstance(WorldContextObject);

		return Action;
	}

	UPROPERTY(BlueprintAssignable)
	FOnPlanetGenerationShaderLibrary_AsyncExecutionCompleted Completed;
	
};