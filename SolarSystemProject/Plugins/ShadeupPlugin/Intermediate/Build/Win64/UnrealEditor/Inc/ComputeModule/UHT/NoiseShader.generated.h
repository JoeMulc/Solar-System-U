// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "NoiseShader/NoiseShader.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UNoiseShaderLibrary_AsyncExecution;
class UObject;
#ifdef COMPUTEMODULE_NoiseShader_generated_h
#error "NoiseShader.generated.h already included, missing '#pragma once' in NoiseShader.h"
#endif
#define COMPUTEMODULE_NoiseShader_generated_h

#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_NoiseShader_NoiseShader_h_81_DELEGATE \
COMPUTEMODULE_API void FOnNoiseShaderLibrary_AsyncExecutionCompleted_DelegateWrapper(const FMulticastScriptDelegate& OnNoiseShaderLibrary_AsyncExecutionCompleted, TArray<FVector> const& Vertices, TArray<FVector> const& Normals);


#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_NoiseShader_NoiseShader_h_86_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execExecuteBaseComputeShader);


#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_NoiseShader_NoiseShader_h_86_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUNoiseShaderLibrary_AsyncExecution(); \
	friend struct Z_Construct_UClass_UNoiseShaderLibrary_AsyncExecution_Statics; \
public: \
	DECLARE_CLASS(UNoiseShaderLibrary_AsyncExecution, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ComputeModule"), NO_API) \
	DECLARE_SERIALIZER(UNoiseShaderLibrary_AsyncExecution)


#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_NoiseShader_NoiseShader_h_86_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UNoiseShaderLibrary_AsyncExecution(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UNoiseShaderLibrary_AsyncExecution(UNoiseShaderLibrary_AsyncExecution&&); \
	UNoiseShaderLibrary_AsyncExecution(const UNoiseShaderLibrary_AsyncExecution&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UNoiseShaderLibrary_AsyncExecution); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UNoiseShaderLibrary_AsyncExecution); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UNoiseShaderLibrary_AsyncExecution) \
	NO_API virtual ~UNoiseShaderLibrary_AsyncExecution();


#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_NoiseShader_NoiseShader_h_83_PROLOG
#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_NoiseShader_NoiseShader_h_86_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_NoiseShader_NoiseShader_h_86_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_NoiseShader_NoiseShader_h_86_INCLASS_NO_PURE_DECLS \
	FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_NoiseShader_NoiseShader_h_86_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMPUTEMODULE_API UClass* StaticClass<class UNoiseShaderLibrary_AsyncExecution>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_NoiseShader_NoiseShader_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
