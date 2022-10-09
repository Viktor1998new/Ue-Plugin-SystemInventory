// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Inventory/Public/InventorySettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventorySettings() {}
// Cross Module References
	INVENTORY_API UEnum* Z_Construct_UEnum_Inventory_EInventoryFlag();
	UPackage* Z_Construct_UPackage__Script_Inventory();
	INVENTORY_API UClass* Z_Construct_UClass_UInventorySettings_NoRegister();
	INVENTORY_API UClass* Z_Construct_UClass_UInventorySettings();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EInventoryFlag;
	static UEnum* EInventoryFlag_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EInventoryFlag.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EInventoryFlag.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Inventory_EInventoryFlag, Z_Construct_UPackage__Script_Inventory(), TEXT("EInventoryFlag"));
		}
		return Z_Registration_Info_UEnum_EInventoryFlag.OuterSingleton;
	}
	template<> INVENTORY_API UEnum* StaticEnum<EInventoryFlag>()
	{
		return EInventoryFlag_StaticEnum();
	}
	struct Z_Construct_UEnum_Inventory_EInventoryFlag_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_Inventory_EInventoryFlag_Statics::Enumerators[] = {
		{ "EInventoryFlag::None", (int64)EInventoryFlag::None },
		{ "EInventoryFlag::Position", (int64)EInventoryFlag::Position },
		{ "EInventoryFlag::Size", (int64)EInventoryFlag::Size },
		{ "EInventoryFlag::Stack", (int64)EInventoryFlag::Stack },
		{ "EInventoryFlag::Mass", (int64)EInventoryFlag::Mass },
		{ "EInventoryFlag::LimitY", (int64)EInventoryFlag::LimitY },
		{ "EInventoryFlag::OnlyX", (int64)EInventoryFlag::OnlyX },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_Inventory_EInventoryFlag_Statics::Enum_MetaDataParams[] = {
		{ "Bitflags", "" },
		{ "BlueprintType", "true" },
		{ "LimitY.Name", "EInventoryFlag::LimitY" },
		{ "Mass.Name", "EInventoryFlag::Mass" },
		{ "ModuleRelativePath", "Public/InventorySettings.h" },
		{ "None.hidden", "" },
		{ "None.Name", "EInventoryFlag::None" },
		{ "OnlyX.Name", "EInventoryFlag::OnlyX" },
		{ "Position.Name", "EInventoryFlag::Position" },
		{ "Size.Name", "EInventoryFlag::Size" },
		{ "Stack.Name", "EInventoryFlag::Stack" },
		{ "UseEnumValuesAsMaskValuesInEditor", "true" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Inventory_EInventoryFlag_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_Inventory,
		nullptr,
		"EInventoryFlag",
		"EInventoryFlag",
		Z_Construct_UEnum_Inventory_EInventoryFlag_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_Inventory_EInventoryFlag_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_Inventory_EInventoryFlag_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_Inventory_EInventoryFlag_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_Inventory_EInventoryFlag()
	{
		if (!Z_Registration_Info_UEnum_EInventoryFlag.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EInventoryFlag.InnerSingleton, Z_Construct_UEnum_Inventory_EInventoryFlag_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EInventoryFlag.InnerSingleton;
	}
	void UInventorySettings::StaticRegisterNativesUInventorySettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInventorySettings);
	UClass* Z_Construct_UClass_UInventorySettings_NoRegister()
	{
		return UInventorySettings::StaticClass();
	}
	struct Z_Construct_UClass_UInventorySettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InventoryFlags_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_InventoryFlags;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInventorySettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Inventory,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySettings_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "InventorySettings.h" },
		{ "ModuleRelativePath", "Public/InventorySettings.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInventorySettings_Statics::NewProp_InventoryFlags_MetaData[] = {
		{ "Bitmask", "" },
		{ "BitmaskEnum", "EInventoryFlag" },
		{ "Category", "InventorySettings" },
		{ "ModuleRelativePath", "Public/InventorySettings.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UInventorySettings_Statics::NewProp_InventoryFlags = { "InventoryFlags", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UInventorySettings, InventoryFlags), METADATA_PARAMS(Z_Construct_UClass_UInventorySettings_Statics::NewProp_InventoryFlags_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UInventorySettings_Statics::NewProp_InventoryFlags_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInventorySettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInventorySettings_Statics::NewProp_InventoryFlags,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInventorySettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInventorySettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInventorySettings_Statics::ClassParams = {
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
		if (!Z_Registration_Info_UClass_UInventorySettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInventorySettings.OuterSingleton, Z_Construct_UClass_UInventorySettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInventorySettings.OuterSingleton;
	}
	template<> INVENTORY_API UClass* StaticClass<UInventorySettings>()
	{
		return UInventorySettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInventorySettings);
	struct Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_Statics::EnumInfo[] = {
		{ EInventoryFlag_StaticEnum, TEXT("EInventoryFlag"), &Z_Registration_Info_UEnum_EInventoryFlag, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2214393756U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInventorySettings, UInventorySettings::StaticClass, TEXT("UInventorySettings"), &Z_Registration_Info_UClass_UInventorySettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInventorySettings), 2798870133U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_4233865782(TEXT("/Script/Inventory"),
		Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
