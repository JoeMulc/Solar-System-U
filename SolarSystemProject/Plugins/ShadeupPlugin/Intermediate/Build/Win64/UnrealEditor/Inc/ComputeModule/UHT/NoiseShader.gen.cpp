// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ComputeModule/Public/NoiseShader/NoiseShader.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNoiseShader() {}

// Begin Cross Module References
COMPUTEMODULE_API UClass* Z_Construct_UClass_UNoiseShaderLibrary_AsyncExecution();
COMPUTEMODULE_API UClass* Z_Construct_UClass_UNoiseShaderLibrary_AsyncExecution_NoRegister();
COMPUTEMODULE_API UFunction* Z_Construct_UDelegateFunction_ComputeModule_OnNoiseShaderLibrary_AsyncExecutionCompleted__DelegateSignature();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintAsyncActionBase();
UPackage* Z_Construct_UPackage__Script_ComputeModule();
// End Cross Module References

// Begin Delegate FOnNoiseShaderLibrary_AsyncExecutionCompleted
struct Z_Construct_UDelegateFunction_ComputeModule_OnNoiseShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics
{
	struct _Script_ComputeModule_eventOnNoiseShaderLibrary_AsyncExecutionCompleted_Parms
	{
		TArray<FVector> values;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/NoiseShader/NoiseShader.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_values_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_values_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_values;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_ComputeModule_OnNoiseShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::NewProp_values_Inner = { "values", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_ComputeModule_OnNoiseShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::NewProp_values = { "values", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ComputeModule_eventOnNoiseShaderLibrary_AsyncExecutionCompleted_Parms, values), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_values_MetaData), NewProp_values_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ComputeModule_OnNoiseShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ComputeModule_OnNoiseShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::NewProp_values_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ComputeModule_OnNoiseShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::NewProp_values,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ComputeModule_OnNoiseShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ComputeModule_OnNoiseShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ComputeModule, nullptr, "OnNoiseShaderLibrary_AsyncExecutionCompleted__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_ComputeModule_OnNoiseShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ComputeModule_OnNoiseShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ComputeModule_OnNoiseShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::_Script_ComputeModule_eventOnNoiseShaderLibrary_AsyncExecutionCompleted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ComputeModule_OnNoiseShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ComputeModule_OnNoiseShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_ComputeModule_OnNoiseShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::_Script_ComputeModule_eventOnNoiseShaderLibrary_AsyncExecutionCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ComputeModule_OnNoiseShaderLibrary_AsyncExecutionCompleted__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ComputeModule_OnNoiseShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnNoiseShaderLibrary_AsyncExecutionCompleted_DelegateWrapper(const FMulticastScriptDelegate& OnNoiseShaderLibrary_AsyncExecutionCompleted, TArray<FVector> const& values)
{
	struct _Script_ComputeModule_eventOnNoiseShaderLibrary_AsyncExecutionCompleted_Parms
	{
		TArray<FVector> values;
	};
	_Script_ComputeModule_eventOnNoiseShaderLibrary_AsyncExecutionCompleted_Parms Parms;
	Parms.values=values;
	OnNoiseShaderLibrary_AsyncExecutionCompleted.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnNoiseShaderLibrary_AsyncExecutionCompleted

// Begin Class UNoiseShaderLibrary_AsyncExecution Function ExecuteBaseComputeShader
struct Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader_Statics
{
	struct NoiseShaderLibrary_AsyncExecution_eventExecuteBaseComputeShader_Parms
	{
		UObject* WorldContextObject;
		TArray<FVector> vs;
		int32 Arg2;
		UNoiseShaderLibrary_AsyncExecution* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "ComputeShader" },
		{ "ModuleRelativePath", "Public/NoiseShader/NoiseShader.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_vs_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_vs;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Arg2;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NoiseShaderLibrary_AsyncExecution_eventExecuteBaseComputeShader_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader_Statics::NewProp_vs_Inner = { "vs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader_Statics::NewProp_vs = { "vs", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NoiseShaderLibrary_AsyncExecution_eventExecuteBaseComputeShader_Parms, vs), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader_Statics::NewProp_Arg2 = { "Arg2", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NoiseShaderLibrary_AsyncExecution_eventExecuteBaseComputeShader_Parms, Arg2), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NoiseShaderLibrary_AsyncExecution_eventExecuteBaseComputeShader_Parms, ReturnValue), Z_Construct_UClass_UNoiseShaderLibrary_AsyncExecution_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader_Statics::NewProp_vs_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader_Statics::NewProp_vs,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader_Statics::NewProp_Arg2,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UNoiseShaderLibrary_AsyncExecution, nullptr, "ExecuteBaseComputeShader", nullptr, nullptr, Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader_Statics::PropPointers), sizeof(Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader_Statics::NoiseShaderLibrary_AsyncExecution_eventExecuteBaseComputeShader_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader_Statics::NoiseShaderLibrary_AsyncExecution_eventExecuteBaseComputeShader_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UNoiseShaderLibrary_AsyncExecution::execExecuteBaseComputeShader)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_TARRAY_REF(FVector,Z_Param_Out_vs);
	P_GET_PROPERTY(FIntProperty,Z_Param_Arg2);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UNoiseShaderLibrary_AsyncExecution**)Z_Param__Result=UNoiseShaderLibrary_AsyncExecution::ExecuteBaseComputeShader(Z_Param_WorldContextObject,Z_Param_Out_vs,Z_Param_Arg2);
	P_NATIVE_END;
}
// End Class UNoiseShaderLibrary_AsyncExecution Function ExecuteBaseComputeShader

// Begin Class UNoiseShaderLibrary_AsyncExecution
void UNoiseShaderLibrary_AsyncExecution::StaticRegisterNativesUNoiseShaderLibrary_AsyncExecution()
{
	UClass* Class = UNoiseShaderLibrary_AsyncExecution::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ExecuteBaseComputeShader", &UNoiseShaderLibrary_AsyncExecution::execExecuteBaseComputeShader },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UNoiseShaderLibrary_AsyncExecution);
UClass* Z_Construct_UClass_UNoiseShaderLibrary_AsyncExecution_NoRegister()
{
	return UNoiseShaderLibrary_AsyncExecution::StaticClass();
}
struct Z_Construct_UClass_UNoiseShaderLibrary_AsyncExecution_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "NoiseShader/NoiseShader.h" },
		{ "ModuleRelativePath", "Public/NoiseShader/NoiseShader.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Completed_MetaData[] = {
		{ "ModuleRelativePath", "Public/NoiseShader/NoiseShader.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_Completed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UNoiseShaderLibrary_AsyncExecution_ExecuteBaseComputeShader, "ExecuteBaseComputeShader" }, // 422484246
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNoiseShaderLibrary_AsyncExecution>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UNoiseShaderLibrary_AsyncExecution_Statics::NewProp_Completed = { "Completed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNoiseShaderLibrary_AsyncExecution, Completed), Z_Construct_UDelegateFunction_ComputeModule_OnNoiseShaderLibrary_AsyncExecutionCompleted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Completed_MetaData), NewProp_Completed_MetaData) }; // 2491323676
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UNoiseShaderLibrary_AsyncExecution_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNoiseShaderLibrary_AsyncExecution_Statics::NewProp_Completed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNoiseShaderLibrary_AsyncExecution_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UNoiseShaderLibrary_AsyncExecution_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintAsyncActionBase,
	(UObject* (*)())Z_Construct_UPackage__Script_ComputeModule,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNoiseShaderLibrary_AsyncExecution_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UNoiseShaderLibrary_AsyncExecution_Statics::ClassParams = {
	&UNoiseShaderLibrary_AsyncExecution::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UNoiseShaderLibrary_AsyncExecution_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UNoiseShaderLibrary_AsyncExecution_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNoiseShaderLibrary_AsyncExecution_Statics::Class_MetaDataParams), Z_Construct_UClass_UNoiseShaderLibrary_AsyncExecution_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UNoiseShaderLibrary_AsyncExecution()
{
	if (!Z_Registration_Info_UClass_UNoiseShaderLibrary_AsyncExecution.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNoiseShaderLibrary_AsyncExecution.OuterSingleton, Z_Construct_UClass_UNoiseShaderLibrary_AsyncExecution_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UNoiseShaderLibrary_AsyncExecution.OuterSingleton;
}
template<> COMPUTEMODULE_API UClass* StaticClass<UNoiseShaderLibrary_AsyncExecution>()
{
	return UNoiseShaderLibrary_AsyncExecution::StaticClass();
}
UNoiseShaderLibrary_AsyncExecution::UNoiseShaderLibrary_AsyncExecution(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UNoiseShaderLibrary_AsyncExecution);
UNoiseShaderLibrary_AsyncExecution::~UNoiseShaderLibrary_AsyncExecution() {}
// End Class UNoiseShaderLibrary_AsyncExecution

// Begin Registration
struct Z_CompiledInDeferFile_FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_NoiseShader_NoiseShader_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UNoiseShaderLibrary_AsyncExecution, UNoiseShaderLibrary_AsyncExecution::StaticClass, TEXT("UNoiseShaderLibrary_AsyncExecution"), &Z_Registration_Info_UClass_UNoiseShaderLibrary_AsyncExecution, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNoiseShaderLibrary_AsyncExecution), 1412204128U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_NoiseShader_NoiseShader_h_2053383850(TEXT("/Script/ComputeModule"),
	Z_CompiledInDeferFile_FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_NoiseShader_NoiseShader_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_NoiseShader_NoiseShader_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
