// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SolarSystemProject/Moon.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMoon() {}

// Begin Cross Module References
SOLARSYSTEMPROJECT_API UClass* Z_Construct_UClass_AMoon();
SOLARSYSTEMPROJECT_API UClass* Z_Construct_UClass_AMoon_NoRegister();
SOLARSYSTEMPROJECT_API UClass* Z_Construct_UClass_AOrbitingBody();
UPackage* Z_Construct_UPackage__Script_SolarSystemProject();
// End Cross Module References

// Begin Class AMoon
void AMoon::StaticRegisterNativesAMoon()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMoon);
UClass* Z_Construct_UClass_AMoon_NoRegister()
{
	return AMoon::StaticClass();
}
struct Z_Construct_UClass_AMoon_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Moon.h" },
		{ "ModuleRelativePath", "Moon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_numCraters_MetaData[] = {
		{ "Category", "Craters" },
		{ "ModuleRelativePath", "Moon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_numOctaves_MetaData[] = {
		{ "Category", "Noise" },
		{ "ModuleRelativePath", "Moon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_noiseStrength_MetaData[] = {
		{ "Category", "Noise" },
		{ "ModuleRelativePath", "Moon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_scale_MetaData[] = {
		{ "Category", "Noise" },
		{ "ModuleRelativePath", "Moon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_persistence_MetaData[] = {
		{ "Category", "Noise" },
		{ "ModuleRelativePath", "Moon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_lacunarity_MetaData[] = {
		{ "Category", "Noise" },
		{ "ModuleRelativePath", "Moon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_baseFrequency_MetaData[] = {
		{ "Category", "Noise" },
		{ "ModuleRelativePath", "Moon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ridgeStrength_MetaData[] = {
		{ "Category", "Noise|Ridges" },
		{ "ModuleRelativePath", "Moon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_detailNoiseStrength_MetaData[] = {
		{ "Category", "Noise|Fine Detail" },
		{ "ModuleRelativePath", "Moon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_detailScale_MetaData[] = {
		{ "Category", "Noise|Fine Detail" },
		{ "ModuleRelativePath", "Moon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_fineDetailStrength_MetaData[] = {
		{ "Category", "Noise|Fine Detail" },
		{ "ModuleRelativePath", "Moon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_fineDetailScale_MetaData[] = {
		{ "Category", "Noise|Fine Detail" },
		{ "ModuleRelativePath", "Moon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ultraFineStrength_MetaData[] = {
		{ "Category", "Noise|Fine Detail" },
		{ "ModuleRelativePath", "Moon.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ultraFineScale_MetaData[] = {
		{ "Category", "Noise|Fine Detail" },
		{ "ModuleRelativePath", "Moon.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_numCraters;
	static const UECodeGen_Private::FIntPropertyParams NewProp_numOctaves;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_noiseStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_scale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_persistence;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_lacunarity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_baseFrequency;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ridgeStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_detailNoiseStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_detailScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_fineDetailStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_fineDetailScale;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ultraFineStrength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ultraFineScale;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMoon>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMoon_Statics::NewProp_numCraters = { "numCraters", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMoon, numCraters), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_numCraters_MetaData), NewProp_numCraters_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMoon_Statics::NewProp_numOctaves = { "numOctaves", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMoon, numOctaves), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_numOctaves_MetaData), NewProp_numOctaves_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMoon_Statics::NewProp_noiseStrength = { "noiseStrength", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMoon, noiseStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_noiseStrength_MetaData), NewProp_noiseStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMoon_Statics::NewProp_scale = { "scale", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMoon, scale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_scale_MetaData), NewProp_scale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMoon_Statics::NewProp_persistence = { "persistence", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMoon, persistence), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_persistence_MetaData), NewProp_persistence_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMoon_Statics::NewProp_lacunarity = { "lacunarity", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMoon, lacunarity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_lacunarity_MetaData), NewProp_lacunarity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMoon_Statics::NewProp_baseFrequency = { "baseFrequency", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMoon, baseFrequency), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_baseFrequency_MetaData), NewProp_baseFrequency_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMoon_Statics::NewProp_ridgeStrength = { "ridgeStrength", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMoon, ridgeStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ridgeStrength_MetaData), NewProp_ridgeStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMoon_Statics::NewProp_detailNoiseStrength = { "detailNoiseStrength", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMoon, detailNoiseStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_detailNoiseStrength_MetaData), NewProp_detailNoiseStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMoon_Statics::NewProp_detailScale = { "detailScale", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMoon, detailScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_detailScale_MetaData), NewProp_detailScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMoon_Statics::NewProp_fineDetailStrength = { "fineDetailStrength", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMoon, fineDetailStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_fineDetailStrength_MetaData), NewProp_fineDetailStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMoon_Statics::NewProp_fineDetailScale = { "fineDetailScale", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMoon, fineDetailScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_fineDetailScale_MetaData), NewProp_fineDetailScale_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMoon_Statics::NewProp_ultraFineStrength = { "ultraFineStrength", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMoon, ultraFineStrength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ultraFineStrength_MetaData), NewProp_ultraFineStrength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMoon_Statics::NewProp_ultraFineScale = { "ultraFineScale", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMoon, ultraFineScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ultraFineScale_MetaData), NewProp_ultraFineScale_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMoon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMoon_Statics::NewProp_numCraters,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMoon_Statics::NewProp_numOctaves,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMoon_Statics::NewProp_noiseStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMoon_Statics::NewProp_scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMoon_Statics::NewProp_persistence,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMoon_Statics::NewProp_lacunarity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMoon_Statics::NewProp_baseFrequency,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMoon_Statics::NewProp_ridgeStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMoon_Statics::NewProp_detailNoiseStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMoon_Statics::NewProp_detailScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMoon_Statics::NewProp_fineDetailStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMoon_Statics::NewProp_fineDetailScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMoon_Statics::NewProp_ultraFineStrength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMoon_Statics::NewProp_ultraFineScale,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMoon_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMoon_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AOrbitingBody,
	(UObject* (*)())Z_Construct_UPackage__Script_SolarSystemProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMoon_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMoon_Statics::ClassParams = {
	&AMoon::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AMoon_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AMoon_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMoon_Statics::Class_MetaDataParams), Z_Construct_UClass_AMoon_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMoon()
{
	if (!Z_Registration_Info_UClass_AMoon.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMoon.OuterSingleton, Z_Construct_UClass_AMoon_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMoon.OuterSingleton;
}
template<> SOLARSYSTEMPROJECT_API UClass* StaticClass<AMoon>()
{
	return AMoon::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMoon);
AMoon::~AMoon() {}
// End Class AMoon

// Begin Registration
struct Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_Moon_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMoon, AMoon::StaticClass, TEXT("AMoon"), &Z_Registration_Info_UClass_AMoon, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMoon), 2619361468U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_Moon_h_1302199713(TEXT("/Script/SolarSystemProject"),
	Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_Moon_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_Moon_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
