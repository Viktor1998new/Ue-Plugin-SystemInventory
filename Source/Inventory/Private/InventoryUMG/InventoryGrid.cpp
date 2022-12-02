//Copyright(c) 2022, Viktor.F.P

#include "InventoryUMG/InventoryGrid.h"
#include "InventoryUMG/InventoryGridSlot.h"
#include "InventorySettings.h"
#include "GameFramework/PlayerState.h"
#include "TimerManager.h"
#include "Inventory.h"

#define LOCTEXT_NAMESPACE "UMG"

UInventoryGrid::UInventoryGrid(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UInventoryGrid::RemoveFromParent() {

	if (Inventory)
		Inventory->NewDataSlot.RemoveDynamic(this, &UInventoryGrid::Event_NewDataSlot);
	
	Super::RemoveFromParent();
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

	if (NoneSlot && Inventory->MaxSlot != FIntPoint::ZeroValue) {
		if (EnumHasAnyFlags((EInventoryFlag)FInventoryModule::Get().GetSettings()->InventoryFlags, EInventoryFlag::OnlyX)) {
			for (int32 X = 0; X < Inventory->MaxSlot.X; X++)
				AddNoneSlot(FIntPoint(X, 0));
		}
		else {
			for (int32 Y = 0; Y < Inventory->MaxSlot.Y; Y++)
				for (int32 X = 0; X < Inventory->MaxSlot.X; X++)
					AddNoneSlot(FIntPoint(X, Y));
		}
	}

	if (Inventory->Items.Num() != 0) {

		for (int32 i = 0; i < Inventory->Items.Num(); i++)
			if (Inventory->Items[i].ItemAsset)
				AddSlot(i);
	}
}

void UInventoryGrid::ReleaseSlateResources(bool bReleaseChildren)
{
	if (Inventory)
		Inventory->NewDataSlot.RemoveDynamic(this, &UInventoryGrid::Event_NewDataSlot);

	Super::ReleaseSlateResources(bReleaseChildren);

	MyPanel.Reset();
}

void UInventoryGrid::AddNoneSlot(FIntPoint Position)
{
	UUserWidget* WidgetSlot = CreateWidget<UUserWidget>(this, NoneSlot);
	UInventoryGridSlot* NewSlot = Cast<UInventoryGridSlot>(Super::AddChild(WidgetSlot));
	NewSlot->SetTransform(Position, FIntPoint(1, 1));
}

void UInventoryGrid::AddSlot(int32 IndexItem)
{
	UUserWidget* WidgetSlot = CreateWidget<UUserWidget>(this,ItemSlot);
	UInventoryGridSlot* NewSlot = Cast<UInventoryGridSlot>(Super::AddChild(WidgetSlot));
	NewSlot->SetIndexItem(IndexItem);
	NewSlot->SetZOrder(1);
	ItemSlots.Add(NewSlot);
}

void UInventoryGrid::RemoveSlot(int32 IndexItem)
{
	RemoveChildAt(Slots.Find(ItemSlots[IndexItem]));
}

void UInventoryGrid::Event_NewDataSlot(int32 Index, FInventorySlot NewData, ETypeSetItem Type)
{	
	if(GetOwningPlayer()){
		if (Inventory->GetIsReplicated()) {
			float TimePing = GetOwningPlayer()->PlayerState->Ping * GetWorld()->GetDeltaSeconds();

			if (TimePing == 0.0f) {
				ChangeSlots(Index, NewData, Type);
				return;
			}

			FTimerHandle TimerPing;
			FTimerDelegate Del_ChangeSlots = FTimerDelegate::CreateUObject(this, &UInventoryGrid::ChangeSlots, Index,NewData,Type);
			GetWorld()->GetTimerManager().SetTimer(TimerPing, Del_ChangeSlots, TimePing, false);
			return;
		}
	}

	ChangeSlots(Index, NewData, Type);
}

void UInventoryGrid::ChangeSlots(int32 Index, FInventorySlot NewData, ETypeSetItem Type) {

	switch (Type)
	{
	case Add:
		AddSlot(Index);
		break;

	case Remove:

		RemoveChild(ItemSlots.Last()->Content);

		if (Inventory->Items.Num() == 0)
			return;

		for (int32 i = Index; i < Inventory->Items.Num(); i++)
			ItemSlots[i]->ChangeSlot(Inventory->Items[i]);

		break;

	case ChangeSlot:
		ItemSlots[Index]->ChangeSlot(NewData);
		break;

	case SetPosition:
		ItemSlots[Index]->SetPosition(NewData.PositionSlot);
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

	CastChecked<UInventoryGridSlot>(inSlot)->Parent = this;
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

	if(Slots.Num() != 0 && Inventory)
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