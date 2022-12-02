//Copyright(c) 2022, Viktor.F.P
#pragma once
#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"
#include "Widgets/Layout/SConstraintCanvas.h"
#include "Layout/Margin.h"
#include "Components/PanelSlot.h"
#include "Inventory/InventoryComponent.h"
#include "InventoryGridSlot.generated.h"

USTRUCT(BlueprintType)
struct FSlotTransformData
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnchorData)
		FMargin Offsets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnchorData)
		FAnchors Anchors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnchorData)
		FVector2D Alignment;

};

class UInventoryGrid;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnChangedSlot, int32, Index, FInventorySlot, Slot);

UCLASS()
class INVENTORY_API UInventoryGridSlot : public UPanelSlot
{
    GENERATED_UCLASS_BODY()

	
	UInventoryGrid* ParentPanel;

public:

	UPROPERTY()
		FSlotTransformData Transform;

	UPROPERTY(BlueprintReadOnly, Category = "InventoryGrid|Slot")
		int32 IndexItem;

	UPROPERTY(BlueprintReadOnly, Category = "InventoryGrid|Slot")
		FIntPoint SlotPosition;

		int32 ZOrder = 0;

	UPROPERTY(BlueprintAssignable)
		FOnChangedSlot OnChangedSlot;

    void BuildSlot(TSharedRef<SConstraintCanvas> GridPanel);

	void SetSize(FIntPoint NewSize);

	void SetPosition(FIntPoint NewPosition);

	void SetTransform(FIntPoint NewPosition, FIntPoint NewSize);

	void SetZOrder(int32 InZOrder);

	void SetIndexItem(int32 NewIndex);

	virtual void SynchronizeProperties() override;

	void ChangeSlot(FInventorySlot NewData);

private:

	enum TypeChangeTranstrorm {
		Position,
		Size
	};

	void ChangeTranstrorm(FIntPoint Value, TypeChangeTranstrorm Change);
	void ChangeTranstrorm(FIntPoint Position, FIntPoint Size);

	SConstraintCanvas::FSlot* Slot;

};