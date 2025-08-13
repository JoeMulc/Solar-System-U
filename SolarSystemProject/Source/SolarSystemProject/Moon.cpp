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
    craterParams.inputVertices.Add(FVector(5, 5, 5));
    craterParams.outputVertices.SetNum(1);

    FCraterShaderInterface::Dispatch(craterParams, [this](TArray<FVector> craterData) {

        UE_LOG(LogTemp, Warning, TEXT("Crater Generated with: %f"),
            craterData[0].X);

        }
    );

   
}