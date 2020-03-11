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
		FIntPoint LocationSlot;

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
	  Use only Server*/
	UFUNCTION(BlueprintCallable)
		bool AddSlot(FInventorySlot NewSlot, int& Index);

	/*Adding an item
	 Use only Server*/
	UFUNCTION(BlueprintCallable)
		bool AddActorItem(AItemActor* Item, int& Index);

	/*Adding an item
	 Use only Server*/
	UFUNCTION(BlueprintCallable)
		bool AddClassItem(TSubclassOf<AItemActor> Item, int Count, const FString& Data, int& Index);

	UFUNCTION(BlueprintCallable)
		bool FindFreeSlot(FIntPoint Size,FIntPoint &ReturnPosition);

	UFUNCTION(BlueprintCallable)
		bool FindItem(TSubclassOf<AItemActor> ClassItem ,bool Child,int& Index);

	UFUNCTION(BlueprintCallable)
		bool RemoveItem(int Index, int count);


};