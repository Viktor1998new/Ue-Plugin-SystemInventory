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
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{

}

bool UInventoryComponent::AddSlot(FInventorySlot Item, int& Index)
{
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

	FIntPoint NewLocation;
	if (FindFreeSlot(DefaultItem->ItemData.SizeSlot, NewLocation)) {
		FInventorySlot NewSlot;
		NewSlot.ClassItem = Item;
		NewSlot.Count = Count;
		
		if (DefaultItem->ItemData.NoneData == false)
			NewSlot.ItemData = Data;
		
		NewSlot.LocationSlot = NewLocation;
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

			for (int i = 0; i < Items.Num(); i++)
			{
				if (IsValid(Items[i].ClassItem)) {

					if (X >= Items[i].LocationSlot.X ? X <= Items[i].LocationSlot.X + (Items[i].ClassItem.GetDefaultObject()->ItemData.SizeSlot.X - 1) : X + (Size.X - 1) >= Items[i].LocationSlot.X) {
						if (Y >= Items[i].LocationSlot.Y ? Y <= Items[i].LocationSlot.Y + (Items[i].ClassItem.GetDefaultObject()->ItemData.SizeSlot.Y - 1) : Y + (Size.Y - 1) >= Items[i].LocationSlot.Y) {
							X += Items[i].LocationSlot.X + (Items[i].ClassItem.GetDefaultObject()->ItemData.SizeSlot.X - 1);
							IsAdd = false;
							break;
						}
					}
				}
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
			if (Items[i].LocationSlot.X == X && Items[i].LocationSlot.Y == Y) {

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