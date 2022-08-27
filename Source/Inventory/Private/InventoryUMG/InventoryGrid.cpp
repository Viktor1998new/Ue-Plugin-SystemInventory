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

	if (Inventory) {
		Inventory->NewDataSlot.RemoveDynamic(this, &UInventoryGrid::Event_NewDataSlot);
	}
}

UInventoryGridSlot* UInventoryGrid::SlotAsInventorySlot(UWidget* Widget) {
	
	if (Widget)	return Cast<UInventoryGridSlot>(Widget->Slot);
	
	return nullptr;
}

void UInventoryGrid::SetInventory(UInventoryComponent* NewInventory)
{

	if (Inventory) {
		Inventory->NewDataSlot.RemoveDynamic(this, &UInventoryGrid::Event_NewDataSlot);
		ClearChildren();
	}

	if (!NewInventory) return;

	Inventory = NewInventory;

	Inventory->NewDataSlot.AddDynamic(this, &UInventoryGrid::Event_NewDataSlot);

	if (NoneSlot) {
		if (Inventory->MaxSlot != FIntPoint::ZeroValue) {

			for (int32 Y = 0; Y < Inventory->MaxSlot.Y; Y++)
				for (int32 X = 0; X < Inventory->MaxSlot.X; X++)
					AddNoneSlot(FIntPoint(X, Y));
		}
	}

	if (!Inventory->Items.IsEmpty()) {

		for (int32 SlotIndex = 0; SlotIndex < Inventory->Items.Num(); SlotIndex++)
			if (Inventory->Items[SlotIndex].ItemAsset && Inventory->Items[SlotIndex].ItemAsset->SlotItemData.SizeSlot != FIntPoint(0, 0))
				AddSlot(SlotIndex);
	}
}

void UInventoryGrid::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	MyPanel.Reset();
}

void UInventoryGrid::AddNoneSlot(FIntPoint Position)
{
	UUserWidget* WidgetSlot = CreateWidget<UUserWidget>(this, NoneSlot);
	UInventoryGridSlot* NewSlot = Cast<UInventoryGridSlot>(Super::AddChild(WidgetSlot));
	NewSlot->SetTransform(Position, FIntPoint(1, 1));
}

UInventoryGridSlot* UInventoryGrid::AddSlot(int32 IndexItem)
{
	UUserWidget* WidgetSlot = CreateWidget<UUserWidget>(this,ItemSlot);
	UInventoryGridSlot* NewSlot = Cast<UInventoryGridSlot>(Super::AddChild(WidgetSlot));
	NewSlot->SetIndexItem(IndexItem);
	ItemSlots.Add(NewSlot);
	return NewSlot;
}

void UInventoryGrid::RemoveSlot(int32 IndexItem)
{
	RemoveChildAt(Slots.Find(ItemSlots[IndexItem]));
}

void UInventoryGrid::Event_NewDataSlot(int32 Index, FInventorySlot NewData, ETypeSetItem Type)
{
	TArray<FInventorySlot> L_Items = Inventory->Items;

	switch (Type)
	{
		case Add:
			AddSlot(Index);
			break;

		case Remove:
			RemoveChild(ItemSlots.Last(0)->Content);

			if (GIsClient)
				L_Items.RemoveAt(Index);

			if (L_Items.IsEmpty())
				return;

			for (int32 SlotIndex = Index; SlotIndex < L_Items.Num(); SlotIndex++)
			{
				UInventoryGridSlot* L_Slot = ItemSlots[SlotIndex];
				L_Slot->SetIndexItem(SlotIndex);
				L_Slot->OnChangedSlot.Broadcast(SlotIndex, L_Items[SlotIndex]);
			}
			break;

		case ChangeSlot:
			ItemSlots[Index]->OnChangedSlot.Broadcast(Index, Inventory->Items[Index]);
			ItemSlots[Index]->SetPosition(NewData.PositionSlot);
			break;

		case SetPosition:
			ItemSlots[Index]->SetPosition(NewData.PositionSlot * SizeSlot);
			break;
	}
}

UClass* UInventoryGrid::GetSlotClass() const
{
	return UInventoryGridSlot::StaticClass();
}

void UInventoryGrid::OnSlotAdded(UPanelSlot* inSlot)
{
	if (!MyPanel.IsValid()) return;

	CastChecked<UInventoryGridSlot>(inSlot)->ParentPanel = this;
	CastChecked<UInventoryGridSlot>(inSlot)->BuildSlot(MyPanel.ToSharedRef());
}

void UInventoryGrid::OnSlotRemoved(UPanelSlot* inSlot)
{
	if (!MyPanel.IsValid()) return;

	TSharedPtr<SWidget> Widget = inSlot->Content->GetCachedWidget();

	if (Widget.IsValid()) ItemSlots.Remove(Cast<UInventoryGridSlot>(inSlot));

	MyPanel->RemoveSlot(Widget.ToSharedRef());
}

TSharedRef<SWidget> UInventoryGrid::RebuildWidget()
{
	MyPanel = SNew(SConstraintCanvas);

	if(!Slots.IsEmpty() && Inventory)
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