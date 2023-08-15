// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UMG/Public/Blueprint/UserWidget.h"
#include "Input/Reply.h"
#include "EditorWidget.generated.h"

/**
 * 
 */
class SConstraintCanvas;
class SVerticalBox;
class STextBlock;
class SHorizontalBoxl;
class UInventoryGrid;
class UInventoryList;
class UInventoryComponent;

UCLASS()
class INVENTORYEDITOR_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	UInventoryGrid* InventoryGrid;
	UInventoryList* InventoryList;
	UInventoryComponent* Inventory;

	uint8 Panel = 0;

	TSharedPtr<STextBlock> TextNameActor;
	TSharedPtr<SHorizontalBox> Recalculation;
	TSharedPtr<class SWidgetSwitcher> Switcher;
	TSharedPtr<STextBlock> MassText;

	FReply RecalculationMass();

	void SwitchPanel(uint8 NewPanel);

	void SetInventory(UInventoryComponent* NewInventory , uint8 NewPanel);

	virtual void RemoveFromParent() override;

protected:

	class UScaleBox* InventoryGridUWidget;
	class UScaleBox* InventoryListUWidget;

	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;

	TSharedPtr<SVerticalBox> MyPanel;

	// UWidget interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
};

UCLASS()
class INVENTORYEDITOR_API UBrowserAssetsWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	TSharedPtr<class SWrapBox> ListAsset;

	TArray<class USlotAssetWidget*> Slots;

	FReply OoClickUpData();

	void GenerationSlots();

protected:

	virtual void NativePreConstruct() override;

	// UWidget interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
};

UCLASS()
class INVENTORYEDITOR_API UEditorWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	bool EnableTick = true;

	TSharedPtr<STextBlock> Text;
	TSharedPtr<SVerticalBox> ListInventory;

	TArray<UObject*> CurrentSelectActors;

	uint8 Panel;

	TMap<AActor*, UInventoryWidget*> Inventorys;

	void AddSelect(TArray<UObject*> NewSelectActors);

	void RemoveSelect(TArray<UObject*> NewSelectActors);

	void ReleaseSlateResources(bool bReleaseChildren) override;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	FReply SwitchList();

	FReply SwitchGrid();

	TArray<UObject*> GetSelectedActors();

	void ClearInventory();

protected:

	TSharedPtr<SConstraintCanvas> MyPanel;

	// UWidget interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
	
	virtual void PostRename(UObject* OldOuter, const FName OldName) override;
};
