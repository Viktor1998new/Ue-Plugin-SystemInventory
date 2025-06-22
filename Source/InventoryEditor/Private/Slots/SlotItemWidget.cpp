//Copyright(c) 2022 - 2025, Viktor.F.P

#include "SlotsWidget.h"
#include "InventoryPanelSlot.h"
#include "InventoryPanel.h"

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

	FIntPoint Size = Item_Slot.ItemAsset->SlotItemData.SizeSlot;

	operation->Payload = this;
	DragVisual->SetRenderTransformPivot(FVector2D(((1 / (SizeSlot * Size.X)) * (SizeSlot / 2) * Size.X), ((1 / (SizeSlot * Size.Y)) * (SizeSlot / 2) * Size.X)));

	DragVisual->SetItem(Item_Slot.GetData().ImageItem, Size * SizeSlot);

	if (Item_Slot.IsRotate) {
		DragVisual->SetRenderTransformAngle(-90);
	}
	else {
		DragVisual->SetRenderTransformAngle(0);
	}

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
			
			FIntPoint Size = Item_Slot.ItemAsset->SlotItemData.SizeSlot;

			operation->DefaultDragVisual->SetRenderTransformPivot(FVector2D(((1 / (SizeSlot * Size.X)) * (SizeSlot / 2) * Size.X), ((1 / (SizeSlot * Size.Y)) * (SizeSlot / 2) * Size.X)));

			if (operation->bRotateItem) {
				operation->DefaultDragVisual->SetRenderTransformAngle(-90);
			}
			else {
				operation->DefaultDragVisual->SetRenderTransformAngle(0);
			}
		}
	}
	return FReply::Handled();
}

void USlotItemWidget::OnChangedSlot_Implementation(int32 NewIndex, FInventorySlot NewSlot)
{
	USlotWidget::OnChangedSlot_Implementation(NewIndex, NewSlot);
	
	if (!IsValid(NewSlot.ItemAsset)) {
		
		FSlateBrush* BrushButtons = new FSlateBrush();
		BrushButtons->TintColor = FLinearColor(1.0f, 0.6f, 1.0f);
		BrushButtons->SetImageSize(FVector2D(SizeSlot));
		ImageItem->SetImage(BrushButtons);
		ImagePanel->Anchors(FAnchors(0.0f, 0.0f, 0.0f, 0.0f));
		ImagePanel->Offset(FMargin(0.0f, 0.0f, SizeSlot, SizeSlot));
		return;
	}

	FSlateBrush* BrushButtons = new FSlateBrush();
	BrushButtons->TintColor = FLinearColor(1.0f, 1.0f, 1.0f);
	BrushButtons->SetResourceObject(NewSlot.ItemAsset->SlotItemData.ImageItem);
	FIntPoint Size = NewSlot.ItemAsset->SlotItemData.SizeSlot * SizeSlot;
	BrushButtons->SetImageSize(FVector2D(Size.X,Size.Y));
	ImageItem->SetImage(BrushButtons);

	if (NewSlot.IsRotate) {
		ImagePanel->Anchors(FAnchors(0.0f, 0.0f, 0.0f, 0.0f));
		ImagePanel->Offset(FMargin(0.0f, 0.0f, Size.X, Size.Y));
	}

	ImageItem->SetRenderTransformPivot(FVector2D(((1 / (SizeSlot * Size.X)) * (SizeSlot / 2) * Size.X), ((1 / (SizeSlot * Size.Y)) * (SizeSlot / 2) * Size.X)));
	
	ImageItem->SetRenderTransform(FSlateRenderTransform(FQuat2D(NewSlot.IsRotate  ? -1.5708f : 0.0f)));
	
	
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
	bIsFocusable = true ;

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
				.Alignment(FVector2D(0.f, 0.f))
				.Expose(ImagePanel)
				[
					SAssignNew(ImageItem, SImage)
				]
		
			+ SConstraintCanvas::Slot()
				.AutoSize(true)
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