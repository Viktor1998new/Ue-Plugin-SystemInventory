//Copyright(c) 2022 - 2025, Viktor.F.P

#include "UMGEditor/InventoryWidget.h"

#include "SlotsWidget.h"
#include "InventorySettings.h"
#include "Components/InventoryComponent.h"

#include "InventoryUMG/InventoryGrid.h"
#include "InventoryUMG/InventoryList.h"

#include "Widgets/Layout/SWidgetSwitcher.h"
#include "Widgets/Layout/SScaleBox.h"
#include "Components/ScaleBox.h"
#include "Components/ScaleBoxSlot.h"
#include "Brushes/SlateColorBrush.h"
#include "Blueprint/WidgetTree.h"
#include "InventoryUMG/InventoryPanelSlot.h"

FReply UInventoryWidget::RecalculationMass()
{
    if (HasInventoryFlag(EInventoryFlag::Mass))
        MassText->SetText(FText::Format(FText::FromString("Mass: {0}"), FText::AsNumber(Inventory->Inventory.Massa)));

    return FReply::Handled();
}

void UInventoryWidget::SwitchPanel(uint8 NewPanel)
{
    Panel = NewPanel;

    Switcher->SetActiveWidgetIndex(Panel);

    if (!IsValid(Inventory))
        return;

    switch (Panel)
    {
    case 0:

        InventoryList->SetInventory(nullptr);
        InventoryGrid->SetInventory(Inventory);
        break;

    case 1:

        InventoryGrid->SetInventory(nullptr);
        InventoryList->SetInventory(Inventory);
        break;
    }
}

bool UInventoryWidget::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
    if (Panel != 1)
        return false;

    if (auto L_Operation = Cast<UInventotySlot_Drag>(InOperation)) {

        if (auto SlotAsset = Cast<USlotAssetWidget>(L_Operation->Payload))
        {
            FInventorySlot L_NewSlot;
            L_NewSlot.ItemAsset = SlotAsset->Asset;
            L_NewSlot.Count = 1;
            L_NewSlot.IsRotate = L_Operation->GetRotateItem();
            int32 L_Index;
            return Inventory->AddSlot(L_NewSlot, true, L_Index);
            
        }
    }

    return false;
}

void UInventoryWidget::SetInventory(UInventoryComponent* NewInventory, uint8 NewPanel)
{
    Inventory = NewInventory;

    SwitchPanel(NewPanel);

    TextNameActor->SetText(FText::Format(FText::FromString("Actor: {0}"), FText::FromString(Inventory->GetOwner()->GetName())));

    if (HasInventoryFlag(EInventoryFlag::Mass)) {
        Recalculation->SetVisibility(EVisibility::Visible);
        MassText->SetText(FText::Format(FText::FromString("Mass: {0}"), FText::AsNumber(Inventory->Inventory.Massa)));
    }
    else {
        Recalculation->SetVisibility(EVisibility::Hidden);
    }
}

TSharedRef<SWidget> UInventoryWidget::RebuildWidget()
{
    Super::RebuildWidget();

    FSlateColorBrush* BrushButtons = new FSlateColorBrush(FLinearColor(0.0f, 0.0f, 0.0f));
    FSlateColorBrush* BrushInventory = new FSlateColorBrush(FLinearColor(0.01f, 0.01f, 0.01f));

    FSlateFontInfo TextFont = FCoreStyle::GetDefaultFontStyle("Roboto", 12);
    FSlateFontInfo ButtonFont = FCoreStyle::GetDefaultFontStyle("Roboto", 12);

    SAssignNew(Recalculation,SHorizontalBox) 
        + SHorizontalBox::Slot()
        .AutoWidth()
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Center)[
            SAssignNew(MassText, STextBlock)
                .Font(TextFont)
                .Text(FText::FromString(""))
        ]
        + SHorizontalBox::Slot()
        .AutoWidth()
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Center)[
            SNew(SButton)
                .OnClicked_UObject(this, &UInventoryWidget::RecalculationMass)
                .Content()[
                    SNew(STextBlock)
                        .Font(TextFont)
                        .Text(FText::FromString("Recalculation Mass"))
                    ]
         ];

    TSharedPtr<SHorizontalBox> TitlePanel;
    
    SAssignNew(TitlePanel,SHorizontalBox)
        + SHorizontalBox::Slot()
        .AutoWidth()
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Center)[
            SAssignNew(TextNameActor, STextBlock)
                .Font(TextFont)
        ]
        + SHorizontalBox::Slot()
        .AutoWidth()
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Center)[
            SAssignNew(TextNameActor, STextBlock)
                .Font(TextFont)
        ]
        + SHorizontalBox::Slot()
        .AutoWidth()[
            SNew(SSpacer).Size(FVector2D(5.0f, 0.0f))
        ]
        + SHorizontalBox::Slot()
        .AutoWidth()
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Center)[
            Recalculation.ToSharedRef()
        ];


    TSharedPtr<SBorder> BorderButtons = SNew(SBorder)
        .BorderImage(BrushButtons)
        .Content()[
            TitlePanel.ToSharedRef()
        ];

    InventoryGrid = WidgetTree->ConstructWidget<UInventoryGrid>(UInventoryGrid::StaticClass(), TEXT("C_InventoryGrid"));
    
    InventoryGrid->NoneSlot = USlotNoneWidget::StaticClass();
    InventoryGrid->ItemSlot = USlotItemWidget::StaticClass();

    InventoryList = WidgetTree->ConstructWidget<UInventoryList>(UInventoryList::StaticClass(), TEXT("C_InventoryList"));
    InventoryList->SizeSlot = 62.0f;
    InventoryList->ItemSlot = USlotItemListWidget::StaticClass();
    
    return SNew(SVerticalBox)
        + SVerticalBox::Slot()
        .AutoHeight()
        .VAlign(VAlign_Fill)
        .HAlign(HAlign_Fill)[
            SNew(SBox)
                .Content()[
                    BorderButtons.ToSharedRef()
                ]
        ]
        + SVerticalBox::Slot()
        .AutoHeight()
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Fill)[
            SNew(SBorder)
                .BorderImage(BrushInventory)
                .Content()[
                    SAssignNew(Switcher, SWidgetSwitcher)
                        + SWidgetSwitcher::Slot()
                        .HAlign(HAlign_Left)
                        .VAlign(VAlign_Top)[
                            SNew(SScaleBox)[
                                InventoryGrid->TakeWidget()
                            ]
                        ]
                        + SWidgetSwitcher::Slot()[
                            SNew(SScaleBox)
                                .HAlign(HAlign_Fill)
                                .VAlign(VAlign_Fill)[
                                InventoryList->TakeWidget()
                            ]
                        ]
                ] 
        ]
        + SVerticalBox::Slot()
          .AutoHeight()[
            SNew(SSpacer).Size(FVector2D(0.0f, 10.0f))
        ];
}

void UInventoryWidget::RemoveFromParent()
{
    Super::RemoveFromParent();

    Inventory = nullptr;

    switch (Panel)
    {
    case 0:

        if (IsValid(InventoryGrid)) {
            
            InventoryGrid->SetInventory(nullptr);
            InventoryGrid->ClearChildren();
            InventoryGrid->RemoveFromParent();
        }

        break;

    case 1:
        if (IsValid(InventoryList)) {
            InventoryList->SetInventory(nullptr);
            InventoryList->ClearChildren();
            InventoryList->RemoveFromParent();
        }

        break;
    }
}
