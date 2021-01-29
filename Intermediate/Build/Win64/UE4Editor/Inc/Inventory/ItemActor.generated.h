// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef INVENTORY_ItemActor_generated_h
#error "ItemActor.generated.h already included, missing '#pragma once' in ItemActor.h"
#endif
#define INVENTORY_ItemActor_generated_h

#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_12_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FItemData_Statics; \
	static class UScriptStruct* StaticStruct();


template<> INVENTORY_API UScriptStruct* StaticStruct<struct FItemData>();

#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_SPARSE_DATA
#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetData); \
	DECLARE_FUNCTION(execSetData);


#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetData); \
	DECLARE_FUNCTION(execSetData);


#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_EVENT_PARMS \
	struct ItemActor_eventReceiveGetData_Parms \
	{ \
		FString Data; \
	}; \
	struct ItemActor_eventReceiveInitData_Parms \
	{ \
		FString Data; \
	};


#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_CALLBACK_WRAPPERS
#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAItemActor(); \
	friend struct Z_Construct_UClass_AItemActor_Statics; \
public: \
	DECLARE_CLASS(AItemActor, AActor, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/Inventory"), NO_API) \
	DECLARE_SERIALIZER(AItemActor)


#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_INCLASS \
private: \
	static void StaticRegisterNativesAItemActor(); \
	friend struct Z_Construct_UClass_AItemActor_Statics; \
public: \
	DECLARE_CLASS(AItemActor, AActor, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/Inventory"), NO_API) \
	DECLARE_SERIALIZER(AItemActor)


#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AItemActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AItemActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AItemActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AItemActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AItemActor(AItemActor&&); \
	NO_API AItemActor(const AItemActor&); \
public:


#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AItemActor(AItemActor&&); \
	NO_API AItemActor(const AItemActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AItemActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AItemActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AItemActor)


#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_PRIVATE_PROPERTY_OFFSET
#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_33_PROLOG \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_EVENT_PARMS


#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_PRIVATE_PROPERTY_OFFSET \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_SPARSE_DATA \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_RPC_WRAPPERS \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_CALLBACK_WRAPPERS \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_INCLASS \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_PRIVATE_PROPERTY_OFFSET \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_SPARSE_DATA \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_RPC_WRAPPERS_NO_PURE_DECLS \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_CALLBACK_WRAPPERS \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_INCLASS_NO_PURE_DECLS \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> INVENTORY_API UClass* StaticClass<class AItemActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
