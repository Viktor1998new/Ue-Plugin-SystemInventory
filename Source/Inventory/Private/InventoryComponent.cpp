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

	DOREPLIFETIME(UInventoryComponent, Items);
	DOREPLIFETIME(UInventoryComponent, CurrentMassa);
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{

}

bool UInventoryComponent::AddSlot(FInventorySlot NewSlot, bool FindPositionSlot, int& Index)
{

	if (!IsValid(NewSlot.ClassItem) && !GIsServer && NewSlot.Count >= 0)
		return false;

	if (FindPositionSlot) {

		FIntPoint NewPosition;

		if (FindFreeSlot(NewSlot.ClassItem.GetDefaultObject()->ItemData.SizeSlot, NewPosition)) {
			NewSlot.PositionSlot = NewPosition;
			int AddIndex = Items.Add(NewSlot);
			Index = AddIndex;

			if (FInventoryModule::Get().GetSettings()->StackItems == false) {
				NewSlot.Count = 1;
			}

			if (FInventoryModule::Get().GetSettings()->MassItems == true) {
				CurrentMassa += NewSlot.ClassItem.GetDefaultObject()->ItemData.MassItem * NewSlot.Count;
			}
			return true;
		}
	}
	else {
		int AddIndex = Items.Add(NewSlot);
		Index = AddIndex;

		if (FInventoryModule::Get().GetSettings()->StackItems == false) {
			NewSlot.Count = 1;
		}

		if (FInventoryModule::Get().GetSettings()->MassItems == true) {
			CurrentMassa += NewSlot.ClassItem.GetDefaultObject()->ItemData.MassItem * NewSlot.Count;
		}
		return true;
	}

	return false;
}

bool UInventoryComponent::AddActorItem(AItemActor* Item, int& Index)
{
	if (!IsValid(Item) && !GIsServer)
		return false;

	return AddClassItem(Item->GetClass(), 1, Item->GetData(), Index);

}

bool UInventoryComponent::AddClassItem(TSubclassOf<AItemActor> Item,int Count, const FString& Data, int& Index)
{
	if (!IsValid(Item) && !GIsServer && Count == 0)
		return false;
	
	AItemActor* DefaultItem = Item.GetDefaultObject();

	if (FInventoryModule::Get().GetSettings()->StackItems == true) {
		
		if (DefaultItem->ItemData.NoneData == true) {

			int FindIndex = 0;

			if (DefaultItem->ItemData.StackItem == true && FindItem(Item, false, FindIndex)) {

				Items[FindIndex].Count += Count;

				if (FInventoryModule::Get().GetSettings()->MassItems == true) {
					CurrentMassa += DefaultItem->ItemData.MassItem * Count;
				}

				Index = FindIndex;
				return true;
			}
		}
		else {
			for (int i = 0; i < Items.Num(); i++)
			{
				if (Items[i].ClassItem == Item && Items[i].ItemData == Data) {
					Items[i].Count += Count;

					if (FInventoryModule::Get().GetSettings()->MassItems == true) {
						CurrentMassa += DefaultItem->ItemData.MassItem * Count;
					}

					Index = i;
					return true;
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
		int IndexAdd = Items.Add(NewSlot);

		if (FInventoryModule::Get().GetSettings()->MassItems == true) {
			CurrentMassa += DefaultItem->ItemData.MassItem * Count;
		}
		Index = IndexAdd;
		return true;
	}

	return false;
}

bool UInventoryComponent::FindFreeSlot(FIntPoint Size, FIntPoint &ReturnPosition)
{
	if (Items.Num() == 0 && Size.X > MaxSlot.X && Size.Y > MaxSlot.Y) {
		ReturnPosition = FIntPoint::ZeroValue;
		UE_LOG(LogInventory, Warning, TEXT("None Item"));
		return true;
	}

	if (FInventoryModule::Get().GetSettings()->SizeSlot == true) {

		int Y = 0;
		int X = 0;

		while (Y < MaxSlot.Y)
		{
			bool IsAdd = true;

			int ItemIndex;
			if (IsPositionFree(FIntPoint(X,Y),Size,ItemIndex)){
				X += Items[ItemIndex].PositionSlot.X + (Items[ItemIndex].ClassItem.GetDefaultObject()->ItemData.SizeSlot.X - 1);
				IsAdd = false;
				break;
			}

			if (IsAdd) {
				ReturnPosition.X = X;
				ReturnPosition.Y = Y;
				return true;
			}

			if (X + (Size.X - 1) >= MaxSlot.X)
			{
				X = 0;
				
				if (FInventoryModule::Get().GetSettings()->LimitSlotY == true) {
					if (Y + (Size.Y - 1) > MaxSlot.Y - 1) {
						return false;
						break;
					}
				}

				Y++;
			}
			
		}

		return true;
	}
	else {
		
		int Y = 0;
		int X = 0;

		for (int i = 0; i < Items.Num(); i++)
		{
			if (Items[i].PositionSlot.X == X && Items[i].PositionSlot.Y == Y) {

				if (X > MaxSlot.X) {
					i = 0;
					X = 0;
					
					if (FInventoryModule::Get().GetSettings()->LimitSlotY == true) {
						if (Y > MaxSlot.Y) {
							return false;
						}
					}

					Y++;
				}
				else
				{
					X++;
				}
			}
		}
		ReturnPosition.X = X;
		ReturnPosition.Y = Y;
		return true;
	}

	return false;
}

bool UInventoryComponent::FindItem(TSubclassOf<AItemActor> ClassItem, bool Child, int& Index)
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

bool UInventoryComponent::RemoveItem(int Index, int Count) {

	if (!Items.IsValidIndex(Index) && !GIsServer) {
		return false;
	}
	if (FInventoryModule::Get().GetSettings()->StackItems == true) {
		if (Items[Index].Count > Count) {

			if (FInventoryModule::Get().GetSettings()->MassItems == true)
				CurrentMassa -= Items[Index].ClassItem.GetDefaultObject()->ItemData.MassItem * Count;

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

		Items.RemoveAt(Index);
		return true;
	}
	return false;
}

bool UInventoryComponent::SendItem(int Index, UInventoryComponent* ToIntentory, int Count, bool FindSlot, FIntPoint Position)
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
			
			int FindIndex;
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

bool UInventoryComponent::IsPositionFree(FIntPoint Position, FIntPoint Size, int &Index)
{
	for (int i = 0; i < Items.Num(); i++)
	{
		if (IsValid(Items[i].ClassItem)) {
			if (FInventoryModule::Get().GetSettings()->SizeSlot == true) {
				if (Position.X >= Items[i].PositionSlot.X ? Position.X <= Items[i].PositionSlot.X + (Items[i].ClassItem.GetDefaultObject()->ItemData.SizeSlot.X - 1) : Position.X + (Size.X - 1) >= Items[i].PositionSlot.X) {
					if (Position.Y >= Items[i].PositionSlot.Y ? Position.Y <= Items[i].PositionSlot.Y + (Items[i].ClassItem.GetDefaultObject()->ItemData.SizeSlot.Y - 1) : Position.Y + (Size.Y - 1) >= Items[i].PositionSlot.Y) {
						Position.X += Items[i].PositionSlot.X + (Items[i].ClassItem.GetDefaultObject()->ItemData.SizeSlot.X - 1);
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