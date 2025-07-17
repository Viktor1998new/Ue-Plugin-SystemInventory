//Copyright(c) 2022 - 2025, Viktor.F.P
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventorySlot.h"
#include "InventoryComponent.generated.h"

USTRUCT(BlueprintType)
struct INVENTORY_API FInventory
{
	GENERATED_BODY()

	UPROPERTY(VisibleInstanceOnly,BlueprintReadOnly, Category = "Inventory")
		TArray<FInventorySlot> Items;

	UPROPERTY(VisibleInstanceOnly,BlueprintReadOnly, Category = "Inventory")
		float Massa;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Inventory", meta = (ClampMin = 1))
		int CountRow;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "Inventory", meta = (ClampMin = 1))
		int MaxSlot;

	FInventory();
};

UENUM(BlueprintType)
enum class ETypeSetItem : uint8
{
	Add,
	Remove,
	ChangeSlot,
	SetPosition
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddItem, int32, Index);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRemoveItem, int32, Index);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FNewDataSlot, int32, Index, FInventorySlot, NewData, ETypeSetItem, SetType);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), NotBlueprintable, BlueprintType)
class INVENTORY_API UInventoryComponent : public UActorComponent {
	
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, Category = "Inventory")
		FInventory Inventory;

	UPROPERTY(BlueprintAssignable)
		FOnAddItem OnAddItem;

	UPROPERTY(BlueprintAssignable)
		FOnRemoveItem OnRemoveItem;

	FNewDataSlot NewDataSlot;

	// Sets default values for this component's properties
	UInventoryComponent();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void SetInventory(FInventory NewInventory) {
			Inventory = NewInventory;
		};


	UFUNCTION(BlueprintPure, Category = "Inventory")
		FInventory& GetInventory() {
			return Inventory;
		};

	UFUNCTION(BlueprintPure, Category = "Inventory|Item")
		FInventorySlot& GetItem(int32 Index) {

			checkf((Index >= 0) & (Index < Inventory.Items.Num()), TEXT("Array index out of bounds: %i from an array of size %i"), Index, Inventory.Items.Num())
			return Inventory.Items[Index];
		};
	
	UFUNCTION(BlueprintPure, Category = "Inventory|Item")
		bool IsValidIndex(int32 Index) const {
			return Inventory.Items.IsValidIndex(Index);
		};
	
	UFUNCTION(BlueprintPure, Category = "Inventory|Item")
		int32 CountItems() const {
			return Inventory.Items.Num();
		};

	/*Adding a slot
	 * @param NewSlot - The new active state of the component
	  Use only in Server*/
	UFUNCTION(BlueprintCallable, Category = "Inventory|Slot|Add")
		virtual	bool AddSlot(FInventorySlot NewSlot, bool FindPositionSlot, int32& Index);

	/*Adding an item
	 Use only in Server*/
	UFUNCTION(BlueprintCallable, Category = "Inventory|Slot|Add")
		bool AddAssetItem(UItemAsset* ItemAsset, int32 Count, const FString& Data, int32& Index);

	/*Adding an item
		Use only in Server*/
	UFUNCTION(BlueprintCallable, Category = "Inventory|Slot|Add")
		bool AddActorItem(AActor* Item, int32& Index);

	/*Adding an item
		Use only in Server*/
	UFUNCTION(BlueprintCallable, Category = "Inventory|Slot")
		virtual bool SetSlot(int32 Index, FInventorySlot NewValue);

	/*Removing an item
		Use only in Server*/
	UFUNCTION(BlueprintCallable, Category = "Inventory|Slot")
		bool RemoveItem(int32 Index, int32 count);

	/*Rotate an item
		Use only in Server*/
	UFUNCTION(BlueprintCallable, Category = "Inventory|Slot")
		void SetRotateSlot(int32 Index, bool NewRotate);

	/*Ignore position an item
		Use only in Server*/
	UFUNCTION(BlueprintCallable, Category = "Inventory|Slot")
		void SetIgnorePositionSlot(int32 Index, bool NewEnable);

	/*Drop an item
		Use only in Server*/
	UFUNCTION(BlueprintCallable, Category = "Inventory|Slot")
		bool DropItem(int32 IndexItem, int32 ToIndex, int32 Count, FIntPoint ToPosition, bool Change, bool FindPosition, bool Rotate);

	/*the function sends an item from the current inventory to another one
	 Use only in Server*/
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool SendItem(int32 Index, class UInventoryComponent* ToIntentory, int32 Count, bool FindSlot, FIntPoint Position, bool Rotate);

	/*the function checks whether the element can be placed in this position*/
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool IsPositionFree(FIntPoint Position, FIntPoint Size, int32& Index);

	/*The function for searching for free space and can also be used to check whether the slot fits into the inventory */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool FindFreeSlot(FIntPoint Size, FIntPoint& ReturnPosition);

	/*search function for an item by class or class child*/
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		bool FindItem(UItemAsset* ItemAsset, int32& Index);

	UFUNCTION(Client, Reliable)
		void ClientRPC_EventSetItem(int32 Index, FInventorySlot NewData, ETypeSetItem Type);

#if WITH_EDITOR
	// Only Edit
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void RecalculationMass();
#endif

protected:
	void ChangeSlot(int32 Index, FInventorySlot Slot, ETypeSetItem Type);

private:
	int GetCountRow(bool IsEnd) const;

	bool ChangeItem(int32 IndexItem, int32 ToIndex, bool FindPosition);

	bool StackItem(int32 IndexItem, int32 ToIndex, int32 Count);

	bool SetPositionItem(int32 IndexItem, int32 Count, bool Rotate, FIntPoint NewPosition);

};