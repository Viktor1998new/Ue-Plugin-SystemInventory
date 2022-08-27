#pragma once
#include "Widgets/Layout/SConstraintCanvas.h"
#include "InventoryUMG/InventoryGrid.h"
#include "InventoryUMG/InventoryGridSlot.h"

UInventoryGridSlot::UInventoryGridSlot(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
	,Slot(nullptr)
	,ParentPanel(nullptr)
	,IndexItem(-1)
	,ZOrder(0)
{
}

void UInventoryGridSlot::BuildSlot(TSharedRef<SConstraintCanvas> GridPanel)
{
	GridPanel->AddSlot()
		.Alignment(FVector2D(0.0f))
		.AutoSize(false)
		.Anchors(FAnchors(0.0f))
		.Expose(Slot)
		[
			Content == nullptr ? SNullWidget::NullWidget : Content->TakeWidget()
		];


}

void UInventoryGridSlot::SetSize(FIntPoint NewSize)
{
	Transform.Offsets.Right = NewSize.X * ParentPanel->SizeSlot;
	Transform.Offsets.Bottom = NewSize.Y * ParentPanel->SizeSlot;

	if (Slot)
		Slot->SetOffset(Transform.Offsets);
}

void UInventoryGridSlot::SetPosition(FIntPoint NewPosition)
{
	SlotPosition = NewPosition;

	Transform.Offsets.Left = NewPosition.X * ParentPanel->SizeSlot;
	Transform.Offsets.Top = NewPosition.Y * ParentPanel->SizeSlot;

	if (Slot)
		Slot->SetOffset(Transform.Offsets);
}

void UInventoryGridSlot::SetTransform(FIntPoint NewPosition, FIntPoint NewSize) {

	SlotPosition = NewPosition;

	Transform.Offsets.Left = NewPosition.X * ParentPanel->SizeSlot;
	Transform.Offsets.Top = NewPosition.Y * ParentPanel->SizeSlot;

	Transform.Offsets.Right = NewSize.X * ParentPanel->SizeSlot;
	Transform.Offsets.Bottom = NewSize.Y * ParentPanel->SizeSlot;

	if (Slot)
		Slot->SetOffset(Transform.Offsets);
}

void UInventoryGridSlot::SetZOrder(int32 InZOrder)
{
	ZOrder = InZOrder;

	if (Slot)
		Slot->SetZOrder(InZOrder);
}

void UInventoryGridSlot::SetIndexItem(int32 NewIndex)
{
	FInventorySlot L_Slot = ParentPanel->Inventory->Items[NewIndex];
	FIntPoint L_SlotSize = L_Slot.ItemAsset->SlotItemData.SizeSlot;
	IndexItem = NewIndex;
	SetTransform(L_Slot.PositionSlot,L_SlotSize);
	OnChangedSlot.Broadcast(NewIndex, L_Slot);
}

void UInventoryGridSlot::SynchronizeProperties() {

	FInventorySlot L_Slot = ParentPanel->Inventory->Items[IndexItem];
	FIntPoint L_SlotSize = L_Slot.ItemAsset->SlotItemData.SizeSlot;
	SetTransform(L_Slot.PositionSlot, L_SlotSize);

}