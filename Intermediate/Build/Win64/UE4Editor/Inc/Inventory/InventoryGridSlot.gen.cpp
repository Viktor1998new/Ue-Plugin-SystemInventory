// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Inventory/Classes/InventoryUMG/InventoryGridSlot.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryGridSlot() {}
// Cross Module References
	INVENTORY_API UScriptStruct* Z_Construct_UScriptStruct_FSlotTransformData();
	UPackage* Z_Construct_UPackage__Script_Inventory();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	SLATE_API UScriptStruct* Z_Construct_UScriptStruct_FAnchors();
	SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FMargin();
	INVENTORY_API UClass* Z_Construct_UClass_UInventoryGridSlot_NoRegister();
	INVENTORY_API UClass* Z_Construct_UClass_UInventoryGridSlot();
	UMG_API UClass* Z_Construct_UClass_UPanelSlot();
	INVENTORY_API UScriptStruct* Z_Construct_UScriptStruct_FInventorySlot();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
// End Cross Module References
class UScriptStruct* FSlotTransformData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern INVENTORY_API uint32 Get_Z_Construct_UScriptStruct_FSlotTransformData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSlotTransformData, Z_Construct_UPackage__Script_Inventory(), TEXT("SlotTransformData"), sizeof(FSlotTransformData), Get_Z_Construct_UScriptStruct_FSlotTransformData_Hash());
	}
	return Singleton;
}
template<> INVENTORY_API UScriptStruct* StaticStruct<FSlotTransformData>()
{
	return FSlotTransformData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSlotTransformData(FSlotTransformData::StaticStruct, TEXT("/Script/Inventory"), TEXT("SlotTransformData"), false, nullptr, nullptr);
static struct FScriptStruct_Inventory_StaticRegisterNativesFSlotTransformData
{
	FScriptStruct_Inventory_StaticRegisterNativesFSlotTransformData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("SlotTransformData")),new UScriptStruct::TCppStructOps<FSlotTransformData>);
	}
} ScriptStruct_Inventory_StaticRegisterNativesFSlotTransformData;
	struct Z_Construct_UScriptStruct_FSlotTransformData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Alignment_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Alignment;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Anchors_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Anchors;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Offsets_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Offsets;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSlotTransformData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSlotTransformData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Alignment_MetaData[] = {
		{ "Category", "AnchorData" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Alignment = { "Alignment", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSlotTransformData, Alignment), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Alignment_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Alignment_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Anchors_MetaData[] = {
		{ "Category", "AnchorData" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Anchors = { "Anchors", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSlotTransformData, Anchors), Z_Construct_UScriptStruct_FAnchors, METADATA_PARAMS(Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Anchors_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Anchors_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Offsets_MetaData[] = {
		{ "Category", "AnchorData" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Offsets = { "Offsets", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSlotTransformData, Offsets), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Offsets_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Offsets_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSlotTransformData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Alignment,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Anchors,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Offsets,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSlotTransformData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Inventory,
		nullptr,
		&NewStructOps,
		"SlotTransformData",
		sizeof(FSlotTransformData),
		alignof(FSlotTransformData),
		Z_Construct_UScriptStruct_FSlotTransformData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSlotTransformData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSlotTransformData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSlotTransformData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSlotTransformData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSlotTransformData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_Inventory();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SlotTransformData"), sizeof(FSlotTransformData), Get_Z_Construct_UScriptStruct_FSlotTransformData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSlotTransformData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSlotTransformData_Hash() { return 570932166U; }
	DEFINE_FUNCTION(UInventoryGridSlot::execGetPosition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FIntPoint*)Z_Param__Result=P_THIS->GetPosition();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryGridSlot::execGetItemIndex)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetItemIndex();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryGridSlot::execGetDataSlot)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FInventorySlot*)Z_Param__Result=P_THIS->GetDataSlot();
		P_NATIVE_END;
	}
	void UInventoryGridSlot::StaticRegisterNativesUInventoryGridSlot()
	{
		UClass* Class = UInventoryGridSlot::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetDataSlot", &UInventoryGridSlot::execGetDataSlot },
			{ "GetItemIndex", &UInventoryGridSlot::execGetItemIndex },
			{ "GetPosition", &UInventoryGridSlot::execGetPosition },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInventoryGridSlot_GetDataSlot_Statics
	{
		struct InventoryGridSlot_eventGetDataSlot_Parms
		{
			FInventorySlot ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryGridSlot_GetDataSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryGridSlot_eventGetDataSlot_Parms, ReturnValue), Z_Construct_UScriptStruct_FInventorySlot, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryGridSlot_GetDataSlot_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryGridSlot_GetDataSlot_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryGridSlot_GetDataSlot_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryGridSlot_GetDataSlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryGridSlot, nullptr, "GetDataSlot", nullptr, nullptr, sizeof(InventoryGridSlot_eventGetDataSlot_Parms), Z_Construct_UFunction_UInventoryGridSlot_GetDataSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryGridSlot_GetDataSlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryGridSlot_GetDataSlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryGridSlot_GetDataSlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryGridSlot_GetDataSlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInventoryGridSlot_GetDataSlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryGridSlot_GetItemIndex_Statics
	{
		struct InventoryGridSlot_eventGetItemIndex_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryGridSlot_GetItemIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryGridSlot_eventGetItemIndex_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryGridSlot_GetItemIndex_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryGridSlot_GetItemIndex_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryGridSlot_GetItemIndex_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryGridSlot_GetItemIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryGridSlot, nullptr, "GetItemIndex", nullptr, nullptr, sizeof(InventoryGridSlot_eventGetItemIndex_Parms), Z_Construct_UFunction_UInventoryGridSlot_GetItemIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryGridSlot_GetItemIndex_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryGridSlot_GetItemIndex_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryGridSlot_GetItemIndex_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryGridSlot_GetItemIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInventoryGridSlot_GetItemIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryGridSlot_GetPosition_Statics
	{
		struct InventoryGridSlot_eventGetPosition_Parms
		{
			FIntPoint ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryGridSlot_GetPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryGridSlot_eventGetPosition_Parms, ReturnValue), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryGridSlot_GetPosition_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryGridSlot_GetPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryGridSlot_GetPosition_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryGridSlot_GetPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryGridSlot, nullptr, "GetPosition", nullptr, nullptr, sizeof(InventoryGridSlot_eventGetPosition_Parms), Z_Construct_UFunction_UInventoryGridSlot_GetPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryGridSlot_GetPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryGridSlot_GetPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryGridSlot_GetPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryGridSlot_GetPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInventoryGridSlot_GetPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UInventoryGridSlot_NoRegister()
	{
		return UInventoryGridSlot::StaticClass();
	}
	struct Z_Construct_UClass_UInventoryGridSlot_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInventoryGridSlot_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPanelSlot,
		(UObject* (*)())Z_Construct_UPackage__Script_Inventory,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UInventoryGridSlot_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventoryGridSlot_GetDataSlot, "GetDataSlot" }, // 212892036
		{ &Z_Construct_UFunction_UInventoryGridSlot_GetItemIndex, "GetItemIndex" }, // 197877454
		{ &Z_Construct_UFunction_UInventoryGridSlot_GetPosition, "GetPosition" }, // 2946962119
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryGridSlot_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * The Slot for the UBorderSlot, contains the widget displayed in a border's single slot\n */" },
		{ "IncludePath", "InventoryUMG/InventoryGridSlot.h" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
		{ "ToolTip", "The Slot for the UBorderSlot, contains the widget displayed in a border's single slot" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInventoryGridSlot_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryGridSlot>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UInventoryGridSlot_Statics::ClassParams = {
		&UInventoryGridSlot::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00B000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UInventoryGridSlot_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryGridSlot_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInventoryGridSlot()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UInventoryGridSlot_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UInventoryGridSlot, 299147595);
	template<> INVENTORY_API UClass* StaticClass<UInventoryGridSlot>()
	{
		return UInventoryGridSlot::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UInventoryGridSlot(Z_Construct_UClass_UInventoryGridSlot, &UInventoryGridSlot::StaticClass, TEXT("/Script/Inventory"), TEXT("UInventoryGridSlot"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInventoryGridSlot);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
