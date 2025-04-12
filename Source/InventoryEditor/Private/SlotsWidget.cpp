//Copyright(c) 2022 - 2025, Viktor.F.P
#include "SlotsWidget.h"
#include "InventoryUMG/InventoryPanel.h"
#include "Brushes/SlateColorBrush.h"

UInventoryComponent* USlotWidget::GetInventory()
{
	return Cast<UInventoryPanel>(GetParent())->Inventory;
}

FMargin USlotWidget::GetOffsetMouse() const
{
	return FMargin(MousePosition.X, MousePosition.Y);
}

FReply USlotWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if (InMouseEvent.IsLeftControlDown()) {

		if (InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton)) {

			Cast<UInventoryPanel>(GetParent())->Inventory->RemoveItem(Item_Index, Item_Slot.Count);
			return FReply::Handled();
		}
	}

	if (InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton)) {

		SetKeyboardFocus();

		TSharedPtr<SWidget> SlateWidgetDetectingDrag = GetCachedWidget();

		if (SlateWidgetDetectingDrag.IsValid())
		{
			return FReply::Handled().DetectDrag(SlateWidgetDetectingDrag.ToSharedRef(), EKeys::LeftMouseButton);
		}
	}

	return FReply::Unhandled();
}

FReply USlotWidget::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{

	if (InMouseEvent.GetEffectingButton() == EKeys::RightMouseButton) {
		MousePosition = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
		MenuAnchor->SetIsOpen(true, true);
		ContextMenu->SetItem(MenuAnchor, Cast<UInventoryPanel>(GetParent())->Inventory, Item_Index);

		return FReply::Handled();
	}

	return FReply::Unhandled();
}

void UVisualDragWidget::SetItem(UTexture2D* Texture, FVector2D Size)
{
	if (SizeBox.IsValid()) {
		SizeBox.ToSharedRef()->SetWidthOverride(Size.X);
		SizeBox.ToSharedRef()->SetHeightOverride(Size.Y);
		return;
	}

	FSlateColorBrush* Brush = new  FSlateColorBrush(FLinearColor(0.0f, 0.0f, 0.0f, 0.6f));

	FSlateBrush* BrushTexure = new FSlateBrush();

	if (BrushTexure->GetResourceObject() != Texture)
	{
		BrushTexure->SetResourceObject(Texture);
		BrushTexure->DrawAs = ESlateBrushDrawType::Image;
		BrushTexure->ImageSize = Size;

		if (Texture)
		{
			Texture->bForceMiplevelsToBeResident = true;
			Texture->bIgnoreStreamingMipBias = true;
		}
	}

	SizeBox = SNew(SBox)
		.WidthOverride(Size.X)
		.HeightOverride(Size.Y)[
			SNew(SBorder)
				.BorderImage(Brush)[
					SNew(SImage)
						.Image(BrushTexure)
				]
		];
}

TSharedRef<SWidget> UVisualDragWidget::RebuildWidget()
{
	return SizeBox.ToSharedRef();
}