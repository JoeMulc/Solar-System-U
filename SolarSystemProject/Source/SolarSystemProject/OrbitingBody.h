// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CelestialBody.h"
#include "SphereGenerationShader\SphereGenerationShader.h"
#include "ProceduralMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "KismetProceduralMeshLibrary.h"
#include "OrbitingBody.generated.h"

/**
 * 
 */
UCLASS()
class SOLARSYSTEMPROJECT_API AOrbitingBody : public ACelestialBody
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AOrbitingBody();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void GenerateSphere();
	void OnSphereReady(const FSphereGeometryData& GeometryData);

	UProceduralMeshComponent* mesh;

	UPROPERTY(EditAnywhere) UMaterialInterface* sphereMaterial;

	UPROPERTY(EditAnywhere) int32 latSegments = 32;
	UPROPERTY(EditAnywhere) int32 longSegments = 64;
	UPROPERTY(EditAnywhere) float radius = 400.f;

	TArray<FVector> vertices;
	TArray<int32> triangles;
	TArray<FVector> normals;
	TArray<FVector2D> UVs;
	TArray<FProcMeshTangent> tangents;
	TArray<FColor> verticeColors;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
