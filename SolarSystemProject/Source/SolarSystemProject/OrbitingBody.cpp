// Fill out your copyright notice in the Description page of Project Settings.
#include "OrbitingBody.h"

// Sets default values
AOrbitingBody::AOrbitingBody()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("SphereMesh"));
    RootComponent = mesh;
    RootComponent->SetMobility(EComponentMobility::Movable);
    mesh->bUseAsyncCooking = true;
    sphereMaterial = nullptr;
    velocity = FVector::ZeroVector;
}

// Called when the game starts or when spawned
void AOrbitingBody::BeginPlay()
{
    Super::BeginPlay();
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOrbitingBody::StaticClass(), otherBodies);
    if (generateSphere) GenerateSphere();

    if (showOrbitDebug) UpdateOrbitPath();

}

// Called every frame
void AOrbitingBody::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (!IsValid(this) || !RootComponent)
    {
        return;
    }

    //Physics
    FVector totalForce = FVector::ZeroVector;
    for (AActor* otherBody : otherBodies)
    {
        if (otherBody != this)
        {
            if (AOrbitingBody* otherCelestialBody = Cast<AOrbitingBody>(otherBody))
            {
                FVector gravitationalForce = CalculateGravitationalForce(this, otherBody, mass, otherCelestialBody->GetMass());
                totalForce += gravitationalForce;
            }
        }
    }
    FVector acceleration = totalForce / mass;
    velocity += acceleration * DeltaTime;
    FVector currentLocation = GetActorLocation();
    FVector newLocation = currentLocation + (velocity * DeltaTime);
    SetActorLocation(newLocation);

    //Planet spin 
    if (spinSpeed != 0.f)
    {
        FRotator rotation = FRotator(0, spinSpeed * DeltaTime, 0.f);
        AddActorLocalRotation(rotation);
    }

    //Draw orbit debug line
    if (showOrbitDebug && orbitLine.Num() > 1)
    {
        for (int32 i = 0; i < orbitLine.Num() - 1; i++)
        {
            DrawDebugLine(GetWorld(), orbitLine[i], orbitLine[i + 1], orbitLineColor, false, -1.0f, 0, 200.0f);
        }
    }

    //Updates the orbit path every 60 frames
    static int32 frameCounter = 0;
    frameCounter++;
    if (showOrbitDebug && frameCounter % 60 == 0)
    {
        UpdateOrbitPath();
    }
}

//Uses newtonian equation to calculate gravitational force
FVector AOrbitingBody::CalculateGravitationalForce(AActor* body1, AActor* body2, float mass1, float mass2)
{
    FVector direction = body2->GetActorLocation() - body1->GetActorLocation();
    float distance = direction.Size();
    if (distance == 0) return FVector::ZeroVector;
    direction.Normalize();
    float g = 8000.f;
    float force = (g * mass1 * mass2) / (distance * distance);
    return direction * force;
}

void AOrbitingBody::UpdateOrbitPath()
{
    orbitLine.Empty();

    //Start from current position and velocity
    FVector currentPos = GetActorLocation();
    FVector currentVel = velocity;

    orbitLine.Add(currentPos);

    //Simulate future positions
    for (int32 step = 0; step < orbitSteps; step++)
    {
        FVector totalForce = FVector::ZeroVector;

        for (AActor* otherBody : otherBodies)
        {
            if (otherBody != this && IsValid(otherBody))
            {
                if (AOrbitingBody* otherCelestialBody = Cast<AOrbitingBody>(otherBody))
                {
                    FVector direction = otherBody->GetActorLocation() - currentPos;
                    float distance = direction.Size();
                    if (distance > 0)
                    {
                        direction.Normalize();
                        float g = 8000.f;
                        float force = (g * mass * otherCelestialBody->GetMass()) / (distance * distance);
                        totalForce += direction * force;
                    }
                }
            }
        }

        FVector acceleration = totalForce / mass;
        currentVel += acceleration * orbitTimeStep;
        currentPos += currentVel * orbitTimeStep;

        orbitLine.Add(currentPos);
    }
}

void AOrbitingBody::GenerateSphere()
{
    FSphereGenerationShaderDispatchParams Params(1, 1, 1);
    Params.radius = radius;
    Params.latitudeSegments = latSegments;
    Params.longitudeSegments = longSegments;
    FSphereGenerationShaderInterface::Dispatch(Params, [this](const FSphereGeometryData& GeometryData) {
        UE_LOG(LogTemp, Warning, TEXT("Orbiting Generated with: %d vertices and %d triangles"),
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
    if (IsValid(sphereMaterial))
    {
        mesh->SetMaterial(0, sphereMaterial);
    }
    mesh->CreateMeshSection(0, vertices, triangles, normals, UVs, verticeColors, tangents, false);
}