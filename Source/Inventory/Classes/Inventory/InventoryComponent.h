// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemActor.h"
#include "InventoryComponent.generated.h"

class UInventorySettings;

USTRUCT(BlueprintType)
struct INVENTORY_API FInventorySlot
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AItemActor> ClassItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FIntPoint PositionSlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ItemData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Count;
};

UENUM()
enum ETypeSetItem
{
	Add,
	Remove,
	SetCount,
	SetPosition
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddItem, int32, Index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRemoveItem, int32, Index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FNewDataSlot, int32, Index, FInventorySlot, NewData, ETypeSetItem, SetType);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType)
class INVENTORY_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure)
		static UInventorySettings* GetInventorySetting();

	UPROPERTY(EditInstanceOnly,BlueprintReadOnly, ReplicatedUsing = OnRep_SetItems)
		TArray<FInventorySlot> Items;
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Replicated)
		float CurrentMassa;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
		FIntPoint MaxSlot;

	UPROPERTY(BlueprintAssignable)
		FOnAddItem OnAddItem;

	UPROPERTY(BlueprintAssignable)
		FOnRemoveItem OnRemoveItem;

		FNewDataSlot NewDataSlot;

	// Sets default values for this component's properties
	UInventoryComponent();

private:
	
	bool IsPositionFreeDrop(FIntPoint Position, int32 DropIndex);

protected:

	ETypeSetItem TypeSetItem;

	int32 ItemIndex;

public:

	/*Adding a slot
	 * @param NewSlot - The new active state of the component
	  Use only in Server*/
	UFUNCTION(BlueprintCallable)
		bool AddSlot(FInventorySlot NewSlot, bool FindPositionSlot, int32& Index);

	/*Adding an item
	 Use only in Server*/
	UFUNCTION(BlueprintCallable)
		bool AddActorItem(AItemActor* Item, int32& Index);

	/*Adding an item
	 Use only in Server*/
	UFUNCTION(BlueprintCallable)
		bool AddClassItem(TSubclassOf<AItemActor> Item, int32 Count, const FString& Data, int32& Index);

	/*The function for searching for free space and can also be used to check whether the slot fits into the inventory */
	UFUNCTION(BlueprintCallable)
		bool FindFreeSlot(FIntPoint Size,FIntPoint &ReturnPosition);

	/*search function for an item by class or class child*/
	UFUNCTION(BlueprintCallable)
		bool FindItem(TSubclassOf<AItemActor> ClassItem ,bool Child,int32& Index);

	/*Removing an item
	 Use only in Server*/
	UFUNCTION(BlueprintCallable)
		bool RemoveItem(int32 Index, int32 count);

	/*the function sends an item from the current inventory to another one
	 Use only in Server*/
	UFUNCTION(BlueprintCallable)
		bool SendItem(int32 Index, class UInventoryComponent* ToIntentory, int32 Count, bool FindSlot , FIntPoint Position);

	/*the function checks whether the element can be placed in this position*/
	UFUNCTION(BlueprintCallable)
		bool IsPositionFree(FIntPoint Position, FIntPoint Size, int32 &Index);

	UFUNCTION(BlueprintCallable)
		bool DropItem(int32 IndexItem,UInventoryComponent* ToInventory, int32 ToIndex, FIntPoint ToPosition);

	UFUNCTION()
		void OnRep_SetItems();

	UFUNCTION(Client, Reliable)
		void ClientRPC_EventSetItem(int32 Index, FInventorySlot NewData, ETypeSetItem Type);

#if WITH_EDITOR
	// Only Edit
	UFUNCTION(BlueprintCallable)
		void RecalculationMass();
#endif
};