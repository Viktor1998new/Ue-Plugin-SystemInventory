// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inventory.h"
#include "ItemActor.h"
#include "InventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddItem, int32, Index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRemoveItem, int32, Index);

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
	Remove
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INVENTORY_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

#if WITH_EDITOR
		virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing = OnRep_SetItems)
		TArray<FInventorySlot> Items;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
		FIntPoint MaxSlot;

	UPROPERTY(BlueprintReadOnly, Replicated)
		float CurrentMassa;

	UPROPERTY(BlueprintAssignable)
		FOnAddItem OnAddItem;

	UPROPERTY(BlueprintAssignable)
		FOnRemoveItem OnRemoveItem;

	int32 ItemIndex;

	ETypeSetItem TypeSetItem;

	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
public:

	/*Adding a slot
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

	UFUNCTION()
		void OnRep_SetItems();

	UFUNCTION(Client, Reliable)
		void ClientRPC_EventSetItem(int32 Index, ETypeSetItem Type);

};