// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inventory.h"
#include "ItemActor.h"
#include "InventoryComponent.generated.h"

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

UCLASS(config = Engine, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INVENTORY_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

#if WITH_EDITOR
		virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated)
		TArray<FInventorySlot> Items;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
		FIntPoint MaxSlot;

	UPROPERTY(BlueprintReadOnly, Replicated)
		float CurrentMassa;


	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
public:

	/*Adding a slot
	  Use only in Server*/
	UFUNCTION(BlueprintCallable)
		bool AddSlot(FInventorySlot NewSlot, bool FindPositionSlot, int& Index);

	/*Adding an item
	 Use only in Server*/
	UFUNCTION(BlueprintCallable)
		bool AddActorItem(AItemActor* Item, int& Index);

	/*Adding an item
	 Use only in Server*/
	UFUNCTION(BlueprintCallable)
		bool AddClassItem(TSubclassOf<AItemActor> Item, int Count, const FString& Data, int& Index);

	/*The function for searching for free space and can also be used to check whether the slot fits into the inventory */
	UFUNCTION(BlueprintCallable)
		bool FindFreeSlot(FIntPoint Size,FIntPoint &ReturnPosition);

	/*search function for an item by class or class child*/
	UFUNCTION(BlueprintCallable)
		bool FindItem(TSubclassOf<AItemActor> ClassItem ,bool Child,int& Index);

	/*Removing an item
	 Use only in Server*/
	UFUNCTION(BlueprintCallable)
		bool RemoveItem(int Index, int count);

	/*the function sends an item from the current inventory to another one
	 Use only in Server*/
	UFUNCTION(BlueprintCallable)
		bool SendItem(int Index, class UInventoryComponent* ToIntentory, int Count, bool FindSlot , FIntPoint Position);

	/*the function checks whether the element can be placed in this position*/
	UFUNCTION(BlueprintCallable)
		bool IsPositionFree(FIntPoint Position, FIntPoint Size, int &Index);
};