// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SphereGenerationShader/SphereGenerationShader.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class USphereGenerationShaderLibrary_AsyncExecution;
#ifdef COMPUTEMODULE_SphereGenerationShader_generated_h
#error "SphereGenerationShader.generated.h already included, missing '#pragma once' in SphereGenerationShader.h"
#endif
#define COMPUTEMODULE_SphereGenerationShader_generated_h

#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_SphereGenerationShader_SphereGenerationShader_h_71_DELEGATE \
COMPUTEMODULE_API void FOnSphereGenerationShaderLibrary_AsyncExecutionCompleted_DelegateWrapper(const FMulticastScriptDelegate& OnSphereGenerationShaderLibrary_AsyncExecutionCompleted, const int32 Value);


#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_SphereGenerationShader_SphereGenerationShader_h_77_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execExecuteBaseComputeShader);


#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_SphereGenerationShader_SphereGenerationShader_h_77_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSphereGenerationShaderLibrary_AsyncExecution(); \
	friend struct Z_Construct_UClass_USphereGenerationShaderLibrary_AsyncExecution_Statics; \
public: \
	DECLARE_CLASS(USphereGenerationShaderLibrary_AsyncExecution, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ComputeModule"), NO_API) \
	DECLARE_SERIALIZER(USphereGenerationShaderLibrary_AsyncExecution)


#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_SphereGenerationShader_SphereGenerationShader_h_77_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USphereGenerationShaderLibrary_AsyncExecution(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	USphereGenerationShaderLibrary_AsyncExecution(USphereGenerationShaderLibrary_AsyncExecution&&); \
	USphereGenerationShaderLibrary_AsyncExecution(const USphereGenerationShaderLibrary_AsyncExecution&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USphereGenerationShaderLibrary_AsyncExecution); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USphereGenerationShaderLibrary_AsyncExecution); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USphereGenerationShaderLibrary_AsyncExecution) \
	NO_API virtual ~USphereGenerationShaderLibrary_AsyncExecution();


#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_SphereGenerationShader_SphereGenerationShader_h_74_PROLOG
#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_SphereGenerationShader_SphereGenerationShader_h_77_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_SphereGenerationShader_SphereGenerationShader_h_77_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_SphereGenerationShader_SphereGenerationShader_h_77_INCLASS_NO_PURE_DECLS \
	FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_SphereGenerationShader_SphereGenerationShader_h_77_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMPUTEMODULE_API UClass* StaticClass<class USphereGenerationShaderLibrary_AsyncExecution>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_SphereGenerationShader_SphereGenerationShader_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
