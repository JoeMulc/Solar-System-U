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
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMoon>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
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
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
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
		{ Z_Construct_UClass_AMoon, AMoon::StaticClass, TEXT("AMoon"), &Z_Registration_Info_UClass_AMoon, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMoon), 2354810661U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_Moon_h_3767835319(TEXT("/Script/SolarSystemProject"),
	Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_Moon_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SolarSystemProject_Source_SolarSystemProject_Moon_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
