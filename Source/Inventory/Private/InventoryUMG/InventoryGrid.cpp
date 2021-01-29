// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryUMG/InventoryGrid.h"
#include "InventoryUMG/InventoryGridSlot.h"

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
		ClearChildren();
	}

	if(IsValid(NewInventory)){

		Inventory = NewInventory;

		Inventory->NewDataSlot.AddDynamic(this, &UInventoryGrid::Event_NewDataSlot);

		if (IsValid(ContentNoneSlot)) {
		
			if (Inventory->MaxSlot != FIntPoint::ZeroValue) {
			
				for (int32 Y = 0; Y < Inventory->MaxSlot.Y; Y++)
				{
					for (int32 X = 0; X < Inventory->MaxSlot.X; X++)
					{
						AddNoneSlot(FIntPoint(X, Y));
					}
				}
			}
		}

		if (Inventory->Items.IsValidIndex(0)) {
			
			for (int32 SlotIndex = 0; SlotIndex < Inventory->Items.Num(); SlotIndex++)
			{
				if(IsValid(Inventory->Items[SlotIndex].ClassItem) && Inventory->Items[SlotIndex].ClassItem.GetDefaultObject()->ItemData.SizeSlot != FIntPoint(0,0))
					AddSlot(SlotIndex);
			}
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

	TArray<FInventorySlot> L_Items = Inventory->Items;
	int32 LastIndex = ItemSlots.Num();

	switch (Type)
	{
	case Add:
		AddSlot(Index);
		break;

	case Remove:

		LastIndex--;
		RemoveChild(ItemSlots[LastIndex]->Content);
		
		if (GIsClient)
			L_Items.RemoveAt(Index);

		if (!L_Items.IsValidIndex(0))
			return;

		for (int32 i = 0; i < ItemSlots.Num(); i++)
		{
			if (L_Items.IsValidIndex(i))
			{
				FIntPoint L_SlotPosition = L_Items[i].PositionSlot * SizeSlot;
				FIntPoint L_SlotSize = L_Items[i].ClassItem.GetDefaultObject()->ItemData.SizeSlot * SizeSlot;
				UInventoryGridSlot* CurrentSlot = ItemSlots[i];

				CurrentSlot->IndexItem = i;
				CurrentSlot->SetPosition(L_SlotPosition);
				CurrentSlot->SetSize(FVector2D(L_SlotSize));
				CurrentSlot->OnChangedSlot.Broadcast(i, L_Items[i]);
			}
		}

		break;
	case SetCount:
		ItemSlots[GetSlotAtItem(Index)]->OnChangedSlot.Broadcast(Index, L_Items[Index]);
		break;

	case SetPosition:
		UInventoryGridSlot* ItemSlot = ItemSlots[GetSlotAtItem(Index)];
		ItemSlot->SetPosition(FVector2D(NewData.PositionSlot.X * SizeSlot, NewData.PositionSlot.Y * SizeSlot));
		break;
	}
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