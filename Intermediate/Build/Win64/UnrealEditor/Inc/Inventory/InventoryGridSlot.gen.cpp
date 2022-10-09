// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Inventory/Classes/InventoryUMG/InventoryGridSlot.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryGridSlot() {}
// Cross Module References
	INVENTORY_API UScriptStruct* Z_Construct_UScriptStruct_FSlotTransformData();
	UPackage* Z_Construct_UPackage__Script_Inventory();
	SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FMargin();
	SLATE_API UScriptStruct* Z_Construct_UScriptStruct_FAnchors();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	INVENTORY_API UFunction* Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature();
	INVENTORY_API UScriptStruct* Z_Construct_UScriptStruct_FInventorySlot();
	INVENTORY_API UClass* Z_Construct_UClass_UInventoryGridSlot_NoRegister();
	INVENTORY_API UClass* Z_Construct_UClass_UInventoryGridSlot();
	UMG_API UClass* Z_Construct_UClass_UPanelSlot();
	INVENTORY_API UClass* Z_Construct_UClass_UInventoryGrid_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SlotTransformData;
class UScriptStruct* FSlotTransformData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SlotTransformData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SlotTransformData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSlotTransformData, Z_Construct_UPackage__Script_Inventory(), TEXT("SlotTransformData"));
	}
	return Z_Registration_Info_UScriptStruct_SlotTransformData.OuterSingleton;
}
template<> INVENTORY_API UScriptStruct* StaticStruct<FSlotTransformData>()
{
	return FSlotTransformData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSlotTransformData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Offsets_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Offsets;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Anchors_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Anchors;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Alignment_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Alignment;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSlotTransformData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSlotTransformData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Offsets_MetaData[] = {
		{ "Category", "AnchorData" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Offsets = { "Offsets", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSlotTransformData, Offsets), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Offsets_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Offsets_MetaData)) }; // 451581171
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Anchors_MetaData[] = {
		{ "Category", "AnchorData" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Anchors = { "Anchors", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSlotTransformData, Anchors), Z_Construct_UScriptStruct_FAnchors, METADATA_PARAMS(Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Anchors_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Anchors_MetaData)) }; // 3608874910
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Alignment_MetaData[] = {
		{ "Category", "AnchorData" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Alignment = { "Alignment", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSlotTransformData, Alignment), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Alignment_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Alignment_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSlotTransformData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Offsets,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Anchors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewProp_Alignment,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSlotTransformData_Statics::ReturnStructParams = {
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
		if (!Z_Registration_Info_UScriptStruct_SlotTransformData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SlotTransformData.InnerSingleton, Z_Construct_UScriptStruct_FSlotTransformData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SlotTransformData.InnerSingleton;
	}
	struct Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics
	{
		struct _Script_Inventory_eventOnChangedSlot_Parms
		{
			int32 Index;
			FInventorySlot Slot;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Slot;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_Inventory_eventOnChangedSlot_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_Inventory_eventOnChangedSlot_Parms, Slot), Z_Construct_UScriptStruct_FInventorySlot, METADATA_PARAMS(nullptr, 0) }; // 2570169405
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::NewProp_Slot,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_Inventory, nullptr, "OnChangedSlot__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::_Script_Inventory_eventOnChangedSlot_Parms), Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	void UInventoryGridSlot::StaticRegisterNativesUInventoryGridSlot()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInventoryGridSlot);
	UClass* Z_Construct_UClass_UInventoryGridSlot_NoRegister()
	{
		return UInventoryGridSlot::StaticClass();
	}
	struct Z_Construct_UClass_UInventoryGridSlot_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ParentPanel_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ParentPanel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Transform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Transform;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IndexItem_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_IndexItem;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SlotPosition_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SlotPosition;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnChangedSlot_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnChangedSlot;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInventoryGridSlot_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPanelSlot,
		(UObject* (*)())Z_Construct_UPackage__Script_Inventory,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryGridSlot_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "InventoryUMG/InventoryGridSlot.h" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_ParentPanel_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_ParentPanel = { "ParentPanel", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryGridSlot, ParentPanel), Z_Construct_UClass_UInventoryGrid_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_ParentPanel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_ParentPanel_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_Transform_MetaData[] = {
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_Transform = { "Transform", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryGridSlot, Transform), Z_Construct_UScriptStruct_FSlotTransformData, METADATA_PARAMS(Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_Transform_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_Transform_MetaData)) }; // 1397175101
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_IndexItem_MetaData[] = {
		{ "Category", "InventoryGridSlot" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_IndexItem = { "IndexItem", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryGridSlot, IndexItem), METADATA_PARAMS(Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_IndexItem_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_IndexItem_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_SlotPosition_MetaData[] = {
		{ "Category", "InventoryGridSlot" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_SlotPosition = { "SlotPosition", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryGridSlot, SlotPosition), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_SlotPosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_SlotPosition_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_OnChangedSlot_MetaData[] = {
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGridSlot.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_OnChangedSlot = { "OnChangedSlot", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryGridSlot, OnChangedSlot), Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_OnChangedSlot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_OnChangedSlot_MetaData)) }; // 897207570
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventoryGridSlot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_ParentPanel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_Transform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_IndexItem,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_SlotPosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryGridSlot_Statics::NewProp_OnChangedSlot,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInventoryGridSlot_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryGridSlot>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventoryGridSlot_Statics::ClassParams = {
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
		if (!Z_Registration_Info_UClass_UInventoryGridSlot.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventoryGridSlot.OuterSingleton, Z_Construct_UClass_UInventoryGridSlot_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInventoryGridSlot.OuterSingleton;
	}
	template<> INVENTORY_API UClass* StaticClass<UInventoryGridSlot>()
	{
		return UInventoryGridSlot::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInventoryGridSlot);
	struct Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_Statics::ScriptStructInfo[] = {
		{ FSlotTransformData::StaticStruct, Z_Construct_UScriptStruct_FSlotTransformData_Statics::NewStructOps, TEXT("SlotTransformData"), &Z_Registration_Info_UScriptStruct_SlotTransformData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSlotTransformData), 1397175101U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInventoryGridSlot, UInventoryGridSlot::StaticClass, TEXT("UInventoryGridSlot"), &Z_Registration_Info_UClass_UInventoryGridSlot, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventoryGridSlot), 2852918877U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_3704423778(TEXT("/Script/Inventory"),
		Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
