//Copyright(c) 2022 - 2025, Viktor.F.P

#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Input/Reply.h"
#include "InventoryWidget.generated.h"

UCLASS(HideDropdown)
class INVENTORYEDITOR_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	class UInventoryGrid* InventoryGrid;
	class UInventoryList* InventoryList;
	TArray<class UInventoryComponent*> Inventors;

	int32 CurrentActive = 0;

	bool IsListInventors = true;

	uint8 Panel = 0;

	FReply RecalculationMass();

	void SwitchPanel(uint8 NewPanel);

	void SetInventory(UInventoryComponent* NewInventory, uint8 NewPanel);
	void SetInventory(TArray<UInventoryComponent*> NewInventors, uint8 NewPanel);

	virtual void RemoveFromParent() override;
	void SelectInventory(int32 Index);

protected:

	TSharedPtr<class STextBlock> TextNameActor;
	TSharedPtr<class SHorizontalBox> Recalculation;
	TSharedPtr<class SWidgetSwitcher> Switcher;
	TSharedPtr<class STextBlock> MassText;
	TSharedPtr<class SComboButton> ListInventoryButtons;

	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;

	TSharedRef<SWidget> GetListInventors();

	// UWidget interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
};