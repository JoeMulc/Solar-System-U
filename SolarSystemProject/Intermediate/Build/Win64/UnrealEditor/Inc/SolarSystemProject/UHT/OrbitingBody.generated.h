// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OrbitingBody.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SOLARSYSTEMPROJECT_OrbitingBody_generated_h
#error "OrbitingBody.generated.h already included, missing '#pragma once' in OrbitingBody.h"
#endif
#define SOLARSYSTEMPROJECT_OrbitingBody_generated_h

#define FID_SolarSystemProject_Source_SolarSystemProject_OrbitingBody_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAOrbitingBody(); \
	friend struct Z_Construct_UClass_AOrbitingBody_Statics; \
public: \
	DECLARE_CLASS(AOrbitingBody, ACelestialBody, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SolarSystemProject"), NO_API) \
	DECLARE_SERIALIZER(AOrbitingBody)


#define FID_SolarSystemProject_Source_SolarSystemProject_OrbitingBody_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AOrbitingBody(AOrbitingBody&&); \
	AOrbitingBody(const AOrbitingBody&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AOrbitingBody); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOrbitingBody); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AOrbitingBody) \
	NO_API virtual ~AOrbitingBody();


#define FID_SolarSystemProject_Source_SolarSystemProject_OrbitingBody_h_16_PROLOG
#define FID_SolarSystemProject_Source_SolarSystemProject_OrbitingBody_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SolarSystemProject_Source_SolarSystemProject_OrbitingBody_h_19_INCLASS_NO_PURE_DECLS \
	FID_SolarSystemProject_Source_SolarSystemProject_OrbitingBody_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SOLARSYSTEMPROJECT_API UClass* StaticClass<class AOrbitingBody>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_SolarSystemProject_Source_SolarSystemProject_OrbitingBody_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
