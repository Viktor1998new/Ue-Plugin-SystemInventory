// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FInventorySlot;
#ifdef INVENTORY_InventoryGridSlot_generated_h
#error "InventoryGridSlot.generated.h already included, missing '#pragma once' in InventoryGridSlot.h"
#endif
#define INVENTORY_InventoryGridSlot_generated_h

#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_14_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSlotTransformData_Statics; \
	INVENTORY_API static class UScriptStruct* StaticStruct();


template<> INVENTORY_API UScriptStruct* StaticStruct<struct FSlotTransformData>();

#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_31_DELEGATE \
struct _Script_Inventory_eventOnChangedSlot_Parms \
{ \
	int32 Index; \
	FInventorySlot Slot; \
}; \
static inline void FOnChangedSlot_DelegateWrapper(const FMulticastScriptDelegate& OnChangedSlot, int32 Index, FInventorySlot Slot) \
{ \
	_Script_Inventory_eventOnChangedSlot_Parms Parms; \
	Parms.Index=Index; \
	Parms.Slot=Slot; \
	OnChangedSlot.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_36_SPARSE_DATA
#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_36_RPC_WRAPPERS
#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_36_RPC_WRAPPERS_NO_PURE_DECLS
#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_36_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventoryGridSlot(); \
	friend struct Z_Construct_UClass_UInventoryGridSlot_Statics; \
public: \
	DECLARE_CLASS(UInventoryGridSlot, UPanelSlot, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Inventory"), NO_API) \
	DECLARE_SERIALIZER(UInventoryGridSlot)


#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_36_INCLASS \
private: \
	static void StaticRegisterNativesUInventoryGridSlot(); \
	friend struct Z_Construct_UClass_UInventoryGridSlot_Statics; \
public: \
	DECLARE_CLASS(UInventoryGridSlot, UPanelSlot, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Inventory"), NO_API) \
	DECLARE_SERIALIZER(UInventoryGridSlot)


#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_36_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventoryGridSlot(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryGridSlot) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryGridSlot); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryGridSlot); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventoryGridSlot(UInventoryGridSlot&&); \
	NO_API UInventoryGridSlot(const UInventoryGridSlot&); \
public:


#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_36_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventoryGridSlot(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventoryGridSlot(UInventoryGridSlot&&); \
	NO_API UInventoryGridSlot(const UInventoryGridSlot&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryGridSlot); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryGridSlot); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryGridSlot)


#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_36_PRIVATE_PROPERTY_OFFSET
#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_33_PROLOG
#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_36_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_36_PRIVATE_PROPERTY_OFFSET \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_36_SPARSE_DATA \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_36_RPC_WRAPPERS \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_36_INCLASS \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_36_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_36_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_36_PRIVATE_PROPERTY_OFFSET \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_36_SPARSE_DATA \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_36_RPC_WRAPPERS_NO_PURE_DECLS \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_36_INCLASS_NO_PURE_DECLS \
	MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h_36_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class InventoryGridSlot."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> INVENTORY_API UClass* StaticClass<class UInventoryGridSlot>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MyProject_Plugins_Inventory_Source_Inventory_Classes_InventoryUMG_InventoryGridSlot_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
