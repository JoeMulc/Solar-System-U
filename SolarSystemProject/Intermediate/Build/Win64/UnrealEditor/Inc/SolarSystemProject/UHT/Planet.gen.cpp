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
SOLARSYSTEMPROJECT_API UClass* Z_Construct_UClass_AOrbitingBody();
SOLARSYSTEMPROJECT_API UClass* Z_Construct_UClass_APlanet();
SOLARSYSTEMPROJECT_API UClass* Z_Construct_UClass_APlanet_NoRegister();
UPackage* Z_Construct_UPackage__Script_SolarSystemProject();
// End Cross Module References

// Begin Class APlanet
void APlanet::StaticRegisterNativesAPlanet()
{
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
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlanet>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
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
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
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
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APlanet, APlanet::StaticClass, TEXT("APlanet"), &Z_Registration_Info_UClass_APlanet, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APlanet), 2348845923U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_Planet_h_3230595259(TEXT("/Script/SolarSystemProject"),
	Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_Planet_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_Planet_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
