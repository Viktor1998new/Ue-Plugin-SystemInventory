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
/**
 * The Slot for the UBorderSlot, contains the widget displayed in a border's single slot
 */
UCLASS()
class INVENTORY_API UInventoryGridSlot : public UPanelSlot
{
    GENERATED_UCLASS_BODY()

public:
	FSlotTransformData Transform;
	
	FInventorySlot DataSlot;

	int32 IndexItem;

	FIntPoint SlotPosition;

	int32 ZOrder = 0;

    void BuildSlot(TSharedRef<SConstraintCanvas> GridPanel);

	void SetSize(FVector2D InSize);

	void SetPosition(FVector2D InPosition);

	void SetZOrder(int32 InZOrder);

	void SetIndexItem(int32 NewIndex);

	UFUNCTION(BlueprintPure)
	FInventorySlot GetDataSlot() const {
		return DataSlot;
	}

	UFUNCTION(BlueprintPure)
	int32 GetItemIndex() const {
		return IndexItem;
	}

	UFUNCTION(BlueprintPure)
	FIntPoint GetPosition() const {
		return SlotPosition;
	}

private:
    SConstraintCanvas::FSlot* Slot;

};