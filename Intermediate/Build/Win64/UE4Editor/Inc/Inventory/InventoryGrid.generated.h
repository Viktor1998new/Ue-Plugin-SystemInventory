// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FInventorySlot;
class UInventoryComponent;
class UWidget;
class UInventoryGridSlot;
#ifdef INVENTORY_InventoryGrid_generated_h
#error "InventoryGrid.generated.h already included, missing '#pragma once' in InventoryGrid.h"
#endif
#define INVENTORY_InventoryGrid_generated_h

#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGrid_h_17_SPARSE_DATA
#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGrid_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execEvent_NewDataSlot); \
	DECLARE_FUNCTION(execGetInventory); \
	DECLARE_FUNCTION(execSlotAsInventorySlot); \
	DECLARE_FUNCTION(execSetInventory);


#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGrid_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEvent_NewDataSlot); \
	DECLARE_FUNCTION(execGetInventory); \
	DECLARE_FUNCTION(execSlotAsInventorySlot); \
	DECLARE_FUNCTION(execSetInventory);


#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGrid_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventoryGrid(); \
	friend struct Z_Construct_UClass_UInventoryGrid_Statics; \
public: \
	DECLARE_CLASS(UInventoryGrid, UPanelWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Inventory"), NO_API) \
	DECLARE_SERIALIZER(UInventoryGrid)


#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGrid_h_17_INCLASS \
private: \
	static void StaticRegisterNativesUInventoryGrid(); \
	friend struct Z_Construct_UClass_UInventoryGrid_Statics; \
public: \
	DECLARE_CLASS(UInventoryGrid, UPanelWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Inventory"), NO_API) \
	DECLARE_SERIALIZER(UInventoryGrid)


#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGrid_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventoryGrid(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryGrid) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryGrid); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryGrid); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventoryGrid(UInventoryGrid&&); \
	NO_API UInventoryGrid(const UInventoryGrid&); \
public:


#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGrid_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventoryGrid(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventoryGrid(UInventoryGrid&&); \
	NO_API UInventoryGrid(const UInventoryGrid&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryGrid); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryGrid); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryGrid)


#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGrid_h_17_PRIVATE_PROPERTY_OFFSET
#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGrid_h_14_PROLOG
#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGrid_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGrid_h_17_PRIVATE_PROPERTY_OFFSET \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGrid_h_17_SPARSE_DATA \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGrid_h_17_RPC_WRAPPERS \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGrid_h_17_INCLASS \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGrid_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGrid_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGrid_h_17_PRIVATE_PROPERTY_OFFSET \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGrid_h_17_SPARSE_DATA \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGrid_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGrid_h_17_INCLASS_NO_PURE_DECLS \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGrid_h_17_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class InventoryGrid."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> INVENTORY_API UClass* StaticClass<class UInventoryGrid>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGrid_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
