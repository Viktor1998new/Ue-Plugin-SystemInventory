#include "InventorySlot.h"
#include "InventorySettings.h"

bool FInventorySlot::IsPosition(FIntPoint Position, FIntPoint Size) {

	if (Position == PositionSlot)
		return true;

	if (HasInventoryFlag(EInventoryFlag::Size)) {

		FIntPoint SizeItem = GetSize();

		SizeItem -= 1;
		Size -= 1;

		if ((Position.X >= PositionSlot.X && Position.X <= PositionSlot.X + SizeItem.X) ||
			(Position.X + Size.X >= PositionSlot.X)) {

			if (HasInventoryFlag(EInventoryFlag::OnlyX)) return true;

			return (Position.Y >= PositionSlot.Y && Position.Y <= PositionSlot.Y + SizeItem.Y) || 
				(Position.Y + Size.Y >= PositionSlot.Y);
		}
	}

	return false;
}

FItemData& FInventorySlot::GetData() {
	return ItemAsset->SlotItemData;
}

FIntPoint FInventorySlot::GetSize()
{
	if (!HasInventoryFlag(EInventoryFlag::Size))
		return FIntPoint(1);

	if (!IsValid(ItemAsset))
		return FIntPoint(0);

	FIntPoint L_ReturnValue = GetData().SizeSlot;

	if (IsRotate)
		return FIntPoint(L_ReturnValue.Y, L_ReturnValue.X);

	return L_ReturnValue;
}

FIntPoint FInventorySlot::GetSize(bool NewRotate)
{
	if (!HasInventoryFlag(EInventoryFlag::Size)) {
		return FIntPoint(1);
	}

	if (!IsValid(ItemAsset))
		return FIntPoint(0);

	FIntPoint L_ReturnValue = GetData().SizeSlot;

	if (NewRotate)
		return FIntPoint(L_ReturnValue.Y, L_ReturnValue.X);

	return L_ReturnValue;
}