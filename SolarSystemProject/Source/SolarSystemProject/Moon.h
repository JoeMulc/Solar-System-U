// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OrbitingBody.h"
#include "CraterShader/CraterShader.h"
#include "NoiseShader/NoiseShader.h"
#include "Moon.generated.h"

UCLASS()
class SOLARSYSTEMPROJECT_API AMoon : public AOrbitingBody
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMoon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void GenerateMoon(); 
	void OnMoonReady(const FSphereGeometryData& GeometryData);
	
	UPROPERTY(EditAnywhere) int numOctaves = 4;
	UPROPERTY(EditAnywhere) float noiseStrength = 1.0;
	UPROPERTY(EditAnywhere) float scale = 20.0;
	UPROPERTY(EditAnywhere) float persistence = 0.5;
	UPROPERTY(EditAnywhere) float lacunarity = 2.0;
	UPROPERTY(EditAnywhere) float baseFrequency = 0.8;

	void ApplyGPUNoise();
	void ApplyCPUNoise();


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
