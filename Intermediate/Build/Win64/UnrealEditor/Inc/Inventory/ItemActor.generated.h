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

#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_12_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FItemData_Statics; \
	static class UScriptStruct* StaticStruct();


template<> INVENTORY_API UScriptStruct* StaticStruct<struct FItemData>();

#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_SPARSE_DATA
#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_RPC_WRAPPERS
#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUItemAsset(); \
	friend struct Z_Construct_UClass_UItemAsset_Statics; \
public: \
	DECLARE_CLASS(UItemAsset, UPrimaryDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Inventory"), NO_API) \
	DECLARE_SERIALIZER(UItemAsset)


#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_INCLASS \
private: \
	static void StaticRegisterNativesUItemAsset(); \
	friend struct Z_Construct_UClass_UItemAsset_Statics; \
public: \
	DECLARE_CLASS(UItemAsset, UPrimaryDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Inventory"), NO_API) \
	DECLARE_SERIALIZER(UItemAsset)


#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UItemAsset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UItemAsset) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UItemAsset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UItemAsset); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UItemAsset(UItemAsset&&); \
	NO_API UItemAsset(const UItemAsset&); \
public:


#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UItemAsset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UItemAsset(UItemAsset&&); \
	NO_API UItemAsset(const UItemAsset&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UItemAsset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UItemAsset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UItemAsset)


#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_33_PROLOG
#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_SPARSE_DATA \
	FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_RPC_WRAPPERS \
	FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_INCLASS \
	FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_SPARSE_DATA \
	FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_INCLASS_NO_PURE_DECLS \
	FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_36_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> INVENTORY_API UClass* StaticClass<class UItemAsset>();

#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_51_SPARSE_DATA
#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_51_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetData); \
	DECLARE_FUNCTION(execSetData);


#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_51_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetData); \
	DECLARE_FUNCTION(execSetData);


#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_51_EVENT_PARMS \
	struct ItemActor_eventReceiveGetData_Parms \
	{ \
		FString Data; \
	}; \
	struct ItemActor_eventReceiveInitData_Parms \
	{ \
		FString Data; \
	};


#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_51_CALLBACK_WRAPPERS
#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_51_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAItemActor(); \
	friend struct Z_Construct_UClass_AItemActor_Statics; \
public: \
	DECLARE_CLASS(AItemActor, AActor, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/Inventory"), NO_API) \
	DECLARE_SERIALIZER(AItemActor)


#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_51_INCLASS \
private: \
	static void StaticRegisterNativesAItemActor(); \
	friend struct Z_Construct_UClass_AItemActor_Statics; \
public: \
	DECLARE_CLASS(AItemActor, AActor, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/Inventory"), NO_API) \
	DECLARE_SERIALIZER(AItemActor)


#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_51_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AItemActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AItemActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AItemActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AItemActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AItemActor(AItemActor&&); \
	NO_API AItemActor(const AItemActor&); \
public:


#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_51_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AItemActor(AItemActor&&); \
	NO_API AItemActor(const AItemActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AItemActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AItemActor); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AItemActor)


#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_48_PROLOG \
	FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_51_EVENT_PARMS


#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_51_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_51_SPARSE_DATA \
	FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_51_RPC_WRAPPERS \
	FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_51_CALLBACK_WRAPPERS \
	FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_51_INCLASS \
	FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_51_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_51_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_51_SPARSE_DATA \
	FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_51_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_51_CALLBACK_WRAPPERS \
	FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_51_INCLASS_NO_PURE_DECLS \
	FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h_51_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> INVENTORY_API UClass* StaticClass<class AItemActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Horror_Plugins_Inventory_Source_Inventory_Classes_Inventory_ItemActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
