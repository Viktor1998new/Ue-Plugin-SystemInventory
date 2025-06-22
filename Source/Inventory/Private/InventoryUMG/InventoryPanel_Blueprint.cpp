//Copyright(c) 2022 - 2025, Viktor.F.P

#include "InventoryPanel_Blueprint.h"
#include "InventoryPanelSlot.h"

UInventoryPanel_Blueprint::UInventoryPanel_Blueprint(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UInventoryPanel_Blueprint::SetInventory(UInventoryComponent* NewInventory)
{
	Super::SetInventory(NewInventory);

	ReceiveInitInventory(NewInventory);
}

void UInventoryPanel_Blueprint::OnChangeSlot(int32 Index, FInventorySlot NewData, ETypeSetItem Type)
{
	ReceiveOnChangeSlot(Index, NewData, Type);
}