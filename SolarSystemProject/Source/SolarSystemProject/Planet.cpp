// Fill out your copyright notice in the Description page of Project Settings.


#include "Planet.h"

APlanet::APlanet()
{

}

void APlanet::BeginPlay()
{
	Super::BeginPlay();
    GeneratePlanet();
}

void APlanet::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
}

void APlanet::GeneratePlanet()
{
	FSphereGenerationShaderDispatchParams sphereParams(1,1,1);
	sphereParams.latitudeSegments = latSegments;
	sphereParams.longitudeSegments = longSegments;
    sphereParams.radius = radius;

    FSphereGenerationShaderInterface::Dispatch(sphereParams, [this](const FSphereGeometryData& GeometryData) {
        UE_LOG(LogTemp, Warning, TEXT("Sphere Generated with: %d vertices and %d triangles"),
            GeometryData.Vertices.Num(), GeometryData.Triangles.Num());

        vertices = GeometryData.Vertices;
        triangles = GeometryData.Triangles;
        normals = GeometryData.Normals;
        UVs = GeometryData.UVs;
        
        this->OnPlanetReady();
        });
}

void APlanet::OnPlanetReady()
{
    FPlanetGenerationShaderDispatchParams planetParams(1, 1, 1);
    planetParams.inputVertices = vertices;
    planetParams.outputVertices.SetNum(vertices.Num());
    planetParams.inputNormals = normals;
    planetParams.outputNormals.SetNum(normals.Num());

    FPlanetGenerationShaderInterface::Dispatch(planetParams, [this](TArray<FVector> finalVertices, TArray<FVector> finalNormals) {
        //vertices = finalVertices;
        //normals = finalNormals;

        if (IsValid(sphereMaterial))
        {
            mesh->SetMaterial(0, sphereMaterial);
        }
        mesh->CreateMeshSection(0, vertices, triangles, normals, UVs, verticeColors, TArray<FProcMeshTangent>(), false);

        });
}