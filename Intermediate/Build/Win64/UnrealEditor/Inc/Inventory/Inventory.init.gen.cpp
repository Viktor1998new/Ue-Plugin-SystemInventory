// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInventory_init() {}
	INVENTORY_API UFunction* Z_Construct_UDelegateFunction_Inventory_NewDataSlot__DelegateSignature();
	INVENTORY_API UFunction* Z_Construct_UDelegateFunction_Inventory_OnAddItem__DelegateSignature();
	INVENTORY_API UFunction* Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature();
	INVENTORY_API UFunction* Z_Construct_UDelegateFunction_Inventory_OnRemoveItem__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Inventory;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Inventory()
	{
		if (!Z_Registration_Info_UPackage__Script_Inventory.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_Inventory_NewDataSlot__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Inventory_OnAddItem__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Inventory_OnChangedSlot__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Inventory_OnRemoveItem__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Inventory",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x31245C04,
				0x5F14BE29,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Inventory.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Inventory.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Inventory(Z_Construct_UPackage__Script_Inventory, TEXT("/Script/Inventory"), Z_Registration_Info_UPackage__Script_Inventory, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x31245C04, 0x5F14BE29));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
