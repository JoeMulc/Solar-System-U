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

    FCraterShaderDispatchParams craterParams(1, 1, 1);      //change x to num vertices maybe!
    craterParams.inputVertices = vertices;
    craterParams.outputVertices.SetNum(vertices.Num());
    craterParams.numCraters = 60;
    
    FCraterShaderInterface::Dispatch(craterParams, [this](TArray<FVector> craterData) {

        vertices = craterData;
        ApplyNoise();

        });
}

void AMoon::ApplyNoise()
{
    //FNoiseShaderDispatchParams Params(1, 1, 1);
    //Params.inputVertices = vertices;
    //Params.outputVertices.SetNum(vertices.Num());
    //
    //FNoiseShaderInterface::Dispatch(Params, [this](TArray<FVector> verts) {
    //
    //    vertices = verts;
    //
    //    if (IsValid(sphereMaterial))
    //
    //    {
    //        mesh->SetMaterial(0, sphereMaterial);
    //    }
    //    mesh->CreateMeshSection(0, vertices, triangles, normals, UVs, verticeColors, TArray<FProcMeshTangent>(), false);
    //    });
    float numOctaves = 4.f;
    float noisestrength = 2;
    float scale = 20.f;

    for (FVector& vertex : vertices)
    {
        FVector normalizedPos = vertex.GetSafeNormal();
        float totalNoise = 0.f;
        float amplitude = 1.0f;
        float frequency = 0.8f;
        float persistence = 0.5f;
        float lacunarity = 2;

        for (int octave = 0; octave < numOctaves; ++octave)
        {
            float noiseValue = FMath::PerlinNoise3D(normalizedPos * frequency);
            totalNoise += noiseValue * amplitude;

            amplitude *= persistence;
            frequency *= lacunarity;
        }

        vertex += normalizedPos * totalNoise * noisestrength * scale;
    }
    if (IsValid(sphereMaterial))
    {
       mesh->SetMaterial(0, sphereMaterial);
    }
    mesh->CreateMeshSection(0, vertices, triangles, normals, UVs, verticeColors, TArray<FProcMeshTangent>(), false);
}
 