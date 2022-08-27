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
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnChangedSlot, int32, Index, FInventorySlot, Slot);

UCLASS()
class INVENTORY_API UInventoryGridSlot : public UPanelSlot
{
    GENERATED_UCLASS_BODY()

public:
	UPROPERTY()
		UInventoryGrid* ParentPanel;

	UPROPERTY()
		FSlotTransformData Transform;

	UPROPERTY()
		int32 IndexItem;

	UPROPERTY(BlueprintReadOnly)
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
private:

	SConstraintCanvas::FSlot* Slot;

};