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
struct FIntPoint;
class AItemActor;
class UInventorySettings;
#ifdef INVENTORY_InventoryComponent_generated_h
#error "InventoryComponent.generated.h already included, missing '#pragma once' in InventoryComponent.h"
#endif
#define INVENTORY_InventoryComponent_generated_h

#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_15_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FInventorySlot_Statics; \
	static class UScriptStruct* StaticStruct();


template<> INVENTORY_API UScriptStruct* StaticStruct<struct FInventorySlot>();

#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_43_DELEGATE \
struct _Script_Inventory_eventNewDataSlot_Parms \
{ \
	int32 Index; \
	FInventorySlot NewData; \
	TEnumAsByte<ETypeSetItem> SetType; \
}; \
static inline void FNewDataSlot_DelegateWrapper(const FMulticastScriptDelegate& NewDataSlot, int32 Index, FInventorySlot NewData, ETypeSetItem SetType) \
{ \
	_Script_Inventory_eventNewDataSlot_Parms Parms; \
	Parms.Index=Index; \
	Parms.NewData=NewData; \
	Parms.SetType=SetType; \
	NewDataSlot.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_42_DELEGATE \
struct _Script_Inventory_eventOnRemoveItem_Parms \
{ \
	int32 Index; \
}; \
static inline void FOnRemoveItem_DelegateWrapper(const FMulticastScriptDelegate& OnRemoveItem, int32 Index) \
{ \
	_Script_Inventory_eventOnRemoveItem_Parms Parms; \
	Parms.Index=Index; \
	OnRemoveItem.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_41_DELEGATE \
struct _Script_Inventory_eventOnAddItem_Parms \
{ \
	int32 Index; \
}; \
static inline void FOnAddItem_DelegateWrapper(const FMulticastScriptDelegate& OnAddItem, int32 Index) \
{ \
	_Script_Inventory_eventOnAddItem_Parms Parms; \
	Parms.Index=Index; \
	OnAddItem.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_SPARSE_DATA
#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_RPC_WRAPPERS \
	virtual void ClientRPC_EventSetItem_Implementation(int32 Index, FInventorySlot NewData, ETypeSetItem Type); \
 \
	DECLARE_FUNCTION(execClientRPC_EventSetItem); \
	DECLARE_FUNCTION(execOnRep_SetItems); \
	DECLARE_FUNCTION(execDropItem); \
	DECLARE_FUNCTION(execIsPositionFree); \
	DECLARE_FUNCTION(execSendItem); \
	DECLARE_FUNCTION(execRemoveItem); \
	DECLARE_FUNCTION(execFindItem); \
	DECLARE_FUNCTION(execFindFreeSlot); \
	DECLARE_FUNCTION(execAddClassItem); \
	DECLARE_FUNCTION(execAddActorItem); \
	DECLARE_FUNCTION(execAddSlot); \
	DECLARE_FUNCTION(execGetInventorySetting);


#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void ClientRPC_EventSetItem_Implementation(int32 Index, FInventorySlot NewData, ETypeSetItem Type); \
 \
	DECLARE_FUNCTION(execClientRPC_EventSetItem); \
	DECLARE_FUNCTION(execOnRep_SetItems); \
	DECLARE_FUNCTION(execDropItem); \
	DECLARE_FUNCTION(execIsPositionFree); \
	DECLARE_FUNCTION(execSendItem); \
	DECLARE_FUNCTION(execRemoveItem); \
	DECLARE_FUNCTION(execFindItem); \
	DECLARE_FUNCTION(execFindFreeSlot); \
	DECLARE_FUNCTION(execAddClassItem); \
	DECLARE_FUNCTION(execAddActorItem); \
	DECLARE_FUNCTION(execAddSlot); \
	DECLARE_FUNCTION(execGetInventorySetting);


#if WITH_EDITOR
#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_EDITOR_ONLY_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execRecalculationMass);


#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_EDITOR_ONLY_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execRecalculationMass);


#else
#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_EDITOR_ONLY_RPC_WRAPPERS
#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_EDITOR_ONLY_RPC_WRAPPERS_NO_PURE_DECLS
#endif //WITH_EDITOR
#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_EVENT_PARMS \
	struct InventoryComponent_eventClientRPC_EventSetItem_Parms \
	{ \
		int32 Index; \
		FInventorySlot NewData; \
		TEnumAsByte<ETypeSetItem> Type; \
	};


#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_CALLBACK_WRAPPERS
#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUInventoryComponent(); \
	friend struct Z_Construct_UClass_UInventoryComponent_Statics; \
public: \
	DECLARE_CLASS(UInventoryComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Inventory"), NO_API) \
	DECLARE_SERIALIZER(UInventoryComponent) \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		Items=NETFIELD_REP_START, \
		CurrentMassa, \
		MaxSlot, \
		NETFIELD_REP_END=MaxSlot	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_INCLASS \
private: \
	static void StaticRegisterNativesUInventoryComponent(); \
	friend struct Z_Construct_UClass_UInventoryComponent_Statics; \
public: \
	DECLARE_CLASS(UInventoryComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Inventory"), NO_API) \
	DECLARE_SERIALIZER(UInventoryComponent) \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		Items=NETFIELD_REP_START, \
		CurrentMassa, \
		MaxSlot, \
		NETFIELD_REP_END=MaxSlot	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventoryComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventoryComponent(UInventoryComponent&&); \
	NO_API UInventoryComponent(const UInventoryComponent&); \
public:


#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventoryComponent(UInventoryComponent&&); \
	NO_API UInventoryComponent(const UInventoryComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UInventoryComponent)


#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_PRIVATE_PROPERTY_OFFSET
#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_45_PROLOG \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_EVENT_PARMS


#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_PRIVATE_PROPERTY_OFFSET \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_SPARSE_DATA \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_RPC_WRAPPERS \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_EDITOR_ONLY_RPC_WRAPPERS \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_CALLBACK_WRAPPERS \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_INCLASS \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_PRIVATE_PROPERTY_OFFSET \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_SPARSE_DATA \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_RPC_WRAPPERS_NO_PURE_DECLS \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_EDITOR_ONLY_RPC_WRAPPERS_NO_PURE_DECLS \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_CALLBACK_WRAPPERS \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_INCLASS_NO_PURE_DECLS \
	Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h_48_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> INVENTORY_API UClass* StaticClass<class UInventoryComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Aplha_Plugins_Inventory_Source_Inventory_Classes_Inventory_InventoryComponent_h


#define FOREACH_ENUM_ETYPESETITEM(op) \
	op(Add) \
	op(Remove) \
	op(SetCount) \
	op(SetPosition) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
