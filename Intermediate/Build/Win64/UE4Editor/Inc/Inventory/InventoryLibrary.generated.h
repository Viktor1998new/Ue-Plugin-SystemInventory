// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
 
#ifdef INVENTORY_InventoryLibrary_generated_h
#error "InventoryLibrary.generated.h already included, missing '#pragma once' in InventoryLibrary.h"
#endif
#define INVENTORY_InventoryLibrary_generated_h

#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryLibrary_h_11_SPARSE_DATA
#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryLibrary_h_11_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execDataItemSetValue); \
	DECLARE_FUNCTION(execDataItemToMap); \
	DECLARE_FUNCTION(execDataItem);


#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryLibrary_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDataItemSetValue); \
	DECLARE_FUNCTION(execDataItemToMap); \
	DECLARE_FUNCTION(execDataItem);


#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryLibrary_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventoryLibrary(); \
	friend struct Z_Construct_UClass_UInventoryLibrary_Statics; \
public: \
	DECLARE_CLASS(UInventoryLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Inventory"), NO_API) \
	DECLARE_SERIALIZER(UInventoryLibrary)


#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryLibrary_h_11_INCLASS \
private: \
	static void StaticRegisterNativesUInventoryLibrary(); \
	friend struct Z_Construct_UClass_UInventoryLibrary_Statics; \
public: \
	DECLARE_CLASS(UInventoryLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Inventory"), NO_API) \
	DECLARE_SERIALIZER(UInventoryLibrary)


#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryLibrary_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventoryLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventoryLibrary(UInventoryLibrary&&); \
	NO_API UInventoryLibrary(const UInventoryLibrary&); \
public:


#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryLibrary_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventoryLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventoryLibrary(UInventoryLibrary&&); \
	NO_API UInventoryLibrary(const UInventoryLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryLibrary)


#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryLibrary_h_11_PRIVATE_PROPERTY_OFFSET
#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryLibrary_h_8_PROLOG
#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryLibrary_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryLibrary_h_11_PRIVATE_PROPERTY_OFFSET \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryLibrary_h_11_SPARSE_DATA \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryLibrary_h_11_RPC_WRAPPERS \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryLibrary_h_11_INCLASS \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryLibrary_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryLibrary_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryLibrary_h_11_PRIVATE_PROPERTY_OFFSET \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryLibrary_h_11_SPARSE_DATA \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryLibrary_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryLibrary_h_11_INCLASS_NO_PURE_DECLS \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryLibrary_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> INVENTORY_API UClass* StaticClass<class UInventoryLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
