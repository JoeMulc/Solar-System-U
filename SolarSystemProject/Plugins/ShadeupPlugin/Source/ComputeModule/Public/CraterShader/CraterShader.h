#pragma once
#include "CoreMinimal.h"
#include "GenericPlatform/GenericPlatformMisc.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Materials/MaterialRenderProxy.h"
#include "CraterShader.generated.h"

struct COMPUTEMODULE_API FCraterShaderDispatchParams
{
    int X;
    int Y;
    int Z;
    int numCraters;
    float normalCalculationEpsilon;
    TArray<FVector> inputVertices;
    TArray<FVector> outputVertices;
    TArray<FVector> outputNormals;

    FCraterShaderDispatchParams(int x, int y, int z)
        : X(x)
        , Y(y)
        , Z(z)
        , normalCalculationEpsilon(0.01f) 
    {
    }
};

// This is a public interface that we define so outside code can invoke our compute shader.
class COMPUTEMODULE_API FCraterShaderInterface {
public:
    // Executes this shader on the render thread
    static void DispatchRenderThread(
        FRHICommandListImmediate& RHICmdList,
        FCraterShaderDispatchParams Params,
        TFunction<void(TArray<FVector> OutputVertices, TArray<FVector> OutputNormals)> AsyncCallback
    );

    // Executes this shader on the render thread from the game thread via EnqueueRenderThreadCommand
    static void DispatchGameThread(
        FCraterShaderDispatchParams Params,
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
        FCraterShaderDispatchParams Params,
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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCraterShaderLibrary_AsyncExecutionCompleted, const TArray<FVector>&, Vertices, const TArray<FVector>&, Normals);

UCLASS() // Change the _API to match your project
class COMPUTEMODULE_API UCraterShaderLibrary_AsyncExecution : public UBlueprintAsyncActionBase
{
    GENERATED_BODY()
public:
    // Execute the actual load
    virtual void Activate() override {
        // Create a dispatch parameters struct and fill it with our input vectors
        FCraterShaderDispatchParams Params(1, 1, 1);
        Params.inputVertices = InputVectors;
        Params.numCraters = craters;
        Params.normalCalculationEpsilon = normalEpsilon;
        Params.outputVertices.SetNum(OutputSize); 
        Params.outputNormals.SetNum(OutputSize); 

        // Dispatch the compute shader and wait until it completes
        FCraterShaderInterface::Dispatch(Params, [this](TArray<FVector> OutputVertices, TArray<FVector> OutputNormals) {
            this->Completed.Broadcast(OutputVertices, OutputNormals);
            });
    }

    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "ComputeShader", WorldContext = "WorldContextObject"))
    static UCraterShaderLibrary_AsyncExecution* ExecuteBaseComputeShader(UObject* WorldContextObject, const TArray<FVector>& InputVectors, int OutputSize, int c, float normalEps = 0.01f) {
        UCraterShaderLibrary_AsyncExecution* Action = NewObject<UCraterShaderLibrary_AsyncExecution>();
        Action->InputVectors = InputVectors;
        Action->OutputSize = OutputSize;
        Action->craters = c;
        Action->normalEpsilon = normalEps;
        Action->RegisterWithGameInstance(WorldContextObject);
        return Action;
    }

    UPROPERTY(BlueprintAssignable)
    FOnCraterShaderLibrary_AsyncExecutionCompleted Completed;

    TArray<FVector> InputVectors;
    int OutputSize;
    int craters;
    float normalEpsilon;
};