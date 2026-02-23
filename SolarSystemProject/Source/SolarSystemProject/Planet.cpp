// Fill out your copyright notice in the Description page of Project Settings.
// 
//Struggling to get the generation I want adn burned out with this thing. In the shader ive assumed planets will always be about 1500 unites wide - scales are whacko bcoz of this - needs adjusted to work with any raidus :D

#include "Planet.h"

APlanet::APlanet()
{
    oceanMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("oceanMesh"));
    oceanMesh->SetupAttachment(RootComponent);
    atmospherePostProcessing = CreateDefaultSubobject<UPostProcessComponent>(TEXT("AtmospherePostProcess"));
    atmospherePostProcessing->SetupAttachment(RootComponent);

    atmospherePostProcessing->bUnbound = true;
    atmospherePostProcessing->Priority = 1.f;
    atmospherePostProcessing->BlendWeight = 1.f;
   
}

void APlanet::BeginPlay()
{
	Super::BeginPlay();
   
    GeneratePlanet();

    if (doGenerateAtmosphere && atmosphereMaterial)
    {
        dynamicAtmosphereMaterial = UMaterialInstanceDynamic::Create(atmosphereMaterial, this, FName(GetName()));
        atmosphereBlend.Object = dynamicAtmosphereMaterial;
        atmosphereBlend.Weight = 1.f;
        GenerateAtmosphere();
    }
}

void APlanet::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

    if (doGenerateAtmosphere && atmosphereMaterial) TickAtmosphere(deltaTime);
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
    FPlanetGenerationShaderDispatchParams planetParams(vertices.Num(), 1, 1);
    planetParams.inputVertices = vertices;
    planetParams.inputNormals = normals;
    planetParams.outputVertices.SetNum(vertices.Num());
    planetParams.outputNormals.SetNum(normals.Num());
    planetParams.outputColors.SetNum(vertices.Num());
    planetParams.seaLevel = planetInfo.seaLevel;
    planetParams.oceanDepth = planetInfo.oceanDepth;
    planetParams.mountainHeight = planetInfo.mountainHeight;
    planetParams.continentHeight = planetInfo.continentHeight;
    planetParams.valleyDepth = planetInfo.valleyDepth;
    planetParams.grassSlopeThreshold = planetInfo.grassSlopeThreshold;
    planetParams.rockSlopeThreshold = planetInfo.rockSlopeThreshold;
    planetParams.snowHeightThreshold = planetInfo.snowHeightThreshold;
    planetParams.sandHeightThreshold = planetInfo.sandHeightThreshold;
    planetParams.continentScale = planetInfo.continentScale;
    planetParams.mountainScale = planetInfo.mountainScale;
    planetParams.detailScale = planetInfo.detailScale;
    planetParams.ridgeScale = planetInfo.ridgeScale;
    planetParams.grassColor = linearToVector(planetInfo.grassColor);
    planetParams.oceanColor = linearToVector(planetInfo.oceanColor);
    planetParams.rockColor = linearToVector(planetInfo.rockColor);
    planetParams.sandColor = linearToVector(planetInfo.sandColor);
    planetParams.shallowColor = linearToVector(planetInfo.shallowColor);
    planetParams.snowColor =  linearToVector(planetInfo.snowColor);
    planetParams.continentMin = planetInfo.continentMin;
    planetParams.continentMax = planetInfo.continentMax;

    FPlanetGenerationShaderInterface::Dispatch(planetParams,
        [this](TArray<FVector> finalVertices, TArray<FVector> finalNormals, TArray<FLinearColor> finalColors) {

            vertices = finalVertices;
            normals = finalNormals;

            verticeColors.Empty();
            verticeColors.Reserve(finalColors.Num());
            for (const FLinearColor& linearColor : finalColors)
            {
                verticeColors.Add(linearColor.ToFColor(true)); 
            }

            if (IsValid(sphereMaterial))
            {
                mesh->SetMaterial(0, sphereMaterial);
            }

            mesh->CreateMeshSection(0, vertices, triangles, normals, UVs, verticeColors, TArray<FProcMeshTangent>(), false);
                 
            GenerateOcean();
        });
}

void APlanet::GenerateOcean()
{
    FSphereGenerationShaderDispatchParams waterparams(1, 1, 1);
    waterparams.latitudeSegments = 64;
    waterparams.longitudeSegments = 128;
    waterparams.radius = radius + planetInfo.seaLevel;

    FSphereGenerationShaderInterface::Dispatch(waterparams, [this](const FSphereGeometryData& GeometryData) {
        UE_LOG(LogTemp, Warning, TEXT("Ocean Generated with: %d vertices and %d triangles"),
            GeometryData.Vertices.Num(), GeometryData.Triangles.Num());

        if (IsValid(oceanMaterial))
        {
            oceanMesh->SetMaterial(1, oceanMaterial);
        }

        oceanMesh->CreateMeshSection(1, GeometryData.Vertices, GeometryData.Triangles, GeometryData.Normals, GeometryData.UVs, TArray<FColor>(), TArray<FProcMeshTangent>(), false);
        oceanMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);
        });
}

FVector4f APlanet::linearToVector(FLinearColor col)
{
    return FVector4f(col.R, col.G, col.B, col.A);
}

void APlanet::GenerateAtmosphere()
{
  
    atmospherePostProcessing->Settings.WeightedBlendables.Array.Add(atmosphereBlend);
    
    dynamicAtmosphereMaterial->SetScalarParameterValue("AtmosphereRadius", radius + 350);
    dynamicAtmosphereMaterial->SetScalarParameterValue("AtmosphereHeight", 350);
    dynamicAtmosphereMaterial->SetScalarParameterValue("Planet Radius", radius);
    
    dynamicAtmosphereMaterial->SetScalarParameterValue("lightStepCount", atmosphereInfo.lightStepCount);
    dynamicAtmosphereMaterial->SetVectorParameterValue("MieCoeff", atmosphereInfo.mieCoeff);
    dynamicAtmosphereMaterial->SetScalarParameterValue("MieStrength", atmosphereInfo.mieStrength);
    dynamicAtmosphereMaterial->SetVectorParameterValue("RayleighCoeff", atmosphereInfo.rayleighCoeff);
    dynamicAtmosphereMaterial->SetScalarParameterValue("RayleighStrength", atmosphereInfo.rayleighStrength);
    dynamicAtmosphereMaterial->SetScalarParameterValue("ScatteringStrength", atmosphereInfo.scatteringStrength);
    dynamicAtmosphereMaterial->SetScalarParameterValue("StepCount", atmosphereInfo.stepCount);
    dynamicAtmosphereMaterial->SetScalarParameterValue("SunIntensity", atmosphereInfo.sunIntensity);
      
}

void APlanet::TickAtmosphere(float deltaTime)
{

    dynamicAtmosphereMaterial->SetVectorParameterValue("PlanetCenter", FLinearColor(this->GetActorLocation()));

    FVector sunDir = FVector::ZeroVector - this->GetActorLocation();
    sunDir.Normalize();
    dynamicAtmosphereMaterial->SetVectorParameterValue("SunDirection", FLinearColor(sunDir));

}