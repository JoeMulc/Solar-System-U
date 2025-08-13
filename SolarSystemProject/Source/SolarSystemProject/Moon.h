// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OrbitingBody.h"
#include "CraterShader/CraterShader.h"
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


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
