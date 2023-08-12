//Copyright(c) 2022, Viktor.F.P

#include "InventoryUMG/InventoryList.h"
#include "InventoryUMG/InventoryPanelSlot.h"
#include "GameFramework/PlayerState.h"
#include "TimerManager.h"

#define LOCTEXT_NAMESPACE "UMG"

UInventoryList::UInventoryList(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) {

}

void UInventoryList::SetInventory(UInventoryComponent* NewInventory)
{
	Super::SetInventory(NewInventory);
	
	if (!IsValid(NewInventory))
		return;

	for (int i = 0; i < Inventory->Items.Num(); i++)
	{
		AddSlot(i);
	}

}

void UInventoryList::AddSlot(int32 IndexItem)
{
	UUserWidget* WidgetSlot = CreateWidget<UUserWidget>(this, ItemSlot);
	UInventoryPanelSlot* NewSlot = Cast<UInventoryPanelSlot>(Super::AddChild(WidgetSlot));
	NewSlot->SetAnchors(FAnchors(0.0f, 0.0f, 1.0f, 0.0f));
	SetSlotPosition(NewSlot, SizeSlot * IndexItem);
	NewSlot->SetIndexItem(IndexItem);
	NewSlot->SetZOrder(1);
	ItemSlots.Add(NewSlot);
}

void UInventoryList::OnChangeSlot(int32 Index, FInventorySlot NewData, ETypeSetItem Type)
{
	if (GetOwningPlayer()) {
		if (Inventory->GetIsReplicated()) {
			float TimePing = GetOwningPlayer()->PlayerState->GetPing() * GetWorld()->GetDeltaSeconds();

			if (TimePing == 0.0f) {
				ChangeSlots(Index, NewData, Type);
				return;
			}

			FTimerHandle TimerPing;
			FTimerDelegate Del_ChangeSlots = FTimerDelegate::CreateUObject(this, &UInventoryList::ChangeSlots, Index, NewData, Type);
			GetWorld()->GetTimerManager().SetTimer(TimerPing, Del_ChangeSlots, TimePing, false);
			return;
		}
	}

	ChangeSlots(Index, NewData, Type);
}

void UInventoryList::ChangeSlots(int32 Index, FInventorySlot NewData, ETypeSetItem Type)
{
	switch (Type)
	{
	case ETypeSetItem::Add:
		AddSlot(Index);
		break;

	case ETypeSetItem::Remove:

		RemoveChild(ItemSlots.Last()->Content);

		if (Inventory->Items.Num() == 0)
			return;

		for (int32 i = Index; i < ItemSlots.Num(); i++) {
			FInventorySlot L_Slot = Inventory->Items[i];
			ItemSlots[i]->ChangeSlot(L_Slot);
			SetSlotPosition(ItemSlots[i], Index);
		}
		break;

	case ETypeSetItem::ChangeSlot:
		ItemSlots[Index]->ChangeSlot(NewData);
		SetSlotPosition(ItemSlots[Index], Index* SizeSlot);
		break;

	case ETypeSetItem::SetPosition:
		SetSlotPosition(ItemSlots[Index], Index * SizeSlot);
		break;
	}
}

void UInventoryList::SetSlotPosition(UInventoryPanelSlot* ChangeSlot, float Position)
{
	ChangeSlot->SetMargin(FMargin(0.0f, Position,0.0f, SizeSlot));
}

#undef LOCTEXT_NAMESPACE
