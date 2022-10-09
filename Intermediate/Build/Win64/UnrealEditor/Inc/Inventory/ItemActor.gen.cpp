// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Inventory/Classes/Inventory/ItemActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeItemActor() {}
// Cross Module References
	INVENTORY_API UScriptStruct* Z_Construct_UScriptStruct_FItemData();
	UPackage* Z_Construct_UPackage__Script_Inventory();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
	INVENTORY_API UClass* Z_Construct_UClass_UItemAsset_NoRegister();
	INVENTORY_API UClass* Z_Construct_UClass_UItemAsset();
	ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	INVENTORY_API UClass* Z_Construct_UClass_AItemActor_NoRegister();
	INVENTORY_API UClass* Z_Construct_UClass_AItemActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ItemData;
class UScriptStruct* FItemData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ItemData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ItemData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FItemData, Z_Construct_UPackage__Script_Inventory(), TEXT("ItemData"));
	}
	return Z_Registration_Info_UScriptStruct_ItemData.OuterSingleton;
}
template<> INVENTORY_API UScriptStruct* StaticStruct<FItemData>()
{
	return FItemData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FItemData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NameItem_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_NameItem;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ImageItem_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ImageItem;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SizeSlot_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SizeSlot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MassItem_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MassItem;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StackItem_MetaData[];
#endif
		static void NewProp_StackItem_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_StackItem;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NoneData_MetaData[];
#endif
		static void NewProp_NoneData_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_NoneData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Classes/Inventory/ItemActor.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FItemData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FItemData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemData_Statics::NewProp_NameItem_MetaData[] = {
		{ "Category", "ItemData" },
		{ "ModuleRelativePath", "Classes/Inventory/ItemActor.h" },
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FItemData_Statics::NewProp_NameItem = { "NameItem", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FItemData, NameItem), METADATA_PARAMS(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_NameItem_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_NameItem_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemData_Statics::NewProp_ImageItem_MetaData[] = {
		{ "Category", "ItemData" },
		{ "ModuleRelativePath", "Classes/Inventory/ItemActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FItemData_Statics::NewProp_ImageItem = { "ImageItem", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FItemData, ImageItem), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_ImageItem_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_ImageItem_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemData_Statics::NewProp_SizeSlot_MetaData[] = {
		{ "Category", "ItemData" },
		{ "ModuleRelativePath", "Classes/Inventory/ItemActor.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FItemData_Statics::NewProp_SizeSlot = { "SizeSlot", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FItemData, SizeSlot), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_SizeSlot_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_SizeSlot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemData_Statics::NewProp_MassItem_MetaData[] = {
		{ "Category", "ItemData" },
		{ "ModuleRelativePath", "Classes/Inventory/ItemActor.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FItemData_Statics::NewProp_MassItem = { "MassItem", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FItemData, MassItem), METADATA_PARAMS(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_MassItem_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_MassItem_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemData_Statics::NewProp_StackItem_MetaData[] = {
		{ "Category", "ItemData" },
		{ "ModuleRelativePath", "Classes/Inventory/ItemActor.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FItemData_Statics::NewProp_StackItem_SetBit(void* Obj)
	{
		((FItemData*)Obj)->StackItem = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FItemData_Statics::NewProp_StackItem = { "StackItem", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FItemData), &Z_Construct_UScriptStruct_FItemData_Statics::NewProp_StackItem_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_StackItem_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_StackItem_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FItemData_Statics::NewProp_NoneData_MetaData[] = {
		{ "Category", "ItemData" },
		{ "ModuleRelativePath", "Classes/Inventory/ItemActor.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FItemData_Statics::NewProp_NoneData_SetBit(void* Obj)
	{
		((FItemData*)Obj)->NoneData = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FItemData_Statics::NewProp_NoneData = { "NoneData", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FItemData), &Z_Construct_UScriptStruct_FItemData_Statics::NewProp_NoneData_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_NoneData_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemData_Statics::NewProp_NoneData_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FItemData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemData_Statics::NewProp_NameItem,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemData_Statics::NewProp_ImageItem,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemData_Statics::NewProp_SizeSlot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemData_Statics::NewProp_MassItem,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemData_Statics::NewProp_StackItem,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemData_Statics::NewProp_NoneData,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FItemData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Inventory,
		nullptr,
		&NewStructOps,
		"ItemData",
		sizeof(FItemData),
		alignof(FItemData),
		Z_Construct_UScriptStruct_FItemData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FItemData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FItemData()
	{
		if (!Z_Registration_Info_UScriptStruct_ItemData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ItemData.InnerSingleton, Z_Construct_UScriptStruct_FItemData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_ItemData.InnerSingleton;
	}
	void UItemAsset::StaticRegisterNativesUItemAsset()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UItemAsset);
	UClass* Z_Construct_UClass_UItemAsset_NoRegister()
	{
		return UItemAsset::StaticClass();
	}
	struct Z_Construct_UClass_UItemAsset_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ClassItemActor_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_ClassItemActor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SlotItemData_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SlotItemData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UItemAsset_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_Inventory,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UItemAsset_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Inventory/ItemActor.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Classes/Inventory/ItemActor.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UItemAsset_Statics::NewProp_ClassItemActor_MetaData[] = {
		{ "Category", "ItemAsset" },
		{ "ModuleRelativePath", "Classes/Inventory/ItemActor.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UItemAsset_Statics::NewProp_ClassItemActor = { "ClassItemActor", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UItemAsset, ClassItemActor), Z_Construct_UClass_AItemActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UItemAsset_Statics::NewProp_ClassItemActor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UItemAsset_Statics::NewProp_ClassItemActor_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UItemAsset_Statics::NewProp_SlotItemData_MetaData[] = {
		{ "Category", "ItemAsset" },
		{ "ModuleRelativePath", "Classes/Inventory/ItemActor.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UItemAsset_Statics::NewProp_SlotItemData = { "SlotItemData", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UItemAsset, SlotItemData), Z_Construct_UScriptStruct_FItemData, METADATA_PARAMS(Z_Construct_UClass_UItemAsset_Statics::NewProp_SlotItemData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UItemAsset_Statics::NewProp_SlotItemData_MetaData)) }; // 917797097
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UItemAsset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemAsset_Statics::NewProp_ClassItemActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UItemAsset_Statics::NewProp_SlotItemData,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UItemAsset_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UItemAsset>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UItemAsset_Statics::ClassParams = {
		&UItemAsset::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UItemAsset_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UItemAsset_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UItemAsset_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UItemAsset_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UItemAsset()
	{
		if (!Z_Registration_Info_UClass_UItemAsset.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UItemAsset.OuterSingleton, Z_Construct_UClass_UItemAsset_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UItemAsset.OuterSingleton;
	}
	template<> INVENTORY_API UClass* StaticClass<UItemAsset>()
	{
		return UItemAsset::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UItemAsset);
	DEFINE_FUNCTION(AItemActor::execGetData)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetData();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AItemActor::execSetData)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_NewData);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetData(Z_Param_NewData);
		P_NATIVE_END;
	}
	static FName NAME_AItemActor_ReceiveGetData = FName(TEXT("ReceiveGetData"));
	void AItemActor::ReceiveGetData(FString& Data)
	{
		ItemActor_eventReceiveGetData_Parms Parms;
		Parms.Data=Data;
		ProcessEvent(FindFunctionChecked(NAME_AItemActor_ReceiveGetData),&Parms);
		Data=Parms.Data;
	}
	static FName NAME_AItemActor_ReceiveInitData = FName(TEXT("ReceiveInitData"));
	void AItemActor::ReceiveInitData(const FString& Data)
	{
		ItemActor_eventReceiveInitData_Parms Parms;
		Parms.Data=Data;
		ProcessEvent(FindFunctionChecked(NAME_AItemActor_ReceiveInitData),&Parms);
	}
	void AItemActor::StaticRegisterNativesAItemActor()
	{
		UClass* Class = AItemActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetData", &AItemActor::execGetData },
			{ "SetData", &AItemActor::execSetData },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AItemActor_GetData_Statics
	{
		struct ItemActor_eventGetData_Parms
		{
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AItemActor_GetData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ItemActor_eventGetData_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AItemActor_GetData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemActor_GetData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AItemActor_GetData_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Inventory/ItemActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AItemActor_GetData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AItemActor, nullptr, "GetData", nullptr, nullptr, sizeof(Z_Construct_UFunction_AItemActor_GetData_Statics::ItemActor_eventGetData_Parms), Z_Construct_UFunction_AItemActor_GetData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemActor_GetData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AItemActor_GetData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemActor_GetData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AItemActor_GetData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AItemActor_GetData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AItemActor_ReceiveGetData_Statics
	{
		static const UECodeGen_Private::FStrPropertyParams NewProp_Data;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AItemActor_ReceiveGetData_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ItemActor_eventReceiveGetData_Parms, Data), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AItemActor_ReceiveGetData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemActor_ReceiveGetData_Statics::NewProp_Data,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AItemActor_ReceiveGetData_Statics::Function_MetaDataParams[] = {
		{ "DisplayName", "GetData" },
		{ "ModuleRelativePath", "Classes/Inventory/ItemActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AItemActor_ReceiveGetData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AItemActor, nullptr, "ReceiveGetData", nullptr, nullptr, sizeof(ItemActor_eventReceiveGetData_Parms), Z_Construct_UFunction_AItemActor_ReceiveGetData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemActor_ReceiveGetData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AItemActor_ReceiveGetData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemActor_ReceiveGetData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AItemActor_ReceiveGetData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AItemActor_ReceiveGetData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AItemActor_ReceiveInitData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Data_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Data;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AItemActor_ReceiveInitData_Statics::NewProp_Data_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AItemActor_ReceiveInitData_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ItemActor_eventReceiveInitData_Parms, Data), METADATA_PARAMS(Z_Construct_UFunction_AItemActor_ReceiveInitData_Statics::NewProp_Data_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemActor_ReceiveInitData_Statics::NewProp_Data_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AItemActor_ReceiveInitData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemActor_ReceiveInitData_Statics::NewProp_Data,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AItemActor_ReceiveInitData_Statics::Function_MetaDataParams[] = {
		{ "DisplayName", "InitData" },
		{ "ModuleRelativePath", "Classes/Inventory/ItemActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AItemActor_ReceiveInitData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AItemActor, nullptr, "ReceiveInitData", nullptr, nullptr, sizeof(ItemActor_eventReceiveInitData_Parms), Z_Construct_UFunction_AItemActor_ReceiveInitData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemActor_ReceiveInitData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AItemActor_ReceiveInitData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemActor_ReceiveInitData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AItemActor_ReceiveInitData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AItemActor_ReceiveInitData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AItemActor_SetData_Statics
	{
		struct ItemActor_eventSetData_Parms
		{
			FString NewData;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NewData_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_NewData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AItemActor_SetData_Statics::NewProp_NewData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AItemActor_SetData_Statics::NewProp_NewData = { "NewData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ItemActor_eventSetData_Parms, NewData), METADATA_PARAMS(Z_Construct_UFunction_AItemActor_SetData_Statics::NewProp_NewData_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemActor_SetData_Statics::NewProp_NewData_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AItemActor_SetData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItemActor_SetData_Statics::NewProp_NewData,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AItemActor_SetData_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Inventory/ItemActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AItemActor_SetData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AItemActor, nullptr, "SetData", nullptr, nullptr, sizeof(Z_Construct_UFunction_AItemActor_SetData_Statics::ItemActor_eventSetData_Parms), Z_Construct_UFunction_AItemActor_SetData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemActor_SetData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AItemActor_SetData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AItemActor_SetData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AItemActor_SetData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AItemActor_SetData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AItemActor);
	UClass* Z_Construct_UClass_AItemActor_NoRegister()
	{
		return AItemActor::StaticClass();
	}
	struct Z_Construct_UClass_AItemActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ItemAsset_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemAsset;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AItemActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Inventory,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AItemActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AItemActor_GetData, "GetData" }, // 277825521
		{ &Z_Construct_UFunction_AItemActor_ReceiveGetData, "ReceiveGetData" }, // 3591277098
		{ &Z_Construct_UFunction_AItemActor_ReceiveInitData, "ReceiveInitData" }, // 843933629
		{ &Z_Construct_UFunction_AItemActor_SetData, "SetData" }, // 3132893095
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AItemActor_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Inventory/ItemActor.h" },
		{ "ModuleRelativePath", "Classes/Inventory/ItemActor.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AItemActor_Statics::NewProp_ItemAsset_MetaData[] = {
		{ "Category", "ItemActor" },
		{ "ExposeOnSpawn", "true" },
		{ "ModuleRelativePath", "Classes/Inventory/ItemActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AItemActor_Statics::NewProp_ItemAsset = { "ItemAsset", nullptr, (EPropertyFlags)0x0011000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AItemActor, ItemAsset), Z_Construct_UClass_UItemAsset_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AItemActor_Statics::NewProp_ItemAsset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AItemActor_Statics::NewProp_ItemAsset_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AItemActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItemActor_Statics::NewProp_ItemAsset,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AItemActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AItemActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AItemActor_Statics::ClassParams = {
		&AItemActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AItemActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AItemActor_Statics::PropPointers),
		0,
		0x009000A5u,
		METADATA_PARAMS(Z_Construct_UClass_AItemActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AItemActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AItemActor()
	{
		if (!Z_Registration_Info_UClass_AItemActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AItemActor.OuterSingleton, Z_Construct_UClass_AItemActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AItemActor.OuterSingleton;
	}
	template<> INVENTORY_API UClass* StaticClass<AItemActor>()
	{
		return AItemActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AItemActor);
	struct Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_Statics::ScriptStructInfo[] = {
		{ FItemData::StaticStruct, Z_Construct_UScriptStruct_FItemData_Statics::NewStructOps, TEXT("ItemData"), &Z_Registration_Info_UScriptStruct_ItemData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FItemData), 917797097U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UItemAsset, UItemAsset::StaticClass, TEXT("UItemAsset"), &Z_Registration_Info_UClass_UItemAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UItemAsset), 1250376498U) },
		{ Z_Construct_UClass_AItemActor, AItemActor::StaticClass, TEXT("AItemActor"), &Z_Registration_Info_UClass_AItemActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AItemActor), 4209449169U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_4242771703(TEXT("/Script/Inventory"),
		Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
