// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent.h"
#include "Inventory.h"
#include "UnrealNetwork.h"

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

	if (Type == ETypeSetItem::Remove || Type == ETypeSetItem::SetCount || Type == ETypeSetItem::SetPosition) {
		OnRemoveItem.Broadcast(Index);
		NewDataSlot.Broadcast(Index, NewData, Type);
	}
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{

}

bool UInventoryComponent::AddSlot(FInventorySlot NewSlot, bool FindPositionSlot, int32& Index)
{
	if (!IsValid(NewSlot.ClassItem) && !GIsServer && NewSlot.Count >= 0)
		return false;

	FIntPoint NewPosition;
	int32 IndexFull;

	if (FindPositionSlot || !IsPositionFree(NewSlot.PositionSlot,NewSlot.ClassItem.GetDefaultObject()->ItemData.SizeSlot, IndexFull)) {

		if (FindFreeSlot(NewSlot.ClassItem.GetDefaultObject()->ItemData.SizeSlot, NewPosition)) {
			NewSlot.PositionSlot = NewPosition;
		}
		else {
			return false;
		}
	}

	if (GetInventorySetting()->StackItems == false) {
		NewSlot.Count = 1;
	}else if(NewSlot.ClassItem.GetDefaultObject()->ItemData.StackItem == false){
		NewSlot.Count = 1;
	}

	if (GetInventorySetting()->MassItems == true) {
		CurrentMassa += NewSlot.ClassItem.GetDefaultObject()->ItemData.MassItem * NewSlot.Count;
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
	if (!IsValid(Item) || !GIsServer)
		return false;

	return AddClassItem(Item->GetClass(), 1, Item->GetData(), Index);

}

bool UInventoryComponent::AddClassItem(TSubclassOf<AItemActor> Item,int32 Count, const FString& Data, int32& Index)
{

	if (!IsValid(Item) || !GIsServer || Count == 0)
		return false;
	
	AItemActor* DefaultItem = Item.GetDefaultObject();

	if (GetInventorySetting()->StackItems == true) {

		if (DefaultItem->ItemData.StackItem == true) {
			if (DefaultItem->ItemData.NoneData == true) {

				int32 FindIndex = 0;

				if (DefaultItem->ItemData.StackItem == true && FindItem(Item, false, FindIndex)) {

					Items[FindIndex].Count += Count;

					if (GetInventorySetting()->MassItems == true) {
						CurrentMassa += DefaultItem->ItemData.MassItem * Count;
					}

					Index = FindIndex;
					NewDataSlot.Broadcast(Index, Items[FindIndex], ETypeSetItem::SetCount);
					OnAddItem.Broadcast(FindIndex);
					ClientRPC_EventSetItem(FindIndex, Items[FindIndex], ETypeSetItem::SetCount);
					return true;
				}
			}
			else {
				for (int32 i = 0; i < Items.Num(); i++)
				{
					if (Items[i].ClassItem == Item && Items[i].ItemData == Data) {
						Items[i].Count += Count;

						if (GetInventorySetting()->MassItems == true) {
							CurrentMassa += DefaultItem->ItemData.MassItem * Count;
						}

						Index = i;
						NewDataSlot.Broadcast(i, Items[i], ETypeSetItem::SetCount);
						OnAddItem.Broadcast(i);
						ClientRPC_EventSetItem(i, Items[i], ETypeSetItem::SetCount);
						return true;
					}
				}
			}
		}
	}

	FIntPoint NewPosition;
	if (FindFreeSlot(DefaultItem->ItemData.SizeSlot, NewPosition)) {
		FInventorySlot NewSlot;
		NewSlot.ClassItem = Item;
		NewSlot.Count = Count;
		
		if (DefaultItem->ItemData.NoneData == false)
			NewSlot.ItemData = Data;
		
		NewSlot.PositionSlot = NewPosition;
		int32 IndexAdd = Items.Add(NewSlot);

		if (GetInventorySetting()->MassItems == true) {
			CurrentMassa += DefaultItem->ItemData.MassItem * Count;
		}
		Index = IndexAdd;
		NewDataSlot.Broadcast(IndexAdd, Items[IndexAdd], ETypeSetItem::Add);
		OnAddItem.Broadcast(IndexAdd);
		ClientRPC_EventSetItem(IndexAdd, Items[IndexAdd], ETypeSetItem::Add);
		
		return true;
	}

	return false;
}

bool UInventoryComponent::FindFreeSlot(FIntPoint Size, FIntPoint &ReturnPosition)
{
	if (GetInventorySetting()->PositionSlot == false)
		return true;

	if (Items.Num() == 0 && Size.X > MaxSlot.X && Size.Y > MaxSlot.Y) {
		ReturnPosition = FIntPoint::ZeroValue;
		return true;
	}

	int32 X = 0, Y = 0;

	bool IsNoFree = true;

	while (IsNoFree) {

		if (X + (Size.X - 1) > (MaxSlot.X - 1)) {
			X = 0;

			if (GetInventorySetting()->LimitSlotY == true)  {
				if (Y + (Size.Y - 1) > (MaxSlot.Y - 1))
				{
					return false;
				}
			}

			Y++;
		}

		int L_ItemIndex;

		IsNoFree = !IsPositionFree(FIntPoint(X, Y), Size, L_ItemIndex);

		if (IsNoFree) {
			
			if (GetInventorySetting()->SizeSlot == true) {
				
				X = Items[L_ItemIndex].PositionSlot.X + Items[L_ItemIndex].ClassItem.GetDefaultObject()->ItemData.SizeSlot.X;
			}
			else {
				X++;
			}
		}

	}

	ReturnPosition = FIntPoint(X, Y);
	return true;

}

bool UInventoryComponent::FindItem(TSubclassOf<AItemActor> ClassItem, bool Child, int32& Index)
{
	if (!IsValid(ClassItem))
		return false;

	for (int i = 0; i < Items.Num(); i++)
	{
		if (Child) {
			if (Items[i].ClassItem->IsChildOf(ClassItem)) {
				Index = i;
				return true;
			}
		}
		else {
			if (Items[i].ClassItem == ClassItem) {
				Index = i;
				return true;
			}
		}
		
	}
	return false;
}

bool UInventoryComponent::RemoveItem(int32 Index, int32 Count) {

	if (!Items.IsValidIndex(Index) || !GIsServer) 
		return false;
	
	if (GetInventorySetting()->StackItems == true) {
		
		if (Items[Index].Count >= Count) {

			if (GetInventorySetting()->MassItems == true)
				CurrentMassa -= Items[Index].ClassItem.GetDefaultObject()->ItemData.MassItem * Count;

			if (Items[Index].Count - Count == 0) {
				NewDataSlot.Broadcast(Index, FInventorySlot(), ETypeSetItem::Remove);
				OnRemoveItem.Broadcast(Index);
				ClientRPC_EventSetItem(Index, FInventorySlot(), ETypeSetItem::Remove);
				Items.RemoveAt(Index);
			}
			else {
				OnRemoveItem.Broadcast(Index);

				Items[Index].Count -= Count;

				NewDataSlot.Broadcast(Index, Items[Index], ETypeSetItem::SetCount);
				
				ClientRPC_EventSetItem(Index, Items[Index], ETypeSetItem::SetCount);
			}
			
			return true;
		}
	}
	else
	{
		if (GetInventorySetting()->MassItems == true)
			CurrentMassa -= Items[Index].ClassItem.GetDefaultObject()->ItemData.MassItem;

		ClientRPC_EventSetItem(Index, FInventorySlot(), ETypeSetItem::Remove);

		Items.RemoveAt(Index);

		return true;
	}
	return false;
}

bool UInventoryComponent::SendItem(int32 Index, UInventoryComponent* ToIntentory, int32 Count, bool FindSlot, FIntPoint Position)
{
	if (!GIsServer || ToIntentory == this)
		return false;

	if (IsValid(ToIntentory)) {
		if (FindSlot) {

			FInventorySlot NewStot = Items[Index];
			
			if (RemoveItem(Index, Count)) {

				FIntPoint NewPosition;

				if (ToIntentory->FindFreeSlot(NewStot.ClassItem.GetDefaultObject()->ItemData.SizeSlot, NewPosition)) {

					NewStot.Count = Count;
					NewStot.PositionSlot = NewPosition;
					int AddIndex;
					ToIntentory->AddSlot(NewStot, false ,AddIndex);
					return true;
				}
			}
		}
		else{
			
			int32 FindIndex;
			FInventorySlot NewStot = Items[Index];
			if (RemoveItem(Index, Count)) {
				if (ToIntentory->IsPositionFree(Position, NewStot.ClassItem.GetDefaultObject()->ItemData.SizeSlot, FindIndex)) {
					NewStot.Count = Count;
					int AddIndex;
					ToIntentory->AddSlot(NewStot,false,AddIndex);
					return true;
				}
			}
		}
	}

	return false;
}

bool UInventoryComponent::IsPositionFree(FIntPoint Position, FIntPoint Size, int32 &Index)
{

	if (GetInventorySetting()->PositionSlot == false)
		return true;

	if (Position.X + (Size.X - 1) > MaxSlot.X)
	{
		Index = -1;
		return false;
	}

	if (GetInventorySetting()->LimitSlotY == true) {
		if (Position.Y + (Size.Y - 1) > MaxSlot.Y)
		{
			Index = -1;
			return false;
		}
	}

	for (int i = 0; i < Items.Num(); i++)
	{
		if (IsValid(Items[i].ClassItem)) {
			if (GetInventorySetting()->SizeSlot == true) {
				
				FIntPoint SizeItem = FIntPoint(Items[i].ClassItem.GetDefaultObject()->ItemData.SizeSlot.X - 1, Items[i].ClassItem.GetDefaultObject()->ItemData.SizeSlot.Y - 1);

				if (Position.X >= Items[i].PositionSlot.X ? Position.X <= Items[i].PositionSlot.X + SizeItem.X : Position.X + (Size.X - 1) >= Items[i].PositionSlot.X) {
					if (Position.Y >= Items[i].PositionSlot.Y ? Position.Y <= Items[i].PositionSlot.Y + SizeItem.Y : Position.Y + (Size.Y - 1) >= Items[i].PositionSlot.Y) {
						Index = i;
						return false;
					}
				}
			}
			else {
				if (Position.X == Items[i].PositionSlot.X && Position.Y == Items[i].PositionSlot.Y) {
					Index = i;
					return false;
				}
			}
		}
	}

	return true;
}

bool UInventoryComponent::DropItem(int32 IndexItem = 0, UInventoryComponent* ToInventory = nullptr, int32 ToIndex = -1, FIntPoint ToPosition = FIntPoint::ZeroValue)
{
	if (!GIsServer)
		return false;

	if (!IsValid(ToInventory)) {
		
		if (GetInventorySetting()->StackItems == true) {
			if (ToIndex != -1 && IndexItem != ToIndex) {
				if (Items[IndexItem].ClassItem.GetDefaultObject()->ItemData.StackItem == true) {
					if (Items[IndexItem].ClassItem == Items[ToIndex].ClassItem) {
						
						Items[IndexItem].Count--;
						Items[ToIndex].Count++;
						
						NewDataSlot.Broadcast(ToIndex, Items[ToIndex], ETypeSetItem::SetCount);
						ClientRPC_EventSetItem(ToIndex, Items[ToIndex], ETypeSetItem::SetCount);

						if (Items[IndexItem].Count == 0) {
							NewDataSlot.Broadcast(IndexItem, FInventorySlot(), ETypeSetItem::Remove);
							ClientRPC_EventSetItem(IndexItem, FInventorySlot(), ETypeSetItem::Remove);
							Items.RemoveAt(IndexItem);

						}
						else {
							NewDataSlot.Broadcast(IndexItem, Items[IndexItem], ETypeSetItem::SetCount);
							ClientRPC_EventSetItem(IndexItem, Items[IndexItem], ETypeSetItem::SetCount);
						}
						return true;
					}
				}
			}
		}
		if (ToIndex == -1) {
			if (GetInventorySetting()->StackItems == true) {
				if (Items[IndexItem].ClassItem.GetDefaultObject()->ItemData.StackItem == true && Items[IndexItem].Count != 1) {
					int32 ItemPosition;
					if (IsPositionFree(ToPosition, Items[IndexItem].ClassItem.GetDefaultObject()->ItemData.SizeSlot, ItemPosition)) {
						FInventorySlot Newslot = Items[IndexItem];
						Newslot.Count = 1;
						Newslot.PositionSlot = ToPosition;

						Items[IndexItem].Count--;

						if (Items[IndexItem].Count == 0) {
							NewDataSlot.Broadcast(IndexItem, FInventorySlot(), ETypeSetItem::Remove);
							ClientRPC_EventSetItem(IndexItem, FInventorySlot(), ETypeSetItem::Remove);
							Items.RemoveAt(IndexItem);
						}
						else {
							NewDataSlot.Broadcast(IndexItem, Items[IndexItem], ETypeSetItem::SetCount);
							ClientRPC_EventSetItem(IndexItem, Items[IndexItem], ETypeSetItem::SetCount);
						}

						int32 NewIndex = Items.Add(Newslot);
						NewDataSlot.Broadcast(NewIndex, Items[NewIndex], ETypeSetItem::Add);
						ClientRPC_EventSetItem(NewIndex, Items[NewIndex], ETypeSetItem::Add);
						return true;
					}
				}
			}

			int32 ItemPosition;
			if (IsPositionFree(ToPosition, Items[IndexItem].ClassItem.GetDefaultObject()->ItemData.SizeSlot, ItemPosition)) {
				Items[IndexItem].PositionSlot = ToPosition;
				NewDataSlot.Broadcast(IndexItem, Items[IndexItem], ETypeSetItem::SetPosition);
				ClientRPC_EventSetItem(IndexItem, Items[IndexItem], ETypeSetItem::SetPosition);
				return true;
			}
		}
	}
	else {
		if (GetInventorySetting()->StackItems == true) {
			if (ToIndex != -1) {
				if (Items[IndexItem].ClassItem.GetDefaultObject()->ItemData.StackItem == true) {
					if (Items[IndexItem].ClassItem == ToInventory->Items[ToIndex].ClassItem) {
						
						Items[IndexItem].Count--;
						
						ToInventory->Items[ToIndex].Count++;

						ToInventory->NewDataSlot.Broadcast(ToIndex, ToInventory->Items[ToIndex], ETypeSetItem::SetCount);
						ToInventory->ClientRPC_EventSetItem(ToIndex, ToInventory->Items[ToIndex], ETypeSetItem::SetCount);

						if (GetInventorySetting()->MassItems == true) {
							CurrentMassa -= Items[IndexItem].ClassItem.GetDefaultObject()->ItemData.MassItem;
							ToInventory->CurrentMassa += Items[ToIndex].ClassItem.GetDefaultObject()->ItemData.MassItem;

						}

						if (Items[IndexItem].Count == 0) {
							Items.RemoveAt(IndexItem);
							NewDataSlot.Broadcast(IndexItem, Items[IndexItem], ETypeSetItem::Remove);
							ClientRPC_EventSetItem(IndexItem, Items[IndexItem], ETypeSetItem::Remove);

						}
						else {
							NewDataSlot.Broadcast(IndexItem, Items[IndexItem], ETypeSetItem::SetCount);
							ClientRPC_EventSetItem(IndexItem, Items[IndexItem], ETypeSetItem::SetCount);

						}
						return true;
					}
				}
			}
		}
		if (ToIndex == -1) {

			if (SendItem(IndexItem, ToInventory, 1, false, ToPosition)) {
				return true;
			}
		}
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

#if WITH_EDITOR
void UInventoryComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	//UE_LOG(RHLogGeneral, Warning, TEXT("EditSetting"));
	
	if (GetInventorySetting()->MassItems == true) {
		float NewMass = 0;

		for (int i = 0; i < Items.Num(); i++)
		{
			if (IsValid(Items[i].ClassItem)) {
				NewMass += Items[i].ClassItem.GetDefaultObject()->ItemData.MassItem * Items[i].Count;
			}
		}
		CurrentMassa = NewMass;
	}
}
#endif

UInventorySettings* UInventoryComponent::GetInventorySetting()
{
	return FInventoryModule::Get().GetSettings();
}