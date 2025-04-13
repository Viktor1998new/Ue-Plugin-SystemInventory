#include "InventorySlot.h"
#include "InventorySettings.h"

bool FInventorySlot::IsPosition(FIntPoint Position, FIntPoint Size) {

	if (Position == PositionSlot)
		return true;

	if (HasInventoryFlag(EInventoryFlag::Size)) {

		FIntPoint SizeItem = GetSize();

//		Position.Y >= PositionSlot.Y ? Position.Y <= PositionSlot.Y + SizeItem.Y : Position.Y + Size.Y >= PositionSlot.Y

		if (IsRang(Position.X, PositionSlot.X, (SizeItem.X - 1), (Size.X - 1))) {

			if (HasInventoryFlag(EInventoryFlag::OnlyX)) return true;

			return IsRang(Position.Y, PositionSlot.Y, (SizeItem.Y - 1), (Size.Y - 1));
		}
	}

	return false;
}

FItemData& FInventorySlot::GetData() {
	return ItemAsset->SlotItemData;
}

bool FInventorySlot::IsRang(int Value, int Pos, int Min, int Max)
{
	if (Value >= Pos) {
		return	Value <= Pos + Min;
	}

	return Value + Max >= Pos;
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