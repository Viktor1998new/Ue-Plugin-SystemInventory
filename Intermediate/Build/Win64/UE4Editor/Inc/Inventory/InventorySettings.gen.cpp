// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Inventory/Public/InventorySettings.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventorySettings() {}
// Cross Module References
	INVENTORY_API UClass* Z_Construct_UClass_UInventorySettings_NoRegister();
	INVENTORY_API UClass* Z_Construct_UClass_UInventorySettings();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_Inventory();
// End Cross Module References
	void UInventorySettings::StaticRegisterNativesUInventorySettings()
	{
	}
	UClass* Z_Construct_UClass_UInventorySettings_NoRegister()
	{
		return UInventorySettings::StaticClass();
	}
	struct Z_Construct_UClass_UInventorySettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SizeSlot_MetaData[];
#endif
		static void NewProp_SizeSlot_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_SizeSlot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StackItems_MetaData[];
#endif
		static void NewProp_StackItems_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_StackItems;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MassItems_MetaData[];
#endif
		static void NewProp_MassItems_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_MassItems;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LimitSlotY_MetaData[];
#endif
		static void NewProp_LimitSlotY_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_LimitSlotY;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInventorySettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Inventory,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySettings_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "InventorySettings.h" },
		{ "ModuleRelativePath", "Public/InventorySettings.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySettings_Statics::NewProp_SizeSlot_MetaData[] = {
		{ "Category", "InventorySettings" },
		{ "ModuleRelativePath", "Public/InventorySettings.h" },
	};
#endif
	void Z_Construct_UClass_UInventorySettings_Statics::NewProp_SizeSlot_SetBit(void* Obj)
	{
		((UInventorySettings*)Obj)->SizeSlot = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UInventorySettings_Statics::NewProp_SizeSlot = { "SizeSlot", nullptr, (EPropertyFlags)0x0010000000004015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UInventorySettings), &Z_Construct_UClass_UInventorySettings_Statics::NewProp_SizeSlot_SetBit, METADATA_PARAMS(Z_Construct_UClass_UInventorySettings_Statics::NewProp_SizeSlot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySettings_Statics::NewProp_SizeSlot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySettings_Statics::NewProp_StackItems_MetaData[] = {
		{ "Category", "InventorySettings" },
		{ "ModuleRelativePath", "Public/InventorySettings.h" },
	};
#endif
	void Z_Construct_UClass_UInventorySettings_Statics::NewProp_StackItems_SetBit(void* Obj)
	{
		((UInventorySettings*)Obj)->StackItems = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UInventorySettings_Statics::NewProp_StackItems = { "StackItems", nullptr, (EPropertyFlags)0x0010000000004015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UInventorySettings), &Z_Construct_UClass_UInventorySettings_Statics::NewProp_StackItems_SetBit, METADATA_PARAMS(Z_Construct_UClass_UInventorySettings_Statics::NewProp_StackItems_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySettings_Statics::NewProp_StackItems_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySettings_Statics::NewProp_MassItems_MetaData[] = {
		{ "Category", "InventorySettings" },
		{ "ModuleRelativePath", "Public/InventorySettings.h" },
	};
#endif
	void Z_Construct_UClass_UInventorySettings_Statics::NewProp_MassItems_SetBit(void* Obj)
	{
		((UInventorySettings*)Obj)->MassItems = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UInventorySettings_Statics::NewProp_MassItems = { "MassItems", nullptr, (EPropertyFlags)0x0010000000004015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UInventorySettings), &Z_Construct_UClass_UInventorySettings_Statics::NewProp_MassItems_SetBit, METADATA_PARAMS(Z_Construct_UClass_UInventorySettings_Statics::NewProp_MassItems_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySettings_Statics::NewProp_MassItems_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySettings_Statics::NewProp_LimitSlotY_MetaData[] = {
		{ "Category", "InventorySettings" },
		{ "ModuleRelativePath", "Public/InventorySettings.h" },
	};
#endif
	void Z_Construct_UClass_UInventorySettings_Statics::NewProp_LimitSlotY_SetBit(void* Obj)
	{
		((UInventorySettings*)Obj)->LimitSlotY = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UInventorySettings_Statics::NewProp_LimitSlotY = { "LimitSlotY", nullptr, (EPropertyFlags)0x0010000000004015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UInventorySettings), &Z_Construct_UClass_UInventorySettings_Statics::NewProp_LimitSlotY_SetBit, METADATA_PARAMS(Z_Construct_UClass_UInventorySettings_Statics::NewProp_LimitSlotY_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySettings_Statics::NewProp_LimitSlotY_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventorySettings_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySettings_Statics::NewProp_SizeSlot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySettings_Statics::NewProp_StackItems,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySettings_Statics::NewProp_MassItems,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySettings_Statics::NewProp_LimitSlotY,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInventorySettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventorySettings>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UInventorySettings_Statics::ClassParams = {
		&UInventorySettings::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UInventorySettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySettings_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(Z_Construct_UClass_UInventorySettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UInventorySettings()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UInventorySettings_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UInventorySettings, 1472413115);
	template<> INVENTORY_API UClass* StaticClass<UInventorySettings>()
	{
		return UInventorySettings::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UInventorySettings(Z_Construct_UClass_UInventorySettings, &UInventorySettings::StaticClass, TEXT("/Script/Inventory"), TEXT("UInventorySettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInventorySettings);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
