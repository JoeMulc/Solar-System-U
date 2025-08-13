// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CraterShader/CraterShader.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UCraterShaderLibrary_AsyncExecution;
class UObject;
#ifdef COMPUTEMODULE_CraterShader_generated_h
#error "CraterShader.generated.h already included, missing '#pragma once' in CraterShader.h"
#endif
#define COMPUTEMODULE_CraterShader_generated_h

#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_CraterShader_CraterShader_h_63_DELEGATE \
COMPUTEMODULE_API void FOnCraterShaderLibrary_AsyncExecutionCompleted_DelegateWrapper(const FMulticastScriptDelegate& OnCraterShaderLibrary_AsyncExecutionCompleted, TArray<FVector> const& Values);


#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_CraterShader_CraterShader_h_68_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execExecuteBaseComputeShader);


#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_CraterShader_CraterShader_h_68_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCraterShaderLibrary_AsyncExecution(); \
	friend struct Z_Construct_UClass_UCraterShaderLibrary_AsyncExecution_Statics; \
public: \
	DECLARE_CLASS(UCraterShaderLibrary_AsyncExecution, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ComputeModule"), NO_API) \
	DECLARE_SERIALIZER(UCraterShaderLibrary_AsyncExecution)


#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_CraterShader_CraterShader_h_68_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCraterShaderLibrary_AsyncExecution(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCraterShaderLibrary_AsyncExecution(UCraterShaderLibrary_AsyncExecution&&); \
	UCraterShaderLibrary_AsyncExecution(const UCraterShaderLibrary_AsyncExecution&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCraterShaderLibrary_AsyncExecution); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCraterShaderLibrary_AsyncExecution); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCraterShaderLibrary_AsyncExecution) \
	NO_API virtual ~UCraterShaderLibrary_AsyncExecution();


#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_CraterShader_CraterShader_h_65_PROLOG
#define FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_CraterShader_CraterShader_h_68_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_CraterShader_CraterShader_h_68_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_CraterShader_CraterShader_h_68_INCLASS_NO_PURE_DECLS \
	FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_CraterShader_CraterShader_h_68_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMPUTEMODULE_API UClass* StaticClass<class UCraterShaderLibrary_AsyncExecution>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_CraterShader_CraterShader_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
