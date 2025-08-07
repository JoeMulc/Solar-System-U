#pragma once

#include "CoreMinimal.h"
#include "GenericPlatform/GenericPlatformMisc.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Materials/MaterialRenderProxy.h"

#include "SphereGenerationShader.generated.h"

struct COMPUTEMODULE_API FSphereGenerationShaderDispatchParams
{
	int X;
	int Y;
	int Z;

	int latitudeSegments;
	int longitudeSegments;
	float radius;
	int Output;
	
	

	FSphereGenerationShaderDispatchParams(int x, int y, int z)
		: X(x)
		, Y(y)
		, Z(z)
	{
	}
};

// This is a public interface that we define so outside code can invoke our compute shader.
class COMPUTEMODULE_API FSphereGenerationShaderInterface {
public:
	// Executes this shader on the render thread
	static void DispatchRenderThread(
		FRHICommandListImmediate& RHICmdList,
		FSphereGenerationShaderDispatchParams Params,
		TFunction<void(int OutputVal)> AsyncCallback
	);

	// Executes this shader on the render thread from the game thread via EnqueueRenderThreadCommand
	static void DispatchGameThread(
		FSphereGenerationShaderDispatchParams Params,
		TFunction<void(int OutputVal)> AsyncCallback
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
		FSphereGenerationShaderDispatchParams Params,
		TFunction<void(int OutputVal)> AsyncCallback
	)
	{
		if (IsInRenderingThread()) {
			DispatchRenderThread(GetImmediateCommandList_ForRenderCommand(), Params, AsyncCallback);
		}else{
			DispatchGameThread(Params, AsyncCallback);
		}
	}
};



DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSphereGenerationShaderLibrary_AsyncExecutionCompleted, const int, Value);


UCLASS() // Change the _API to match your project
class COMPUTEMODULE_API USphereGenerationShaderLibrary_AsyncExecution : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	
	// Execute the actual load
	virtual void Activate() override {
		// Create a dispatch parameters struct and fill it the input array with our args
		FSphereGenerationShaderDispatchParams Params(1, 1, 1);
		Params.radius = Arg1;
		Params.latitudeSegments = latSegments;
		Params.longitudeSegments = lonSegments;

		// Dispatch the compute shader and wait until it completes
		FSphereGenerationShaderInterface::Dispatch(Params, [this](int OutputVal) {
			this->Completed.Broadcast(OutputVal);
		});
	}
	
	
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "ComputeShader", WorldContext = "WorldContextObject"))
	static USphereGenerationShaderLibrary_AsyncExecution* ExecuteBaseComputeShader(UObject* WorldContextObject, float Arg1, int lat, int lon) {
		USphereGenerationShaderLibrary_AsyncExecution* Action = NewObject<USphereGenerationShaderLibrary_AsyncExecution>();
		Action->Arg1 = Arg1;
		Action->latSegments = lat;
		Action->lonSegments = lon;
		Action->RegisterWithGameInstance(WorldContextObject);

		return Action;
	}

	UPROPERTY(BlueprintAssignable)
	FOnSphereGenerationShaderLibrary_AsyncExecutionCompleted Completed;

	float Arg1;
	int latSegments;
	int lonSegments;
};