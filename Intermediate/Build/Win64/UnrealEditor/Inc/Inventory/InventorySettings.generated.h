// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef INVENTORY_InventorySettings_generated_h
#error "InventorySettings.generated.h already included, missing '#pragma once' in InventorySettings.h"
#endif
#define INVENTORY_InventorySettings_generated_h

#define FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_21_SPARSE_DATA
#define FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_21_RPC_WRAPPERS
#define FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_21_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventorySettings(); \
	friend struct Z_Construct_UClass_UInventorySettings_Statics; \
public: \
	DECLARE_CLASS(UInventorySettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/Inventory"), NO_API) \
	DECLARE_SERIALIZER(UInventorySettings) \
	static const TCHAR* StaticConfigName() {return TEXT("Engine");} \



#define FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_21_INCLASS \
private: \
	static void StaticRegisterNativesUInventorySettings(); \
	friend struct Z_Construct_UClass_UInventorySettings_Statics; \
public: \
	DECLARE_CLASS(UInventorySettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/Inventory"), NO_API) \
	DECLARE_SERIALIZER(UInventorySettings) \
	static const TCHAR* StaticConfigName() {return TEXT("Engine");} \



#define FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventorySettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventorySettings) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventorySettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventorySettings); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventorySettings(UInventorySettings&&); \
	NO_API UInventorySettings(const UInventorySettings&); \
public:


#define FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventorySettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventorySettings(UInventorySettings&&); \
	NO_API UInventorySettings(const UInventorySettings&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventorySettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventorySettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventorySettings)


#define FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_18_PROLOG
#define FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_21_SPARSE_DATA \
	FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_21_RPC_WRAPPERS \
	FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_21_INCLASS \
	FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_21_SPARSE_DATA \
	FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_21_INCLASS_NO_PURE_DECLS \
	FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h_21_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class InventorySettings."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> INVENTORY_API UClass* StaticClass<class UInventorySettings>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Horror_Plugins_Inventory_Source_Inventory_Public_InventorySettings_h


#define FOREACH_ENUM_EINVENTORYFLAG(op) \
	op(EInventoryFlag::None) \
	op(EInventoryFlag::Position) \
	op(EInventoryFlag::Size) \
	op(EInventoryFlag::Stack) \
	op(EInventoryFlag::Mass) \
	op(EInventoryFlag::LimitY) \
	op(EInventoryFlag::OnlyX) 

enum class EInventoryFlag : uint8;
template<> INVENTORY_API UEnum* StaticEnum<EInventoryFlag>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
