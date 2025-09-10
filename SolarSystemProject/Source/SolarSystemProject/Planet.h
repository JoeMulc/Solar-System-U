// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OrbitingBody.h"
#include "PlanetGenerationShader/PlanetGenerationShader.h"
#include "Components\PostProcessComponent.h"
#include "Planet.generated.h"

USTRUCT()
struct FPlanetInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Planet Generation") float seaLevel = 0.0f;
	UPROPERTY(EditAnywhere, Category = "Planet Generation") float oceanDepth = -80.f;               //Nested structs?? - cant be bothered rn with unreal stuff but would be better :D
	UPROPERTY(EditAnywhere, Category = "Planet Generation") float mountainHeight = 150.f;
	UPROPERTY(EditAnywhere, Category = "Planet Generation") float continentHeight = 40.f;
	UPROPERTY(EditAnywhere, Category = "Planet Generation") float valleyDepth = -30.f;

	UPROPERTY(EditAnywhere, Category = "Planet Generation|Color Thresholds") float grassSlopeThreshold = 0.3f;
	UPROPERTY(EditAnywhere, Category = "Planet Generation|Color Thresholds") float rockSlopeThreshold = 0.7f;
	UPROPERTY(EditAnywhere, Category = "Planet Generation|Color Thresholds") float snowHeightThreshold = 80.f;
	UPROPERTY(EditAnywhere, Category = "Planet Generation|Color Thresholds") float sandHeightThreshold = 10.f;

    UPROPERTY(EditAnywhere, Category = "Planet Generation|Scales") float continentMin = 1.1f;
    UPROPERTY(EditAnywhere, Category = "Planet Generation|Scales") float continentMax = 1.0f;
	UPROPERTY(EditAnywhere, Category = "Planet Generation|Scales") float continentScale = 0.002f;
	UPROPERTY(EditAnywhere, Category = "Planet Generation|Scales") float mountainScale = 0.005f;
	UPROPERTY(EditAnywhere, Category = "Planet Generation|Scales") float detailScale = 0.008f;
	UPROPERTY(EditAnywhere, Category = "Planet Generation|Scales") float ridgeScale = 0.008f;

    UPROPERTY(EditAnywhere, Category = "Planet Generation|Colours") FLinearColor oceanColor = FLinearColor(0.1, 0.3, 0.8, 1.0);
    UPROPERTY(EditAnywhere, Category = "Planet Generation|Colours") FLinearColor shallowColor = FLinearColor(0.2, 0.6, 0.9, 1.0);
    UPROPERTY(EditAnywhere, Category = "Planet Generation|Colours") FLinearColor sandColor = FLinearColor(0.9, 0.8, 0.6, 1.0);
    UPROPERTY(EditAnywhere, Category = "Planet Generation|Colours") FLinearColor grassColor = FLinearColor(0.2, 0.7, 0.1, 1.0);
    UPROPERTY(EditAnywhere, Category = "Planet Generation|Colours") FLinearColor rockColor = FLinearColor(0.4, 0.3, 0.2, 1.0);
    UPROPERTY(EditAnywhere, Category = "Planet Generation|Colours") FLinearColor snowColor = FLinearColor(0.95, 0.95, 0.98, 1.0);

    //These are shite and dont work as inteded with updated shaders - future joe do this work

    static FPlanetInfo CreateEarthLike()
    {
        FPlanetInfo planet;
        planet.seaLevel = 0.0f;
        planet.oceanDepth = -100.0f;
        planet.mountainHeight = 200.0f;
        planet.continentHeight = 50.0f;
        planet.valleyDepth = -20.0f;
        planet.grassSlopeThreshold = 0.3f;
        planet.rockSlopeThreshold = 0.6f;
        planet.snowHeightThreshold = 120.0f;
        planet.sandHeightThreshold = 5.0f;
        planet.continentScale = 0.001f;
        planet.mountainScale = 0.005f;
        planet.detailScale = 0.008f;
        planet.ridgeScale = 0.008f;
        return planet;
    }

    static FPlanetInfo CreateVolcanicPlanet()
    {
        FPlanetInfo planet;
        planet.seaLevel = -20.0f;
        planet.oceanDepth = -120.0f;
        planet.mountainHeight = 280.0f;
        planet.continentHeight = 80.0f;
        planet.valleyDepth = -60.0f;
        planet.grassSlopeThreshold = 0.15f;
        planet.rockSlopeThreshold = 0.4f;
        planet.snowHeightThreshold = 200.0f;
        planet.sandHeightThreshold = -10.0f;
        planet.continentScale = 0.0015f;
        planet.mountainScale = 0.008f;
        planet.detailScale = 0.012f;
        planet.ridgeScale = 0.010f;
        return planet;
    }

    static FPlanetInfo CreateJunglePlanet()
    {
        FPlanetInfo planet;
        planet.seaLevel = 15.0f;
        planet.oceanDepth = -60.0f;
        planet.mountainHeight = 120.0f;
        planet.continentHeight = 25.0f;
        planet.valleyDepth = -15.0f;
        planet.grassSlopeThreshold = 0.6f;
        planet.rockSlopeThreshold = 0.85f;
        planet.snowHeightThreshold = 100.0f;
        planet.sandHeightThreshold = 20.0f;
        planet.continentScale = 0.003f;
        planet.mountainScale = 0.004f;
        planet.detailScale = 0.006f;
        planet.ridgeScale = 0.005f;
        return planet;
    }

    static FPlanetInfo CreateIcePlanet()
    {
        FPlanetInfo planet;
        planet.seaLevel = 30.0f;
        planet.oceanDepth = -40.0f;
        planet.mountainHeight = 200.0f;
        planet.continentHeight = 60.0f;
        planet.valleyDepth = -10.0f;
        planet.grassSlopeThreshold = 0.05f;
        planet.rockSlopeThreshold = 0.9f;
        planet.snowHeightThreshold = -50.0f;
        planet.sandHeightThreshold = -100.0f;
        planet.continentScale = 0.001f;
        planet.mountainScale = 0.003f;
        planet.detailScale = 0.005f;
        planet.ridgeScale = 0.004f;
        return planet;
    }

    static FPlanetInfo CreateDesertPlanet()
    {
        FPlanetInfo planet;
        planet.seaLevel = -30.0f;
        planet.oceanDepth = -80.0f;
        planet.mountainHeight = 40.0f;
        planet.continentHeight = 40.0f;
        planet.valleyDepth = -40.0f;
        planet.grassSlopeThreshold = 0.05f;
        planet.rockSlopeThreshold = 0.5f;
        planet.snowHeightThreshold = 180.0f;
        planet.sandHeightThreshold = 100.0f;
        planet.continentScale = 0.0018f;
        planet.mountainScale = 0.007f;
        planet.detailScale = 0.010f;
        planet.ridgeScale = 0.012f;
        return planet;
    }

    static FPlanetInfo CreateCrystalPlanet()
    {
        FPlanetInfo planet;
        planet.seaLevel = 5.0f;
        planet.oceanDepth = -90.0f;
        planet.mountainHeight = 240.0f;
        planet.continentHeight = 70.0f;
        planet.valleyDepth = -25.0f;
        planet.grassSlopeThreshold = 0.2f;
        planet.rockSlopeThreshold = 0.4f;
        planet.snowHeightThreshold = 160.0f;
        planet.sandHeightThreshold = 15.0f;
        planet.continentScale = 0.0012f;
        planet.mountainScale = 0.009f;
        planet.detailScale = 0.015f;
        planet.ridgeScale = 0.011f;
        return planet;
    }

    static FPlanetInfo CreateTundraPlanet()
    {
        FPlanetInfo planet;
        planet.seaLevel = 10.0f;
        planet.oceanDepth = -70.0f;
        planet.mountainHeight = 140.0f;
        planet.continentHeight = 35.0f;
        planet.valleyDepth = -18.0f;
        planet.grassSlopeThreshold = 0.4f;
        planet.rockSlopeThreshold = 0.7f;
        planet.snowHeightThreshold = 60.0f;
        planet.sandHeightThreshold = 12.0f;
        planet.continentScale = 0.002f;
        planet.mountainScale = 0.004f;
        planet.detailScale = 0.007f;
        planet.ridgeScale = 0.006f;
        return planet;
    }

    static FPlanetInfo CreateMarsLikePlanet()
    {
        FPlanetInfo planet;
        planet.seaLevel = -50.0f;
        planet.oceanDepth = -60.0f;
        planet.mountainHeight = 300.0f;
        planet.continentHeight = 20.0f;
        planet.valleyDepth = -80.0f;
        planet.grassSlopeThreshold = 0.02f;
        planet.rockSlopeThreshold = 0.3f;
        planet.snowHeightThreshold = 250.0f;
        planet.sandHeightThreshold = 50.0f;
        planet.continentScale = 0.0008f;
        planet.mountainScale = 0.006f;
        planet.detailScale = 0.009f;
        planet.ridgeScale = 0.007f;
        return planet;
    }

    static FPlanetInfo CreateArchipelagoPlanet()
    {
        FPlanetInfo planet;
        planet.seaLevel = 40.0f;
        planet.oceanDepth = -120.0f;
        planet.mountainHeight = 180.0f;
        planet.continentHeight = 30.0f;
        planet.valleyDepth = -10.0f;
        planet.grassSlopeThreshold = 0.4f;
        planet.rockSlopeThreshold = 0.65f;
        planet.snowHeightThreshold = 130.0f;
        planet.sandHeightThreshold = 45.0f;
        planet.continentScale = 0.004f;
        planet.mountainScale = 0.006f;
        planet.detailScale = 0.008f;
        planet.ridgeScale = 0.007f;
        return planet;
    }

    static FPlanetInfo CreateSwampPlanet()
    {
        FPlanetInfo planet;
        planet.seaLevel = 20.0f;
        planet.oceanDepth = -50.0f;
        planet.mountainHeight = 80.0f;
        planet.continentHeight = 15.0f;
        planet.valleyDepth = -8.0f;
        planet.grassSlopeThreshold = 0.8f;
        planet.rockSlopeThreshold = 0.95f;
        planet.snowHeightThreshold = 70.0f;
        planet.sandHeightThreshold = 25.0f;
        planet.continentScale = 0.005f;
        planet.mountainScale = 0.003f;
        planet.detailScale = 0.004f;
        planet.ridgeScale = 0.003f;
        return planet;
    }

    static FPlanetInfo CreateHighlandsPlanet()
    {
        FPlanetInfo planet;
        planet.seaLevel = -10.0f;
        planet.oceanDepth = -60.0f;
        planet.mountainHeight = 320.0f;
        planet.continentHeight = 150.0f;
        planet.valleyDepth = 20.0f;
        planet.grassSlopeThreshold = 0.25f;
        planet.rockSlopeThreshold = 0.55f;
        planet.snowHeightThreshold = 200.0f;
        planet.sandHeightThreshold = -5.0f;
        planet.continentScale = 0.0008f;
        planet.mountainScale = 0.004f;
        planet.detailScale = 0.007f;
        planet.ridgeScale = 0.009f;
        return planet;
    }

};

USTRUCT()
struct FAtmosphereInfo
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere) float lightStepCount = 4.0f;
    UPROPERTY(EditAnywhere) FLinearColor mieCoeff = FLinearColor(0.002, 0.002, 0.002, 0);
    UPROPERTY(EditAnywhere) float mieStrength = 0.5f;
    UPROPERTY(EditAnywhere) FLinearColor rayleighCoeff = FLinearColor(0.0025, 0.0041, 0.0098, 0);

    UPROPERTY(EditAnywhere) float rayleighStrength = 1.0f;
    UPROPERTY(EditAnywhere) float scatteringStrength = 2.0f;
    UPROPERTY(EditAnywhere) float stepCount = 8.f;
    UPROPERTY(EditAnywhere) float sunIntensity = 2.f;
};

UCLASS()
class SOLARSYSTEMPROJECT_API APlanet : public AOrbitingBody
{
	GENERATED_BODY()

public:
	APlanet();

protected:
	virtual void BeginPlay() override;

	void GeneratePlanet();
	void OnPlanetReady();
    void GenerateOcean();
    FVector4f linearToVector(FLinearColor col);

    UProceduralMeshComponent* oceanMesh;
    UPROPERTY(EditAnywhere) UMaterialInterface* oceanMaterial;

    UPROPERTY(EditAnywhere) bool doGenerateAtmosphere = true;
    UPROPERTY(EditAnywhere) UMaterialInterface* atmosphereMaterial;
    UMaterialInstanceDynamic* dynamicAtmosphereMaterial;
    FWeightedBlendable atmosphereBlend;
    void GenerateAtmosphere();
    void TickAtmosphere(float deltaTime);

    UPROPERTY(EditAnywhere) FAtmosphereInfo atmosphereInfo;
    UPROPERTY(EditAnywhere) UPostProcessComponent* atmospherePostProcessing;

    
	UPROPERTY(EditAnywhere) FPlanetInfo planetInfo;

    UFUNCTION(CallInEditor, Category = "Planet Presets")
    void SetEarthLike()
    {
        planetInfo = FPlanetInfo::CreateEarthLike();
        Modify();
    }

    UFUNCTION(CallInEditor, Category = "Planet Presets")
    void SetVolcanicPlanet()
    {
        planetInfo = FPlanetInfo::CreateVolcanicPlanet();
        Modify();
    }

    UFUNCTION(CallInEditor, Category = "Planet Presets")
    void SetJungleWorld()
    {
        planetInfo = FPlanetInfo::CreateJunglePlanet();
        Modify();
    }

    UFUNCTION(CallInEditor, Category = "Planet Presets")
    void SetIceWorld()
    {
        planetInfo = FPlanetInfo::CreateIcePlanet();
        Modify();
    }

    UFUNCTION(CallInEditor, Category = "Planet Presets")
    void SetCrystalPlanet()
    {
        planetInfo = FPlanetInfo::CreateCrystalPlanet();
        Modify();
    }

    UFUNCTION(CallInEditor, Category = "Planet Presets")
    void SetDesertPlanet()
    {
        planetInfo = FPlanetInfo::CreateDesertPlanet();
        Modify();
    }

    UFUNCTION(CallInEditor, Category = "Planet Presets")
    void SetTundraPlanet()
    {
        planetInfo = FPlanetInfo::CreateTundraPlanet();
        Modify();
    }

    UFUNCTION(CallInEditor, Category = "Planet Presets")
    void SetMarsLikePlanet()
    {
        planetInfo = FPlanetInfo::CreateMarsLikePlanet();
        Modify();
    }

    UFUNCTION(CallInEditor, Category = "Planet Presets")
    void SetArchipelagoPlanet()
    {
        planetInfo = FPlanetInfo::CreateArchipelagoPlanet();
        Modify();
    }

    UFUNCTION(CallInEditor, Category = "Planet Presets")
    void SetSwampPlanet()
    {
        planetInfo = FPlanetInfo::CreateSwampPlanet();
        Modify();
    }

    UFUNCTION(CallInEditor, Category = "Planet Presets")
    void SetHighlandsPlanet()
    {
        planetInfo = FPlanetInfo::CreateHighlandsPlanet();
        Modify();
    }
	
public:
	virtual void Tick(float DeltaTime) override;
};
