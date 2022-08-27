// Fill out your copyright notice in the Description page of Project Settings.

#include "Inventory/InventoryComponent.h"
#include "Inventory.h"
#include "InventorySettings.h"
#include "Net/UnrealNetwork.h"

FInventory::FInventory() {
	Massa = 0.0f;
	MaxSlot = FIntPoint(0, 0);

};

FInventory::FInventory(UInventoryComponent* InventoryComponent) {

	if (!InventoryComponent)
		return;

	Items = InventoryComponent->Items;
	Massa = InventoryComponent->CurrentMassa;
	MaxSlot = InventoryComponent->MaxSlot;
};

bool FInventorySlot::IsPosition(FIntPoint Position, FIntPoint Size) {
	
	if (FInventoryModule::Get().GetSettings()->SizeSlot == true) {
		
		FIntPoint SizeItem = FIntPoint(ItemAsset->SlotItemData.SizeSlot.X, ItemAsset->SlotItemData.SizeSlot.Y);
		
		SizeItem -= 1;
		Size -= 1;

		if (Position.X >= PositionSlot.X ? Position.X <= PositionSlot.X + SizeItem.X : Position.X + Size.X >= PositionSlot.X) {
			if (Position.Y >= PositionSlot.Y ? Position.Y <= PositionSlot.Y + SizeItem.Y : Position.Y + Size.Y >= PositionSlot.Y) {
				return true;
			}
		}
	}
	else {
		if (Position.X == PositionSlot.X && Position.Y == PositionSlot.Y) {
			return true;
		}
	}

	return false;
}

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UInventoryComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(UInventoryComponent, Items, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(UInventoryComponent, CurrentMassa, COND_OwnerOnly);
}

void UInventoryComponent::ClientRPC_EventSetItem_Implementation(int32 Index, FInventorySlot NewData, ETypeSetItem Type)
{
	if (GetOwner()->HasAuthority())
		return;

	ItemIndex = Index;
	TypeSetItem = Type;

	if (Type != ETypeSetItem::Add) {
		OnRemoveItem.Broadcast(Index);
		NewDataSlot.Broadcast(Index, NewData, Type);
	}
}

bool UInventoryComponent::SetSlot(int32 Index, FInventorySlot NewValue) {

	if (!NewValue.ItemAsset || !Items.IsValidIndex(Index) || NewValue.Count <= 0)
		return false;

	if (Items[Index].ItemAsset != NewValue.ItemAsset || Items[Index].PositionSlot != NewValue.PositionSlot)
	{
		for (int32 i = 0; i < Items.Num(); i++)
		{
			if (GetInventorySetting()->StackItems == true) 
				if (i == Index)
					continue;

			if (Items[i].ItemAsset) {
				if (Items[i].IsPosition(NewValue.PositionSlot, NewValue.ItemAsset->SlotItemData.SizeSlot)) {
					Index = i;
					return false;
				}
			}
		}
	}
	
	if (GetInventorySetting()->MassItems == true) {
		if (Items[Index].ItemAsset != NewValue.ItemAsset || Items[Index].Count != NewValue.Count) {
			CurrentMassa -= Items[Index].ItemAsset->SlotItemData.MassItem * Items[Index].Count;
			CurrentMassa += NewValue.ItemAsset->SlotItemData.MassItem * NewValue.Count;
		}
	}
	
	Items[Index] = NewValue;

	NewDataSlot.Broadcast(Index, Items[Index], ETypeSetItem::ChangeSlot);
	ClientRPC_EventSetItem(Index, Items[Index], ETypeSetItem::ChangeSlot);

	return true;
}

bool UInventoryComponent::AddSlot(FInventorySlot NewSlot, bool FindPositionSlot, int32& Index)
{
	if (!NewSlot.ItemAsset || NewSlot.Count <= 0)
		return false;

	FIntPoint NewPosition;
	int32 IndexFull;

	if (FindPositionSlot || !IsPositionFree(NewSlot.PositionSlot, NewSlot.ItemAsset->SlotItemData.SizeSlot, IndexFull)) {

		if (FindFreeSlot(NewSlot.ItemAsset->SlotItemData.SizeSlot, NewPosition)) {
			NewSlot.PositionSlot = NewPosition;
		}
		else {
			return false;
		}
	}

	if (GetInventorySetting()->StackItems == false) {
		NewSlot.Count = 1;
	}
	else if (NewSlot.ItemAsset->SlotItemData.StackItem == false) {
		NewSlot.Count = 1;
	}

	if (GetInventorySetting()->MassItems == true) {
		CurrentMassa += NewSlot.ItemAsset->SlotItemData.MassItem * NewSlot.Count;
	}

	int32 AddIndex = Items.Add(NewSlot);
	Index = AddIndex;

	NewDataSlot.Broadcast(AddIndex, NewSlot, ETypeSetItem::Add);
	OnAddItem.Broadcast(AddIndex);
	ClientRPC_EventSetItem(AddIndex, NewSlot, ETypeSetItem::Add);

	return true;
}

bool UInventoryComponent::AddActorItem(AItemActor* Item, int32& Index)
{
	return AddAssetItem(Item->ItemAsset, 1, Item->GetData(), Index);

}

bool UInventoryComponent::AddAssetItem(UItemAsset* ItemAsset, int32 Count, const FString& Data, int32& Index)
{
	if (!ItemAsset || Count <= 0) return false;

	if (GetInventorySetting()->StackItems == true) {
		if (ItemAsset->SlotItemData.StackItem == true) {
			if (ItemAsset->SlotItemData.NoneData == true) {

				int32 FindIndex = 0;

				if (ItemAsset->SlotItemData.StackItem == true && FindItem(ItemAsset, FindIndex)) {

					Items[FindIndex].Count += Count;

					if (GetInventorySetting()->MassItems == true) {
						CurrentMassa += ItemAsset->SlotItemData.MassItem * Count;
					}

					Index = FindIndex;
					NewDataSlot.Broadcast(Index, Items[FindIndex], ETypeSetItem::ChangeSlot);
					OnAddItem.Broadcast(FindIndex);
					ClientRPC_EventSetItem(FindIndex, Items[FindIndex], ETypeSetItem::ChangeSlot);
					return true;
				}
			}
			else {
				for (int32 i = 0; i < Items.Num(); i++)
				{
					if (Items[i].ItemAsset == ItemAsset && Items[i].ItemData == Data) {
						Items[i].Count += Count;

						if (GetInventorySetting()->MassItems == true) {
							CurrentMassa += ItemAsset->SlotItemData.MassItem * Count;
						}

						Index = i;
						NewDataSlot.Broadcast(i, Items[i], ETypeSetItem::ChangeSlot);
						OnAddItem.Broadcast(i);
						ClientRPC_EventSetItem(i, Items[i], ETypeSetItem::ChangeSlot);
						return true;
					}
				}
			}
		}
	}

	FIntPoint NewPosition;
	if (FindFreeSlot(ItemAsset->SlotItemData.SizeSlot, NewPosition)) {
		FInventorySlot NewSlot;
		NewSlot.ItemAsset = ItemAsset;
		NewSlot.Count = Count;

		if (ItemAsset->SlotItemData.NoneData == false)
			NewSlot.ItemData = Data;

		NewSlot.PositionSlot = NewPosition;
		int32 IndexAdd = Items.Add(NewSlot);

		if (GetInventorySetting()->MassItems == true) {
			CurrentMassa += ItemAsset->SlotItemData.MassItem * Count;
		}
		Index = IndexAdd;
		NewDataSlot.Broadcast(IndexAdd, Items[IndexAdd], ETypeSetItem::Add);
		OnAddItem.Broadcast(IndexAdd);
		ClientRPC_EventSetItem(IndexAdd, Items[IndexAdd], ETypeSetItem::Add);

		return true;
	}

	return false;
}

bool UInventoryComponent::FindFreeSlot(FIntPoint Size, FIntPoint& ReturnPosition)
{
	if (Items.Num() == 0 && Size.X > MaxSlot.X&& Size.Y > MaxSlot.Y) {
		ReturnPosition = FIntPoint::ZeroValue;
		return true;
	}

	int32 X = 0, Y = 0;

	bool IsNoFree;

	do {
		if (X + (Size.X - 1) > (MaxSlot.X - 1)) {
			X = 0;

			if (GetInventorySetting()->LimitSlotY == true) {
				if (Y + (Size.Y - 1) > (MaxSlot.Y - 1))
				{
					return false;
				}
			}

			Y++;
		}

		int32 L_ItemIndex;

		IsNoFree = !IsPositionFree(FIntPoint(X, Y), Size, L_ItemIndex);

		if (IsNoFree) {

			if (GetInventorySetting()->SizeSlot == true) {
				if (Items.IsValidIndex(L_ItemIndex))
					X = Items[L_ItemIndex].PositionSlot.X + Items[L_ItemIndex].ItemAsset->SlotItemData.SizeSlot.X;
				else
					X++;
			}
			else {
				X++;
			}
		}

	} while (IsNoFree);

	ReturnPosition = FIntPoint(X, Y);
	return true;

}

bool UInventoryComponent::FindItem(UItemAsset* ItemAsset, int32& Index)
{
	if (!IsValid(ItemAsset))
		return false;

	for (int32 i = 0; i < Items.Num(); i++)
	{
		if (Items[i].ItemAsset == ItemAsset) {
			Index = i;
			return true;
		}

	}
	return false;
}

bool UInventoryComponent::RemoveItem(int32 Index, int32 Count) {

	if (!Items.IsValidIndex(Index))
		return false;

	if (GetInventorySetting()->StackItems == true) {

		if (Items[Index].Count >= Count) {

			if (GetInventorySetting()->MassItems == true)
				CurrentMassa -= Items[Index].ItemAsset->SlotItemData.MassItem * Count;

			if (Items[Index].Count - Count == 0) {
				NewDataSlot.Broadcast(Index, FInventorySlot(), ETypeSetItem::Remove);
				OnRemoveItem.Broadcast(Index);
				ClientRPC_EventSetItem(Index, FInventorySlot(), ETypeSetItem::Remove);
				Items.RemoveAt(Index);
			}
			else {
				OnRemoveItem.Broadcast(Index);

				Items[Index].Count -= Count;

				NewDataSlot.Broadcast(Index, Items[Index], ETypeSetItem::ChangeSlot);

				ClientRPC_EventSetItem(Index, Items[Index], ETypeSetItem::ChangeSlot);
			}

			return true;
		}
	}
	else
	{
		if (GetInventorySetting()->MassItems == true)
			CurrentMassa -= Items[Index].ItemAsset->SlotItemData.MassItem;

		ClientRPC_EventSetItem(Index, FInventorySlot(), ETypeSetItem::Remove);

		Items.RemoveAt(Index);

		return true;
	}
	return false;
}

bool UInventoryComponent::SendItem(int32 Index, UInventoryComponent* ToIntentory, int32 Count, bool FindSlot, FIntPoint Position)
{
	if(!ToIntentory|| !Items.IsValidIndex(Index) || this == ToIntentory || Items[Index].Count < Count)
		return false;

	FInventorySlot NewStot = Items[Index];
	FIntPoint NewPosition = Position;
	int32 FindIndex;

	if (FindSlot)
	{
		if (!ToIntentory->FindFreeSlot(NewStot.ItemAsset->SlotItemData.SizeSlot, NewPosition)) 
			return false;
	}
	else
	{
		if (!ToIntentory->IsPositionFree(NewPosition, NewStot.ItemAsset->SlotItemData.SizeSlot, FindIndex))
			return false;
	}

	RemoveItem(Index, Count);

	NewStot.Count = Count;
	NewStot.PositionSlot = NewPosition;
	int32 AddIndex;
	ToIntentory->AddSlot(NewStot, false, AddIndex);
	return true;
}

bool UInventoryComponent::IsPositionFree(FIntPoint Position, FIntPoint Size, int32& Index)
{
	if (Position.X + Size.X > MaxSlot.X)
	{
		Index = -1;
		return false;
	}

	if (GetInventorySetting()->LimitSlotY == true) {
		if (Position.Y + Size.Y > MaxSlot.Y)
		{
			Index = -1;
			return false;
		}
	}

	for (int32 i = 0; i < Items.Num(); i++)
	{
		if (Items[i].ItemAsset) {
			if (Items[i].IsPosition(Position, Size)) {
				Index = i;
				return false;
			}
		}
	}

	return true;
}


bool UInventoryComponent::DropItem(int32 IndexItem = 0, int32 ToIndex = -1, int32 Count = 1, FIntPoint ToPosition = FIntPoint::ZeroValue)
{
	if (ToIndex != -1) {
		
		if (!GetInventorySetting()->StackItems) return false;

		if (!Items.IsValidIndex(IndexItem) || Count <= 0 || Count > Items[ItemIndex].Count) return false;

		if (Items[IndexItem].ItemAsset->SlotItemData.StackItem == true && IndexItem != ToIndex && Items[IndexItem] == Items[ToIndex]) {

			Items[IndexItem].Count -= Count;
			Items[ToIndex].Count += Count;

			NewDataSlot.Broadcast(ToIndex, Items[ToIndex], ETypeSetItem::ChangeSlot);
			ClientRPC_EventSetItem(ToIndex, Items[ToIndex], ETypeSetItem::ChangeSlot);

			if (Items[IndexItem].Count == 0) {
				NewDataSlot.Broadcast(IndexItem, FInventorySlot(), ETypeSetItem::Remove);
				ClientRPC_EventSetItem(IndexItem, FInventorySlot(), ETypeSetItem::Remove);
				Items.RemoveAt(IndexItem);

			}
			else {
				NewDataSlot.Broadcast(IndexItem, Items[IndexItem], ETypeSetItem::ChangeSlot);
				ClientRPC_EventSetItem(IndexItem, Items[IndexItem], ETypeSetItem::ChangeSlot);
			}
			return true;
		}
	}
	else {
		if (ToPosition.X + Items[IndexItem].ItemAsset->SlotItemData.SizeSlot.X > MaxSlot.X) return false;

		if (GetInventorySetting()->LimitSlotY == true)
			if (ToPosition.Y + Items[IndexItem].ItemAsset->SlotItemData.SizeSlot.Y > MaxSlot.Y) return false;

		for (int32 i = 0; i < Items.Num(); i++)
		{
			if (i == IndexItem && Items[i].Count == Count)
				continue;

			if (Items[i].IsPosition(ToPosition, Items[IndexItem].ItemAsset->SlotItemData.SizeSlot)) {
				return false;
			}
		}

		if (GetInventorySetting()->StackItems == true) {
			if (Items[IndexItem].Count != 1) {

				FInventorySlot Newslot = Items[IndexItem];
				Newslot.Count = Count;
				Newslot.PositionSlot = ToPosition;

				Items[IndexItem].Count -= Count;

				if (Items[IndexItem].Count == 0) {
					NewDataSlot.Broadcast(IndexItem, FInventorySlot(), ETypeSetItem::Remove);
					ClientRPC_EventSetItem(IndexItem, FInventorySlot(), ETypeSetItem::Remove);
					Items.RemoveAt(IndexItem);
				}
				else {
					NewDataSlot.Broadcast(IndexItem, Items[IndexItem], ETypeSetItem::ChangeSlot);
					ClientRPC_EventSetItem(IndexItem, Items[IndexItem], ETypeSetItem::ChangeSlot);
				}

				int32 NewIndex = Items.Add(Newslot);
				NewDataSlot.Broadcast(NewIndex, Items[NewIndex], ETypeSetItem::Add);
				ClientRPC_EventSetItem(NewIndex, Items[NewIndex], ETypeSetItem::Add);
				return true;
			}
		}

		Items[IndexItem].PositionSlot = ToPosition;
		NewDataSlot.Broadcast(IndexItem, Items[IndexItem], ETypeSetItem::SetPosition);
		ClientRPC_EventSetItem(IndexItem, Items[IndexItem], ETypeSetItem::SetPosition);
		return true;
	}

	return false;
}

void UInventoryComponent::OnRep_SetItems()
{
	switch (TypeSetItem)
	{
	case ETypeSetItem::Add:
		OnAddItem.Broadcast(ItemIndex);
		NewDataSlot.Broadcast(ItemIndex, Items[ItemIndex], ETypeSetItem::Add);
		break;
	}
}

UInventorySettings* UInventoryComponent::GetInventorySetting()
{
	return FInventoryModule::Get().GetSettings();
}

#if WITH_EDITOR
void UInventoryComponent::RecalculationMass() {
	
	CurrentMassa = 0;

	for (auto Element : Items) {
		if(Element.ItemAsset)
			CurrentMassa += Element.ItemAsset->SlotItemData.MassItem * Element.Count;
	}
}
#endif