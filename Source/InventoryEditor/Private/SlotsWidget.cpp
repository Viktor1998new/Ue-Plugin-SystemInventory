//Copyright(c) 2022, Viktor.F.P

#include "SlotsWidget.h"
#include "Inventory.h"
#include "InventorySettings.h"

#include "Widgets/Layout/SBorder.h"
#include "InventoryUMG/InventoryPanel.h"
#include "InventoryUMG/InventoryPanelSlot.h"
#include "Brushes/SlateColorBrush.h"
#include "Widgets/Input/SMenuAnchor.h"
#include "Widgets/Images/SImage.h"
#include "Components/DetailsView.h"
#include "InventoryLibrary.h"
#include "Components/MenuAnchor.h"
#include "Widgets/Layout/SScaleBox.h"

class UMyDetailsView : public UDetailsView {
	
public:

	FOnPropertyValueChanged* GetOnPropertyValueChanged() {
		return &OnPropertyChanged;
	}
};

UInventoryComponent* USlotWidget::GetInventory()
{
	return Cast<UInventoryPanel>(GetParent())->Inventory;
}

bool USlotNoneWidget::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	UInventoryPanelSlot* L_Slot = Cast<UInventoryPanelSlot>(Slot);

	if (!IsValid(L_Slot))
		return false;

	FIntPoint L_CurrentPositin = FIntPoint(L_Slot->Transform.Offsets.Left/32.0f, L_Slot->Transform.Offsets.Top / 32.0f);
	UInventoryComponent* L_Inventory = GetInventory();

	if (auto Operation = Cast<UEditor_Drag>(InOperation)) {

		if (Operation->Inventory == L_Inventory) {
			Operation->Inventory->DropItem(Operation->Index,-1,1,L_CurrentPositin,true,true);
			Cast<UWidget>(Operation->Payload)->SetVisibility(ESlateVisibility::Visible);
			return true;
		}
		
		Operation->Inventory->SendItem(Operation->Index, L_Inventory,1,false,L_CurrentPositin);
		Cast<UWidget>(Operation->Payload)->SetVisibility(ESlateVisibility::Visible);
		return true;
	}

	if (auto Operation = Cast<UEditor_DragNewItem>(InOperation)) {
		FInventorySlot LNewSlot = Operation->Slot;
		LNewSlot.PositionSlot = L_CurrentPositin;
		int32 L_Index;
		L_Inventory->AddSlot(LNewSlot,false,L_Index);
	}
	return true;
}

TSharedRef<SWidget> USlotNoneWidget::RebuildWidget()
{
	FSlateColorBrush* BrushButtons = new  FSlateColorBrush(FLinearColor(0.0f, 0.0f, 0.0f));

	MyPanel = SNew(SConstraintCanvas)
		+ SConstraintCanvas::Slot()
		.Anchors(FAnchors(0.0f,0.0f,1.0f,1.0f))
		.Offset(FMargin(1.5f,1.5f,1.5f,1.5f))
		[
			SNew(SBorder)
			.BorderImage(BrushButtons)
		];

	return  MyPanel.ToSharedRef();
}

void USlotItemWidget::NativePreConstruct()
{
	UInventoryPanelSlot* L_Slot = Cast<UInventoryPanelSlot>(Slot);
	L_Slot->OnChangedSlot.AddDynamic(this,&USlotItemWidget::OnChangedSlot);
}

FReply USlotItemWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if (InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton)) {

		FEventReply Reply;
		TSharedPtr<SWidget> SlateWidgetDetectingDrag = GetCachedWidget();

		if (SlateWidgetDetectingDrag.IsValid())
		{
			Reply.NativeReply = FReply::Handled();

			Reply.NativeReply = Reply.NativeReply.DetectDrag(SlateWidgetDetectingDrag.ToSharedRef(), EKeys::LeftMouseButton);
		}
		return Reply.NativeReply;
	}

	FVector2D Position = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());

	SlotMenu->Offset(FMargin(Position.X, Position.Y));
	MenuAnchor->SetIsOpen(true, true);
	ContextMenu->SetItem(MenuAnchor,Cast<UInventoryPanel>(GetParent())->Inventory, Item_Index);
		

	return FReply::Handled();
}

FReply USlotItemWidget::NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if (InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton)) {
	
		Item_Slot.IsRotate = !Item_Slot.IsRotate;
		GetInventory()->SetRotateSlot(Item_Index,Item_Slot.IsRotate);
		FReply::Handled();
	}

	return FReply::Unhandled();
}

void USlotItemWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation)
{
	auto drag_drop_operation = NewObject<UEditor_Drag>();

	drag_drop_operation->Pivot = EDragPivot::TopLeft;

	auto DragVisual = CreateWidget<UVisualDragWidget>(this);
	
	drag_drop_operation->Payload = this;

	UItemAsset* L_Asset = Item_Slot.ItemAsset;
	DragVisual->SetItem(L_Asset->SlotItemData.ImageItem, L_Asset->SlotItemData.SizeSlot * 32.0f);

	drag_drop_operation->DefaultDragVisual = DragVisual;

	drag_drop_operation->Index = Item_Index;
	drag_drop_operation->Inventory = Cast<UInventoryPanel>(GetParent())->Inventory;

	if (Item_Slot.Count - 1 <= 0)
	{
		SetVisibility(ESlateVisibility::Hidden);
	}

	OutOperation = drag_drop_operation;
}

void USlotItemWidget::NativeOnDragCancelled(const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	SetVisibility(ESlateVisibility::Visible);
}

void USlotItemWidget::OnChangedSlot(int32 NewIndex, FInventorySlot NewSlot)
{
	Item_Index = NewIndex;
	Item_Slot = NewSlot;

	FSlateBrush* BrushButtons = new FSlateBrush();
	BrushButtons->TintColor = FLinearColor(1.0f, 1.0f, 1.0f);
	BrushButtons->SetResourceObject(NewSlot.ItemAsset->SlotItemData.ImageItem);
	ImageItem->SetBorderImage(BrushButtons);

	if (NewSlot.ItemAsset->SlotItemData.StackItem ) 
		NumberText->SetText(FText::AsNumber(NewSlot.Count));
	else
		NumberText->SetText(FText::FromString(""));
	
	SetVisibility(ESlateVisibility::Visible);
}

bool USlotItemWidget::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	if (UInventoryPanelSlot* L_PanelSlot = Cast<UInventoryPanelSlot>(Slot)) {

		if (UEditor_Drag* Drag = Cast<UEditor_Drag>(InOperation)) {

			if (auto L_Inventory = GetInventory()) {
				if (L_Inventory == Drag->Inventory) {
					Drag->Inventory->DropItem(Drag->Index, Item_Index, 1, FIntPoint(), true, true);

					return true;
				}
				else {
					FInventorySlot Drop_Slot = Drag->GetSlot();

					bool IsQAsset = Drop_Slot.ItemAsset == Item_Slot.ItemAsset;
					bool IsQData = Drop_Slot.ItemData == Item_Slot.ItemData;

					if (IsQAsset && IsQData && Drop_Slot.ItemAsset->SlotItemData.StackItem) {
						FInventorySlot New_Slot = Item_Slot;
						New_Slot.Count += 1;
						bool IsSet = L_Inventory->SetSlot(Item_Index, New_Slot);

						if (IsSet)
							return Drag->Inventory->RemoveItem(Drag->Index, 1);
					}
				}
			}
		}
	}
	return false;
}

TSharedRef<SWidget> USlotItemWidget::HandleGetMenuContent()
{
	UInventoryPanel* Panel = Cast<UInventoryPanel>(GetParent());

	ContextMenu = CreateWidget<UMenuContextItemWidget>(this);

	return ContextMenu->TakeWidget();
}

TSharedRef<SWidget> USlotItemWidget::RebuildWidget()
{
	FSlateFontInfo NumderFont = FCoreStyle::GetDefaultFontStyle("Roboto", 15);

	MyPanel = SNew(SConstraintCanvas)
		+ SConstraintCanvas::Slot()
		.Anchors(FAnchors(0.0f, 0.0f, 1.0f, 1.0f))
		.Offset(FMargin(0.0f, 0.0f, 0.0f, 0.0f))
		[
			SAssignNew(ImageItem, SBorder)
			.Content()[
				SAssignNew(NumberText, STextBlock)
					.Font(NumderFont)
					.Text(FText::FromString(""))
			]
		];

	SlotMenu = &MyPanel->AddSlot()
		.AutoSize(true)[
		SAssignNew(MenuAnchor, SMenuAnchor)
			.Placement(EMenuPlacement::MenuPlacement_ComboBox)
			.OnGetMenuContent_UObject(this, &USlotItemWidget::HandleGetMenuContent)];
		
	return MyPanel.ToSharedRef();
}

void UVisualDragWidget::SetItem(UTexture2D* Texture, FVector2D Size)
{
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

void USlotAssetWidget::SetAssetItem(UItemAsset* NewAsset)
{
	if (!NewAsset)
		return;

	Asset = NewAsset;
	UTexture2D* Texture = Asset->SlotItemData.ImageItem;

	FSlateBrush* Brush = new FSlateBrush();

	if (Brush->GetResourceObject() != Texture)
	{
		Brush->SetResourceObject(Texture);

		if (Texture)
		{
			Texture->bForceMiplevelsToBeResident = true;
			Texture->bIgnoreStreamingMipBias = true;
			Brush->ImageSize = FVector2D(64.f,64.f);
		}

		ItemIcon.ToSharedRef()->SetImage(Brush);
	}

	NameAsset.ToSharedRef()->SetText(FText::FromString(Asset->GetName()));
}

FReply USlotAssetWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if (InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton)) {

		TSharedPtr<SWidget> SlateWidgetDetectingDrag = GetCachedWidget();

		FEventReply Reply;
		if (SlateWidgetDetectingDrag.IsValid())
		{
			Reply.NativeReply = FReply::Handled();

			Reply.NativeReply = Reply.NativeReply.DetectDrag(SlateWidgetDetectingDrag.ToSharedRef(), EKeys::LeftMouseButton);
		}
		return Reply.NativeReply;
	}
	return FReply::Handled();
}

void USlotAssetWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation)
{
	auto drag_drop_operation = NewObject<UEditor_DragNewItem>();

	drag_drop_operation->Pivot = EDragPivot::TopLeft;

	auto DragVisual = CreateWidget<UVisualDragWidget>(this);
	
	DragVisual->SetItem(Asset->SlotItemData.ImageItem,Asset->SlotItemData.SizeSlot*32.0f);

	drag_drop_operation->DefaultDragVisual = DragVisual;
	
	FInventorySlot NewSlot;
	NewSlot.ItemAsset = Asset;
	NewSlot.Count = 1;

	drag_drop_operation->Slot = NewSlot;

	OutOperation = drag_drop_operation;
}

TSharedRef<SWidget> USlotAssetWidget::RebuildWidget()
{
	FSlateColorBrush* Brush = new  FSlateColorBrush(FLinearColor(0.0f, 0.0f, 0.0f, 0.6f));
	FSlateFontInfo NumderFont = FCoreStyle::GetDefaultFontStyle("Roboto", 9);

	return SNew(SBox)
		.WidthOverride(128.0f)
		.HeightOverride(128.0f)
		.MaxDesiredHeight(128.0f)
		.MaxDesiredWidth(128.0f)
		[
			SNew(SBorder)
			.BorderImage(Brush)[
				SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.AutoHeight()
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					.Padding(FMargin(10.f))[
						SAssignNew(ItemIcon, SImage)
					]

					+ SVerticalBox::Slot()
					.AutoHeight()[
						SNew(SSpacer)
							.Size(FVector2D(1.f,5.f))
					]

					+ SVerticalBox::Slot()
					.FillHeight(1.f)[
						SAssignNew(NameAsset, STextBlock)
							.Font(NumderFont)
							.Text(FText::FromString(""))
							.Justification(ETextJustify::Center)
							.AutoWrapText(true)
							.WrappingPolicy(ETextWrappingPolicy::AllowPerCharacterWrapping)
							.Clipping(EWidgetClipping::ClipToBounds)

					]
			]
		];
}

void UMenuContextItemWidget::SetItem(TSharedPtr<class SMenuAnchor> MewMenu,UInventoryComponent* NewInventory, int32 NewIndex)
{
	FInventorySlot L_SlotItem = NewInventory->Items[NewIndex];

	Asset = L_SlotItem.ItemAsset;
	Data = UInventoryLibrary::DataItemToMap(L_SlotItem.ItemData);
	Count = L_SlotItem.Count;

	Inventory = NewInventory;
	Index = NewIndex;
	Menu = MewMenu;
}

void UMenuContextItemWidget::OnPropertyValueChanged(FName Name)
{
	if (!Inventory)
		return;

	FInventorySlot L_SlotItem = Inventory->Items[Index];
	FInventorySlot L_NewSlotItem;
	L_NewSlotItem.ItemAsset = Asset;
	L_NewSlotItem.ItemData = UInventoryLibrary::DataItem(Data);
	L_NewSlotItem.PositionSlot = L_SlotItem.PositionSlot;
	L_NewSlotItem.Count = L_NewSlotItem.ItemAsset->SlotItemData.StackItem ? Count : 1;

	bool IsSet = Inventory->SetSlot(Index, L_NewSlotItem);

	if (!IsSet) {

		Asset = L_SlotItem.ItemAsset;
		Data = UInventoryLibrary::DataItemToMap(L_SlotItem.ItemData);
	}
	
	Count = L_SlotItem.Count;
}

FReply UMenuContextItemWidget::OnClickedRemoveItem()
{
	Inventory->RemoveItem(Index, Inventory->Items[Index].Count);
	Menu->SetIsOpen(false, false);
	return FReply::Handled();
}

TSharedRef<SWidget> UMenuContextItemWidget::RebuildWidget()
{
	FSlateFontInfo NumderFont = FCoreStyle::GetDefaultFontStyle("Roboto", 9);

	UMyDetailsView* Details = NewObject<UMyDetailsView>();
	Details->CategoriesToShow.Add("AssetData");
	Details->GetOnPropertyValueChanged()->AddDynamic(this, &UMenuContextItemWidget::OnPropertyValueChanged);
	Details->SetObject(this);

	return SNew(SBox)[
		SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.FillHeight(1.0f)[
				Details->TakeWidget()
			]
			+ SVerticalBox::Slot()
				.AutoHeight()[
					SNew(SButton)
					.OnClicked(FOnClicked::CreateUObject(this, &UMenuContextItemWidget::OnClickedRemoveItem))
					.Content()
					[
						SNew(STextBlock)
						.Font(NumderFont)
						.Text(FText::FromString("Remove Item"))
					].HAlign(HAlign_Center).VAlign(VAlign_Center)
			]
	];
}

void USlotItemListWidget::NativePreConstruct()
{
	UInventoryPanelSlot* L_Slot = Cast<UInventoryPanelSlot>(Slot);
	L_Slot->OnChangedSlot.AddDynamic(this, &USlotItemListWidget::OnChangedSlot);
}

FReply USlotItemListWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{

	if (InMouseEvent.IsMouseButtonDown(EKeys::RightMouseButton)) {
		FVector2D Position = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());

		SlotMenu->Offset(FMargin(Position.X, Position.Y));
		MenuAnchor->SetIsOpen(true, true);
		ContextMenu->SetItem(MenuAnchor,Cast<UInventoryPanel>(GetParent())->Inventory, Item_Index);
	}

	return FReply::Handled();
}

void USlotItemListWidget::OnChangedSlot(int32 NewIndex, FInventorySlot NewSlot)
{
	Item_Index = NewIndex;

	if (!NewSlot.ItemAsset)
		return;

	UItemAsset * Asset = NewSlot.ItemAsset;
	UTexture2D* Texture = Asset->SlotItemData.ImageItem;

	FSlateBrush* Brush = new FSlateBrush();

	if (Brush->GetResourceObject() != Texture)
	{
		Brush->SetResourceObject(Texture);

		if (Texture)
		{
			Texture->bForceMiplevelsToBeResident = true;
			Texture->bIgnoreStreamingMipBias = true;
			Brush->ImageSize = FVector2D(32.f, 32.f);
		}
		if(Asset->SlotItemData.NameItem.IsEmpty())
			Text_Name.ToSharedRef()->SetText(FText::FromString("No Name"));
		else
			Text_Name.ToSharedRef()->SetText(Asset->SlotItemData.NameItem);

		auto L_Data = UInventoryLibrary::DataItemToMap(NewSlot.ItemData);

		FString StringResult;
		TArray<FString> Keys;
		L_Data.GetKeys(Keys);

		if (Keys.IsValidIndex(0)) {
			for (int32 i = 0; i < L_Data.Num(); i++) {

				FString AddValue = FString("Name: ") + Keys[i] + " " + FString("Value: ") + L_Data[Keys[i]];

				if (L_Data.Num() == i)
					StringResult += AddValue;
				else
					StringResult += AddValue + ",";
			}
			Text_Data.ToSharedRef()->SetText(FText::FromString(StringResult));
		}
		else
			Text_Data.ToSharedRef()->SetText(FText::FromString("No Data"));

		Image.ToSharedRef()->SetImage(Brush);
	}

}

TSharedRef<SWidget> USlotItemListWidget::HandleGetMenuContent()
{
	UInventoryPanel* Panel = Cast<UInventoryPanel>(GetParent());

	ContextMenu = CreateWidget<UMenuContextItemWidget>(this);

	return ContextMenu->TakeWidget();
}

TSharedRef<SWidget> USlotItemListWidget::RebuildWidget()
{
	FSlateColorBrush* BrushSlot = new  FSlateColorBrush(FLinearColor(0.0f, 0.0f, 0.0f,0.5f));
	FSlateFontInfo FontName = FCoreStyle::GetDefaultFontStyle("Roboto", 12);
	FSlateFontInfo FontData = FCoreStyle::GetDefaultFontStyle("Roboto", 10);

	TSharedPtr<SConstraintCanvas> Panel = SNew(SConstraintCanvas)
		+ SConstraintCanvas::Slot()
		.AutoSize(true)
		.Anchors(FAnchors(0.0f, 0.0f, 1.0f, 1.0f))
		.Offset(FMargin(0.0f, 0.0f, 0.0f, 0.0f))[
		SNew(SBorder)
			.BorderImage(BrushSlot)[
				SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.Padding(FMargin(10.0f, 0.0f, 0.0f, 0.0f))
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)[
						SAssignNew(Image,SImage)
					]
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.VAlign(VAlign_Center)[
						SNew(SSpacer)
							.Size(FVector2D(20.0f,0.0f))
					]

					+ SHorizontalBox::Slot()
					.AutoWidth()
					.VAlign(VAlign_Center)
					.HAlign(HAlign_Center)[

						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						.AutoHeight()
						.Padding(FMargin(0.0f,5.0f,0.0f,0.0f))
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
					]
				]
		];

	SlotMenu = &Panel.ToSharedRef()->AddSlot()
		.AutoSize(true)[
	 	 SAssignNew(MenuAnchor, SMenuAnchor)
		.Placement(EMenuPlacement::MenuPlacement_ComboBox)
		.OnGetMenuContent_UObject(this, &USlotItemListWidget::HandleGetMenuContent)];

	return Panel.ToSharedRef();
}
