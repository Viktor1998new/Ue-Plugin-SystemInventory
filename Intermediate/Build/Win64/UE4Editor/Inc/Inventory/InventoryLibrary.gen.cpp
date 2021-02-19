// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Inventory/Classes/InventoryLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventoryLibrary() {}
// Cross Module References
	INVENTORY_API UClass* Z_Construct_UClass_UInventoryLibrary_NoRegister();
	INVENTORY_API UClass* Z_Construct_UClass_UInventoryLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_Inventory();
// End Cross Module References
	DEFINE_FUNCTION(UInventoryLibrary::execDataItemSetValue)
	{
		P_GET_TMAP(FString,FString,Z_Param_MapDataItem);
		P_GET_PROPERTY(FStrProperty,Z_Param_Key);
		P_GET_PROPERTY(FStrProperty,Z_Param_NewValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TMap<FString,FString>*)Z_Param__Result=UInventoryLibrary::DataItemSetValue(Z_Param_MapDataItem,Z_Param_Key,Z_Param_NewValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryLibrary::execDataItemToMap)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_DataItem);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TMap<FString,FString>*)Z_Param__Result=UInventoryLibrary::DataItemToMap(Z_Param_DataItem);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UInventoryLibrary::execDataItem)
	{
		P_GET_TMAP(FString,FString,Z_Param_MapDataItem);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UInventoryLibrary::DataItem(Z_Param_MapDataItem);
		P_NATIVE_END;
	}
	void UInventoryLibrary::StaticRegisterNativesUInventoryLibrary()
	{
		UClass* Class = UInventoryLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DataItem", &UInventoryLibrary::execDataItem },
			{ "DataItemSetValue", &UInventoryLibrary::execDataItemSetValue },
			{ "DataItemToMap", &UInventoryLibrary::execDataItemToMap },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInventoryLibrary_DataItem_Statics
	{
		struct InventoryLibrary_eventDataItem_Parms
		{
			TMap<FString,FString> MapDataItem;
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_MapDataItem_ValueProp;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_MapDataItem_Key_KeyProp;
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_MapDataItem;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UInventoryLibrary_DataItem_Statics::NewProp_MapDataItem_ValueProp = { "MapDataItem", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UInventoryLibrary_DataItem_Statics::NewProp_MapDataItem_Key_KeyProp = { "MapDataItem_Key", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UInventoryLibrary_DataItem_Statics::NewProp_MapDataItem = { "MapDataItem", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryLibrary_eventDataItem_Parms, MapDataItem), EMapPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UInventoryLibrary_DataItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryLibrary_eventDataItem_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryLibrary_DataItem_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryLibrary_DataItem_Statics::NewProp_MapDataItem_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryLibrary_DataItem_Statics::NewProp_MapDataItem_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryLibrary_DataItem_Statics::NewProp_MapDataItem,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryLibrary_DataItem_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryLibrary_DataItem_Statics::Function_MetaDataParams[] = {
		{ "Category", "InventoryLibrary" },
		{ "Comment", "///** Starts an analytics session without any custom attributes specified */\n" },
		{ "ModuleRelativePath", "Classes/InventoryLibrary.h" },
		{ "ToolTip", "Starts an analytics session without any custom attributes specified" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryLibrary_DataItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryLibrary, nullptr, "DataItem", nullptr, nullptr, sizeof(InventoryLibrary_eventDataItem_Parms), Z_Construct_UFunction_UInventoryLibrary_DataItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryLibrary_DataItem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryLibrary_DataItem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryLibrary_DataItem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryLibrary_DataItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInventoryLibrary_DataItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics
	{
		struct InventoryLibrary_eventDataItemSetValue_Parms
		{
			TMap<FString,FString> MapDataItem;
			FString Key;
			FString NewValue;
			TMap<FString,FString> ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_MapDataItem_ValueProp;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_MapDataItem_Key_KeyProp;
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_MapDataItem;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Key;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_NewValue;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue_ValueProp;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Key_KeyProp;
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::NewProp_MapDataItem_ValueProp = { "MapDataItem", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::NewProp_MapDataItem_Key_KeyProp = { "MapDataItem_Key", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::NewProp_MapDataItem = { "MapDataItem", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryLibrary_eventDataItemSetValue_Parms, MapDataItem), EMapPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryLibrary_eventDataItemSetValue_Parms, Key), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::NewProp_NewValue = { "NewValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryLibrary_eventDataItemSetValue_Parms, NewValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryLibrary_eventDataItemSetValue_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::NewProp_MapDataItem_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::NewProp_MapDataItem_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::NewProp_MapDataItem,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::NewProp_Key,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::NewProp_NewValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::NewProp_ReturnValue_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::NewProp_ReturnValue_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "InventoryLibrary" },
		{ "ModuleRelativePath", "Classes/InventoryLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryLibrary, nullptr, "DataItemSetValue", nullptr, nullptr, sizeof(InventoryLibrary_eventDataItemSetValue_Parms), Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInventoryLibrary_DataItemToMap_Statics
	{
		struct InventoryLibrary_eventDataItemToMap_Parms
		{
			FString DataItem;
			TMap<FString,FString> ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_DataItem;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue_ValueProp;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Key_KeyProp;
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UInventoryLibrary_DataItemToMap_Statics::NewProp_DataItem = { "DataItem", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryLibrary_eventDataItemToMap_Parms, DataItem), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UInventoryLibrary_DataItemToMap_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UInventoryLibrary_DataItemToMap_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UInventoryLibrary_DataItemToMap_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InventoryLibrary_eventDataItemToMap_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInventoryLibrary_DataItemToMap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryLibrary_DataItemToMap_Statics::NewProp_DataItem,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryLibrary_DataItemToMap_Statics::NewProp_ReturnValue_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryLibrary_DataItemToMap_Statics::NewProp_ReturnValue_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInventoryLibrary_DataItemToMap_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInventoryLibrary_DataItemToMap_Statics::Function_MetaDataParams[] = {
		{ "Category", "InventoryLibrary" },
		{ "ModuleRelativePath", "Classes/InventoryLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UInventoryLibrary_DataItemToMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInventoryLibrary, nullptr, "DataItemToMap", nullptr, nullptr, sizeof(InventoryLibrary_eventDataItemToMap_Parms), Z_Construct_UFunction_UInventoryLibrary_DataItemToMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryLibrary_DataItemToMap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UInventoryLibrary_DataItemToMap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UInventoryLibrary_DataItemToMap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UInventoryLibrary_DataItemToMap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UInventoryLibrary_DataItemToMap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UInventoryLibrary_NoRegister()
	{
		return UInventoryLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UInventoryLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInventoryLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_Inventory,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UInventoryLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInventoryLibrary_DataItem, "DataItem" }, // 1110176946
		{ &Z_Construct_UFunction_UInventoryLibrary_DataItemSetValue, "DataItemSetValue" }, // 3442038419
		{ &Z_Construct_UFunction_UInventoryLibrary_DataItemToMap, "DataItemToMap" }, // 1102778630
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventoryLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "InventoryLibrary.h" },
		{ "ModuleRelativePath", "Classes/InventoryLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInventoryLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventoryLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UInventoryLibrary_Statics::ClassParams = {
		&UInventoryLibrary::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UInventoryLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UInventoryLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInventoryLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UInventoryLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UInventoryLibrary, 1096575059);
	template<> INVENTORY_API UClass* StaticClass<UInventoryLibrary>()
	{
		return UInventoryLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UInventoryLibrary(Z_Construct_UClass_UInventoryLibrary, &UInventoryLibrary::StaticClass, TEXT("/Script/Inventory"), TEXT("UInventoryLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInventoryLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
