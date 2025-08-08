// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SolarSystemProject/CelestialBody.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCelestialBody() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
SOLARSYSTEMPROJECT_API UClass* Z_Construct_UClass_ACelestialBody();
SOLARSYSTEMPROJECT_API UClass* Z_Construct_UClass_ACelestialBody_NoRegister();
UPackage* Z_Construct_UPackage__Script_SolarSystemProject();
// End Cross Module References

// Begin Class ACelestialBody
void ACelestialBody::StaticRegisterNativesACelestialBody()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACelestialBody);
UClass* Z_Construct_UClass_ACelestialBody_NoRegister()
{
	return ACelestialBody::StaticClass();
}
struct Z_Construct_UClass_ACelestialBody_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "CelestialBody.h" },
		{ "ModuleRelativePath", "CelestialBody.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mass_MetaData[] = {
		{ "Category", "CelestialBody" },
		{ "ModuleRelativePath", "CelestialBody.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_mass;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACelestialBody>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACelestialBody_Statics::NewProp_mass = { "mass", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACelestialBody, mass), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mass_MetaData), NewProp_mass_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACelestialBody_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACelestialBody_Statics::NewProp_mass,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACelestialBody_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACelestialBody_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_SolarSystemProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACelestialBody_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACelestialBody_Statics::ClassParams = {
	&ACelestialBody::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ACelestialBody_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ACelestialBody_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACelestialBody_Statics::Class_MetaDataParams), Z_Construct_UClass_ACelestialBody_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACelestialBody()
{
	if (!Z_Registration_Info_UClass_ACelestialBody.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACelestialBody.OuterSingleton, Z_Construct_UClass_ACelestialBody_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACelestialBody.OuterSingleton;
}
template<> SOLARSYSTEMPROJECT_API UClass* StaticClass<ACelestialBody>()
{
	return ACelestialBody::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACelestialBody);
ACelestialBody::~ACelestialBody() {}
// End Class ACelestialBody

// Begin Registration
struct Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_CelestialBody_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACelestialBody, ACelestialBody::StaticClass, TEXT("ACelestialBody"), &Z_Registration_Info_UClass_ACelestialBody, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACelestialBody), 1662350491U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_CelestialBody_h_3694881713(TEXT("/Script/SolarSystemProject"),
	Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_CelestialBody_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_CelestialBody_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
