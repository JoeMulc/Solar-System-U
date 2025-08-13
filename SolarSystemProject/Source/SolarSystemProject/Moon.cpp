// Fill out your copyright notice in the Description page of Project Settings.


#include "Moon.h"

AMoon::AMoon()
{

}

void AMoon::BeginPlay()
{
	Super::BeginPlay();
    GenerateMoon();
}

void AMoon::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
}

void AMoon::GenerateMoon()
{
    FSphereGenerationShaderDispatchParams Params(1, 1, 1);
    Params.radius = radius;
    Params.latitudeSegments = latSegments;
    Params.longitudeSegments = longSegments;

    FSphereGenerationShaderInterface::Dispatch(Params, [this](const FSphereGeometryData& GeometryData) {
        UE_LOG(LogTemp, Warning, TEXT("Sphere Generated with: %d vertices and %d triangles"),
            GeometryData.Vertices.Num(), GeometryData.Triangles.Num());

        this->OnMoonReady(GeometryData);
        });

}

void AMoon::OnMoonReady(const FSphereGeometryData& GeometryData)
{
    vertices = GeometryData.Vertices;
    triangles = GeometryData.Triangles;
    normals = GeometryData.Normals;
    UVs = GeometryData.UVs;

    FCraterShaderDispatchParams craterParams(1, 1, 1);
    craterParams.inputVertices = vertices;
    craterParams.outputVertices.SetNum(vertices.Num());
    
    FCraterShaderInterface::Dispatch(craterParams, [this](TArray<FVector> craterData) {
    
        UE_LOG(LogTemp, Warning, TEXT("Input vertices: %d, Output vertices: %d"),
            vertices.Num(), craterData.Num());
    
        if (craterData.Num() > 0) {
            UE_LOG(LogTemp, Warning, TEXT("First input vertex: %s"),
                *vertices[0].ToString());
            UE_LOG(LogTemp, Warning, TEXT("First output vertex: %s"),
                *craterData[0].ToString());
        }
        vertices = craterData;
        normals.Empty();
        UKismetProceduralMeshLibrary::CalculateTangentsForMesh(vertices, triangles, UVs, normals, tangents);
        mesh->CreateMeshSection(0, vertices, triangles, normals, UVs, verticeColors, tangents, false);
    
        });
    
}