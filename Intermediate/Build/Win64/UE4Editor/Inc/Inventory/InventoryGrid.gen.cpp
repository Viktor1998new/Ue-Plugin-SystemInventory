// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Inventory/Classes/InventoryUMG/InventoryGrid.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryGrid() {}
// Cross Module References
	INVENTORY_API UClass* Z_Construct_UClass_UInventoryGrid_NoRegister();
	INVENTORY_API UClass* Z_Construct_UClass_UInventoryGrid();
	UMG_API UClass* Z_Construct_UClass_UPanelWidget();
	UPackage* Z_Construct_UPackage__Script_Inventory();
	INVENTORY_API UScriptStruct* Z_Construct_UScriptStruct_FInventorySlot();
	INVENTORY_API UEnum* Z_Construct_UEnum_Inventory_ETypeSetItem();
	INVENTORY_API UClass* Z_Construct_UClass_UInventoryComponent_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UWidget_NoRegister();
	INVENTORY_API UClass* Z_Construct_UClass_UInventoryGridSlot_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UInventoryGrid::execEvent_NewDataSlot)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_GET_STRUCT(FInventorySlot,Z_Param_NewData);
		P_GET_PROPERTY(FByteProperty,Z_Param_Type);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Event_NewDataSlot(Z_Param_Index,Z_Param_NewData,ETypeSetItem(Z_Param_Type));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryGrid::execGetSlotAtItem)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_ItemIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetSlotAtItem(Z_Param_ItemIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryGrid::execGetInventory)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UInventoryComponent**)Z_Param__Result=P_THIS->GetInventory();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryGrid::execSlotAsInventorySlot)
	{
		P_GET_OBJECT(UWidget,Z_Param_Widget);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UInventoryGridSlot**)Z_Param__Result=UInventoryGrid::SlotAsInventorySlot(Z_Param_Widget);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryGrid::execSetInventory)
	{
		P_GET_OBJECT(UInventoryComponent,Z_Param_NewInventory);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetInventory(Z_Param_NewInventory);
		P_NATIVE_END;
	}
	void UInventoryGrid::StaticRegisterNativesUInventoryGrid()
	{
		UClass* Class = UInventoryGrid::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Event_NewDataSlot", &UInventoryGrid::execEvent_NewDataSlot },
			{ "GetInventory", &UInventoryGrid::execGetInventory },
			{ "GetSlotAtItem", &UInventoryGrid::execGetSlotAtItem },
			{ "SetInventory", &UInventoryGrid::execSetInventory },
			{ "SlotAsInventorySlot", &UInventoryGrid::execSlotAsInventorySlot },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInventoryGrid_Event_NewDataSlot_Statics
	{
		struct InventoryGrid_eventEvent_NewDataSlot_Parms
		{
			int32 Index;
			FInventorySlot NewData;
			TEnumAsByte<ETypeSetItem> Type;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_NewData;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Type;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryGrid_Event_NewDataSlot_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryGrid_eventEvent_NewDataSlot_Parms, Index), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInventoryGrid_Event_NewDataSlot_Statics::NewProp_NewData = { "NewData", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryGrid_eventEvent_NewDataSlot_Parms, NewData), Z_Construct_UScriptStruct_FInventorySlot, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UInventoryGrid_Event_NewDataSlot_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryGrid_eventEvent_NewDataSlot_Parms, Type), Z_Construct_UEnum_Inventory_ETypeSetItem, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryGrid_Event_NewDataSlot_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryGrid_Event_NewDataSlot_Statics::NewProp_Index,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryGrid_Event_NewDataSlot_Statics::NewProp_NewData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryGrid_Event_NewDataSlot_Statics::NewProp_Type,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryGrid_Event_NewDataSlot_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryGrid_Event_NewDataSlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryGrid, nullptr, "Event_NewDataSlot", nullptr, nullptr, sizeof(InventoryGrid_eventEvent_NewDataSlot_Parms), Z_Construct_UFunction_UInventoryGrid_Event_NewDataSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryGrid_Event_NewDataSlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryGrid_Event_NewDataSlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryGrid_Event_NewDataSlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryGrid_Event_NewDataSlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInventoryGrid_Event_NewDataSlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryGrid_GetInventory_Statics
	{
		struct InventoryGrid_eventGetInventory_Parms
		{
			UInventoryComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryGrid_GetInventory_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryGrid_GetInventory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryGrid_eventGetInventory_Parms, ReturnValue), Z_Construct_UClass_UInventoryComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UInventoryGrid_GetInventory_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryGrid_GetInventory_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryGrid_GetInventory_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryGrid_GetInventory_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryGrid_GetInventory_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryGrid_GetInventory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryGrid, nullptr, "GetInventory", nullptr, nullptr, sizeof(InventoryGrid_eventGetInventory_Parms), Z_Construct_UFunction_UInventoryGrid_GetInventory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryGrid_GetInventory_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryGrid_GetInventory_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryGrid_GetInventory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryGrid_GetInventory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInventoryGrid_GetInventory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryGrid_GetSlotAtItem_Statics
	{
		struct InventoryGrid_eventGetSlotAtItem_Parms
		{
			int32 ItemIndex;
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ItemIndex;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryGrid_GetSlotAtItem_Statics::NewProp_ItemIndex = { "ItemIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryGrid_eventGetSlotAtItem_Parms, ItemIndex), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInventoryGrid_GetSlotAtItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryGrid_eventGetSlotAtItem_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryGrid_GetSlotAtItem_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryGrid_GetSlotAtItem_Statics::NewProp_ItemIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryGrid_GetSlotAtItem_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryGrid_GetSlotAtItem_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryGrid_GetSlotAtItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryGrid, nullptr, "GetSlotAtItem", nullptr, nullptr, sizeof(InventoryGrid_eventGetSlotAtItem_Parms), Z_Construct_UFunction_UInventoryGrid_GetSlotAtItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryGrid_GetSlotAtItem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryGrid_GetSlotAtItem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryGrid_GetSlotAtItem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryGrid_GetSlotAtItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInventoryGrid_GetSlotAtItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryGrid_SetInventory_Statics
	{
		struct InventoryGrid_eventSetInventory_Parms
		{
			UInventoryComponent* NewInventory;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NewInventory_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NewInventory;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryGrid_SetInventory_Statics::NewProp_NewInventory_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryGrid_SetInventory_Statics::NewProp_NewInventory = { "NewInventory", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryGrid_eventSetInventory_Parms, NewInventory), Z_Construct_UClass_UInventoryComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UInventoryGrid_SetInventory_Statics::NewProp_NewInventory_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryGrid_SetInventory_Statics::NewProp_NewInventory_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryGrid_SetInventory_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryGrid_SetInventory_Statics::NewProp_NewInventory,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryGrid_SetInventory_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryGrid_SetInventory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryGrid, nullptr, "SetInventory", nullptr, nullptr, sizeof(InventoryGrid_eventSetInventory_Parms), Z_Construct_UFunction_UInventoryGrid_SetInventory_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryGrid_SetInventory_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryGrid_SetInventory_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryGrid_SetInventory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryGrid_SetInventory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInventoryGrid_SetInventory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryGrid_SlotAsInventorySlot_Statics
	{
		struct InventoryGrid_eventSlotAsInventorySlot_Parms
		{
			UWidget* Widget;
			UInventoryGridSlot* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Widget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Widget;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryGrid_SlotAsInventorySlot_Statics::NewProp_Widget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryGrid_SlotAsInventorySlot_Statics::NewProp_Widget = { "Widget", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryGrid_eventSlotAsInventorySlot_Parms, Widget), Z_Construct_UClass_UWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UInventoryGrid_SlotAsInventorySlot_Statics::NewProp_Widget_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryGrid_SlotAsInventorySlot_Statics::NewProp_Widget_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryGrid_SlotAsInventorySlot_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInventoryGrid_SlotAsInventorySlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryGrid_eventSlotAsInventorySlot_Parms, ReturnValue), Z_Construct_UClass_UInventoryGridSlot_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UInventoryGrid_SlotAsInventorySlot_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryGrid_SlotAsInventorySlot_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryGrid_SlotAsInventorySlot_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryGrid_SlotAsInventorySlot_Statics::NewProp_Widget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryGrid_SlotAsInventorySlot_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryGrid_SlotAsInventorySlot_Statics::Function_MetaDataParams[] = {
		{ "Category", "Slot" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryGrid_SlotAsInventorySlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryGrid, nullptr, "SlotAsInventorySlot", nullptr, nullptr, sizeof(InventoryGrid_eventSlotAsInventorySlot_Parms), Z_Construct_UFunction_UInventoryGrid_SlotAsInventorySlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryGrid_SlotAsInventorySlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryGrid_SlotAsInventorySlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryGrid_SlotAsInventorySlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryGrid_SlotAsInventorySlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInventoryGrid_SlotAsInventorySlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UInventoryGrid_NoRegister()
	{
		return UInventoryGrid::StaticClass();
	}
	struct Z_Construct_UClass_UInventoryGrid_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemSlots_Inner_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ItemSlots_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemSlots_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ItemSlots;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ContentItemSlot_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ContentItemSlot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ContentNoneSlot_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ContentNoneSlot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SizeSlot_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SizeSlot;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInventoryGrid_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPanelWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_Inventory,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UInventoryGrid_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventoryGrid_Event_NewDataSlot, "Event_NewDataSlot" }, // 1464863420
		{ &Z_Construct_UFunction_UInventoryGrid_GetInventory, "GetInventory" }, // 514349697
		{ &Z_Construct_UFunction_UInventoryGrid_GetSlotAtItem, "GetSlotAtItem" }, // 1473815355
		{ &Z_Construct_UFunction_UInventoryGrid_SetInventory, "SetInventory" }, // 3470154787
		{ &Z_Construct_UFunction_UInventoryGrid_SlotAsInventorySlot, "SlotAsInventorySlot" }, // 311312809
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryGrid_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "InventoryUMG/InventoryGrid.h" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGrid.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryGrid_Statics::NewProp_ItemSlots_Inner_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UInventoryGrid_Statics::NewProp_ItemSlots_Inner = { "ItemSlots", nullptr, (EPropertyFlags)0x0002000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UInventoryGridSlot_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UInventoryGrid_Statics::NewProp_ItemSlots_Inner_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryGrid_Statics::NewProp_ItemSlots_Inner_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryGrid_Statics::NewProp_ItemSlots_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UInventoryGrid_Statics::NewProp_ItemSlots = { "ItemSlots", nullptr, (EPropertyFlags)0x0010008000000008, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryGrid, ItemSlots), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UInventoryGrid_Statics::NewProp_ItemSlots_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryGrid_Statics::NewProp_ItemSlots_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryGrid_Statics::NewProp_ContentItemSlot_MetaData[] = {
		{ "Category", "InventoryGrid" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UInventoryGrid_Statics::NewProp_ContentItemSlot = { "ContentItemSlot", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryGrid, ContentItemSlot), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UInventoryGrid_Statics::NewProp_ContentItemSlot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryGrid_Statics::NewProp_ContentItemSlot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryGrid_Statics::NewProp_ContentNoneSlot_MetaData[] = {
		{ "Category", "InventoryGrid" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UInventoryGrid_Statics::NewProp_ContentNoneSlot = { "ContentNoneSlot", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryGrid, ContentNoneSlot), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UInventoryGrid_Statics::NewProp_ContentNoneSlot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryGrid_Statics::NewProp_ContentNoneSlot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryGrid_Statics::NewProp_SizeSlot_MetaData[] = {
		{ "Category", "InventoryGrid" },
		{ "ModuleRelativePath", "Classes/InventoryUMG/InventoryGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UInventoryGrid_Statics::NewProp_SizeSlot = { "SizeSlot", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventoryGrid, SizeSlot), METADATA_PARAMS(Z_Construct_UClass_UInventoryGrid_Statics::NewProp_SizeSlot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryGrid_Statics::NewProp_SizeSlot_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventoryGrid_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryGrid_Statics::NewProp_ItemSlots_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryGrid_Statics::NewProp_ItemSlots,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryGrid_Statics::NewProp_ContentItemSlot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryGrid_Statics::NewProp_ContentNoneSlot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventoryGrid_Statics::NewProp_SizeSlot,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInventoryGrid_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryGrid>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UInventoryGrid_Statics::ClassParams = {
		&UInventoryGrid::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UInventoryGrid_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryGrid_Statics::PropPointers),
		0,
		0x00B000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UInventoryGrid_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryGrid_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInventoryGrid()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UInventoryGrid_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UInventoryGrid, 4262066923);
	template<> INVENTORY_API UClass* StaticClass<UInventoryGrid>()
	{
		return UInventoryGrid::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UInventoryGrid(Z_Construct_UClass_UInventoryGrid, &UInventoryGrid::StaticClass, TEXT("/Script/Inventory"), TEXT("UInventoryGrid"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInventoryGrid);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
