// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitingBody.h"

// Sets default values
AOrbitingBody::AOrbitingBody()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("SphereMesh"));
    RootComponent = mesh;
    mesh->bUseAsyncCooking;
}

// Called when the game starts or when spawned
void AOrbitingBody::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AOrbitingBody::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void AOrbitingBody::GenerateSphere()
{
    FSphereGenerationShaderDispatchParams Params(1, 1, 1);
    Params.radius = radius;
    Params.latitudeSegments = latSegments;
    Params.longitudeSegments = longSegments;

    FSphereGenerationShaderInterface::Dispatch(Params, [this](const FSphereGeometryData& GeometryData) {
        UE_LOG(LogTemp, Warning, TEXT("Sphere Generated with: %d vertices and %d triangles"),
            GeometryData.Vertices.Num(), GeometryData.Triangles.Num());
       
                this->OnSphereReady(GeometryData);
        });
}

void AOrbitingBody::OnSphereReady(const FSphereGeometryData& GeometryData)
{
    vertices = GeometryData.Vertices;
    triangles = GeometryData.Triangles;
    normals = GeometryData.Normals;
    UVs = GeometryData.UVs;
    UKismetProceduralMeshLibrary::CalculateTangentsForMesh(vertices, triangles, UVs, normals, tangents);
    mesh->CreateMeshSection(0, vertices, triangles, normals, UVs, verticeColors, tangents, true);
}