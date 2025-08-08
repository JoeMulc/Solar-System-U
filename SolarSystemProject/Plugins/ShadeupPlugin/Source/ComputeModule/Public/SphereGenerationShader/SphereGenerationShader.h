#pragma once
#include "CoreMinimal.h"
#include "GenericPlatform/GenericPlatformMisc.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Materials/MaterialRenderProxy.h"
#include "SphereGenerationShader.generated.h"

// Struct to hold sphere geometry data
USTRUCT(BlueprintType)
struct COMPUTEMODULE_API FSphereGeometryData
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    TArray<FVector> Vertices;

    UPROPERTY(BlueprintReadOnly)
    TArray<int32> Triangles;

    UPROPERTY(BlueprintReadOnly)
    TArray<FVector> Normals;

    UPROPERTY(BlueprintReadOnly)
    TArray<FVector2D> UVs;


    FSphereGeometryData()
    {
        Vertices.Empty();
        Triangles.Empty();
        Normals.Empty();
        UVs.Empty();
    }
};

struct COMPUTEMODULE_API FSphereGenerationShaderDispatchParams
{
    int X;
    int Y;
    int Z;
    int latitudeSegments;
    int longitudeSegments;
    float radius;

    FSphereGenerationShaderDispatchParams(int x, int y, int z)
        : X(x)
        , Y(y)
        , Z(z)
        , latitudeSegments(16)
        , longitudeSegments(32)
        , radius(100.0f)
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
        TFunction<void(const FSphereGeometryData&)> AsyncCallback
    );

    // Executes this shader on the render thread from the game thread via EnqueueRenderThreadCommand
    static void DispatchGameThread(
        FSphereGenerationShaderDispatchParams Params,
        TFunction<void(const FSphereGeometryData&)> AsyncCallback
    )
    {
        ENQUEUE_RENDER_COMMAND(SphereGenerationShaderCommand)(
            [Params, AsyncCallback](FRHICommandListImmediate& RHICmdList)
            {
                DispatchRenderThread(RHICmdList, Params, AsyncCallback);
            });
    }

    // Dispatches this shader. Can be called from any thread
    static void Dispatch(
        FSphereGenerationShaderDispatchParams Params,
        TFunction<void(const FSphereGeometryData&)> AsyncCallback
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

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSphereGenerationShaderLibrary_AsyncExecutionCompleted, const FSphereGeometryData&, GeometryData);

UCLASS() // Change the _API to match your project
class COMPUTEMODULE_API USphereGenerationShaderLibrary_AsyncExecution : public UBlueprintAsyncActionBase
{
    GENERATED_BODY()
public:

    // Execute the actual load
    virtual void Activate() override {
        // Create a dispatch parameters struct and fill it with our args
        FSphereGenerationShaderDispatchParams Params(1, 1, 1);
        Params.radius = Radius;
        Params.latitudeSegments = LatitudeSegments;
        Params.longitudeSegments = LongitudeSegments;

        // Dispatch the compute shader and wait until it completes
        FSphereGenerationShaderInterface::Dispatch(Params, [this](const FSphereGeometryData& GeometryData) {
            this->Completed.Broadcast(GeometryData);
            });
    }

    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "ComputeShader", WorldContext = "WorldContextObject"))
    static USphereGenerationShaderLibrary_AsyncExecution* ExecuteSphereGenerationShader(
        UObject* WorldContextObject,
        float InRadius = 100.0f,
        int32 InLatitudeSegments = 16,
        int32 InLongitudeSegments = 32)
    {
        USphereGenerationShaderLibrary_AsyncExecution* Action = NewObject<USphereGenerationShaderLibrary_AsyncExecution>();
        Action->Radius = InRadius;
        Action->LatitudeSegments = InLatitudeSegments;
        Action->LongitudeSegments = InLongitudeSegments;
        Action->RegisterWithGameInstance(WorldContextObject);
        return Action;
    }

    UPROPERTY(BlueprintAssignable)
    FOnSphereGenerationShaderLibrary_AsyncExecutionCompleted Completed;

private:
    float Radius;
    int32 LatitudeSegments;
    int32 LongitudeSegments;
};