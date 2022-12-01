//Copyright(c) 2022, Viktor.F.P

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Components/PanelWidget.h"
#include "Widgets/Layout/SConstraintCanvas.h"
#include "Inventory/InventoryComponent.h"
#include "InventoryGrid.generated.h"

class UInventoryGridSlot;

UCLASS()
class INVENTORY_API UInventoryGrid : public UPanelWidget
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(Instanced)
		TArray<UInventoryGridSlot*> ItemSlots;

	UPROPERTY()
		UInventoryComponent* Inventory;

public:
	UPROPERTY(EditAnywhere, NoClear, Category = "InventoryGrid")
		TSubclassOf<UUserWidget> ItemSlot;
	
	UPROPERTY(EditAnywhere, NoClear, Category = "InventoryGrid")
		TSubclassOf<UUserWidget> NoneSlot;

	UPROPERTY(EditAnywhere, Category = "InventoryGrid")
		float SizeSlot = 32;

#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif

	UFUNCTION(BlueprintCallable, Category = "InventoryGrid")
	void SetInventory(UInventoryComponent* NewInventory);

	UFUNCTION(BlueprintPure, Category = "Slot")
		static UInventoryGridSlot* SlotAsInventorySlot(UWidget* Widget);

	UFUNCTION(BlueprintPure, Category = "InventoryGrid")
		UInventoryComponent* GetInventory() const {
			return Inventory;
	};

	void ReleaseSlateResources(bool bReleaseChildren) override;

protected:
	
	void AddNoneSlot(FIntPoint Position);

	void AddSlot(int32 IndexItem);

	void RemoveSlot(int32 IndexItem);
	
	UFUNCTION()
		void Event_NewDataSlot(int32 Index, FInventorySlot NewData, ETypeSetItem Type);

	virtual void RemoveFromParent() override;

	// UPanelWidget
	virtual UClass* GetSlotClass() const override;
	virtual void OnSlotAdded(UPanelSlot* inSlot) override;
	virtual void OnSlotRemoved(UPanelSlot* inSlot) override;

protected:

	TSharedPtr<SConstraintCanvas> MyPanel;

	// UWidget interface
	virtual TSharedRef<SWidget> RebuildWidget() override;

	UFUNCTION()
		void ChangeSlots(int32 Index, FInventorySlot NewData, ETypeSetItem Type);

};
