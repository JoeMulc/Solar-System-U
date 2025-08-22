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
	AMoon();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Craters") int numCraters = 60;
	
	UPROPERTY(EditAnywhere, Category = "Noise") int numOctaves = 4;
	UPROPERTY(EditAnywhere, Category = "Noise") float noiseStrength = 15;
	UPROPERTY(EditAnywhere, Category = "Noise") float scale = 20.0;
	UPROPERTY(EditAnywhere, Category = "Noise") float persistence = 0.5;
	UPROPERTY(EditAnywhere, Category = "Noise") float lacunarity = 0.8;
	UPROPERTY(EditAnywhere, Category = "Noise") float baseFrequency = 0.2;
	UPROPERTY(EditAnywhere, Category = "Noise|Ridges") float ridgeStrength = 60.0;
	UPROPERTY(EditAnywhere, Category = "Noise|Fine Detail") float detailNoiseStrength = 10.0;
	UPROPERTY(EditAnywhere, Category = "Noise|Fine Detail") float detailScale = 5.0;
	UPROPERTY(EditAnywhere, Category = "Noise|Fine Detail") float fineDetailStrength = 6;
	UPROPERTY(EditAnywhere, Category = "Noise|Fine Detail") float fineDetailScale = 12;
	UPROPERTY(EditAnywhere, Category = "Noise|Fine Detail") float ultraFineStrength = 3;
	UPROPERTY(EditAnywhere, Category = "Noise|Fine Detail") float ultraFineScale = 24;

	void GenerateMoon();
	void OnMoonReady(const FSphereGeometryData& GeometryData);
	//CPU SOOOOOOOOOOOO SLOW NEVER USE 
	void ApplyGPUNoise();
	void ApplyCPUNoise();



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
