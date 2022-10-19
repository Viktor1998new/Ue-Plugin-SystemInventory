//Copyright(c) 2022, Viktor.F.P
#pragma once
#include "InventoryUMG/InventoryGridSlot.h"
#include "Widgets/Layout/SConstraintCanvas.h"
#include "InventoryUMG/InventoryGrid.h"

UInventoryGridSlot::UInventoryGridSlot(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
	,ParentPanel(nullptr)
	,IndexItem(-1)
	,ZOrder(0)
{
}

void UInventoryGridSlot::ChangeTranstrorm(FIntPoint Value, TypeChangeTranstrorm Change) {
	
	switch(Change) {

	case TypeChangeTranstrorm::Position:

		SlotPosition = Value;

		Transform.Offsets.Left = Value.X * ParentPanel->SizeSlot;
		Transform.Offsets.Top = Value.Y * ParentPanel->SizeSlot;
		break;


	case TypeChangeTranstrorm::Size:

		Transform.Offsets.Right = Value.X * ParentPanel->SizeSlot;
		Transform.Offsets.Bottom = Value.Y * ParentPanel->SizeSlot;
		break;
	}

	if (!Slot) return;
		
	Slot->SetOffset(Transform.Offsets);
}

void UInventoryGridSlot::ChangeTranstrorm(FIntPoint Position, FIntPoint Size) {

	SlotPosition = Position;

	if (!Slot) return;

	Transform.Offsets.Left = Position.X * ParentPanel->SizeSlot;
	Transform.Offsets.Top = Position.Y * ParentPanel->SizeSlot;

	Transform.Offsets.Right = Size.X * ParentPanel->SizeSlot;
	Transform.Offsets.Bottom = Size.Y * ParentPanel->SizeSlot;

	Slot->SetOffset(Transform.Offsets);
}

void UInventoryGridSlot::ChangeSlot(FInventorySlot NewData) {

	ChangeTranstrorm(NewData.PositionSlot, NewData.ItemAsset->SlotItemData.SizeSlot);
	OnChangedSlot.Broadcast(IndexItem, NewData);
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
	ChangeTranstrorm(NewSize, Size);
}

void UInventoryGridSlot::SetPosition(FIntPoint NewPosition)
{
	ChangeTranstrorm(NewPosition, Position);
}

void UInventoryGridSlot::SetTransform(FIntPoint NewPosition, FIntPoint NewSize) {

	ChangeTranstrorm(NewPosition, NewSize);
}

void UInventoryGridSlot::SetZOrder(int32 InZOrder)
{
	ZOrder = InZOrder;

	if (Slot)
		Slot->SetZOrder(InZOrder);
}

void UInventoryGridSlot::SetIndexItem(int32 NewIndex)
{
	if (NewIndex == INDEX_NONE) return;

	FInventorySlot L_Slot = ParentPanel->Inventory->Items[NewIndex];
	FIntPoint L_SlotSize = L_Slot.ItemAsset->SlotItemData.SizeSlot;
	IndexItem = NewIndex;
	ChangeTranstrorm(L_Slot.PositionSlot,L_SlotSize);
	OnChangedSlot.Broadcast(IndexItem, ParentPanel->Inventory->Items[IndexItem]);
}

void UInventoryGridSlot::SynchronizeProperties() {

	if (IndexItem == INDEX_NONE) return;

	FInventorySlot L_Slot = ParentPanel->Inventory->Items[IndexItem];
	FIntPoint L_SlotSize = L_Slot.ItemAsset->SlotItemData.SizeSlot;
	ChangeTranstrorm(L_Slot.PositionSlot, L_SlotSize);
	OnChangedSlot.Broadcast(IndexItem, ParentPanel->Inventory->Items[IndexItem]);
}