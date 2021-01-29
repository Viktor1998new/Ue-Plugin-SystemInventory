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
	INVENTORY_API UFunction* Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_Inventory();
	INVENTORY_API UScriptStruct* Z_Construct_UScriptStruct_FInventorySlot();
	INVENTORY_API UScriptStruct* Z_Construct_UScriptStruct_FSlotTransformData();
	SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FMargin();
	SLATE_API UScriptStruct* Z_Construct_UScriptStruct_FAnchors();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	INVENTORY_API UClass* Z_Construct_UClass_UInventoryGridSlot_NoRegister();
	INVENTORY_API UClass* Z_Construct_UClass_UInventoryGridSlot();
	UMG_API UClass* Z_Construct_UClass_UPanelSlot();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics
	{
		struct _Script_Inventory_eventOnChangedSlot_Parms
		{
			int32 Index;
			FInventorySlot Slot;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Slot;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_Inventory_eventOnChangedSlot_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_Inventory_eventOnChangedSlot_Parms, Slot), Z_Construct_UScriptStruct_FInventorySlot, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::NewProp_Index,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::NewProp_Slot,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/**\n * The Slot for the UBorderSlot, contains the widget displayed in a border's single slot\n */" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
		{ "ToolTip", "The Slot for the UBorderSlot, contains the widget displayed in a border's single slot" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Inventory, nullptr, "OnChangedSlot__DelegateSignature", nullptr, nullptr, sizeof(_Script_Inventory_eventOnChangedSlot_Parms), Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Offsets_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Offsets;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Anchors_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Anchors;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Alignment_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Alignment;
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Offsets_MetaData[] = {
		{ "Category", "AnchorData" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Offsets = { "Offsets", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSlotTransformData, Offsets), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Offsets_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Offsets_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Anchors_MetaData[] = {
		{ "Category", "AnchorData" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Anchors = { "Anchors", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSlotTransformData, Anchors), Z_Construct_UScriptStruct_FAnchors, METADATA_PARAMS(Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Anchors_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Anchors_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Alignment_MetaData[] = {
		{ "Category", "AnchorData" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Alignment = { "Alignment", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSlotTransformData, Alignment), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Alignment_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Alignment_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSlotTransformData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Offsets,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Anchors,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Alignment,
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
	uint32 Get_Z_Construct_UScriptStruct_FSlotTransformData_Hash() { return 2618059104U; }
	void UInventoryGridSlot::StaticRegisterNativesUInventoryGridSlot()
	{
	}
	UClass* Z_Construct_UClass_UInventoryGridSlot_NoRegister()
	{
		return UInventoryGridSlot::StaticClass();
	}
	struct Z_Construct_UClass_UInventoryGridSlot_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Transform_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Transform;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IndexItem_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_IndexItem;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SlotPosition_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SlotPosition;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnChangedSlot_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnChangedSlot;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInventoryGridSlot_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPanelSlot,
		(UObject* (*)())Z_Construct_UPackage__Script_Inventory,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryGridSlot_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "InventoryUMG/InventoryGridSlot.h" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_Transform_MetaData[] = {
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_Transform = { "Transform", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryGridSlot, Transform), Z_Construct_UScriptStruct_FSlotTransformData, METADATA_PARAMS(Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_Transform_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_Transform_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_IndexItem_MetaData[] = {
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_IndexItem = { "IndexItem", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryGridSlot, IndexItem), METADATA_PARAMS(Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_IndexItem_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_IndexItem_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_SlotPosition_MetaData[] = {
		{ "Category", "InventoryGridSlot" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_SlotPosition = { "SlotPosition", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryGridSlot, SlotPosition), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_SlotPosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_SlotPosition_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_OnChangedSlot_MetaData[] = {
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_OnChangedSlot = { "OnChangedSlot", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryGridSlot, OnChangedSlot), Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_OnChangedSlot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_OnChangedSlot_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventoryGridSlot_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_Transform,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_IndexItem,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_SlotPosition,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_OnChangedSlot,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInventoryGridSlot_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryGridSlot>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UInventoryGridSlot_Statics::ClassParams = {
		&UInventoryGridSlot::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UInventoryGridSlot_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryGridSlot_Statics::PropPointers),
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
	IMPLEMENT_CLASS(UInventoryGridSlot, 841132077);
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
