// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SolarSystemProject/Planet.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlanet() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
SOLARSYSTEMPROJECT_API UClass* Z_Construct_UClass_AOrbitingBody();
SOLARSYSTEMPROJECT_API UClass* Z_Construct_UClass_APlanet();
SOLARSYSTEMPROJECT_API UClass* Z_Construct_UClass_APlanet_NoRegister();
SOLARSYSTEMPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FPlanetInfo();
UPackage* Z_Construct_UPackage__Script_SolarSystemProject();
// End Cross Module References

// Begin ScriptStruct FPlanetInfo
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PlanetInfo;
class UScriptStruct* FPlanetInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PlanetInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PlanetInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPlanetInfo, (UObject*)Z_Construct_UPackage__Script_SolarSystemProject(), TEXT("PlanetInfo"));
	}
	return Z_Registration_Info_UScriptStruct_PlanetInfo.OuterSingleton;
}
template<> SOLARSYSTEMPROJECT_API UScriptStruct* StaticStruct<FPlanetInfo>()
{
	return FPlanetInfo::StaticStruct();
}
struct Z_Construct_UScriptStruct_FPlanetInfo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_seaLevel_MetaData[] = {
		{ "Category", "Planet Generation" },
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_oceanDepth_MetaData[] = {
		{ "Category", "Planet Generation" },
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mountainHeight_MetaData[] = {
		{ "Category", "Planet Generation" },
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_continentHeight_MetaData[] = {
		{ "Category", "Planet Generation" },
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_valleyDepth_MetaData[] = {
		{ "Category", "Planet Generation" },
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_grassSlopeThreshold_MetaData[] = {
		{ "Category", "Planet Generation|Color Thresholds" },
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_rockSlopeThreshold_MetaData[] = {
		{ "Category", "Planet Generation|Color Thresholds" },
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_snowHeightThreshold_MetaData[] = {
		{ "Category", "Planet Generation|Color Thresholds" },
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_sandHeightThreshold_MetaData[] = {
		{ "Category", "Planet Generation|Color Thresholds" },
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_continentMin_MetaData[] = {
		{ "Category", "Planet Generation|Scales" },
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_continentMax_MetaData[] = {
		{ "Category", "Planet Generation|Scales" },
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_continentScale_MetaData[] = {
		{ "Category", "Planet Generation|Scales" },
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mountainScale_MetaData[] = {
		{ "Category", "Planet Generation|Scales" },
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_detailScale_MetaData[] = {
		{ "Category", "Planet Generation|Scales" },
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ridgeScale_MetaData[] = {
		{ "Category", "Planet Generation|Scales" },
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_oceanColor_MetaData[] = {
		{ "Category", "Planet Generation|Colours" },
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_shallowColor_MetaData[] = {
		{ "Category", "Planet Generation|Colours" },
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_sandColor_MetaData[] = {
		{ "Category", "Planet Generation|Colours" },
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_grassColor_MetaData[] = {
		{ "Category", "Planet Generation|Colours" },
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_rockColor_MetaData[] = {
		{ "Category", "Planet Generation|Colours" },
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_snowColor_MetaData[] = {
		{ "Category", "Planet Generation|Colours" },
		{ "ModuleRelativePath", "Planet.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_seaLevel;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_oceanDepth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_mountainHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_continentHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_valleyDepth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_grassSlopeThreshold;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_rockSlopeThreshold;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_snowHeightThreshold;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_sandHeightThreshold;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_continentMin;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_continentMax;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_continentScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_mountainScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_detailScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ridgeScale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_oceanColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_shallowColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_sandColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_grassColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_rockColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_snowColor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPlanetInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_seaLevel = { "seaLevel", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetInfo, seaLevel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_seaLevel_MetaData), NewProp_seaLevel_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_oceanDepth = { "oceanDepth", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetInfo, oceanDepth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_oceanDepth_MetaData), NewProp_oceanDepth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_mountainHeight = { "mountainHeight", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetInfo, mountainHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mountainHeight_MetaData), NewProp_mountainHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_continentHeight = { "continentHeight", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetInfo, continentHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_continentHeight_MetaData), NewProp_continentHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_valleyDepth = { "valleyDepth", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetInfo, valleyDepth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_valleyDepth_MetaData), NewProp_valleyDepth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_grassSlopeThreshold = { "grassSlopeThreshold", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetInfo, grassSlopeThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_grassSlopeThreshold_MetaData), NewProp_grassSlopeThreshold_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_rockSlopeThreshold = { "rockSlopeThreshold", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetInfo, rockSlopeThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_rockSlopeThreshold_MetaData), NewProp_rockSlopeThreshold_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_snowHeightThreshold = { "snowHeightThreshold", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetInfo, snowHeightThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_snowHeightThreshold_MetaData), NewProp_snowHeightThreshold_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_sandHeightThreshold = { "sandHeightThreshold", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetInfo, sandHeightThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_sandHeightThreshold_MetaData), NewProp_sandHeightThreshold_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_continentMin = { "continentMin", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetInfo, continentMin), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_continentMin_MetaData), NewProp_continentMin_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_continentMax = { "continentMax", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetInfo, continentMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_continentMax_MetaData), NewProp_continentMax_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_continentScale = { "continentScale", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetInfo, continentScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_continentScale_MetaData), NewProp_continentScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_mountainScale = { "mountainScale", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetInfo, mountainScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mountainScale_MetaData), NewProp_mountainScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_detailScale = { "detailScale", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetInfo, detailScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_detailScale_MetaData), NewProp_detailScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_ridgeScale = { "ridgeScale", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetInfo, ridgeScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ridgeScale_MetaData), NewProp_ridgeScale_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_oceanColor = { "oceanColor", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetInfo, oceanColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_oceanColor_MetaData), NewProp_oceanColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_shallowColor = { "shallowColor", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetInfo, shallowColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_shallowColor_MetaData), NewProp_shallowColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_sandColor = { "sandColor", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetInfo, sandColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_sandColor_MetaData), NewProp_sandColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_grassColor = { "grassColor", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetInfo, grassColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_grassColor_MetaData), NewProp_grassColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_rockColor = { "rockColor", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetInfo, rockColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_rockColor_MetaData), NewProp_rockColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_snowColor = { "snowColor", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPlanetInfo, snowColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_snowColor_MetaData), NewProp_snowColor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPlanetInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_seaLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_oceanDepth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_mountainHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_continentHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_valleyDepth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_grassSlopeThreshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_rockSlopeThreshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_snowHeightThreshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_sandHeightThreshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_continentMin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_continentMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_continentScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_mountainScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_detailScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_ridgeScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_oceanColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_shallowColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_sandColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_grassColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_rockColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewProp_snowColor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlanetInfo_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPlanetInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_SolarSystemProject,
	nullptr,
	&NewStructOps,
	"PlanetInfo",
	Z_Construct_UScriptStruct_FPlanetInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlanetInfo_Statics::PropPointers),
	sizeof(FPlanetInfo),
	alignof(FPlanetInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPlanetInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPlanetInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FPlanetInfo()
{
	if (!Z_Registration_Info_UScriptStruct_PlanetInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PlanetInfo.InnerSingleton, Z_Construct_UScriptStruct_FPlanetInfo_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_PlanetInfo.InnerSingleton;
}
// End ScriptStruct FPlanetInfo

// Begin Class APlanet Function SetArchipelagoPlanet
struct Z_Construct_UFunction_APlanet_SetArchipelagoPlanet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Planet Presets" },
		{ "ModuleRelativePath", "Planet.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlanet_SetArchipelagoPlanet_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlanet, nullptr, "SetArchipelagoPlanet", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanet_SetArchipelagoPlanet_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlanet_SetArchipelagoPlanet_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlanet_SetArchipelagoPlanet()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlanet_SetArchipelagoPlanet_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlanet::execSetArchipelagoPlanet)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetArchipelagoPlanet();
	P_NATIVE_END;
}
// End Class APlanet Function SetArchipelagoPlanet

// Begin Class APlanet Function SetCrystalPlanet
struct Z_Construct_UFunction_APlanet_SetCrystalPlanet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Planet Presets" },
		{ "ModuleRelativePath", "Planet.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlanet_SetCrystalPlanet_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlanet, nullptr, "SetCrystalPlanet", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanet_SetCrystalPlanet_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlanet_SetCrystalPlanet_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlanet_SetCrystalPlanet()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlanet_SetCrystalPlanet_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlanet::execSetCrystalPlanet)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCrystalPlanet();
	P_NATIVE_END;
}
// End Class APlanet Function SetCrystalPlanet

// Begin Class APlanet Function SetDesertPlanet
struct Z_Construct_UFunction_APlanet_SetDesertPlanet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Planet Presets" },
		{ "ModuleRelativePath", "Planet.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlanet_SetDesertPlanet_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlanet, nullptr, "SetDesertPlanet", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanet_SetDesertPlanet_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlanet_SetDesertPlanet_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlanet_SetDesertPlanet()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlanet_SetDesertPlanet_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlanet::execSetDesertPlanet)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDesertPlanet();
	P_NATIVE_END;
}
// End Class APlanet Function SetDesertPlanet

// Begin Class APlanet Function SetEarthLike
struct Z_Construct_UFunction_APlanet_SetEarthLike_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Planet Presets" },
		{ "ModuleRelativePath", "Planet.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlanet_SetEarthLike_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlanet, nullptr, "SetEarthLike", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanet_SetEarthLike_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlanet_SetEarthLike_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlanet_SetEarthLike()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlanet_SetEarthLike_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlanet::execSetEarthLike)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetEarthLike();
	P_NATIVE_END;
}
// End Class APlanet Function SetEarthLike

// Begin Class APlanet Function SetHighlandsPlanet
struct Z_Construct_UFunction_APlanet_SetHighlandsPlanet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Planet Presets" },
		{ "ModuleRelativePath", "Planet.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlanet_SetHighlandsPlanet_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlanet, nullptr, "SetHighlandsPlanet", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanet_SetHighlandsPlanet_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlanet_SetHighlandsPlanet_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlanet_SetHighlandsPlanet()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlanet_SetHighlandsPlanet_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlanet::execSetHighlandsPlanet)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetHighlandsPlanet();
	P_NATIVE_END;
}
// End Class APlanet Function SetHighlandsPlanet

// Begin Class APlanet Function SetIceWorld
struct Z_Construct_UFunction_APlanet_SetIceWorld_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Planet Presets" },
		{ "ModuleRelativePath", "Planet.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlanet_SetIceWorld_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlanet, nullptr, "SetIceWorld", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanet_SetIceWorld_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlanet_SetIceWorld_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlanet_SetIceWorld()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlanet_SetIceWorld_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlanet::execSetIceWorld)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetIceWorld();
	P_NATIVE_END;
}
// End Class APlanet Function SetIceWorld

// Begin Class APlanet Function SetJungleWorld
struct Z_Construct_UFunction_APlanet_SetJungleWorld_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Planet Presets" },
		{ "ModuleRelativePath", "Planet.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlanet_SetJungleWorld_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlanet, nullptr, "SetJungleWorld", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanet_SetJungleWorld_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlanet_SetJungleWorld_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlanet_SetJungleWorld()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlanet_SetJungleWorld_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlanet::execSetJungleWorld)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetJungleWorld();
	P_NATIVE_END;
}
// End Class APlanet Function SetJungleWorld

// Begin Class APlanet Function SetMarsLikePlanet
struct Z_Construct_UFunction_APlanet_SetMarsLikePlanet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Planet Presets" },
		{ "ModuleRelativePath", "Planet.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlanet_SetMarsLikePlanet_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlanet, nullptr, "SetMarsLikePlanet", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanet_SetMarsLikePlanet_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlanet_SetMarsLikePlanet_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlanet_SetMarsLikePlanet()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlanet_SetMarsLikePlanet_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlanet::execSetMarsLikePlanet)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMarsLikePlanet();
	P_NATIVE_END;
}
// End Class APlanet Function SetMarsLikePlanet

// Begin Class APlanet Function SetSwampPlanet
struct Z_Construct_UFunction_APlanet_SetSwampPlanet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Planet Presets" },
		{ "ModuleRelativePath", "Planet.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlanet_SetSwampPlanet_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlanet, nullptr, "SetSwampPlanet", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanet_SetSwampPlanet_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlanet_SetSwampPlanet_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlanet_SetSwampPlanet()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlanet_SetSwampPlanet_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlanet::execSetSwampPlanet)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSwampPlanet();
	P_NATIVE_END;
}
// End Class APlanet Function SetSwampPlanet

// Begin Class APlanet Function SetTundraPlanet
struct Z_Construct_UFunction_APlanet_SetTundraPlanet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Planet Presets" },
		{ "ModuleRelativePath", "Planet.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlanet_SetTundraPlanet_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlanet, nullptr, "SetTundraPlanet", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanet_SetTundraPlanet_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlanet_SetTundraPlanet_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlanet_SetTundraPlanet()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlanet_SetTundraPlanet_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlanet::execSetTundraPlanet)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTundraPlanet();
	P_NATIVE_END;
}
// End Class APlanet Function SetTundraPlanet

// Begin Class APlanet Function SetVolcanicPlanet
struct Z_Construct_UFunction_APlanet_SetVolcanicPlanet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Planet Presets" },
		{ "ModuleRelativePath", "Planet.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlanet_SetVolcanicPlanet_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlanet, nullptr, "SetVolcanicPlanet", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlanet_SetVolcanicPlanet_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlanet_SetVolcanicPlanet_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlanet_SetVolcanicPlanet()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlanet_SetVolcanicPlanet_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlanet::execSetVolcanicPlanet)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetVolcanicPlanet();
	P_NATIVE_END;
}
// End Class APlanet Function SetVolcanicPlanet

// Begin Class APlanet
void APlanet::StaticRegisterNativesAPlanet()
{
	UClass* Class = APlanet::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "SetArchipelagoPlanet", &APlanet::execSetArchipelagoPlanet },
		{ "SetCrystalPlanet", &APlanet::execSetCrystalPlanet },
		{ "SetDesertPlanet", &APlanet::execSetDesertPlanet },
		{ "SetEarthLike", &APlanet::execSetEarthLike },
		{ "SetHighlandsPlanet", &APlanet::execSetHighlandsPlanet },
		{ "SetIceWorld", &APlanet::execSetIceWorld },
		{ "SetJungleWorld", &APlanet::execSetJungleWorld },
		{ "SetMarsLikePlanet", &APlanet::execSetMarsLikePlanet },
		{ "SetSwampPlanet", &APlanet::execSetSwampPlanet },
		{ "SetTundraPlanet", &APlanet::execSetTundraPlanet },
		{ "SetVolcanicPlanet", &APlanet::execSetVolcanicPlanet },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APlanet);
UClass* Z_Construct_UClass_APlanet_NoRegister()
{
	return APlanet::StaticClass();
}
struct Z_Construct_UClass_APlanet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Planet.h" },
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_oceanMaterial_MetaData[] = {
		{ "Category", "Planet" },
		{ "ModuleRelativePath", "Planet.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_planetInfo_MetaData[] = {
		{ "Category", "Planet" },
		{ "ModuleRelativePath", "Planet.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_oceanMaterial;
	static const UECodeGen_Private::FStructPropertyParams NewProp_planetInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_APlanet_SetArchipelagoPlanet, "SetArchipelagoPlanet" }, // 3242342203
		{ &Z_Construct_UFunction_APlanet_SetCrystalPlanet, "SetCrystalPlanet" }, // 2802147632
		{ &Z_Construct_UFunction_APlanet_SetDesertPlanet, "SetDesertPlanet" }, // 995562376
		{ &Z_Construct_UFunction_APlanet_SetEarthLike, "SetEarthLike" }, // 2584438513
		{ &Z_Construct_UFunction_APlanet_SetHighlandsPlanet, "SetHighlandsPlanet" }, // 1023691519
		{ &Z_Construct_UFunction_APlanet_SetIceWorld, "SetIceWorld" }, // 630086716
		{ &Z_Construct_UFunction_APlanet_SetJungleWorld, "SetJungleWorld" }, // 1959274879
		{ &Z_Construct_UFunction_APlanet_SetMarsLikePlanet, "SetMarsLikePlanet" }, // 2533613683
		{ &Z_Construct_UFunction_APlanet_SetSwampPlanet, "SetSwampPlanet" }, // 2702918706
		{ &Z_Construct_UFunction_APlanet_SetTundraPlanet, "SetTundraPlanet" }, // 2209067337
		{ &Z_Construct_UFunction_APlanet_SetVolcanicPlanet, "SetVolcanicPlanet" }, // 3285396320
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlanet>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlanet_Statics::NewProp_oceanMaterial = { "oceanMaterial", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlanet, oceanMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_oceanMaterial_MetaData), NewProp_oceanMaterial_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_APlanet_Statics::NewProp_planetInfo = { "planetInfo", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlanet, planetInfo), Z_Construct_UScriptStruct_FPlanetInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_planetInfo_MetaData), NewProp_planetInfo_MetaData) }; // 3633191090
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APlanet_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlanet_Statics::NewProp_oceanMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlanet_Statics::NewProp_planetInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APlanet_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_APlanet_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AOrbitingBody,
	(UObject* (*)())Z_Construct_UPackage__Script_SolarSystemProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APlanet_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APlanet_Statics::ClassParams = {
	&APlanet::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_APlanet_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_APlanet_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APlanet_Statics::Class_MetaDataParams), Z_Construct_UClass_APlanet_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APlanet()
{
	if (!Z_Registration_Info_UClass_APlanet.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APlanet.OuterSingleton, Z_Construct_UClass_APlanet_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APlanet.OuterSingleton;
}
template<> SOLARSYSTEMPROJECT_API UClass* StaticClass<APlanet>()
{
	return APlanet::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(APlanet);
APlanet::~APlanet() {}
// End Class APlanet

// Begin Registration
struct Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_Planet_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FPlanetInfo::StaticStruct, Z_Construct_UScriptStruct_FPlanetInfo_Statics::NewStructOps, TEXT("PlanetInfo"), &Z_Registration_Info_UScriptStruct_PlanetInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPlanetInfo), 3633191090U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APlanet, APlanet::StaticClass, TEXT("APlanet"), &Z_Registration_Info_UClass_APlanet, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APlanet), 1859756497U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_Planet_h_2141794284(TEXT("/Script/SolarSystemProject"),
	Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_Planet_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_Planet_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_Planet_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_Planet_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
