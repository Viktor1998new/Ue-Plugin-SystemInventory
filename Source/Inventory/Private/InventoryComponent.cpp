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

void UInventoryComponent::ClientRPC_EventSetItem_Implementation(int32 Index, ETypeSetItem Type)
{
	ItemIndex = Index;
	TypeSetItem = Type;
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{

}

bool UInventoryComponent::AddSlot(FInventorySlot NewSlot, bool FindPositionSlot, int32& Index)
{

	if (!IsValid(NewSlot.ClassItem) && !GIsServer && NewSlot.Count >= 0)
		return false;

	if (FindPositionSlot) {

		FIntPoint NewPosition;

		if (FindFreeSlot(NewSlot.ClassItem.GetDefaultObject()->ItemData.SizeSlot, NewPosition)) {
			NewSlot.PositionSlot = NewPosition;
			int32 AddIndex = Items.Add(NewSlot);
			Index = AddIndex;

			if (FInventoryModule::Get().GetSettings()->StackItems == false) {
				NewSlot.Count = 1;
			}else if(NewSlot.ClassItem.GetDefaultObject()->ItemData.StackItem == false){
				NewSlot.Count = 1;
			}

			if (FInventoryModule::Get().GetSettings()->MassItems == true) {
				CurrentMassa += NewSlot.ClassItem.GetDefaultObject()->ItemData.MassItem * NewSlot.Count;
			}
			return true;
		}
	}
	else {
		int32 AddIndex = Items.Add(NewSlot);
		Index = AddIndex;

		if (FInventoryModule::Get().GetSettings()->StackItems == false) {
			NewSlot.Count = 1;
		}
		else if (NewSlot.ClassItem.GetDefaultObject()->ItemData.StackItem == false) {
			NewSlot.Count = 1;
		}

		if (FInventoryModule::Get().GetSettings()->MassItems == true) {
			CurrentMassa += NewSlot.ClassItem.GetDefaultObject()->ItemData.MassItem * NewSlot.Count;
		}
		return true;
	}

	return false;
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

	if (FInventoryModule::Get().GetSettings()->StackItems == true) {

		if (DefaultItem->ItemData.StackItem == true) {
			if (DefaultItem->ItemData.NoneData == true) {

				int32 FindIndex = 0;

				if (DefaultItem->ItemData.StackItem == true && FindItem(Item, false, FindIndex)) {

					Items[FindIndex].Count += Count;

					if (FInventoryModule::Get().GetSettings()->MassItems == true) {
						CurrentMassa += DefaultItem->ItemData.MassItem * Count;
					}

					Index = FindIndex;
						
					OnAddItem.Broadcast(FindIndex);
					ClientRPC_EventSetItem(FindIndex, ETypeSetItem::Add);
					return true;
				}
			}
			else {
				for (int32 i = 0; i < Items.Num(); i++)
				{
					if (Items[i].ClassItem == Item && Items[i].ItemData == Data) {
						Items[i].Count += Count;

						if (FInventoryModule::Get().GetSettings()->MassItems == true) {
							CurrentMassa += DefaultItem->ItemData.MassItem * Count;
						}

						Index = i;
						
						OnAddItem.Broadcast(Index);

						ClientRPC_EventSetItem(i, ETypeSetItem::Add);
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

		if (FInventoryModule::Get().GetSettings()->MassItems == true) {
			CurrentMassa += DefaultItem->ItemData.MassItem * Count;
		}
		Index = IndexAdd;

		OnAddItem.Broadcast(IndexAdd);
		ClientRPC_EventSetItem(IndexAdd, ETypeSetItem::Add);
		return true;
	}

	return false;
}

bool UInventoryComponent::FindFreeSlot(FIntPoint Size, FIntPoint &ReturnPosition)
{
	if (Items.Num() == 0 && Size.X > MaxSlot.X && Size.Y > MaxSlot.Y) {
		ReturnPosition = FIntPoint::ZeroValue;
		return true;
	}

	int32 X = 0, Y = 0;

	bool IsNoFree = true;

	while (IsNoFree) {

		int L_ItemIndex;

		IsNoFree = !IsPositionFree(FIntPoint(X, Y), Size, L_ItemIndex);

		if (IsNoFree) {
			
			if (FInventoryModule::Get().GetSettings()->SizeSlot == true) {

				X = Items[L_ItemIndex].PositionSlot.X + Items[L_ItemIndex].ClassItem.GetDefaultObject()->ItemData.SizeSlot.X;
			}
			else {
				X++;
			}
		}

		if (X + (Size.X - 1) > MaxSlot.X) {
			X = 0;

			if (FInventoryModule::Get().GetSettings()->LimitSlotY == true) {
				if (Y + (Size.Y - 1) > MaxSlot.Y)
				{
					return false;
				}
			}

			Y++;
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

	if (!Items.IsValidIndex(Index) || !GIsServer || Items.Num() == 0) {
		return false;
	}

	if (FInventoryModule::Get().GetSettings()->StackItems == true) {
		
		if (Items[Index].Count >= Count) {

			if (FInventoryModule::Get().GetSettings()->MassItems == true)
				CurrentMassa -= Items[Index].ClassItem.GetDefaultObject()->ItemData.MassItem * Count;

			OnRemoveItem.Broadcast(Index);
			ClientRPC_EventSetItem(Index, ETypeSetItem::Remove);

			if (Items[Index].Count - Count == 0) {
				
				Items.RemoveAt(Index);
			}
			else {
				Items[Index].Count -= Count;
			}

			return true;
		}
	}
	else
	{
		if (FInventoryModule::Get().GetSettings()->MassItems == true)
			CurrentMassa -= Items[Index].ClassItem.GetDefaultObject()->ItemData.MassItem;

		OnRemoveItem.Broadcast(Index);
		Items.RemoveAt(Index);

		return true;
	}
	return false;
}

bool UInventoryComponent::SendItem(int32 Index, UInventoryComponent* ToIntentory, int32 Count, bool FindSlot, FIntPoint Position)
{
	if (!GIsServer)
		return true;

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
				}
			}
		}
	}

	return false;
}

bool UInventoryComponent::IsPositionFree(FIntPoint Position, FIntPoint Size, int32 &Index)
{

	if (Position.X + (Size.X - 1) > MaxSlot.X)
	{
		Index = -1;
		return false;
	}

	if (FInventoryModule::Get().GetSettings()->LimitSlotY == true) {
		if (Position.Y + (Size.Y - 1) > MaxSlot.Y)
		{
			Index = -1;
			return false;
		}
	}

	for (int i = 0; i < Items.Num(); i++)
	{
		if (IsValid(Items[i].ClassItem)) {
			if (FInventoryModule::Get().GetSettings()->SizeSlot == true) {
				
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

void UInventoryComponent::OnRep_SetItems()
{
	
	switch (TypeSetItem)
	{
	case ETypeSetItem::Add:
		OnAddItem.Broadcast(ItemIndex);

		break;

	case ETypeSetItem::Remove:
		OnRemoveItem.Broadcast(ItemIndex);
		break;
	}
}

#if WITH_EDITOR
void UInventoryComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	//UE_LOG(RHLogGeneral, Warning, TEXT("EditSetting"));

	if (FInventoryModule::Get().GetSettings()->MassItems == true) {
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