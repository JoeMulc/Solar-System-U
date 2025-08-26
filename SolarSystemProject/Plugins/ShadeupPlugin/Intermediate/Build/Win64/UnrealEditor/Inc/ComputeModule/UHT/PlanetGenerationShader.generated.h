// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PlanetGenerationShader/PlanetGenerationShader.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class UPlanetGenerationShaderLibrary_AsyncExecution;
struct FLinearColor;
#ifdef COMPUTEMODULE_PlanetGenerationShader_generated_h
#error "PlanetGenerationShader.generated.h already included, missing '#pragma once' in PlanetGenerationShader.h"
#endif
#define COMPUTEMODULE_PlanetGenerationShader_generated_h

#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_PlanetGenerationShader_PlanetGenerationShader_h_87_DELEGATE \
COMPUTEMODULE_API void FOnPlanetGenerationShaderLibrary_AsyncExecutionCompleted_DelegateWrapper(const FMulticastScriptDelegate& OnPlanetGenerationShaderLibrary_AsyncExecutionCompleted, TArray<FVector> const& Vertices, TArray<FVector> const& Normals, TArray<FLinearColor> const& Colors);


#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_PlanetGenerationShader_PlanetGenerationShader_h_92_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execExecuteBaseComputeShader);


#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_PlanetGenerationShader_PlanetGenerationShader_h_92_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPlanetGenerationShaderLibrary_AsyncExecution(); \
	friend struct Z_Construct_UClass_UPlanetGenerationShaderLibrary_AsyncExecution_Statics; \
public: \
	DECLARE_CLASS(UPlanetGenerationShaderLibrary_AsyncExecution, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ComputeModule"), NO_API) \
	DECLARE_SERIALIZER(UPlanetGenerationShaderLibrary_AsyncExecution)


#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_PlanetGenerationShader_PlanetGenerationShader_h_92_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPlanetGenerationShaderLibrary_AsyncExecution(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UPlanetGenerationShaderLibrary_AsyncExecution(UPlanetGenerationShaderLibrary_AsyncExecution&&); \
	UPlanetGenerationShaderLibrary_AsyncExecution(const UPlanetGenerationShaderLibrary_AsyncExecution&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPlanetGenerationShaderLibrary_AsyncExecution); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPlanetGenerationShaderLibrary_AsyncExecution); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPlanetGenerationShaderLibrary_AsyncExecution) \
	NO_API virtual ~UPlanetGenerationShaderLibrary_AsyncExecution();


#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_PlanetGenerationShader_PlanetGenerationShader_h_89_PROLOG
#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_PlanetGenerationShader_PlanetGenerationShader_h_92_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_PlanetGenerationShader_PlanetGenerationShader_h_92_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_PlanetGenerationShader_PlanetGenerationShader_h_92_INCLASS_NO_PURE_DECLS \
	FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_PlanetGenerationShader_PlanetGenerationShader_h_92_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMPUTEMODULE_API UClass* StaticClass<class UPlanetGenerationShaderLibrary_AsyncExecution>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_PlanetGenerationShader_PlanetGenerationShader_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
