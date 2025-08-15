// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Moon.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SOLARSYSTEMPROJECT_Moon_generated_h
#error "Moon.generated.h already included, missing '#pragma once' in Moon.h"
#endif
#define SOLARSYSTEMPROJECT_Moon_generated_h

#define FID_SolarSystemProject_Source_SolarSystemProject_Moon_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMoon(); \
	friend struct Z_Construct_UClass_AMoon_Statics; \
public: \
	DECLARE_CLASS(AMoon, AOrbitingBody, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SolarSystemProject"), NO_API) \
	DECLARE_SERIALIZER(AMoon)


#define FID_SolarSystemProject_Source_SolarSystemProject_Moon_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMoon(AMoon&&); \
	AMoon(const AMoon&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMoon); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMoon); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMoon) \
	NO_API virtual ~AMoon();


#define FID_SolarSystemProject_Source_SolarSystemProject_Moon_h_11_PROLOG
#define FID_SolarSystemProject_Source_SolarSystemProject_Moon_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SolarSystemProject_Source_SolarSystemProject_Moon_h_14_INCLASS_NO_PURE_DECLS \
	FID_SolarSystemProject_Source_SolarSystemProject_Moon_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SOLARSYSTEMPROJECT_API UClass* StaticClass<class AMoon>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_SolarSystemProject_Source_SolarSystemProject_Moon_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
