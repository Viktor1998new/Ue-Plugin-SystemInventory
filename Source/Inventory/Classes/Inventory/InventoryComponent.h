//Copyright(c) 2022, Viktor.F.P

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Slot")
		UItemAsset* ItemAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Slot")
		FIntPoint PositionSlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Slot")
		FString ItemData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Slot")
		int32 Count;

	bool IsPosition(FIntPoint Position, FIntPoint Size);

	bool operator == (const FInventorySlot &A) {

		return ItemAsset == A.ItemAsset && ItemData == A.ItemData;
	}

	void operator ++() {
		Count++;
	}

	void operator --() {
		Count--;
	}
};

USTRUCT(BlueprintType)
struct INVENTORY_API FInventory
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
		TArray<FInventorySlot> Items;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
		float Massa;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory")
		FIntPoint MaxSlot;

	FInventory();

	FInventory(class UInventoryComponent* InventoryComponent);
};

UENUM()
enum ETypeSetItem
{
	Add,
	Remove,
	ChangeSlot,
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

	UFUNCTION(BlueprintPure, Category = "Inventory")
		static UInventorySettings* GetInventorySetting();

	UPROPERTY(EditInstanceOnly,BlueprintReadOnly, Replicated, Category = "Inventory")
		TArray<FInventorySlot> Items;
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Replicated, Category = "Inventory")
		float CurrentMassa;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Slot")
		FIntPoint MaxSlot;

	UPROPERTY(BlueprintAssignable)
		FOnAddItem OnAddItem;

	UPROPERTY(BlueprintAssignable)
		FOnRemoveItem OnRemoveItem;

		FNewDataSlot NewDataSlot;

	// Sets default values for this component's properties
	UInventoryComponent();

public:

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SetInventory(FInventory NewInventory) {
		Items = NewInventory.Items;
		CurrentMassa = NewInventory.Massa;
		MaxSlot = NewInventory.MaxSlot;
	};


	UFUNCTION(BlueprintPure, Category = "Inventory")
	FInventory GetInventory() {
		return FInventory(this);
	};

	/*Adding a slot
	 * @param NewSlot - The new active state of the component
	  Use only in Server*/
	UFUNCTION(BlueprintCallable, Category = "Inventory|Slot|Add")
		bool AddSlot(FInventorySlot NewSlot, bool FindPositionSlot, int32& Index);

	/*Adding an item
	 Use only in Server*/
	UFUNCTION(BlueprintCallable, Category = "Inventory|Slot|Add")
		bool AddActorItem(AItemActor* Item, int32& Index );

	/*Adding an item
	 Use only in Server*/
	UFUNCTION(BlueprintCallable, Category = "Inventory|Slot")
		bool SetSlot(int32 Index, FInventorySlot NewValue);

	/*Adding an item
	 Use only in Server*/
	UFUNCTION(BlueprintCallable, Category = "Inventory|Slot|Add")
		bool AddAssetItem(UItemAsset* ItemAsset, int32 Count, const FString& Data, int32& Index);

	/*The function for searching for free space and can also be used to check whether the slot fits into the inventory */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool FindFreeSlot(FIntPoint Size,FIntPoint &ReturnPosition);

	/*search function for an item by class or class child*/
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool FindItem(UItemAsset* ItemAsset,int32& Index);

	/*Removing an item
	 Use only in Server*/
	UFUNCTION(BlueprintCallable, Category = "Inventory|Slot")
		bool RemoveItem(int32 Index, int32 count);

	/*the function sends an item from the current inventory to another one
	 Use only in Server*/
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool SendItem(int32 Index, class UInventoryComponent* ToIntentory, int32 Count, bool FindSlot , FIntPoint Position);

	/*the function checks whether the element can be placed in this position*/
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool IsPositionFree(FIntPoint Position, FIntPoint Size, int32 &Index);

	UFUNCTION(BlueprintCallable, Category = "Inventory|Slot")
		bool DropItem(int32 IndexItem, int32 ToIndex, int32 Count, FIntPoint ToPosition);

	UFUNCTION(Client, Reliable)
		void ClientRPC_EventSetItem(int32 Index, FInventorySlot NewData, ETypeSetItem Type);

#if WITH_EDITOR
	// Only Edit
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void RecalculationMass();
#endif

	private:
	void ChangeSlot(int32 Index, FInventorySlot Slot, ETypeSetItem Type);
};