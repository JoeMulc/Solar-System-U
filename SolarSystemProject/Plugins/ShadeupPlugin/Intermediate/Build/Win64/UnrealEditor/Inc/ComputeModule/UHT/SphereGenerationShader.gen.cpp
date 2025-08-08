// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ComputeModule/Public/SphereGenerationShader/SphereGenerationShader.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSphereGenerationShader() {}

// Begin Cross Module References
COMPUTEMODULE_API UClass* Z_Construct_UClass_USphereGenerationShaderLibrary_AsyncExecution();
COMPUTEMODULE_API UClass* Z_Construct_UClass_USphereGenerationShaderLibrary_AsyncExecution_NoRegister();
COMPUTEMODULE_API UFunction* Z_Construct_UDelegateFunction_ComputeModule_OnSphereGenerationShaderLibrary_AsyncExecutionCompleted__DelegateSignature();
COMPUTEMODULE_API UScriptStruct* Z_Construct_UScriptStruct_FSphereGeometryData();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintAsyncActionBase();
UPackage* Z_Construct_UPackage__Script_ComputeModule();
// End Cross Module References

// Begin ScriptStruct FSphereGeometryData
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SphereGeometryData;
class UScriptStruct* FSphereGeometryData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SphereGeometryData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SphereGeometryData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSphereGeometryData, (UObject*)Z_Construct_UPackage__Script_ComputeModule(), TEXT("SphereGeometryData"));
	}
	return Z_Registration_Info_UScriptStruct_SphereGeometryData.OuterSingleton;
}
template<> COMPUTEMODULE_API UScriptStruct* StaticStruct<FSphereGeometryData>()
{
	return FSphereGeometryData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSphereGeometryData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Struct to hold sphere geometry data\n" },
#endif
		{ "ModuleRelativePath", "Public/SphereGenerationShader/SphereGenerationShader.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Struct to hold sphere geometry data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Vertices_MetaData[] = {
		{ "Category", "SphereGeometryData" },
		{ "ModuleRelativePath", "Public/SphereGenerationShader/SphereGenerationShader.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Triangles_MetaData[] = {
		{ "Category", "SphereGeometryData" },
		{ "ModuleRelativePath", "Public/SphereGenerationShader/SphereGenerationShader.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Normals_MetaData[] = {
		{ "Category", "SphereGeometryData" },
		{ "ModuleRelativePath", "Public/SphereGenerationShader/SphereGenerationShader.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UVs_MetaData[] = {
		{ "Category", "SphereGeometryData" },
		{ "ModuleRelativePath", "Public/SphereGenerationShader/SphereGenerationShader.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Vertices_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Vertices;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Triangles_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Triangles;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Normals_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Normals;
	static const UECodeGen_Private::FStructPropertyParams NewProp_UVs_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_UVs;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSphereGeometryData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSphereGeometryData_Statics::NewProp_Vertices_Inner = { "Vertices", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSphereGeometryData_Statics::NewProp_Vertices = { "Vertices", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSphereGeometryData, Vertices), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Vertices_MetaData), NewProp_Vertices_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSphereGeometryData_Statics::NewProp_Triangles_Inner = { "Triangles", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSphereGeometryData_Statics::NewProp_Triangles = { "Triangles", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSphereGeometryData, Triangles), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Triangles_MetaData), NewProp_Triangles_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSphereGeometryData_Statics::NewProp_Normals_Inner = { "Normals", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSphereGeometryData_Statics::NewProp_Normals = { "Normals", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSphereGeometryData, Normals), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Normals_MetaData), NewProp_Normals_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSphereGeometryData_Statics::NewProp_UVs_Inner = { "UVs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSphereGeometryData_Statics::NewProp_UVs = { "UVs", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSphereGeometryData, UVs), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UVs_MetaData), NewProp_UVs_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSphereGeometryData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSphereGeometryData_Statics::NewProp_Vertices_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSphereGeometryData_Statics::NewProp_Vertices,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSphereGeometryData_Statics::NewProp_Triangles_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSphereGeometryData_Statics::NewProp_Triangles,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSphereGeometryData_Statics::NewProp_Normals_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSphereGeometryData_Statics::NewProp_Normals,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSphereGeometryData_Statics::NewProp_UVs_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSphereGeometryData_Statics::NewProp_UVs,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSphereGeometryData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSphereGeometryData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ComputeModule,
	nullptr,
	&NewStructOps,
	"SphereGeometryData",
	Z_Construct_UScriptStruct_FSphereGeometryData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSphereGeometryData_Statics::PropPointers),
	sizeof(FSphereGeometryData),
	alignof(FSphereGeometryData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSphereGeometryData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSphereGeometryData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSphereGeometryData()
{
	if (!Z_Registration_Info_UScriptStruct_SphereGeometryData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SphereGeometryData.InnerSingleton, Z_Construct_UScriptStruct_FSphereGeometryData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SphereGeometryData.InnerSingleton;
}
// End ScriptStruct FSphereGeometryData

// Begin Delegate FOnSphereGenerationShaderLibrary_AsyncExecutionCompleted
struct Z_Construct_UDelegateFunction_ComputeModule_OnSphereGenerationShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics
{
	struct _Script_ComputeModule_eventOnSphereGenerationShaderLibrary_AsyncExecutionCompleted_Parms
	{
		FSphereGeometryData GeometryData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SphereGenerationShader/SphereGenerationShader.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GeometryData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_GeometryData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_ComputeModule_OnSphereGenerationShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::NewProp_GeometryData = { "GeometryData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_ComputeModule_eventOnSphereGenerationShaderLibrary_AsyncExecutionCompleted_Parms, GeometryData), Z_Construct_UScriptStruct_FSphereGeometryData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GeometryData_MetaData), NewProp_GeometryData_MetaData) }; // 1625863103
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ComputeModule_OnSphereGenerationShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ComputeModule_OnSphereGenerationShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::NewProp_GeometryData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ComputeModule_OnSphereGenerationShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ComputeModule_OnSphereGenerationShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ComputeModule, nullptr, "OnSphereGenerationShaderLibrary_AsyncExecutionCompleted__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_ComputeModule_OnSphereGenerationShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ComputeModule_OnSphereGenerationShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ComputeModule_OnSphereGenerationShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::_Script_ComputeModule_eventOnSphereGenerationShaderLibrary_AsyncExecutionCompleted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ComputeModule_OnSphereGenerationShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ComputeModule_OnSphereGenerationShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_ComputeModule_OnSphereGenerationShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::_Script_ComputeModule_eventOnSphereGenerationShaderLibrary_AsyncExecutionCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ComputeModule_OnSphereGenerationShaderLibrary_AsyncExecutionCompleted__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ComputeModule_OnSphereGenerationShaderLibrary_AsyncExecutionCompleted__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnSphereGenerationShaderLibrary_AsyncExecutionCompleted_DelegateWrapper(const FMulticastScriptDelegate& OnSphereGenerationShaderLibrary_AsyncExecutionCompleted, FSphereGeometryData const& GeometryData)
{
	struct _Script_ComputeModule_eventOnSphereGenerationShaderLibrary_AsyncExecutionCompleted_Parms
	{
		FSphereGeometryData GeometryData;
	};
	_Script_ComputeModule_eventOnSphereGenerationShaderLibrary_AsyncExecutionCompleted_Parms Parms;
	Parms.GeometryData=GeometryData;
	OnSphereGenerationShaderLibrary_AsyncExecutionCompleted.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnSphereGenerationShaderLibrary_AsyncExecutionCompleted

// Begin Class USphereGenerationShaderLibrary_AsyncExecution Function ExecuteSphereGenerationShader
struct Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader_Statics
{
	struct SphereGenerationShaderLibrary_AsyncExecution_eventExecuteSphereGenerationShader_Parms
	{
		UObject* WorldContextObject;
		float InRadius;
		int32 InLatitudeSegments;
		int32 InLongitudeSegments;
		USphereGenerationShaderLibrary_AsyncExecution* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "ComputeShader" },
		{ "CPP_Default_InLatitudeSegments", "16" },
		{ "CPP_Default_InLongitudeSegments", "32" },
		{ "CPP_Default_InRadius", "100.000000" },
		{ "ModuleRelativePath", "Public/SphereGenerationShader/SphereGenerationShader.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InRadius;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InLatitudeSegments;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InLongitudeSegments;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SphereGenerationShaderLibrary_AsyncExecution_eventExecuteSphereGenerationShader_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader_Statics::NewProp_InRadius = { "InRadius", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SphereGenerationShaderLibrary_AsyncExecution_eventExecuteSphereGenerationShader_Parms, InRadius), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader_Statics::NewProp_InLatitudeSegments = { "InLatitudeSegments", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SphereGenerationShaderLibrary_AsyncExecution_eventExecuteSphereGenerationShader_Parms, InLatitudeSegments), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader_Statics::NewProp_InLongitudeSegments = { "InLongitudeSegments", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SphereGenerationShaderLibrary_AsyncExecution_eventExecuteSphereGenerationShader_Parms, InLongitudeSegments), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SphereGenerationShaderLibrary_AsyncExecution_eventExecuteSphereGenerationShader_Parms, ReturnValue), Z_Construct_UClass_USphereGenerationShaderLibrary_AsyncExecution_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader_Statics::NewProp_InRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader_Statics::NewProp_InLatitudeSegments,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader_Statics::NewProp_InLongitudeSegments,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USphereGenerationShaderLibrary_AsyncExecution, nullptr, "ExecuteSphereGenerationShader", nullptr, nullptr, Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader_Statics::PropPointers), sizeof(Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader_Statics::SphereGenerationShaderLibrary_AsyncExecution_eventExecuteSphereGenerationShader_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader_Statics::Function_MetaDataParams), Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader_Statics::SphereGenerationShaderLibrary_AsyncExecution_eventExecuteSphereGenerationShader_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USphereGenerationShaderLibrary_AsyncExecution::execExecuteSphereGenerationShader)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InRadius);
	P_GET_PROPERTY(FIntProperty,Z_Param_InLatitudeSegments);
	P_GET_PROPERTY(FIntProperty,Z_Param_InLongitudeSegments);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(USphereGenerationShaderLibrary_AsyncExecution**)Z_Param__Result=USphereGenerationShaderLibrary_AsyncExecution::ExecuteSphereGenerationShader(Z_Param_WorldContextObject,Z_Param_InRadius,Z_Param_InLatitudeSegments,Z_Param_InLongitudeSegments);
	P_NATIVE_END;
}
// End Class USphereGenerationShaderLibrary_AsyncExecution Function ExecuteSphereGenerationShader

// Begin Class USphereGenerationShaderLibrary_AsyncExecution
void USphereGenerationShaderLibrary_AsyncExecution::StaticRegisterNativesUSphereGenerationShaderLibrary_AsyncExecution()
{
	UClass* Class = USphereGenerationShaderLibrary_AsyncExecution::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ExecuteSphereGenerationShader", &USphereGenerationShaderLibrary_AsyncExecution::execExecuteSphereGenerationShader },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USphereGenerationShaderLibrary_AsyncExecution);
UClass* Z_Construct_UClass_USphereGenerationShaderLibrary_AsyncExecution_NoRegister()
{
	return USphereGenerationShaderLibrary_AsyncExecution::StaticClass();
}
struct Z_Construct_UClass_USphereGenerationShaderLibrary_AsyncExecution_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "SphereGenerationShader/SphereGenerationShader.h" },
		{ "ModuleRelativePath", "Public/SphereGenerationShader/SphereGenerationShader.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Completed_MetaData[] = {
		{ "ModuleRelativePath", "Public/SphereGenerationShader/SphereGenerationShader.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_Completed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USphereGenerationShaderLibrary_AsyncExecution_ExecuteSphereGenerationShader, "ExecuteSphereGenerationShader" }, // 1652023702
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USphereGenerationShaderLibrary_AsyncExecution>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USphereGenerationShaderLibrary_AsyncExecution_Statics::NewProp_Completed = { "Completed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USphereGenerationShaderLibrary_AsyncExecution, Completed), Z_Construct_UDelegateFunction_ComputeModule_OnSphereGenerationShaderLibrary_AsyncExecutionCompleted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Completed_MetaData), NewProp_Completed_MetaData) }; // 428071152
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USphereGenerationShaderLibrary_AsyncExecution_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USphereGenerationShaderLibrary_AsyncExecution_Statics::NewProp_Completed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USphereGenerationShaderLibrary_AsyncExecution_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_USphereGenerationShaderLibrary_AsyncExecution_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintAsyncActionBase,
	(UObject* (*)())Z_Construct_UPackage__Script_ComputeModule,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USphereGenerationShaderLibrary_AsyncExecution_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USphereGenerationShaderLibrary_AsyncExecution_Statics::ClassParams = {
	&USphereGenerationShaderLibrary_AsyncExecution::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_USphereGenerationShaderLibrary_AsyncExecution_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_USphereGenerationShaderLibrary_AsyncExecution_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USphereGenerationShaderLibrary_AsyncExecution_Statics::Class_MetaDataParams), Z_Construct_UClass_USphereGenerationShaderLibrary_AsyncExecution_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_USphereGenerationShaderLibrary_AsyncExecution()
{
	if (!Z_Registration_Info_UClass_USphereGenerationShaderLibrary_AsyncExecution.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USphereGenerationShaderLibrary_AsyncExecution.OuterSingleton, Z_Construct_UClass_USphereGenerationShaderLibrary_AsyncExecution_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USphereGenerationShaderLibrary_AsyncExecution.OuterSingleton;
}
template<> COMPUTEMODULE_API UClass* StaticClass<USphereGenerationShaderLibrary_AsyncExecution>()
{
	return USphereGenerationShaderLibrary_AsyncExecution::StaticClass();
}
USphereGenerationShaderLibrary_AsyncExecution::USphereGenerationShaderLibrary_AsyncExecution(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(USphereGenerationShaderLibrary_AsyncExecution);
USphereGenerationShaderLibrary_AsyncExecution::~USphereGenerationShaderLibrary_AsyncExecution() {}
// End Class USphereGenerationShaderLibrary_AsyncExecution

// Begin Registration
struct Z_CompiledInDeferFile_FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_SphereGenerationShader_SphereGenerationShader_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FSphereGeometryData::StaticStruct, Z_Construct_UScriptStruct_FSphereGeometryData_Statics::NewStructOps, TEXT("SphereGeometryData"), &Z_Registration_Info_UScriptStruct_SphereGeometryData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSphereGeometryData), 1625863103U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USphereGenerationShaderLibrary_AsyncExecution, USphereGenerationShaderLibrary_AsyncExecution::StaticClass, TEXT("USphereGenerationShaderLibrary_AsyncExecution"), &Z_Registration_Info_UClass_USphereGenerationShaderLibrary_AsyncExecution, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USphereGenerationShaderLibrary_AsyncExecution), 3197448153U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_SphereGenerationShader_SphereGenerationShader_h_2720976333(TEXT("/Script/ComputeModule"),
	Z_CompiledInDeferFile_FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_SphereGenerationShader_SphereGenerationShader_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_SphereGenerationShader_SphereGenerationShader_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_SphereGenerationShader_SphereGenerationShader_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SolarSystemProject_Plugins_ShadeupPlugin_Source_ComputeModule_Public_SphereGenerationShader_SphereGenerationShader_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
