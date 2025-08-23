// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OrbitingBody.h"
#include "PlanetGenerationShader/PlanetGenerationShader.h"
#include "Planet.generated.h"

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
	
public:
	virtual void Tick(float DeltaTime) override;
};
