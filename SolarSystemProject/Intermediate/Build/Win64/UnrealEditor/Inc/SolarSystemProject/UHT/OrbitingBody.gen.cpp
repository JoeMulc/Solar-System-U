// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SolarSystemProject/OrbitingBody.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOrbitingBody() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
SOLARSYSTEMPROJECT_API UClass* Z_Construct_UClass_ACelestialBody();
SOLARSYSTEMPROJECT_API UClass* Z_Construct_UClass_AOrbitingBody();
SOLARSYSTEMPROJECT_API UClass* Z_Construct_UClass_AOrbitingBody_NoRegister();
UPackage* Z_Construct_UPackage__Script_SolarSystemProject();
// End Cross Module References

// Begin Class AOrbitingBody
void AOrbitingBody::StaticRegisterNativesAOrbitingBody()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AOrbitingBody);
UClass* Z_Construct_UClass_AOrbitingBody_NoRegister()
{
	return AOrbitingBody::StaticClass();
}
struct Z_Construct_UClass_AOrbitingBody_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "OrbitingBody.h" },
		{ "ModuleRelativePath", "OrbitingBody.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_sphereMaterial_MetaData[] = {
		{ "Category", "OrbitingBody" },
		{ "ModuleRelativePath", "OrbitingBody.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_latSegments_MetaData[] = {
		{ "Category", "OrbitingBody" },
		{ "ModuleRelativePath", "OrbitingBody.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_longSegments_MetaData[] = {
		{ "Category", "OrbitingBody" },
		{ "ModuleRelativePath", "OrbitingBody.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_radius_MetaData[] = {
		{ "Category", "OrbitingBody" },
		{ "ModuleRelativePath", "OrbitingBody.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_spinSpeed_MetaData[] = {
		{ "Category", "OrbitingBody" },
		{ "ModuleRelativePath", "OrbitingBody.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_sphereMaterial;
	static const UECodeGen_Private::FIntPropertyParams NewProp_latSegments;
	static const UECodeGen_Private::FIntPropertyParams NewProp_longSegments;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_radius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_spinSpeed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOrbitingBody>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOrbitingBody_Statics::NewProp_sphereMaterial = { "sphereMaterial", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOrbitingBody, sphereMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_sphereMaterial_MetaData), NewProp_sphereMaterial_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AOrbitingBody_Statics::NewProp_latSegments = { "latSegments", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOrbitingBody, latSegments), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_latSegments_MetaData), NewProp_latSegments_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AOrbitingBody_Statics::NewProp_longSegments = { "longSegments", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOrbitingBody, longSegments), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_longSegments_MetaData), NewProp_longSegments_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AOrbitingBody_Statics::NewProp_radius = { "radius", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOrbitingBody, radius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_radius_MetaData), NewProp_radius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AOrbitingBody_Statics::NewProp_spinSpeed = { "spinSpeed", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOrbitingBody, spinSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_spinSpeed_MetaData), NewProp_spinSpeed_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOrbitingBody_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOrbitingBody_Statics::NewProp_sphereMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOrbitingBody_Statics::NewProp_latSegments,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOrbitingBody_Statics::NewProp_longSegments,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOrbitingBody_Statics::NewProp_radius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOrbitingBody_Statics::NewProp_spinSpeed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOrbitingBody_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AOrbitingBody_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACelestialBody,
	(UObject* (*)())Z_Construct_UPackage__Script_SolarSystemProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOrbitingBody_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AOrbitingBody_Statics::ClassParams = {
	&AOrbitingBody::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AOrbitingBody_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AOrbitingBody_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOrbitingBody_Statics::Class_MetaDataParams), Z_Construct_UClass_AOrbitingBody_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AOrbitingBody()
{
	if (!Z_Registration_Info_UClass_AOrbitingBody.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOrbitingBody.OuterSingleton, Z_Construct_UClass_AOrbitingBody_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AOrbitingBody.OuterSingleton;
}
template<> SOLARSYSTEMPROJECT_API UClass* StaticClass<AOrbitingBody>()
{
	return AOrbitingBody::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AOrbitingBody);
AOrbitingBody::~AOrbitingBody() {}
// End Class AOrbitingBody

// Begin Registration
struct Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_OrbitingBody_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AOrbitingBody, AOrbitingBody::StaticClass, TEXT("AOrbitingBody"), &Z_Registration_Info_UClass_AOrbitingBody, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOrbitingBody), 804809606U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_OrbitingBody_h_467959755(TEXT("/Script/SolarSystemProject"),
	Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_OrbitingBody_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_OrbitingBody_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
