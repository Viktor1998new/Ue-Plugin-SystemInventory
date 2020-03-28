#pragma once


#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"
#include "Widgets/Layout/SConstraintCanvas.h"
#include "Layout/Margin.h"
#include "Components/PanelSlot.h"

#include "InventoryPanelSlot.generated.h"

struct FInventorySlot;

USTRUCT(BlueprintType)
struct FSlotTransformData
{
public:
	GENERATED_USTRUCT_BODY()

public:

	/** Offset. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnchorData)
		FMargin Offsets;

	/** Anchors. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnchorData)
		FAnchors Anchors;

	/**
	 * Alignment is the pivot point of the widget.  Starting in the upper left at (0,0),
	 * ending in the lower right at (1,1).  Moving the alignment point allows you to move
	 * the origin of the widget.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnchorData)
		FVector2D Alignment;

	/**
	* Compares this set of FAnchorData with another for equality.
	*
	* @param Other The other FAnchorData.
	* @return true if the two FAnchors are equal, false otherwise.
	*/
	bool operator==(const FSlotTransformData& Other) const
	{
		return Offsets == Other.Offsets &&
			Anchors == Other.Anchors &&
			Alignment == Other.Alignment;
	}

	/**
	* Compares this set of FAnchorData with another for inequality.
	*
	* @param Other The other FAnchorData.
	* @return true if the two FAnchors are not equal, false otherwise.
	*/
	bool operator!=(const FSlotTransformData& Other) const
	{
		return !(*this == Other);
	}
};
/**
 * The Slot for the UBorderSlot, contains the widget displayed in a border's single slot
 */
UCLASS()
class INVENTORY_API UInventoryPanelSlot : public UPanelSlot
{
    GENERATED_UCLASS_BODY()

public:

	FSlotTransformData Transform;
	
	FInventorySlot DataSlot;

	int32 IndexItem;

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

	UFUNCTION(BlueprintCallable)
	int32 GetItemIndex() const {
		return IndexItem;
	}

private:
    SConstraintCanvas::FSlot* Slot;

};