

#include "InventoryUMG/InventoryGridSlot.h"
#include "InventoryUMG/InventoryGrid.h"

UInventoryGridSlot::UInventoryGridSlot(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, Slot(nullptr)
{
	Transform.Offsets = FMargin(0, 0, 100, 30);
	Transform.Anchors = FAnchors(0.0f, 0.0f);
	Transform.Alignment = FVector2D(0.0f, 0.0f);
	ZOrder = 0;
}

void UInventoryGridSlot::BuildSlot(TSharedRef<SConstraintCanvas> GridPanel)
{
	Slot = &GridPanel->AddSlot()
		[
			Content == nullptr ? SNullWidget::NullWidget : Content->TakeWidget()
		];
	Slot->Alignment(FVector2D(0.0f, 0.0f));

}

void UInventoryGridSlot::SetSize(FVector2D InSize)
{
	Transform.Offsets.Right = InSize.X;
	Transform.Offsets.Bottom = InSize.Y;

	if (Slot)
	{
		Slot->Offset(Transform.Offsets);
	}
}

void UInventoryGridSlot::SetPosition(FVector2D InPosition)
{
	Transform.Offsets.Left = InPosition.X;
	Transform.Offsets.Top = InPosition.Y;

	if (Slot)
	{
		Slot->Offset(Transform.Offsets);
	}
}

void UInventoryGridSlot::SetZOrder(int32 InZOrder)
{
	ZOrder = InZOrder;
	if (Slot)
	{
		Slot->ZOrder(InZOrder);
	}
}

void UInventoryGridSlot::SetIndexItem(int32 NewIndex)
{
	UInventoryGrid* ParentPanel = Cast<UInventoryGrid>(Parent);
	FInventorySlot L_Slot = ParentPanel->Inventory->Items[NewIndex];
	FIntPoint L_SlotSize = L_Slot.ClassItem.GetDefaultObject()->ItemData.SizeSlot;
	IndexItem = NewIndex;
	SetPosition(FVector2D(L_Slot.PositionSlot.X * ParentPanel->SizeSlot, L_Slot.PositionSlot.Y * ParentPanel->SizeSlot));
	SetSize(FVector2D(L_SlotSize.X * ParentPanel->SizeSlot, L_SlotSize.Y * ParentPanel->SizeSlot));
	OnChangedSlot.Broadcast(NewIndex, L_Slot);
}
