

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
	IndexItem = NewIndex;
	DataSlot = ParentPanel->Inventory->Items[NewIndex];
	SetPosition(FVector2D(ParentPanel->Inventory->Items[NewIndex].PositionSlot.X * ParentPanel->SizeSlot, ParentPanel->Inventory->Items[NewIndex].PositionSlot.Y * ParentPanel->SizeSlot));
	SetSize(FVector2D(DataSlot.ClassItem.GetDefaultObject()->ItemData.SizeSlot.X * ParentPanel->SizeSlot, DataSlot.ClassItem.GetDefaultObject()->ItemData.SizeSlot.Y * ParentPanel->SizeSlot));
}
