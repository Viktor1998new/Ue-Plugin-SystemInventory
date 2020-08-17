// Fill out your copyright notice in the Description page of Project Settings.

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

		UInventoryComponent* Inventory;

public:

	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> ContentItemSlot;
	
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> ContentNoneSlot;

	UPROPERTY(EditAnywhere)
		float SizeSlot = 32;

#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif

	UFUNCTION(BlueprintCallable)
	void SetInventory(UInventoryComponent* NewInventory);

	UFUNCTION(BlueprintPure, Category = "Slot")
		static UInventoryGridSlot* SlotAsInventorySlot(UWidget* Widget);

	UFUNCTION(BlueprintPure)
		UInventoryComponent* GetInventory()const {
			return Inventory;
	};

	
	UFUNCTION(BlueprintPure)
		int32 GetSlotAtItem(int32 ItemIndex);

protected:
	
	void AddNoneSlot(FIntPoint Position);

	UInventoryGridSlot* AddSlot(int32 IndexItem);

	void RemoveSlot(int32 IndexItem);
	
	UFUNCTION()
		void Event_NewDataSlot(int32 Index, FInventorySlot NewData, ETypeSetItem Type);

	virtual void BeginDestroy() override;

	// UPanelWidget
	virtual UClass* GetSlotClass() const override;
	virtual void OnSlotAdded(UPanelSlot* inSlot) override;
	virtual void OnSlotRemoved(UPanelSlot* inSlot) override;

protected:

	TSharedPtr<SConstraintCanvas> MyPanel;

protected:

	// UWidget interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
};
