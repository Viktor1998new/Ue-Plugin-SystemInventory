// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Components/PanelWidget.h"
#include "Widgets/Layout/SConstraintCanvas.h"
#include "InventoryComponent.h"
#include "InventoryPanel.generated.h"

class UInventoryPanelSlot;
/**
 * 
 */
UCLASS(abstract)
class INVENTORY_API UInventoryPanel : public UPanelWidget
{
	GENERATED_UCLASS_BODY()

		UInventoryComponent* Inventory;

public:
	UPROPERTY(EditAnywhere)
		int32 SizeSlot = 32;

	UPROPERTY(EditAnywhere)
		bool AutoSize = false;

	UFUNCTION(BlueprintCallable)
	void SetInventory(UInventoryComponent* NewInventory);

	UFUNCTION(BlueprintPure, Category = "Slot")
		static UInventoryPanelSlot* SlotAsInventorySlot(UWidget* Widget);

	UFUNCTION(BlueprintPure)
		UInventoryComponent* GetInventory()const {
			return Inventory;
	};

	int32 GetSlotAtItem(int32 ItemIndex);


protected:

	UInventoryPanelSlot* AddSlot(int32 IndexItem);

	void RemoveSlot(int32 IndexItem);
	
	UFUNCTION()
		void Event_AddSlot(int32 IndexItem);

	UFUNCTION()
		void Event_RemoveSlot(int32 IndexItem);

	UFUNCTION(BlueprintCallable)
		virtual UWidget* CreateContent();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "CreateContent"))
		void ReceiveCreateContent(UWidget*& Content);

	virtual void BeginDestroy() override;

	// UPanelWidget
	virtual UClass* GetSlotClass() const override;
	virtual void OnSlotAdded(UPanelSlot* inSlot) override;
	virtual void OnSlotRemoved(UPanelSlot* inSlot) override;

protected:

	TSharedPtr<SConstraintCanvas> MyInventoryPanel;

protected:

	// UWidget interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
};
