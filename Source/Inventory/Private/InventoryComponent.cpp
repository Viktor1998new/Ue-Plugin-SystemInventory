//Copyright(c) 2022, Viktor.F.P

#include "Inventory/InventoryComponent.h"
#include "InventorySettings.h"
#include "Net/UnrealNetwork.h"

bool HasInventoryFlag(EInventoryFlag Contains)
{
	return EnumHasAnyFlags<EInventoryFlag>((EInventoryFlag)UInventorySettings::Get()->InventoryFlags, Contains);
}

void UInventoryComponent::ChangeSlot(int32 Index, FInventorySlot Slot, ETypeSetItem Type) {

	if(GIsServer)
		ClientRPC_EventSetItem(Index, Slot, Type);
	else
		NewDataSlot.Broadcast(Index, Slot, Type);
}

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
	
	if (HasInventoryFlag(EInventoryFlag::Size)) {
		
		FIntPoint SizeItem = FIntPoint(GetSize().X, GetSize().Y);
		
		SizeItem -= 1;
		Size -= 1;

		if (Position.X >= PositionSlot.X ? Position.X <= PositionSlot.X + SizeItem.X : Position.X + Size.X >= PositionSlot.X) {
			
			if (HasInventoryFlag(EInventoryFlag::OnlyX)) {
				return true;
			}

			if (Position.Y >= PositionSlot.Y ? Position.Y <= PositionSlot.Y + SizeItem.Y : Position.Y + Size.Y >= PositionSlot.Y) {
				return true;
			}
		}
	}
	else {
		if (Position == PositionSlot) {
			return true;
		}
	}

	return false;
}

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInventoryComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(UInventoryComponent, Items, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(UInventoryComponent, CurrentMassa, COND_OwnerOnly);
	DOREPLIFETIME_CONDITION(UInventoryComponent, MaxSlot, COND_OwnerOnly);
}

void UInventoryComponent::ClientRPC_EventSetItem_Implementation(int32 Index, FInventorySlot NewData, ETypeSetItem Type)
{
	NewDataSlot.Broadcast(Index, NewData, Type);
}

bool UInventoryComponent::SetSlot(int32 Index, FInventorySlot NewValue) {

	if (!NewValue.ItemAsset || !Items.IsValidIndex(Index) || NewValue.Count <= 0 || NewValue.Count > NewValue.ItemAsset->SlotItemData.MaxStack)
		return false;

	if (Items[Index].ItemAsset != NewValue.ItemAsset || Items[Index].PositionSlot != NewValue.PositionSlot)
	{
		for (int32 i = 0; i < Items.Num(); i++)
		{
			if (HasInventoryFlag(EInventoryFlag::Stack))
				if (i == Index)
					continue;

			if (Items[i].ItemAsset) {
				if (Items[i].IsPosition(NewValue.PositionSlot, NewValue.GetSize())) {
					
					return false;
				}
			}
		}
	}
	
	if (HasInventoryFlag(EInventoryFlag::Mass)) {
		if (Items[Index].ItemAsset != NewValue.ItemAsset || Items[Index].Count != NewValue.Count) {
			CurrentMassa -= Items[Index].ItemAsset->SlotItemData.MassItem * Items[Index].Count;
			CurrentMassa += NewValue.ItemAsset->SlotItemData.MassItem * NewValue.Count;
		}
	}
	
	Items[Index] = NewValue;

	ChangeSlot(Index, NewValue, ETypeSetItem::ChangeSlot);

	return true;
}

bool UInventoryComponent::AddSlot(FInventorySlot NewSlot, bool FindPositionSlot, int32& Index) {

	if (!NewSlot.ItemAsset || NewSlot.Count <= 0) {
		return false;
	}

	FIntPoint NewPosition;
	int32 IndexFull;

	if (!IsPositionFree(NewSlot.PositionSlot, NewSlot.GetSize(), IndexFull)) {

		if (!FindPositionSlot) {
			return false;
		}

		if (FindFreeSlot(NewSlot.GetSize(), NewPosition)) {
			NewSlot.PositionSlot = NewPosition;
		}
		else {
			return false;
		}
	}

	if (HasInventoryFlag(EInventoryFlag::Stack)) {

		if (!NewSlot.ItemAsset->SlotItemData.StackItem && NewSlot.Count > NewSlot.ItemAsset->SlotItemData.MaxStack) {
			return false;
		}
		else NewSlot.Count = 1;
	}
	else {
		NewSlot.Count = 1;
	}


	if (HasInventoryFlag(EInventoryFlag::Mass)) {
		CurrentMassa += NewSlot.ItemAsset->SlotItemData.MassItem * NewSlot.Count;
	}

	int32 AddIndex = Items.Add(NewSlot);
	Index = AddIndex;

	OnAddItem.Broadcast(AddIndex);
	ChangeSlot(AddIndex, NewSlot, ETypeSetItem::Add);

	return true;
}

bool UInventoryComponent::AddActorItem(AItemActor* Item, int32& Index)
{
	return AddAssetItem(Item->ItemAsset, 1, Item->GetData(), Index);
}

bool UInventoryComponent::AddAssetItem(UItemAsset* ItemAsset, int32 Count, const FString& Data, int32& Index)
{
	if (!ItemAsset || Count <= 0 || Count > ItemAsset->SlotItemData.MaxStack) return false;

	if (HasInventoryFlag(EInventoryFlag::Stack) && ItemAsset->SlotItemData.StackItem) {
		
		int32 FindIndex = INDEX_NONE;

		if (ItemAsset->SlotItemData.NoneData) {
			for (int32 i = 0; i < Items.Num(); i++) {
				if (Items[i].ItemAsset == ItemAsset){
					FindIndex = i;
					break;
				}
			}
		}
		else {
			for (int32 i = 0; i < Items.Num(); i++) {
				if (Items[i].ItemAsset == ItemAsset && Items[i].ItemData == Data) {
					FindIndex = i;
					break;
				}
			}
		}

		if (FindIndex != INDEX_NONE) {

			auto L_ChangeSlot = Items[FindIndex];
				
			L_ChangeSlot.Count += Count;
			
			bool L_IsAdd = SetSlot(FindIndex, L_ChangeSlot);
			
			if(L_IsAdd)
				OnAddItem.Broadcast(FindIndex);
			
			return true;
		}
	}

	FInventorySlot NewSlot;
	NewSlot.ItemAsset = ItemAsset;
	NewSlot.Count = Count;
	
	return AddSlot(NewSlot, true, Index);
}

bool UInventoryComponent::FindFreeSlot(FIntPoint Size, FIntPoint& ReturnPosition)
{
	bool LimitY = !HasInventoryFlag(EInventoryFlag::OnlyX) ? HasInventoryFlag(EInventoryFlag::LimitY) ? Size.Y <= MaxSlot.Y : true : true;

	if (Size.X <= MaxSlot.X  && LimitY) {
		if (Items.Num() == 0) {
			ReturnPosition = FIntPoint::ZeroValue;
			return true;
		}
	}
	else {
		return false;
	}

	int32 X = 0, Y = 0;

	bool IsNoFree;

	do {
		if (HasInventoryFlag(EInventoryFlag::OnlyX)) {
			if (X + (Size.X - 1) > (MaxSlot.X - 1)) {
				return false;
			}
		}
		else {
			if (X + (Size.X - 1) > (MaxSlot.X - 1)) {
				X = 0;

				if (HasInventoryFlag(EInventoryFlag::LimitY))
					if (Y + (Size.Y - 1) > (MaxSlot.Y - 1))
						return false;
				Y++;
			}
		}

		int32 L_ItemIndex;

		IsNoFree = !IsPositionFree(FIntPoint(X, Y), Size, L_ItemIndex);

		if (IsNoFree) {

			if (HasInventoryFlag(EInventoryFlag::Size) && Items.IsValidIndex(L_ItemIndex)) 
				X = Items[L_ItemIndex].PositionSlot.X + Items[L_ItemIndex].GetSize().X;	
			else 
				X++;
			
		}

	} while (IsNoFree);

	ReturnPosition = FIntPoint(X, Y);
	return true;

}

bool UInventoryComponent::FindItem(UItemAsset* ItemAsset, int32& Index)
{
	if (!IsValid(ItemAsset)) {
		Index = INDEX_NONE;
		return false;
	}

	for (int32 i = 0; i < Items.Num(); i++)
		if (Items[i].ItemAsset == ItemAsset) {
			Index = i;
			return true;
		}

	Index = INDEX_NONE;
	return false;
}

bool UInventoryComponent::RemoveItem(int32 Index, int32 Count) {

	if (!Items.IsValidIndex(Index))
		return false;

	if (HasInventoryFlag(EInventoryFlag::Stack) && Items[Index].ItemAsset->SlotItemData.StackItem) {

		if (Items[Index].Count >= Count) {

			if (HasInventoryFlag(EInventoryFlag::Mass))
				CurrentMassa -= Items[Index].ItemAsset->SlotItemData.MassItem * Count;

			if (Items[Index].Count - Count == 0) {
				
				OnRemoveItem.Broadcast(Index);
				Items.RemoveAt(Index);
				ChangeSlot(Index, FInventorySlot(), ETypeSetItem::Remove);
				
			}
			else {
				OnRemoveItem.Broadcast(Index);
				Items[Index].Count -= Count;
				ChangeSlot(Index, Items[Index], ETypeSetItem::ChangeSlot);
			}

			return true;
		}
	}

	if (HasInventoryFlag(EInventoryFlag::Mass))
		CurrentMassa -= Items[Index].ItemAsset->SlotItemData.MassItem;

	OnRemoveItem.Broadcast(Index);
	Items.RemoveAt(Index);
	ChangeSlot(Index, FInventorySlot(), ETypeSetItem::Remove);

	return true;
}

bool UInventoryComponent::SendItem(int32 Index, UInventoryComponent* ToIntentory, int32 Count, bool FindSlot, FIntPoint Position)
{
	if(!ToIntentory|| !Items.IsValidIndex(Index) || this == ToIntentory || Items[Index].Count < Count) return false;

	FInventorySlot NewStot = Items[Index];
	FIntPoint NewPosition = Position;
	int32 FindIndex;

	if (FindSlot) {
		if (!ToIntentory->FindFreeSlot(NewStot.GetSize(), NewPosition)) 
			return false;
	}
	else {
		if (!ToIntentory->IsPositionFree(NewPosition, NewStot.GetSize(), FindIndex)) 
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
		Index = INDEX_NONE;
		return false;
	}

	if(!HasInventoryFlag(EInventoryFlag::OnlyX) && HasInventoryFlag(EInventoryFlag::LimitY))
		if (Position.Y + Size.Y > MaxSlot.Y)
		{
			Index = INDEX_NONE;
			return false;
		}

	for (int32 i = 0; i < Items.Num(); i++)
	{
		if (Items[i].ItemAsset) 
			if (Items[i].IsPosition(Position, Size)) {
				Index = i;
				return false;
			}
	}

	return true;
}

void UInventoryComponent::SetRotateSlot(int32 Index, bool NewRotate)
{
	if (!Items.IsValidIndex(Index) || Items[Index].IsRotate == NewRotate || !GIsServer)
		return;

	auto CuToPosition = Items[Index].PositionSlot;
	bool L_OldRotate = Items[Index].IsRotate;
	int32 L_Index;

	Items[Index].PositionSlot = Items[Index].GetSize() * -2;
	Items[Index].IsRotate = NewRotate;

	if (!IsPositionFree(CuToPosition, Items[Index].GetSize(), L_Index)){
		Items[Index].IsRotate = L_OldRotate;
		Items[Index].PositionSlot = CuToPosition;
		return;
	}

	Items[Index].PositionSlot = CuToPosition;

	ChangeSlot(Index, Items[Index], ETypeSetItem::ChangeSlot);

}

bool UInventoryComponent::DropItem(int32 IndexItem = 0, int32 ToIndex = INDEX_NONE, int32 Count = 1, FIntPoint ToPosition = FIntPoint::ZeroValue, bool Change = false, bool FindPosition = false)
{
	if (!Items.IsValidIndex(IndexItem)) return false;

	if (ToIndex != INDEX_NONE) {
		
		if (!HasInventoryFlag(EInventoryFlag::Stack))
		{
			if (Change) {
				int32 Index;

				auto CuToPosition = Items[ToIndex].PositionSlot;

				auto CuPosition = Items[IndexItem].PositionSlot;

				Items[ToIndex].PositionSlot = Items[ToIndex].GetSize() * -2;
				Items[IndexItem].PositionSlot = Items[IndexItem].GetSize() * -2;

				if (IsPositionFree(CuToPosition, Items[IndexItem].GetSize(), Index)) {

					Items[IndexItem].PositionSlot = CuToPosition;

					if (IsPositionFree(CuPosition, Items[ToIndex].GetSize(), Index)) {

						Items[ToIndex].PositionSlot = CuPosition;

						ChangeSlot(ToIndex, Items[ToIndex], ETypeSetItem::ChangeSlot);
						ChangeSlot(IndexItem, Items[IndexItem], ETypeSetItem::ChangeSlot);
						return true;
					}
					else if (FindPosition) {

						FIntPoint NewPosition;

						if (FindFreeSlot(Items[ToIndex].GetSize(), NewPosition))
						{
							Items[ToIndex].PositionSlot = NewPosition;

							ChangeSlot(ToIndex, Items[ToIndex], ETypeSetItem::ChangeSlot);
							ChangeSlot(IndexItem, Items[IndexItem], ETypeSetItem::ChangeSlot);
							return true;
						}
					}
				}

				Items[ToIndex].PositionSlot = CuToPosition;
				Items[IndexItem].PositionSlot = CuPosition;
			}

			return false;
		}

		if (Count <= 0 || Count > Items[IndexItem].Count) return false;

		if (IndexItem != ToIndex) {
			if (Items[IndexItem].ItemAsset->SlotItemData.StackItem && Items[IndexItem] == Items[ToIndex] && Items[ToIndex].Count + Count <= Items[ToIndex].ItemAsset->SlotItemData.MaxStack)
			{
				Items[IndexItem].Count -= Count;
				Items[ToIndex].Count += Count;

				ChangeSlot(ToIndex, Items[ToIndex], ETypeSetItem::ChangeSlot);

				bool IsCountRemove = Items[IndexItem].Count == 0;

				if (IsCountRemove) {
					Items.RemoveAt(IndexItem);
					ChangeSlot(IndexItem, FInventorySlot(), ETypeSetItem::Remove);
				}
				else
					ChangeSlot(IndexItem, Items[IndexItem], ETypeSetItem::ChangeSlot);

				return true;
			}
			else if (Change) {

				int32 Index;

				auto CuToPosition = Items[ToIndex].PositionSlot;
				
				auto CuPosition = Items[IndexItem].PositionSlot;

				Items[ToIndex].PositionSlot = Items[ToIndex].GetSize() * -2;
				Items[IndexItem].PositionSlot = Items[IndexItem].GetSize() * -2;

				if (IsPositionFree(CuToPosition, Items[IndexItem].GetSize(), Index)) {

					Items[IndexItem].PositionSlot = CuToPosition;

					if (IsPositionFree(CuPosition, Items[ToIndex].GetSize(), Index)) {

						Items[ToIndex].PositionSlot = CuPosition;

						ChangeSlot(ToIndex, Items[ToIndex], ETypeSetItem::ChangeSlot);
						ChangeSlot(IndexItem, Items[IndexItem], ETypeSetItem::ChangeSlot);
						return true;
					}
					else if (FindPosition) {

						FIntPoint NewPosition;
						
						if (FindFreeSlot(Items[ToIndex].GetSize(), NewPosition))
						{
							Items[ToIndex].PositionSlot = NewPosition;

							ChangeSlot(ToIndex, Items[ToIndex], ETypeSetItem::ChangeSlot);
							ChangeSlot(IndexItem, Items[IndexItem], ETypeSetItem::ChangeSlot);
							return true;
						}
					}
				}

				Items[ToIndex].PositionSlot = CuToPosition;
				Items[IndexItem].PositionSlot = CuPosition;
			}
		}
	}
	else {
		if (ToPosition.X + Items[IndexItem].GetSize().X > MaxSlot.X) return false;

		if (HasInventoryFlag(EInventoryFlag::LimitY))
			if (ToPosition.Y + Items[IndexItem].GetSize().Y > MaxSlot.Y) return false;

		for (int32 i = 0; i < Items.Num(); i++)
		{
			if (i == IndexItem && Items[i].Count == Count)
				continue;

			if (Items[i].IsPosition(ToPosition, Items[IndexItem].GetSize())) {
				return false;
			}
		}

		if (HasInventoryFlag(EInventoryFlag::Stack)) {
			if (Items[IndexItem].Count != 1) {

				FInventorySlot Newslot = Items[IndexItem];
				Newslot.Count = Count;
				Newslot.PositionSlot = ToPosition;

				Items[IndexItem].Count -= Count;

				bool IsCountRemove = Items[IndexItem].Count == 0;

				if (IsCountRemove) {
					Items.RemoveAt(IndexItem);
					ChangeSlot(IndexItem, FInventorySlot(), ETypeSetItem::Remove);
				}
				else
					ChangeSlot(IndexItem, Items[IndexItem], ETypeSetItem::ChangeSlot);

				int32 NewIndex = Items.Add(Newslot);
				ChangeSlot(NewIndex, Items[NewIndex], ETypeSetItem::Add);
				return true;
			}
		}

		Items[IndexItem].PositionSlot = ToPosition;
		ChangeSlot(IndexItem, Items[IndexItem], ETypeSetItem::SetPosition);
		return true;
	}

	return false;
}

#if WITH_EDITOR
void UInventoryComponent::RecalculationMass() {
	
	if (!HasInventoryFlag(EInventoryFlag::Mass))
		return;

	CurrentMassa = 0;

	for (auto& Element : Items) {
		if(Element.ItemAsset)
			CurrentMassa += Element.ItemAsset->SlotItemData.MassItem * Element.Count;
	}
}
#endif