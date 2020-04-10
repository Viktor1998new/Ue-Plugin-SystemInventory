// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryGrid.h"
#include "InventoryGridSlot.h"



#define LOCTEXT_NAMESPACE "UMG"

UInventoryGrid::UInventoryGrid(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UInventoryGrid::BeginDestroy() {

	Super::BeginDestroy();

	if (Inventory != nullptr) {
		Inventory->NewDataSlot.RemoveDynamic(this, &UInventoryGrid::Event_NewDataSlot);
	}
}

UInventoryGridSlot* UInventoryGrid::SlotAsInventorySlot(UWidget* Widget) {
	
	if (Widget)
	{
		return Cast<UInventoryGridSlot>(Widget->Slot);
	}

	return nullptr;
}

int32 UInventoryGrid::GetSlotAtItem(int32 ItemIndex)
{
	for (int32 SlotIndex = 0; SlotIndex < ItemSlots.Num(); SlotIndex++)
	{
		if (ItemSlots[SlotIndex]->IndexItem == ItemIndex) {
			return SlotIndex;
		}
	}

	return -1;
}

void UInventoryGrid::SetInventory(UInventoryComponent* NewInventory)
{

	if (IsValid(Inventory)) {
		Inventory->NewDataSlot.RemoveDynamic(this, &UInventoryGrid::Event_NewDataSlot);

		for (int32 SlotIndex = 0; SlotIndex < Slots.Num(); SlotIndex++)
		{
			RemoveChildAt(SlotIndex);
		}
	}

	if(IsValid(NewInventory)){

		Inventory = NewInventory;

		Inventory->NewDataSlot.AddDynamic(this, &UInventoryGrid::Event_NewDataSlot);

		if (IsValid(ContentNoneSlot)) {

			for (int32 Y = 0; Y < Inventory->MaxSlot.Y; Y++)
			{
				for (int32 X = 0; X < Inventory->MaxSlot.X; X++)
				{
					AddNoneSlot(FIntPoint(X, Y));
				}
			}
		}

		for (int32 SlotIndex = 0; SlotIndex < Inventory->Items.Num(); SlotIndex++)
		{
			AddSlot(SlotIndex);
		}
	}
}

void UInventoryGrid::AddNoneSlot(FIntPoint Position)
{
	UUserWidget* ContentWidget = NewObject<UUserWidget>(this, ContentNoneSlot);
	UInventoryGridSlot* NewSlot = Cast<UInventoryGridSlot>(Super::AddChild(ContentWidget));
	NewSlot->SetPosition(FVector2D(Position.X * SizeSlot, Position.Y * SizeSlot));
	NewSlot->SetSize(FVector2D(SizeSlot, SizeSlot));
	NewSlot->SlotPosition = Position;
}

UInventoryGridSlot* UInventoryGrid::AddSlot(int32 IndexItem)
{
	UUserWidget* ContentWidget = NewObject<UUserWidget>(this, ContentItemSlot);
	UInventoryGridSlot* NewSlot = Cast<UInventoryGridSlot>(Super::AddChild(ContentWidget));
	NewSlot->SetIndexItem(IndexItem);
	ItemSlots.Add(NewSlot);
	return NewSlot;
}

void UInventoryGrid::RemoveSlot(int32 IndexItem)
{
	RemoveChildAt(GetSlotAtItem(IndexItem));
}

void UInventoryGrid::Event_NewDataSlot(int32 Index, FInventorySlot NewData, ETypeSetItem Type)
{
	if (Type == ETypeSetItem::Add) {
		AddSlot(Index);
		return;
	}
	else if (Type == ETypeSetItem::Remove) {
		
		int32 LastIndex = ItemSlots.Num();
		LastIndex--;
		RemoveChild(ItemSlots[LastIndex]->Content);

		if (!Inventory->Items.IsValidIndex(0))
			return;

		TArray<FInventorySlot> L_Items = Inventory->Items;
		L_Items.RemoveAt(Index);

		for (int32 i = 0; i < ItemSlots.Num(); i++)
		{
			UInventoryGridSlot* CurrentSlot = ItemSlots[i];
			if (IsValid(CurrentSlot) && L_Items.IsValidIndex(i))
			{
				CurrentSlot->IndexItem = i;
				CurrentSlot->DataSlot = L_Items[i];
				CurrentSlot->SetPosition(FVector2D(L_Items[i].PositionSlot.X * SizeSlot, L_Items[i].PositionSlot.Y * SizeSlot));
				CurrentSlot->SetSize(FVector2D(L_Items[i].ClassItem.GetDefaultObject()->ItemData.SizeSlot.X * SizeSlot, L_Items[i].ClassItem.GetDefaultObject()->ItemData.SizeSlot.Y * SizeSlot));
			}
		}
		return;
	}
	else if (Type == ETypeSetItem::SetPosition) {
		UInventoryGridSlot* ItemSlot = ItemSlots[GetSlotAtItem(Index)];
		ItemSlot->SetPosition(FVector2D(NewData.PositionSlot.X * SizeSlot, NewData.PositionSlot.Y * SizeSlot));
		ItemSlot->DataSlot = NewData;
		return;
	}

	UInventoryGridSlot* ItemSlot = ItemSlots[GetSlotAtItem(Index)];
	ItemSlot->DataSlot = NewData;
}

UClass* UInventoryGrid::GetSlotClass() const
{
	return UInventoryGridSlot::StaticClass();
}

void UInventoryGrid::OnSlotAdded(UPanelSlot* inSlot)
{
	// Add the child to the live canvas if it already exists
	if (MyPanel.IsValid())
	{
		CastChecked<UInventoryGridSlot>(inSlot)->BuildSlot(MyPanel.ToSharedRef());
	}
}

void UInventoryGrid::OnSlotRemoved(UPanelSlot* inSlot)
{
	// Remove the widget from the live slot if it exists.
	if (MyPanel.IsValid())
	{
		TSharedPtr<SWidget> Widget = inSlot->Content->GetCachedWidget();
		if (Widget.IsValid())
		{
			ItemSlots.Remove(Cast<UInventoryGridSlot>(inSlot));
			MyPanel->RemoveSlot(Widget.ToSharedRef());
		}
	}
}

UWidget* UInventoryGrid::CreateContent(){

	return CreateWidget<UUserWidget>(GetOwningPlayer(), ContentItemSlot);
}

TSharedRef<SWidget> UInventoryGrid::RebuildWidget()
{
	MyPanel = SNew(SConstraintCanvas);

	for (UPanelSlot* PanelSlot : Slots)
	{
		if (UInventoryGridSlot* TypedSlot = Cast<UInventoryGridSlot>(PanelSlot))
		{
			TypedSlot->Parent = this;
			TypedSlot->BuildSlot(MyPanel.ToSharedRef());
		}
	}
	return MyPanel.ToSharedRef();
}

#if WITH_EDITOR

const FText UInventoryGrid::GetPaletteCategory()
{
	return LOCTEXT("Panel", "Panel");
}

#endif

#undef LOCTEXT_NAMESPACE