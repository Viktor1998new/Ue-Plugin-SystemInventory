//Copyright(c) 2022 - 2025, Viktor.F.P
#include "SlotsWidget.h"
#include "InventoryUMG/InventoryPanelSlot.h"
#include "InventoryUMG/InventoryPanel.h"

void USlotItemWidget::SetVisible()
{
	SetVisibility(ESlateVisibility::Visible);
	ImageItem->SetVisibility(EVisibility::Visible);
	NumberText->SetVisibility(EVisibility::Visible);
}

void USlotItemWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation)
{
	operation = NewObject<UInventotySlot_Drag>();

	operation->Pivot = EDragPivot::TopLeft;

	auto DragVisual = CreateWidget<UVisualDragWidget>(this);

	operation->Payload = this;

	DragVisual->SetItem(Item_Slot.GetData().ImageItem, Item_Slot.GetSize() * SizeSlot);

	operation->DefaultDragVisual = DragVisual;

	operation->Index = Item_Index;
	operation->Count = Item_Slot.Count;
	operation->SetRotateItem(Item_Slot.IsRotate); 

	operation->Inventory = Cast<UInventoryPanel>(GetParent())->Inventory;

	SetVisibility(ESlateVisibility::HitTestInvisible);
	ImageItem->SetVisibility(EVisibility::Hidden);
	NumberText->SetVisibility(EVisibility::Hidden);

	OutOperation = operation;
}

void USlotItemWidget::NativeOnDragCancelled(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	SetVisible();
}

FReply USlotItemWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	if (InKeyEvent.GetKey() == EKeys::LeftShift) {
		if (IsValid(operation)) {
			operation->RotateItem();
			Cast<class UVisualDragWidget>(operation->DefaultDragVisual)->SetItem(Item_Slot.GetData().ImageItem, Item_Slot.GetSize(operation->bRotateItem) * SizeSlot);
		}
	}
	return FReply::Handled();
}

void USlotItemWidget::OnChangedSlot_Implementation(int32 NewIndex, FInventorySlot NewSlot)
{
	USlotWidget::OnChangedSlot_Implementation(NewIndex, NewSlot);

	FSlateBrush* BrushButtons = new FSlateBrush();
	BrushButtons->TintColor = FLinearColor(1.0f, 1.0f, 1.0f);
	BrushButtons->SetResourceObject(NewSlot.ItemAsset->SlotItemData.ImageItem);
	ImageItem->SetImage(BrushButtons);

	if (NewSlot.ItemAsset->SlotItemData.StackItem)
		NumberText->SetText(FText::AsNumber(NewSlot.Count));
	else
		NumberText->SetText(FText::FromString(""));

	SetVisible();

}

bool USlotItemWidget::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	bool IsSussen = false;
	if (UInventoryPanelSlot* L_PanelSlot = Cast<UInventoryPanelSlot>(Slot)) {

		if (auto Drag = Cast<UInventotySlot_Drag>(InOperation)) {

			if (Cast<USlotItemWidget>(Drag->Payload)) {

				IsSussen = Drag->DropInSlot(L_PanelSlot, SizeSlot);
				Cast<USlotItemWidget>(Drag->Payload)->SetVisible();	
			}
		}
	}
	return IsSussen;
}

TSharedRef<SWidget> USlotItemWidget::RebuildWidget()
{
	bIsFocusable = true;

	FSlateFontInfo NumderFont = FCoreStyle::GetDefaultFontStyle("Roboto", 10);

	A_Offset.BindUObject(this, &USlotItemWidget::GetOffsetMouse);

	MyPanel = SNew(SConstraintCanvas)
		.Visibility(EVisibility::Visible)
		+ SConstraintCanvas::Slot()
			.Offset(A_Offset)
			.AutoSize(true)[
				SAssignNew(MenuAnchor, SMenuAnchor)
					.Placement(EMenuPlacement::MenuPlacement_ComboBox)
					.OnGetMenuContent(FOnGetContent::CreateUObject(this, &USlotItemWidget::HandleGetMenuContent))
			]

		+ SConstraintCanvas::Slot()
			.Anchors(FAnchors(0.0f, 0.0f, 1.0f, 1.0f))
			.Offset(FMargin(0.0f, 0.0f, 0.0f, 0.0f))
			[
				SAssignNew(ImageItem, SImage)
			]
		
		+ SConstraintCanvas::Slot()
			.Anchors(FAnchors(0.0f, 0.0f, 1.0f, 1.0f))
			.Offset(FMargin(0.0f, 0.0f, 0.0f, 0.0f))
			[
				SAssignNew(NumberText, STextBlock)
					.Font(NumderFont)
					.Text(FText::FromString(""))
			];

	return SNew(SBox)
			.WidthOverride(32.f)
			.HeightOverride(32.f)
			[
				MyPanel.ToSharedRef()
			];
}