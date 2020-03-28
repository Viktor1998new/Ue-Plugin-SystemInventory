
#include "InventoryPanelSlot.h"
#include "InventoryPanel.h"

UInventoryPanelSlot::UInventoryPanelSlot(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, Slot(nullptr)
{
}

void UInventoryPanelSlot::BuildSlot(TSharedRef<SConstraintCanvas> GridPanel)
{
	Slot = &GridPanel->AddSlot()
		[
			Content == nullptr ? SNullWidget::NullWidget : Content->TakeWidget()
		];
	Slot->Alignment(FVector2D(0.0f, 0.0f));
}

void UInventoryPanelSlot::SetSize(FVector2D InSize)
{
	Transform.Offsets.Right = InSize.X;
	Transform.Offsets.Bottom = InSize.Y;

	if (Slot)
	{
		Slot->Offset(Transform.Offsets);
	}
}

void UInventoryPanelSlot::SetPosition(FVector2D InPosition)
{
	Transform.Offsets.Left = InPosition.X;
	Transform.Offsets.Top = InPosition.Y;

	if (Slot)
	{
		Slot->Offset(Transform.Offsets);
	}
}

void UInventoryPanelSlot::SetZOrder(int32 InZOrder)
{
	ZOrder = InZOrder;
	if (Slot)
	{
		Slot->ZOrder(InZOrder);
	}
}

void UInventoryPanelSlot::SetIndexItem(int32 NewIndex)
{
	IndexItem = NewIndex;
	DataSlot = Cast<UInventoryPanel>(Parent)->Inventory->Items[NewIndex];
}
