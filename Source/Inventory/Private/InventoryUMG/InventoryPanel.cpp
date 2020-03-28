// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryPanel.h"
#include "InventoryPanelSlot.h"


UInventoryPanel::UInventoryPanel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UInventoryPanel::BeginDestroy() {

	Super::BeginDestroy();
	/*
	if (Inventory != nullptr) {
		Inventory->OnAddItem.RemoveDynamic(this, &UInventoryPanel::Event_AddSlot);
		Inventory->OnRemoveItem.RemoveDynamic(this, &UInventoryPanel::Event_RemoveSlot);
	}*/
}

UInventoryPanelSlot* UInventoryPanel::SlotAsInventorySlot(UWidget* Widget) {
	
	if (Widget)
	{
		return Cast<UInventoryPanelSlot>(Widget->Slot);
	}

	return nullptr;
}

int32 UInventoryPanel::GetSlotAtItem(int32 ItemIndex)
{
	for (int32 SlotIndex = 0; SlotIndex < Slots.Num(); SlotIndex++)
	{
		if (Cast<UInventoryPanelSlot>(Slots[SlotIndex])->IndexItem == ItemIndex) {
			return SlotIndex;
		}
	}

	return -1;
}

void UInventoryPanel::SetInventory(UInventoryComponent* NewInventory)
{
	if (NewInventory == nullptr)
		return;

	if (IsValid(Inventory)) {
		Inventory->OnAddItem.RemoveDynamic(this, &UInventoryPanel::Event_AddSlot);
		Inventory->OnRemoveItem.RemoveDynamic(this, &UInventoryPanel::Event_RemoveSlot);
	
		for (int32 SlotIndex = 0; SlotIndex < Slots.Num(); SlotIndex++)
		{
			RemoveChildAt(SlotIndex);
		}
	}

	Inventory = NewInventory;

	Inventory->OnAddItem.AddDynamic(this,&UInventoryPanel::Event_AddSlot);
	Inventory->OnRemoveItem.AddDynamic(this, &UInventoryPanel::Event_RemoveSlot);

	for (int32 SlotIndex = 0; SlotIndex < Inventory->Items.Num(); SlotIndex++)
	{
		AddSlot(SlotIndex);
	}
	
}

UInventoryPanelSlot* UInventoryPanel::AddSlot(int32 IndexItem)
{
	UInventoryPanelSlot* NewSlot = Cast<UInventoryPanelSlot>(AddChild(CreateContent()));
	NewSlot->SetPosition(FVector2D(Inventory->Items[IndexItem].PositionSlot.X * SizeSlot, Inventory->Items[IndexItem].PositionSlot.Y * SizeSlot));
	NewSlot->SetSize(FVector2D(Inventory->Items[IndexItem].ClassItem.GetDefaultObject()->ItemData.SizeSlot.X * SizeSlot, Inventory->Items[IndexItem].ClassItem.GetDefaultObject()->ItemData.SizeSlot.Y * SizeSlot));
	NewSlot->SetIndexItem(IndexItem);
	return NewSlot;
}

void UInventoryPanel::RemoveSlot(int32 IndexItem)
{
	RemoveChildAt(GetSlotAtItem(IndexItem));
}

void UInventoryPanel::Event_RemoveSlot(int32 IndexItem) {
	
	UE_LOG(LogInventory, Warning, TEXT("Event remove"));

	if (Inventory->Items.Num() != Slots.Num()) {
		int32 LastIndex = Slots.Find(Slots.Last());
		RemoveChildAt(Slots.Find(Slots.Last()));

		UE_LOG(LogInventory, Warning, TEXT("LastIndex: %d"), LastIndex);
	
		/*
		for (int32 SlotIndex = 0; SlotIndex < Slots.Num(); SlotIndex++)
		{
			if (!Inventory->Items.IsValidIndex(Cast<UInventoryPanelSlot>(Slots[SlotIndex])->IndexItem)) {
				int32 NewIndex = Cast<UInventoryPanelSlot>(Slots[SlotIndex])->IndexItem;
				NewIndex--;
				Cast<UInventoryPanelSlot>(Slots[SlotIndex])->SetIndexItem(NewIndex);
			}
			
		}*/
	}
}

void UInventoryPanel::Event_AddSlot(int32 IndexItem)
{
	UE_LOG(LogInventory, Warning, TEXT("Event Add"));
	if (Inventory->Items.Num() != Slots.Num()) {
		AddSlot(IndexItem);
	}
}

UClass* UInventoryPanel::GetSlotClass() const
{
	return UInventoryPanelSlot::StaticClass();
}

void UInventoryPanel::OnSlotAdded(UPanelSlot* inSlot)
{
	// Add the child to the live canvas if it already exists
	if (MyInventoryPanel.IsValid())
	{
		CastChecked<UInventoryPanelSlot>(inSlot)->BuildSlot(MyInventoryPanel.ToSharedRef());
	}
}

void UInventoryPanel::OnSlotRemoved(UPanelSlot* inSlot)
{
	// Remove the widget from the live slot if it exists.
	if (MyInventoryPanel.IsValid())
	{
		TSharedPtr<SWidget> Widget = inSlot->Content->GetCachedWidget();
		if (Widget.IsValid())
		{
			MyInventoryPanel->RemoveSlot(Widget.ToSharedRef());
		}
	}
}

UWidget* UInventoryPanel::CreateContent()
{
	UWidget* Value;

	ReceiveCreateContent(Value);

	return Value;
}

TSharedRef<SWidget> UInventoryPanel::RebuildWidget()
{
	MyInventoryPanel = SNew(SConstraintCanvas);

	return MyInventoryPanel.ToSharedRef();
}
