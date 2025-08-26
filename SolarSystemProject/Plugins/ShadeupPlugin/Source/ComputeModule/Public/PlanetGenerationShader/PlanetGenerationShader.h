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

    float seaLevel;
    float oceanDepth;
    float mountainHeight;
    float continentHeight;
    float valleyDepth;

    float grassSlopeThreshold;
    float rockSlopeThreshold;
    float snowHeightThreshold;
    float sandHeightThreshold;

    float continentScale;
    float mountainScale;
    float detailScale;
    float ridgeScale;

    TArray<FVector> inputVertices;
    TArray<FVector> inputNormals;
    TArray<FVector> outputVertices;
    TArray<FVector> outputNormals;
    TArray<FLinearColor> outputColors;

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
        TFunction<void(TArray<FVector> OutputVertices, TArray<FVector> OutputNormals, TArray<FLinearColor> OutputColors)> AsyncCallback
    );

    // Executes this shader on the render thread from the game thread via EnqueueRenderThreadCommand
    static void DispatchGameThread(
        FPlanetGenerationShaderDispatchParams Params,
        TFunction<void(TArray<FVector> OutputVertices, TArray<FVector> OutputNormals, TArray<FLinearColor> OutputColors)> AsyncCallback
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
        TFunction<void(TArray<FVector> OutputVertices, TArray<FVector> OutputNormals, TArray<FLinearColor> OutputColors)> AsyncCallback
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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPlanetGenerationShaderLibrary_AsyncExecutionCompleted,
    const TArray<FVector>&, Vertices,
    const TArray<FVector>&, Normals,
    const TArray<FLinearColor>&, Colors);

UCLASS() // Change the _API to match your project
class COMPUTEMODULE_API UPlanetGenerationShaderLibrary_AsyncExecution : public UBlueprintAsyncActionBase
{
    GENERATED_BODY()

public:
    float sL;
    float oDf;
    float mHf;
    float cH;
    float vDf;

    float gST;
    float rST;
    float snowHT;
    float sandHT;

    float cs;
    float mS;
    float dS;
    float rS;
    TArray<FVector> inVert;
    TArray<FVector> inNorm;

    // Execute the actual load
    virtual void Activate() override {
        FPlanetGenerationShaderDispatchParams Params(inVert.Num(), 1, 1);
        Params.inputVertices = inVert;
        Params.inputNormals = inNorm;

        // Dispatch the compute shader and wait until it completes
        FPlanetGenerationShaderInterface::Dispatch(Params, [this](TArray<FVector> OutputVertices, TArray<FVector> OutputNormals, TArray<FLinearColor> OutputColors) {
            this->Completed.Broadcast(OutputVertices, OutputNormals, OutputColors);
            });
    }

    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "ComputeShader", WorldContext = "WorldContextObject"))
    static UPlanetGenerationShaderLibrary_AsyncExecution* ExecuteBaseComputeShader(UObject* WorldContextObject, TArray<FVector>& vs, TArray<FVector>& ns, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6, float arg7, float arg8, float arg9, float arg10, float arg11, float arg12, float arg13) {
        UPlanetGenerationShaderLibrary_AsyncExecution* Action = NewObject<UPlanetGenerationShaderLibrary_AsyncExecution>();
        Action->sL = arg1;
        Action->oDf = arg2;
        Action->mHf = arg3;
        Action->cH = arg4;
        Action->vDf = arg5;
        Action->gST = arg6;
        Action->rST = arg7;
        Action->snowHT = arg8;
        Action->sandHT = arg9;
        Action->cs = arg10;
        Action->mS = arg11;
        Action->dS = arg12;
        Action->rS = arg13;
        Action->inVert = vs;
        Action->inNorm = ns;
       
        Action->RegisterWithGameInstance(WorldContextObject);
        return Action;
    }

    UPROPERTY(BlueprintAssignable)
    FOnPlanetGenerationShaderLibrary_AsyncExecutionCompleted Completed;
};