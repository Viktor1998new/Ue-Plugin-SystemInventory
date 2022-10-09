// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Inventory/Classes/Inventory/InventoryComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryComponent() {}
// Cross Module References
	INVENTORY_API UScriptStruct* Z_Construct_UScriptStruct_FInventorySlot();
	UPackage* Z_Construct_UPackage__Script_Inventory();
	INVENTORY_API UClass* Z_Construct_UClass_UItemAsset_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
	INVENTORY_API UScriptStruct* Z_Construct_UScriptStruct_FInventory();
	INVENTORY_API UEnum* Z_Construct_UEnum_Inventory_ETypeSetItem();
	INVENTORY_API UFunction* Z_Construct_UDelegateFunction_Inventory_OnAddItem__DelegateSignature();
	INVENTORY_API UFunction* Z_Construct_UDelegateFunction_Inventory_OnRemoveItem__DelegateSignature();
	INVENTORY_API UFunction* Z_Construct_UDelegateFunction_Inventory_NewDataSlot__DelegateSignature();
	INVENTORY_API UClass* Z_Construct_UClass_UInventoryComponent_NoRegister();
	INVENTORY_API UClass* Z_Construct_UClass_UInventoryComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	INVENTORY_API UClass* Z_Construct_UClass_AItemActor_NoRegister();
	INVENTORY_API UClass* Z_Construct_UClass_UInventorySettings_NoRegister();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_InventorySlot;
class UScriptStruct* FInventorySlot::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_InventorySlot.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_InventorySlot.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FInventorySlot, Z_Construct_UPackage__Script_Inventory(), TEXT("InventorySlot"));
	}
	return Z_Registration_Info_UScriptStruct_InventorySlot.OuterSingleton;
}
template<> INVENTORY_API UScriptStruct* StaticStruct<FInventorySlot>()
{
	return FInventorySlot::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FInventorySlot_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ItemAsset_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemAsset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PositionSlot_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_PositionSlot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ItemData_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ItemData;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Count_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Count;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventorySlot_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FInventorySlot_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FInventorySlot>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_ItemAsset_MetaData[] = {
		{ "Category", "InventorySlot" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_ItemAsset = { "ItemAsset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FInventorySlot, ItemAsset), Z_Construct_UClass_UItemAsset_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_ItemAsset_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_ItemAsset_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_PositionSlot_MetaData[] = {
		{ "Category", "InventorySlot" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_PositionSlot = { "PositionSlot", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FInventorySlot, PositionSlot), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_PositionSlot_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_PositionSlot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_ItemData_MetaData[] = {
		{ "Category", "InventorySlot" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_ItemData = { "ItemData", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FInventorySlot, ItemData), METADATA_PARAMS(Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_ItemData_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_ItemData_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_Count_MetaData[] = {
		{ "Category", "InventorySlot" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_Count = { "Count", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FInventorySlot, Count), METADATA_PARAMS(Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_Count_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_Count_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FInventorySlot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_ItemAsset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_PositionSlot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_ItemData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventorySlot_Statics::NewProp_Count,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FInventorySlot_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Inventory,
		nullptr,
		&NewStructOps,
		"InventorySlot",
		sizeof(FInventorySlot),
		alignof(FInventorySlot),
		Z_Construct_UScriptStruct_FInventorySlot_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventorySlot_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FInventorySlot_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventorySlot_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FInventorySlot()
	{
		if (!Z_Registration_Info_UScriptStruct_InventorySlot.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_InventorySlot.InnerSingleton, Z_Construct_UScriptStruct_FInventorySlot_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_InventorySlot.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_Inventory;
class UScriptStruct* FInventory::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_Inventory.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_Inventory.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FInventory, Z_Construct_UPackage__Script_Inventory(), TEXT("Inventory"));
	}
	return Z_Registration_Info_UScriptStruct_Inventory.OuterSingleton;
}
template<> INVENTORY_API UScriptStruct* StaticStruct<FInventory>()
{
	return FInventory::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FInventory_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructPropertyParams NewProp_Items_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Items_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Items;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Massa_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Massa;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxSlot_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_MaxSlot;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventory_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FInventory_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FInventory>();
	}
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FInventory_Statics::NewProp_Items_Inner = { "Items", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FInventorySlot, METADATA_PARAMS(nullptr, 0) }; // 2570169405
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventory_Statics::NewProp_Items_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FInventory_Statics::NewProp_Items = { "Items", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FInventory, Items), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FInventory_Statics::NewProp_Items_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventory_Statics::NewProp_Items_MetaData)) }; // 2570169405
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventory_Statics::NewProp_Massa_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FInventory_Statics::NewProp_Massa = { "Massa", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FInventory, Massa), METADATA_PARAMS(Z_Construct_UScriptStruct_FInventory_Statics::NewProp_Massa_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventory_Statics::NewProp_Massa_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FInventory_Statics::NewProp_MaxSlot_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FInventory_Statics::NewProp_MaxSlot = { "MaxSlot", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FInventory, MaxSlot), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(Z_Construct_UScriptStruct_FInventory_Statics::NewProp_MaxSlot_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventory_Statics::NewProp_MaxSlot_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FInventory_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventory_Statics::NewProp_Items_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventory_Statics::NewProp_Items,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventory_Statics::NewProp_Massa,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FInventory_Statics::NewProp_MaxSlot,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FInventory_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Inventory,
		nullptr,
		&NewStructOps,
		"Inventory",
		sizeof(FInventory),
		alignof(FInventory),
		Z_Construct_UScriptStruct_FInventory_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventory_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FInventory_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FInventory_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FInventory()
	{
		if (!Z_Registration_Info_UScriptStruct_Inventory.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_Inventory.InnerSingleton, Z_Construct_UScriptStruct_FInventory_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_Inventory.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ETypeSetItem;
	static UEnum* ETypeSetItem_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ETypeSetItem.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ETypeSetItem.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Inventory_ETypeSetItem, Z_Construct_UPackage__Script_Inventory(), TEXT("ETypeSetItem"));
		}
		return Z_Registration_Info_UEnum_ETypeSetItem.OuterSingleton;
	}
	template<> INVENTORY_API UEnum* StaticEnum<ETypeSetItem>()
	{
		return ETypeSetItem_StaticEnum();
	}
	struct Z_Construct_UEnum_Inventory_ETypeSetItem_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_Inventory_ETypeSetItem_Statics::Enumerators[] = {
		{ "Add", (int64)Add },
		{ "Remove", (int64)Remove },
		{ "ChangeSlot", (int64)ChangeSlot },
		{ "SetPosition", (int64)SetPosition },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Inventory_ETypeSetItem_Statics::Enum_MetaDataParams[] = {
		{ "Add.Name", "Add" },
		{ "ChangeSlot.Name", "ChangeSlot" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
		{ "Remove.Name", "Remove" },
		{ "SetPosition.Name", "SetPosition" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Inventory_ETypeSetItem_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_Inventory,
		nullptr,
		"ETypeSetItem",
		"ETypeSetItem",
		Z_Construct_UEnum_Inventory_ETypeSetItem_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_Inventory_ETypeSetItem_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(Z_Construct_UEnum_Inventory_ETypeSetItem_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_Inventory_ETypeSetItem_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_Inventory_ETypeSetItem()
	{
		if (!Z_Registration_Info_UEnum_ETypeSetItem.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ETypeSetItem.InnerSingleton, Z_Construct_UEnum_Inventory_ETypeSetItem_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ETypeSetItem.InnerSingleton;
	}
	struct Z_Construct_UDelegateFunction_Inventory_OnAddItem__DelegateSignature_Statics
	{
		struct _Script_Inventory_eventOnAddItem_Parms
		{
			int32 Index;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_Inventory_OnAddItem__DelegateSignature_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_Inventory_eventOnAddItem_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Inventory_OnAddItem__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Inventory_OnAddItem__DelegateSignature_Statics::NewProp_Index,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Inventory_OnAddItem__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Inventory_OnAddItem__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Inventory, nullptr, "OnAddItem__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_Inventory_OnAddItem__DelegateSignature_Statics::_Script_Inventory_eventOnAddItem_Parms), Z_Construct_UDelegateFunction_Inventory_OnAddItem__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Inventory_OnAddItem__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_Inventory_OnAddItem__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Inventory_OnAddItem__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_Inventory_OnAddItem__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Inventory_OnAddItem__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_Inventory_OnRemoveItem__DelegateSignature_Statics
	{
		struct _Script_Inventory_eventOnRemoveItem_Parms
		{
			int32 Index;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_Inventory_OnRemoveItem__DelegateSignature_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_Inventory_eventOnRemoveItem_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Inventory_OnRemoveItem__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Inventory_OnRemoveItem__DelegateSignature_Statics::NewProp_Index,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Inventory_OnRemoveItem__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Inventory_OnRemoveItem__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Inventory, nullptr, "OnRemoveItem__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_Inventory_OnRemoveItem__DelegateSignature_Statics::_Script_Inventory_eventOnRemoveItem_Parms), Z_Construct_UDelegateFunction_Inventory_OnRemoveItem__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Inventory_OnRemoveItem__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_Inventory_OnRemoveItem__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Inventory_OnRemoveItem__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_Inventory_OnRemoveItem__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Inventory_OnRemoveItem__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_Inventory_NewDataSlot__DelegateSignature_Statics
	{
		struct _Script_Inventory_eventNewDataSlot_Parms
		{
			int32 Index;
			FInventorySlot NewData;
			TEnumAsByte<ETypeSetItem> SetType;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FStructPropertyParams NewProp_NewData;
		static const UECodeGen_Private::FBytePropertyParams NewProp_SetType;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_Inventory_NewDataSlot__DelegateSignature_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_Inventory_eventNewDataSlot_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Inventory_NewDataSlot__DelegateSignature_Statics::NewProp_NewData = { "NewData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_Inventory_eventNewDataSlot_Parms, NewData), Z_Construct_UScriptStruct_FInventorySlot, METADATA_PARAMS(nullptr, 0) }; // 2570169405
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_Inventory_NewDataSlot__DelegateSignature_Statics::NewProp_SetType = { "SetType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_Inventory_eventNewDataSlot_Parms, SetType), Z_Construct_UEnum_Inventory_ETypeSetItem, METADATA_PARAMS(nullptr, 0) }; // 2442544145
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Inventory_NewDataSlot__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Inventory_NewDataSlot__DelegateSignature_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Inventory_NewDataSlot__DelegateSignature_Statics::NewProp_NewData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Inventory_NewDataSlot__DelegateSignature_Statics::NewProp_SetType,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Inventory_NewDataSlot__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Inventory_NewDataSlot__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Inventory, nullptr, "NewDataSlot__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_Inventory_NewDataSlot__DelegateSignature_Statics::_Script_Inventory_eventNewDataSlot_Parms), Z_Construct_UDelegateFunction_Inventory_NewDataSlot__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Inventory_NewDataSlot__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_Inventory_NewDataSlot__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Inventory_NewDataSlot__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_Inventory_NewDataSlot__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Inventory_NewDataSlot__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(UInventoryComponent::execClientRPC_EventSetItem)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_GET_STRUCT(FInventorySlot,Z_Param_NewData);
		P_GET_PROPERTY(FByteProperty,Z_Param_Type);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClientRPC_EventSetItem_Implementation(Z_Param_Index,Z_Param_NewData,ETypeSetItem(Z_Param_Type));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryComponent::execDropItem)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_IndexItem);
		P_GET_PROPERTY(FIntProperty,Z_Param_ToIndex);
		P_GET_PROPERTY(FIntProperty,Z_Param_Count);
		P_GET_STRUCT(FIntPoint,Z_Param_ToPosition);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->DropItem(Z_Param_IndexItem,Z_Param_ToIndex,Z_Param_Count,Z_Param_ToPosition);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryComponent::execIsPositionFree)
	{
		P_GET_STRUCT(FIntPoint,Z_Param_Position);
		P_GET_STRUCT(FIntPoint,Z_Param_Size);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsPositionFree(Z_Param_Position,Z_Param_Size,Z_Param_Out_Index);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryComponent::execSendItem)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_GET_OBJECT(UInventoryComponent,Z_Param_ToIntentory);
		P_GET_PROPERTY(FIntProperty,Z_Param_Count);
		P_GET_UBOOL(Z_Param_FindSlot);
		P_GET_STRUCT(FIntPoint,Z_Param_Position);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SendItem(Z_Param_Index,Z_Param_ToIntentory,Z_Param_Count,Z_Param_FindSlot,Z_Param_Position);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryComponent::execRemoveItem)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_GET_PROPERTY(FIntProperty,Z_Param_count);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->RemoveItem(Z_Param_Index,Z_Param_count);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryComponent::execFindItem)
	{
		P_GET_OBJECT(UItemAsset,Z_Param_ItemAsset);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->FindItem(Z_Param_ItemAsset,Z_Param_Out_Index);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryComponent::execFindFreeSlot)
	{
		P_GET_STRUCT(FIntPoint,Z_Param_Size);
		P_GET_STRUCT_REF(FIntPoint,Z_Param_Out_ReturnPosition);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->FindFreeSlot(Z_Param_Size,Z_Param_Out_ReturnPosition);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryComponent::execAddAssetItem)
	{
		P_GET_OBJECT(UItemAsset,Z_Param_ItemAsset);
		P_GET_PROPERTY(FIntProperty,Z_Param_Count);
		P_GET_PROPERTY(FStrProperty,Z_Param_Data);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->AddAssetItem(Z_Param_ItemAsset,Z_Param_Count,Z_Param_Data,Z_Param_Out_Index);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryComponent::execSetSlot)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_GET_STRUCT(FInventorySlot,Z_Param_NewValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SetSlot(Z_Param_Index,Z_Param_NewValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryComponent::execAddActorItem)
	{
		P_GET_OBJECT(AItemActor,Z_Param_Item);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->AddActorItem(Z_Param_Item,Z_Param_Out_Index);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryComponent::execAddSlot)
	{
		P_GET_STRUCT(FInventorySlot,Z_Param_NewSlot);
		P_GET_UBOOL(Z_Param_FindPositionSlot);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->AddSlot(Z_Param_NewSlot,Z_Param_FindPositionSlot,Z_Param_Out_Index);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryComponent::execGetInventory)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FInventory*)Z_Param__Result=P_THIS->GetInventory();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryComponent::execSetInventory)
	{
		P_GET_STRUCT(FInventory,Z_Param_NewInventory);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetInventory(Z_Param_NewInventory);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryComponent::execGetInventorySetting)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UInventorySettings**)Z_Param__Result=UInventoryComponent::GetInventorySetting();
		P_NATIVE_END;
	}
#if WITH_EDITOR
	DEFINE_FUNCTION(UInventoryComponent::execRecalculationMass)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RecalculationMass();
		P_NATIVE_END;
	}
#endif //WITH_EDITOR
	static FName NAME_UInventoryComponent_ClientRPC_EventSetItem = FName(TEXT("ClientRPC_EventSetItem"));
	void UInventoryComponent::ClientRPC_EventSetItem(int32 Index, FInventorySlot NewData, ETypeSetItem Type)
	{
		InventoryComponent_eventClientRPC_EventSetItem_Parms Parms;
		Parms.Index=Index;
		Parms.NewData=NewData;
		Parms.Type=Type;
		ProcessEvent(FindFunctionChecked(NAME_UInventoryComponent_ClientRPC_EventSetItem),&Parms);
	}
	void UInventoryComponent::StaticRegisterNativesUInventoryComponent()
	{
		UClass* Class = UInventoryComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddActorItem", &UInventoryComponent::execAddActorItem },
			{ "AddAssetItem", &UInventoryComponent::execAddAssetItem },
			{ "AddSlot", &UInventoryComponent::execAddSlot },
			{ "ClientRPC_EventSetItem", &UInventoryComponent::execClientRPC_EventSetItem },
			{ "DropItem", &UInventoryComponent::execDropItem },
			{ "FindFreeSlot", &UInventoryComponent::execFindFreeSlot },
			{ "FindItem", &UInventoryComponent::execFindItem },
			{ "GetInventory", &UInventoryComponent::execGetInventory },
			{ "GetInventorySetting", &UInventoryComponent::execGetInventorySetting },
			{ "IsPositionFree", &UInventoryComponent::execIsPositionFree },
#if WITH_EDITOR
			{ "RecalculationMass", &UInventoryComponent::execRecalculationMass },
#endif // WITH_EDITOR
			{ "RemoveItem", &UInventoryComponent::execRemoveItem },
			{ "SendItem", &UInventoryComponent::execSendItem },
			{ "SetInventory", &UInventoryComponent::execSetInventory },
			{ "SetSlot", &UInventoryComponent::execSetSlot },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInventoryComponent_AddActorItem_Statics
	{
		struct InventoryComponent_eventAddActorItem_Parms
		{
			AItemActor* Item;
			int32 Index;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Item;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryComponent_AddActorItem_Statics::NewProp_Item = { "Item", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventAddActorItem_Parms, Item), Z_Construct_UClass_AItemActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_AddActorItem_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventAddActorItem_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UInventoryComponent_AddActorItem_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((InventoryComponent_eventAddActorItem_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryComponent_AddActorItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(InventoryComponent_eventAddActorItem_Parms), &Z_Construct_UFunction_UInventoryComponent_AddActorItem_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_AddActorItem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_AddActorItem_Statics::NewProp_Item,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_AddActorItem_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_AddActorItem_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryComponent_AddActorItem_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*Adding an item\n\x09 Use only in Server*/" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
		{ "ToolTip", "Adding an item\n        Use only in Server" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_AddActorItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "AddActorItem", nullptr, nullptr, sizeof(Z_Construct_UFunction_UInventoryComponent_AddActorItem_Statics::InventoryComponent_eventAddActorItem_Parms), Z_Construct_UFunction_UInventoryComponent_AddActorItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_AddActorItem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryComponent_AddActorItem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_AddActorItem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryComponent_AddActorItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_AddActorItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics
	{
		struct InventoryComponent_eventAddAssetItem_Parms
		{
			UItemAsset* ItemAsset;
			int32 Count;
			FString Data;
			int32 Index;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemAsset;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Count;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Data_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Data;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::NewProp_ItemAsset = { "ItemAsset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventAddAssetItem_Parms, ItemAsset), Z_Construct_UClass_UItemAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::NewProp_Count = { "Count", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventAddAssetItem_Parms, Count), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::NewProp_Data_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventAddAssetItem_Parms, Data), METADATA_PARAMS(Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::NewProp_Data_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::NewProp_Data_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventAddAssetItem_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((InventoryComponent_eventAddAssetItem_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(InventoryComponent_eventAddAssetItem_Parms), &Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::NewProp_ItemAsset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::NewProp_Count,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::NewProp_Data,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*Adding an item\n\x09 Use only in Server*/" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
		{ "ToolTip", "Adding an item\n        Use only in Server" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "AddAssetItem", nullptr, nullptr, sizeof(Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::InventoryComponent_eventAddAssetItem_Parms), Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryComponent_AddAssetItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_AddAssetItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryComponent_AddSlot_Statics
	{
		struct InventoryComponent_eventAddSlot_Parms
		{
			FInventorySlot NewSlot;
			bool FindPositionSlot;
			int32 Index;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_NewSlot;
		static void NewProp_FindPositionSlot_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_FindPositionSlot;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryComponent_AddSlot_Statics::NewProp_NewSlot = { "NewSlot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventAddSlot_Parms, NewSlot), Z_Construct_UScriptStruct_FInventorySlot, METADATA_PARAMS(nullptr, 0) }; // 2570169405
	void Z_Construct_UFunction_UInventoryComponent_AddSlot_Statics::NewProp_FindPositionSlot_SetBit(void* Obj)
	{
		((InventoryComponent_eventAddSlot_Parms*)Obj)->FindPositionSlot = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryComponent_AddSlot_Statics::NewProp_FindPositionSlot = { "FindPositionSlot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(InventoryComponent_eventAddSlot_Parms), &Z_Construct_UFunction_UInventoryComponent_AddSlot_Statics::NewProp_FindPositionSlot_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_AddSlot_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventAddSlot_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UInventoryComponent_AddSlot_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((InventoryComponent_eventAddSlot_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryComponent_AddSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(InventoryComponent_eventAddSlot_Parms), &Z_Construct_UFunction_UInventoryComponent_AddSlot_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_AddSlot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_AddSlot_Statics::NewProp_NewSlot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_AddSlot_Statics::NewProp_FindPositionSlot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_AddSlot_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_AddSlot_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryComponent_AddSlot_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*Adding a slot\n\x09 * @param NewSlot - The new active state of the component\n\x09  Use only in Server*/" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
		{ "ToolTip", "Adding a slot\n        * @param NewSlot - The new active state of the component\n         Use only in Server" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_AddSlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "AddSlot", nullptr, nullptr, sizeof(Z_Construct_UFunction_UInventoryComponent_AddSlot_Statics::InventoryComponent_eventAddSlot_Parms), Z_Construct_UFunction_UInventoryComponent_AddSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_AddSlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryComponent_AddSlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_AddSlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryComponent_AddSlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_AddSlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryComponent_ClientRPC_EventSetItem_Statics
	{
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FStructPropertyParams NewProp_NewData;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Type;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_ClientRPC_EventSetItem_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventClientRPC_EventSetItem_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryComponent_ClientRPC_EventSetItem_Statics::NewProp_NewData = { "NewData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventClientRPC_EventSetItem_Parms, NewData), Z_Construct_UScriptStruct_FInventorySlot, METADATA_PARAMS(nullptr, 0) }; // 2570169405
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UInventoryComponent_ClientRPC_EventSetItem_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventClientRPC_EventSetItem_Parms, Type), Z_Construct_UEnum_Inventory_ETypeSetItem, METADATA_PARAMS(nullptr, 0) }; // 2442544145
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_ClientRPC_EventSetItem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_ClientRPC_EventSetItem_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_ClientRPC_EventSetItem_Statics::NewProp_NewData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_ClientRPC_EventSetItem_Statics::NewProp_Type,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryComponent_ClientRPC_EventSetItem_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_ClientRPC_EventSetItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "ClientRPC_EventSetItem", nullptr, nullptr, sizeof(InventoryComponent_eventClientRPC_EventSetItem_Parms), Z_Construct_UFunction_UInventoryComponent_ClientRPC_EventSetItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_ClientRPC_EventSetItem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryComponent_ClientRPC_EventSetItem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_ClientRPC_EventSetItem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryComponent_ClientRPC_EventSetItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_ClientRPC_EventSetItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryComponent_DropItem_Statics
	{
		struct InventoryComponent_eventDropItem_Parms
		{
			int32 IndexItem;
			int32 ToIndex;
			int32 Count;
			FIntPoint ToPosition;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_IndexItem;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ToIndex;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Count;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ToPosition;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_DropItem_Statics::NewProp_IndexItem = { "IndexItem", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventDropItem_Parms, IndexItem), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_DropItem_Statics::NewProp_ToIndex = { "ToIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventDropItem_Parms, ToIndex), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_DropItem_Statics::NewProp_Count = { "Count", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventDropItem_Parms, Count), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryComponent_DropItem_Statics::NewProp_ToPosition = { "ToPosition", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventDropItem_Parms, ToPosition), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UInventoryComponent_DropItem_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((InventoryComponent_eventDropItem_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryComponent_DropItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(InventoryComponent_eventDropItem_Parms), &Z_Construct_UFunction_UInventoryComponent_DropItem_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_DropItem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_DropItem_Statics::NewProp_IndexItem,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_DropItem_Statics::NewProp_ToIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_DropItem_Statics::NewProp_Count,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_DropItem_Statics::NewProp_ToPosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_DropItem_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryComponent_DropItem_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_DropItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "DropItem", nullptr, nullptr, sizeof(Z_Construct_UFunction_UInventoryComponent_DropItem_Statics::InventoryComponent_eventDropItem_Parms), Z_Construct_UFunction_UInventoryComponent_DropItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_DropItem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryComponent_DropItem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_DropItem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryComponent_DropItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_DropItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryComponent_FindFreeSlot_Statics
	{
		struct InventoryComponent_eventFindFreeSlot_Parms
		{
			FIntPoint Size;
			FIntPoint ReturnPosition;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Size;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnPosition;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryComponent_FindFreeSlot_Statics::NewProp_Size = { "Size", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventFindFreeSlot_Parms, Size), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryComponent_FindFreeSlot_Statics::NewProp_ReturnPosition = { "ReturnPosition", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventFindFreeSlot_Parms, ReturnPosition), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UInventoryComponent_FindFreeSlot_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((InventoryComponent_eventFindFreeSlot_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryComponent_FindFreeSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(InventoryComponent_eventFindFreeSlot_Parms), &Z_Construct_UFunction_UInventoryComponent_FindFreeSlot_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_FindFreeSlot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_FindFreeSlot_Statics::NewProp_Size,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_FindFreeSlot_Statics::NewProp_ReturnPosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_FindFreeSlot_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryComponent_FindFreeSlot_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*The function for searching for free space and can also be used to check whether the slot fits into the inventory */" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
		{ "ToolTip", "The function for searching for free space and can also be used to check whether the slot fits into the inventory" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_FindFreeSlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "FindFreeSlot", nullptr, nullptr, sizeof(Z_Construct_UFunction_UInventoryComponent_FindFreeSlot_Statics::InventoryComponent_eventFindFreeSlot_Parms), Z_Construct_UFunction_UInventoryComponent_FindFreeSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_FindFreeSlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryComponent_FindFreeSlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_FindFreeSlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryComponent_FindFreeSlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_FindFreeSlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryComponent_FindItem_Statics
	{
		struct InventoryComponent_eventFindItem_Parms
		{
			UItemAsset* ItemAsset;
			int32 Index;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemAsset;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryComponent_FindItem_Statics::NewProp_ItemAsset = { "ItemAsset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventFindItem_Parms, ItemAsset), Z_Construct_UClass_UItemAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_FindItem_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventFindItem_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UInventoryComponent_FindItem_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((InventoryComponent_eventFindItem_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryComponent_FindItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(InventoryComponent_eventFindItem_Parms), &Z_Construct_UFunction_UInventoryComponent_FindItem_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_FindItem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_FindItem_Statics::NewProp_ItemAsset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_FindItem_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_FindItem_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryComponent_FindItem_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*search function for an item by class or class child*/" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
		{ "ToolTip", "search function for an item by class or class child" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_FindItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "FindItem", nullptr, nullptr, sizeof(Z_Construct_UFunction_UInventoryComponent_FindItem_Statics::InventoryComponent_eventFindItem_Parms), Z_Construct_UFunction_UInventoryComponent_FindItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_FindItem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryComponent_FindItem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_FindItem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryComponent_FindItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_FindItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryComponent_GetInventory_Statics
	{
		struct InventoryComponent_eventGetInventory_Parms
		{
			FInventory ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryComponent_GetInventory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventGetInventory_Parms, ReturnValue), Z_Construct_UScriptStruct_FInventory, METADATA_PARAMS(nullptr, 0) }; // 2547612215
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_GetInventory_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_GetInventory_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryComponent_GetInventory_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_GetInventory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "GetInventory", nullptr, nullptr, sizeof(Z_Construct_UFunction_UInventoryComponent_GetInventory_Statics::InventoryComponent_eventGetInventory_Parms), Z_Construct_UFunction_UInventoryComponent_GetInventory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_GetInventory_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryComponent_GetInventory_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_GetInventory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryComponent_GetInventory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_GetInventory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryComponent_GetInventorySetting_Statics
	{
		struct InventoryComponent_eventGetInventorySetting_Parms
		{
			UInventorySettings* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryComponent_GetInventorySetting_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventGetInventorySetting_Parms, ReturnValue), Z_Construct_UClass_UInventorySettings_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_GetInventorySetting_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_GetInventorySetting_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryComponent_GetInventorySetting_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_GetInventorySetting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "GetInventorySetting", nullptr, nullptr, sizeof(Z_Construct_UFunction_UInventoryComponent_GetInventorySetting_Statics::InventoryComponent_eventGetInventorySetting_Parms), Z_Construct_UFunction_UInventoryComponent_GetInventorySetting_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_GetInventorySetting_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryComponent_GetInventorySetting_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_GetInventorySetting_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryComponent_GetInventorySetting()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_GetInventorySetting_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryComponent_IsPositionFree_Statics
	{
		struct InventoryComponent_eventIsPositionFree_Parms
		{
			FIntPoint Position;
			FIntPoint Size;
			int32 Index;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Size;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryComponent_IsPositionFree_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventIsPositionFree_Parms, Position), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryComponent_IsPositionFree_Statics::NewProp_Size = { "Size", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventIsPositionFree_Parms, Size), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_IsPositionFree_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventIsPositionFree_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UInventoryComponent_IsPositionFree_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((InventoryComponent_eventIsPositionFree_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryComponent_IsPositionFree_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(InventoryComponent_eventIsPositionFree_Parms), &Z_Construct_UFunction_UInventoryComponent_IsPositionFree_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_IsPositionFree_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_IsPositionFree_Statics::NewProp_Position,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_IsPositionFree_Statics::NewProp_Size,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_IsPositionFree_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_IsPositionFree_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryComponent_IsPositionFree_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*the function checks whether the element can be placed in this position*/" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
		{ "ToolTip", "the function checks whether the element can be placed in this position" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_IsPositionFree_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "IsPositionFree", nullptr, nullptr, sizeof(Z_Construct_UFunction_UInventoryComponent_IsPositionFree_Statics::InventoryComponent_eventIsPositionFree_Parms), Z_Construct_UFunction_UInventoryComponent_IsPositionFree_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_IsPositionFree_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryComponent_IsPositionFree_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_IsPositionFree_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryComponent_IsPositionFree()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_IsPositionFree_Statics::FuncParams);
		}
		return ReturnFunction;
	}
#if WITH_EDITOR
	struct Z_Construct_UFunction_UInventoryComponent_RecalculationMass_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryComponent_RecalculationMass_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// Only Edit\n" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
		{ "ToolTip", "Only Edit" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_RecalculationMass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "RecalculationMass", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x24020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryComponent_RecalculationMass_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_RecalculationMass_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryComponent_RecalculationMass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_RecalculationMass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
#endif //WITH_EDITOR
	struct Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics
	{
		struct InventoryComponent_eventRemoveItem_Parms
		{
			int32 Index;
			int32 count;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FIntPropertyParams NewProp_count;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventRemoveItem_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::NewProp_count = { "count", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventRemoveItem_Parms, count), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((InventoryComponent_eventRemoveItem_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(InventoryComponent_eventRemoveItem_Parms), &Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::NewProp_count,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*Removing an item\n\x09 Use only in Server*/" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
		{ "ToolTip", "Removing an item\n        Use only in Server" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "RemoveItem", nullptr, nullptr, sizeof(Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::InventoryComponent_eventRemoveItem_Parms), Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryComponent_RemoveItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_RemoveItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryComponent_SendItem_Statics
	{
		struct InventoryComponent_eventSendItem_Parms
		{
			int32 Index;
			UInventoryComponent* ToIntentory;
			int32 Count;
			bool FindSlot;
			FIntPoint Position;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ToIntentory_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ToIntentory;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Count;
		static void NewProp_FindSlot_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_FindSlot;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventSendItem_Parms, Index), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::NewProp_ToIntentory_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::NewProp_ToIntentory = { "ToIntentory", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventSendItem_Parms, ToIntentory), Z_Construct_UClass_UInventoryComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::NewProp_ToIntentory_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::NewProp_ToIntentory_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::NewProp_Count = { "Count", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventSendItem_Parms, Count), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::NewProp_FindSlot_SetBit(void* Obj)
	{
		((InventoryComponent_eventSendItem_Parms*)Obj)->FindSlot = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::NewProp_FindSlot = { "FindSlot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(InventoryComponent_eventSendItem_Parms), &Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::NewProp_FindSlot_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventSendItem_Parms, Position), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((InventoryComponent_eventSendItem_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(InventoryComponent_eventSendItem_Parms), &Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::NewProp_ToIntentory,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::NewProp_Count,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::NewProp_FindSlot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::NewProp_Position,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*the function sends an item from the current inventory to another one\n\x09 Use only in Server*/" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
		{ "ToolTip", "the function sends an item from the current inventory to another one\n        Use only in Server" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "SendItem", nullptr, nullptr, sizeof(Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::InventoryComponent_eventSendItem_Parms), Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryComponent_SendItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_SendItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryComponent_SetInventory_Statics
	{
		struct InventoryComponent_eventSetInventory_Parms
		{
			FInventory NewInventory;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_NewInventory;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryComponent_SetInventory_Statics::NewProp_NewInventory = { "NewInventory", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventSetInventory_Parms, NewInventory), Z_Construct_UScriptStruct_FInventory, METADATA_PARAMS(nullptr, 0) }; // 2547612215
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_SetInventory_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_SetInventory_Statics::NewProp_NewInventory,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryComponent_SetInventory_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_SetInventory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "SetInventory", nullptr, nullptr, sizeof(Z_Construct_UFunction_UInventoryComponent_SetInventory_Statics::InventoryComponent_eventSetInventory_Parms), Z_Construct_UFunction_UInventoryComponent_SetInventory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_SetInventory_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryComponent_SetInventory_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_SetInventory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryComponent_SetInventory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_SetInventory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryComponent_SetSlot_Statics
	{
		struct InventoryComponent_eventSetSlot_Parms
		{
			int32 Index;
			FInventorySlot NewValue;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FStructPropertyParams NewProp_NewValue;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryComponent_SetSlot_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventSetSlot_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryComponent_SetSlot_Statics::NewProp_NewValue = { "NewValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryComponent_eventSetSlot_Parms, NewValue), Z_Construct_UScriptStruct_FInventorySlot, METADATA_PARAMS(nullptr, 0) }; // 2570169405
	void Z_Construct_UFunction_UInventoryComponent_SetSlot_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((InventoryComponent_eventSetSlot_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInventoryComponent_SetSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(InventoryComponent_eventSetSlot_Parms), &Z_Construct_UFunction_UInventoryComponent_SetSlot_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryComponent_SetSlot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_SetSlot_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_SetSlot_Statics::NewProp_NewValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryComponent_SetSlot_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryComponent_SetSlot_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*Adding an item\n\x09 Use only in Server*/" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
		{ "ToolTip", "Adding an item\n        Use only in Server" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryComponent_SetSlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryComponent, nullptr, "SetSlot", nullptr, nullptr, sizeof(Z_Construct_UFunction_UInventoryComponent_SetSlot_Statics::InventoryComponent_eventSetSlot_Parms), Z_Construct_UFunction_UInventoryComponent_SetSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_SetSlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryComponent_SetSlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryComponent_SetSlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryComponent_SetSlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInventoryComponent_SetSlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInventoryComponent);
	UClass* Z_Construct_UClass_UInventoryComponent_NoRegister()
	{
		return UInventoryComponent::StaticClass();
	}
	struct Z_Construct_UClass_UInventoryComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Items_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Items_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Items;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentMassa_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentMassa;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxSlot_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_MaxSlot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnAddItem_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAddItem;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnRemoveItem_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnRemoveItem;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInventoryComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_Inventory,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UInventoryComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventoryComponent_AddActorItem, "AddActorItem" }, // 588713273
		{ &Z_Construct_UFunction_UInventoryComponent_AddAssetItem, "AddAssetItem" }, // 3670229327
		{ &Z_Construct_UFunction_UInventoryComponent_AddSlot, "AddSlot" }, // 755385923
		{ &Z_Construct_UFunction_UInventoryComponent_ClientRPC_EventSetItem, "ClientRPC_EventSetItem" }, // 2041976395
		{ &Z_Construct_UFunction_UInventoryComponent_DropItem, "DropItem" }, // 461172873
		{ &Z_Construct_UFunction_UInventoryComponent_FindFreeSlot, "FindFreeSlot" }, // 2431132944
		{ &Z_Construct_UFunction_UInventoryComponent_FindItem, "FindItem" }, // 2148675702
		{ &Z_Construct_UFunction_UInventoryComponent_GetInventory, "GetInventory" }, // 2941643593
		{ &Z_Construct_UFunction_UInventoryComponent_GetInventorySetting, "GetInventorySetting" }, // 4245309300
		{ &Z_Construct_UFunction_UInventoryComponent_IsPositionFree, "IsPositionFree" }, // 1792633612
#if WITH_EDITOR
		{ &Z_Construct_UFunction_UInventoryComponent_RecalculationMass, "RecalculationMass" }, // 1334671384
#endif //WITH_EDITOR
		{ &Z_Construct_UFunction_UInventoryComponent_RemoveItem, "RemoveItem" }, // 4104151082
		{ &Z_Construct_UFunction_UInventoryComponent_SendItem, "SendItem" }, // 2406183436
		{ &Z_Construct_UFunction_UInventoryComponent_SetInventory, "SetInventory" }, // 1360831228
		{ &Z_Construct_UFunction_UInventoryComponent_SetSlot, "SetSlot" }, // 1000965482
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Inventory/InventoryComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UInventoryComponent_Statics::NewProp_Items_Inner = { "Items", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FInventorySlot, METADATA_PARAMS(nullptr, 0) }; // 2570169405
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryComponent_Statics::NewProp_Items_MetaData[] = {
		{ "Category", "InventoryComponent" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UInventoryComponent_Statics::NewProp_Items = { "Items", nullptr, (EPropertyFlags)0x0010000000000835, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryComponent, Items), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UInventoryComponent_Statics::NewProp_Items_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponent_Statics::NewProp_Items_MetaData)) }; // 2570169405
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryComponent_Statics::NewProp_CurrentMassa_MetaData[] = {
		{ "Category", "InventoryComponent" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UInventoryComponent_Statics::NewProp_CurrentMassa = { "CurrentMassa", nullptr, (EPropertyFlags)0x0010000000020835, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryComponent, CurrentMassa), METADATA_PARAMS(Z_Construct_UClass_UInventoryComponent_Statics::NewProp_CurrentMassa_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponent_Statics::NewProp_CurrentMassa_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryComponent_Statics::NewProp_MaxSlot_MetaData[] = {
		{ "Category", "InventoryComponent" },
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UInventoryComponent_Statics::NewProp_MaxSlot = { "MaxSlot", nullptr, (EPropertyFlags)0x0010000000000025, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryComponent, MaxSlot), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(Z_Construct_UClass_UInventoryComponent_Statics::NewProp_MaxSlot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponent_Statics::NewProp_MaxSlot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnAddItem_MetaData[] = {
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnAddItem = { "OnAddItem", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryComponent, OnAddItem), Z_Construct_UDelegateFunction_Inventory_OnAddItem__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnAddItem_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnAddItem_MetaData)) }; // 814311692
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnRemoveItem_MetaData[] = {
		{ "ModuleRelativePath", "Classes/Inventory/InventoryComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnRemoveItem = { "OnRemoveItem", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryComponent, OnRemoveItem), Z_Construct_UDelegateFunction_Inventory_OnRemoveItem__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnRemoveItem_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnRemoveItem_MetaData)) }; // 3941192966
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventoryComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryComponent_Statics::NewProp_Items_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryComponent_Statics::NewProp_Items,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryComponent_Statics::NewProp_CurrentMassa,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryComponent_Statics::NewProp_MaxSlot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnAddItem,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryComponent_Statics::NewProp_OnRemoveItem,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInventoryComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventoryComponent_Statics::ClassParams = {
		&UInventoryComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UInventoryComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UInventoryComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInventoryComponent()
	{
		if (!Z_Registration_Info_UClass_UInventoryComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventoryComponent.OuterSingleton, Z_Construct_UClass_UInventoryComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInventoryComponent.OuterSingleton;
	}
	template<> INVENTORY_API UClass* StaticClass<UInventoryComponent>()
	{
		return UInventoryComponent::StaticClass();
	}

	void UInventoryComponent::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
	{
		static const FName Name_Items(TEXT("Items"));
		static const FName Name_CurrentMassa(TEXT("CurrentMassa"));
		static const FName Name_MaxSlot(TEXT("MaxSlot"));

		const bool bIsValid = true
			&& Name_Items == ClassReps[(int32)ENetFields_Private::Items].Property->GetFName()
			&& Name_CurrentMassa == ClassReps[(int32)ENetFields_Private::CurrentMassa].Property->GetFName()
			&& Name_MaxSlot == ClassReps[(int32)ENetFields_Private::MaxSlot].Property->GetFName();

		checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in UInventoryComponent"));
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInventoryComponent);
	struct Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_Statics::EnumInfo[] = {
		{ ETypeSetItem_StaticEnum, TEXT("ETypeSetItem"), &Z_Registration_Info_UEnum_ETypeSetItem, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2442544145U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_Statics::ScriptStructInfo[] = {
		{ FInventorySlot::StaticStruct, Z_Construct_UScriptStruct_FInventorySlot_Statics::NewStructOps, TEXT("InventorySlot"), &Z_Registration_Info_UScriptStruct_InventorySlot, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FInventorySlot), 2570169405U) },
		{ FInventory::StaticStruct, Z_Construct_UScriptStruct_FInventory_Statics::NewStructOps, TEXT("Inventory"), &Z_Registration_Info_UScriptStruct_Inventory, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FInventory), 2547612215U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInventoryComponent, UInventoryComponent::StaticClass, TEXT("UInventoryComponent"), &Z_Registration_Info_UClass_UInventoryComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventoryComponent), 725528333U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_2859103560(TEXT("/Script/Inventory"),
		Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
