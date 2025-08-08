// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CelestialBody.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SOLARSYSTEMPROJECT_CelestialBody_generated_h
#error "CelestialBody.generated.h already included, missing '#pragma once' in CelestialBody.h"
#endif
#define SOLARSYSTEMPROJECT_CelestialBody_generated_h

#define FID_SolarSystemProject_Source_SolarSystemProject_CelestialBody_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACelestialBody(); \
	friend struct Z_Construct_UClass_ACelestialBody_Statics; \
public: \
	DECLARE_CLASS(ACelestialBody, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SolarSystemProject"), NO_API) \
	DECLARE_SERIALIZER(ACelestialBody)


#define FID_SolarSystemProject_Source_SolarSystemProject_CelestialBody_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ACelestialBody(ACelestialBody&&); \
	ACelestialBody(const ACelestialBody&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACelestialBody); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACelestialBody); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACelestialBody) \
	NO_API virtual ~ACelestialBody();


#define FID_SolarSystemProject_Source_SolarSystemProject_CelestialBody_h_9_PROLOG
#define FID_SolarSystemProject_Source_SolarSystemProject_CelestialBody_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SolarSystemProject_Source_SolarSystemProject_CelestialBody_h_12_INCLASS_NO_PURE_DECLS \
	FID_SolarSystemProject_Source_SolarSystemProject_CelestialBody_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SOLARSYSTEMPROJECT_API UClass* StaticClass<class ACelestialBody>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_SolarSystemProject_Source_SolarSystemProject_CelestialBody_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
