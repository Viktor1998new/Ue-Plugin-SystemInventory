#include "Components/InventoryComponent_Blueprint.h"

bool UInventoryComponent_Blueprint::AddSlot(FInventorySlot NewSlot, bool FindPositionSlot, int32& Index) {

	bool L_IsAdding = ReceiveAddSlot(NewSlot, FindPositionSlot, Index);

	if (L_IsAdding) {
		OnAddItem.Broadcast(Index);
		Inventory.Massa += NewSlot.ItemAsset->SlotItemData.MassItem * NewSlot.Count;
		ChangeSlot(Index, NewSlot, ETypeSetItem::Add);
	}

	return L_IsAdding;
};

bool UInventoryComponent_Blueprint::SetSlot(int32 Index, FInventorySlot NewValue) {

	float DelMass = 0, AddMass = 0;
	if (Inventory.Items[Index].ItemAsset != NewValue.ItemAsset || Inventory.Items[Index].Count != NewValue.Count) {
		DelMass = Inventory.Items[Index].ItemAsset->SlotItemData.MassItem * Inventory.Items[Index].Count;
		AddMass = NewValue.ItemAsset->SlotItemData.MassItem * NewValue.Count;
	}

	bool Is_Seted = ReceiveSetSlot(Index, NewValue);

	if (Is_Seted) {
		Inventory.Massa -= DelMass;
		Inventory.Massa += AddMass;
		ChangeSlot(Index, NewValue, ETypeSetItem::ChangeSlot);
	}

	return Is_Seted;
};