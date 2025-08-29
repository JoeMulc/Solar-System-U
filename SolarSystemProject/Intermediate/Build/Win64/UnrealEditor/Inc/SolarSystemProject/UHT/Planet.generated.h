// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Planet.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SOLARSYSTEMPROJECT_Planet_generated_h
#error "Planet.generated.h already included, missing '#pragma once' in Planet.h"
#endif
#define SOLARSYSTEMPROJECT_Planet_generated_h

#define FID_SolarSystemProject_Source_SolarSystemProject_Planet_h_13_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPlanetInfo_Statics; \
	SOLARSYSTEMPROJECT_API static class UScriptStruct* StaticStruct();


template<> SOLARSYSTEMPROJECT_API UScriptStruct* StaticStruct<struct FPlanetInfo>();

#define FID_SolarSystemProject_Source_SolarSystemProject_Planet_h_256_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSetHighlandsPlanet); \
	DECLARE_FUNCTION(execSetSwampPlanet); \
	DECLARE_FUNCTION(execSetArchipelagoPlanet); \
	DECLARE_FUNCTION(execSetMarsLikePlanet); \
	DECLARE_FUNCTION(execSetTundraPlanet); \
	DECLARE_FUNCTION(execSetDesertPlanet); \
	DECLARE_FUNCTION(execSetCrystalPlanet); \
	DECLARE_FUNCTION(execSetIceWorld); \
	DECLARE_FUNCTION(execSetJungleWorld); \
	DECLARE_FUNCTION(execSetVolcanicPlanet); \
	DECLARE_FUNCTION(execSetEarthLike);


#define FID_SolarSystemProject_Source_SolarSystemProject_Planet_h_256_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlanet(); \
	friend struct Z_Construct_UClass_APlanet_Statics; \
public: \
	DECLARE_CLASS(APlanet, AOrbitingBody, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SolarSystemProject"), NO_API) \
	DECLARE_SERIALIZER(APlanet)


#define FID_SolarSystemProject_Source_SolarSystemProject_Planet_h_256_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	APlanet(APlanet&&); \
	APlanet(const APlanet&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlanet); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlanet); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlanet) \
	NO_API virtual ~APlanet();


#define FID_SolarSystemProject_Source_SolarSystemProject_Planet_h_253_PROLOG
#define FID_SolarSystemProject_Source_SolarSystemProject_Planet_h_256_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SolarSystemProject_Source_SolarSystemProject_Planet_h_256_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_SolarSystemProject_Source_SolarSystemProject_Planet_h_256_INCLASS_NO_PURE_DECLS \
	FID_SolarSystemProject_Source_SolarSystemProject_Planet_h_256_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SOLARSYSTEMPROJECT_API UClass* StaticClass<class APlanet>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_SolarSystemProject_Source_SolarSystemProject_Planet_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
