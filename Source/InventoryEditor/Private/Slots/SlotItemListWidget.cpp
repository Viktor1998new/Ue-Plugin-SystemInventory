 //Copyright(c) 2022 - 2025, Viktor.F.P
#include "SlotsWidget.h"
#include "InventoryUMG/InventoryPanel.h"
#include "Brushes/SlateColorBrush.h"

void USlotItemListWidget::OnChangedSlot_Implementation(int32 NewIndex, FInventorySlot NewSlot)
{
	USlotWidget::OnChangedSlot_Implementation(NewIndex, NewSlot);

	FSlateBrush* Brush = new FSlateBrush();

	if (!IsValid(NewSlot.ItemAsset)) {

		Brush->TintColor = FLinearColor(1.0f, 0.6f, 1.0f);
		Brush->SetImageSize(FVector2D(SizeSlot));
		ImageItem->SetImage(Brush);
		Text_Name->SetText(FText::FromString("Null Item (Need Remove)"));
		return;
	}

	UItemAsset* Asset = NewSlot.ItemAsset;
	UTexture2D* Texture = Asset->SlotItemData.ImageItem;

	Brush->SetResourceObject(Texture);

	if (Texture)
	{
		Texture->bForceMiplevelsToBeResident = true;
		Texture->bIgnoreStreamingMipBias = true;
		Brush->SetImageSize(FVector2D(32.f, 32.f));
	}
	if (Asset->SlotItemData.NameItem.IsEmpty())
		Text_Name->SetText(FText::FromString("No Name"));
	else
		Text_Name->SetText(Asset->SlotItemData.NameItem);

	ImageItem->SetImage(Brush);

}

TSharedRef<SWidget> USlotItemListWidget::RebuildWidget()
{
	FSlateColorBrush* BrushSlot = new  FSlateColorBrush(FLinearColor(0.0f, 0.0f, 0.0f, 0.5f));
	FSlateFontInfo FontName = FCoreStyle::GetDefaultFontStyle("Roboto", 12);
	FSlateFontInfo FontData = FCoreStyle::GetDefaultFontStyle("Roboto", 10);

	TSharedPtr<SHorizontalBox> Horizontal;
		
	SAssignNew(Horizontal,SHorizontalBox)
		.Visibility(EVisibility::Visible)
		+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(FMargin(10.0f, 0.0f, 0.0f, 0.0f))
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)[
				SAssignNew(ImageItem, SImage)
		]

		+ SHorizontalBox::Slot()
		.AutoWidth()
		.VAlign(VAlign_Center)[
			SNew(SSpacer)
				.Size(FVector2D(20.0f, 0.0f))
		]

		+ SHorizontalBox::Slot()
		.AutoWidth()
		.VAlign(VAlign_Center)
		.HAlign(HAlign_Center)[

			SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(FMargin(0.0f, 5.0f, 0.0f, 0.0f))
				.VAlign(VAlign_Top)
				.HAlign(HAlign_Fill)[
					SAssignNew(Text_Name, STextBlock)
						.Font(FontName)
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(FMargin(0.0f, 10.0f, 0.0f, 0.0f))
				.VAlign(VAlign_Top)
				.HAlign(HAlign_Fill)[
					SAssignNew(Text_Data, STextBlock)
						.Font(FontData)
				]
		];

	A_Offset.BindUObject(this, &USlotItemListWidget::GetOffsetMouse);

	return SNew(SConstraintCanvas)
		+ SConstraintCanvas::Slot()
		.AutoSize(true)
		.Anchors(FAnchors(0.0f, 0.0f, 1.0f, 1.0f))
		.Offset(FMargin(0.0f, 0.0f, 0.0f, 0.0f))[
			SNew(SBorder)
				.Visibility(EVisibility::Visible)
				.BorderImage(BrushSlot)[
					Horizontal.ToSharedRef()
				]
		]
		+SConstraintCanvas::Slot()
		.Offset(A_Offset)
		.AutoSize(true)[
			SAssignNew(MenuAnchor, SMenuAnchor)
				.Placement(EMenuPlacement::MenuPlacement_ComboBox)
				.OnGetMenuContent(FOnGetContent::CreateUObject(this, &USlotItemListWidget::HandleGetMenuContent))
		];
}