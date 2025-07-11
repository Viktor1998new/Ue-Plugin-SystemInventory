//Copyright(c) 2022 - 2025, Viktor.F.P

#include "UMGEditor/InventoryWidget.h"

#include "SlotsWidget.h"
#include "InventorySettings.h"
#include "Components/InventoryComponent.h"

#include "UMG/InventoryGrid.h"
#include "UMG/InventoryList.h"
#include "UMG/InventoryPanelSlot.h"

#include "EditorStyleSet.h"
#include "EditorFontGlyphs.h"

#include "Widgets/Input/SComboButton.h"
#include "Widgets/Layout/SWidgetSwitcher.h"
#include "Widgets/Layout/SScaleBox.h"
#include "Components/ScaleBox.h"
#include "Components/ScaleBoxSlot.h"
#include "Brushes/SlateColorBrush.h"
#include "Blueprint/WidgetTree.h"

#define LOCTEXT_NAMESPACE "InventoryEditor"

FReply UInventoryWidget::RecalculationMass()
{
    if (HasInventoryFlag(EInventoryFlag::Mass))
        MassText->SetText(FText::Format(FText::FromString("Mass: {0}"), FText::AsNumber(Inventors[CurrentActive]->Inventory.Massa)));

    return FReply::Handled();
}

void UInventoryWidget::SwitchPanel(uint8 NewPanel)
{
    Panel = NewPanel;

    Switcher->SetActiveWidgetIndex(Panel);

    if (Inventors.Num() == 0)
        return;

    switch (Panel)
    {
    case 0:

        InventoryList->SetInventory(nullptr);
        InventoryGrid->SetInventory(Inventors[CurrentActive]);
        break;

    case 1:

        InventoryGrid->SetInventory(nullptr);
        InventoryList->SetInventory(Inventors[CurrentActive]);
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
            return Inventors[CurrentActive]->AddSlot(L_NewSlot, true, L_Index);
            
        }
    }

    return false;
}

void UInventoryWidget::SetInventory(TArray<UInventoryComponent*> NewInventors, uint8 NewPanel) {

    if (NewInventors.Num() == 1) {
        SetInventory(NewInventors, NewPanel);
        return;
    }
    
    Inventors = NewInventors;
    CurrentActive = 0;
    SwitchPanel(NewPanel);

    if (IsValid(Inventors[0]->GetOwner()))
    {
        TextNameActor->SetText(FText::Format(FText::FromString("Actor: {0}"), FText::FromString(Inventors[0]->GetOwner()->GetName())));
    }
    else
    {
        FString L_NameComponent = Inventors[0]->GetName();
        L_NameComponent.RemoveFromEnd(TEXT("_GEN_VARIABLE"));
        TextNameActor->SetText(FText::Format(FText::FromString("Component: {0}"), FText::FromString(L_NameComponent)));
    }

    if (HasInventoryFlag(EInventoryFlag::Mass)) {
        Recalculation->SetVisibility(EVisibility::Visible);
        MassText->SetText(FText::Format(FText::FromString("Mass: {0}"), FText::AsNumber(Inventors[0]->Inventory.Massa)));
    }
    else {
        Recalculation->SetVisibility(EVisibility::Hidden);
    }

    ListInventoryButtons->SetVisibility(EVisibility::Visible);
}


void UInventoryWidget::SelectInventory(int32 Index)
{
    CurrentActive = Index;

    switch (Panel)
    {
    case 0:

        InventoryGrid->SetInventory(Inventors[CurrentActive]);
        break;

    case 1:

        InventoryList->SetInventory(Inventors[CurrentActive]);
        break;
    }
}

void UInventoryWidget::SetInventory(UInventoryComponent* NewInventory, uint8 NewPanel)
{
    if (!IsValid(NewInventory))
        return;

    CurrentActive = 0;
    Inventors.Empty();
    Inventors.Add(NewInventory);

    SwitchPanel(NewPanel);


    if(IsValid(NewInventory->GetOwner()))
    {
        TextNameActor->SetText(FText::Format(FText::FromString("Actor: {0}"), FText::FromString(NewInventory->GetOwner()->GetName())));
    }
    else
    {
       FString L_NameComponent = NewInventory->GetName();
       L_NameComponent.RemoveFromEnd(TEXT("_GEN_VARIABLE"));
       TextNameActor->SetText(FText::Format(FText::FromString("Component: {0}"), FText::FromString(L_NameComponent)));
    }

    if (HasInventoryFlag(EInventoryFlag::Mass)) {
        Recalculation->SetVisibility(EVisibility::Visible);
        MassText->SetText(FText::Format(FText::FromString("Mass: {0}"), FText::AsNumber(NewInventory->Inventory.Massa)));
    }
    else {
        Recalculation->SetVisibility(EVisibility::Hidden);
    }

    ListInventoryButtons->SetVisibility(EVisibility::Collapsed);
}


TSharedRef<SWidget> UInventoryWidget::GetListInventors()
{
    TSharedPtr<SVerticalBox> ListButtoms = SNew(SVerticalBox);
    
    for (int32 i = 0; i < Inventors.Num(); i++)
    {
        ListButtoms->AddSlot()[
            SNew(SButton)
                .ButtonStyle(FEditorStyle::Get(), "FlatButton")
                .ContentPadding(FMargin(12, 2))
                .IsEnabled(CurrentActive != i)
                .OnClicked_Lambda([this, i]()-> FReply {
                
                    SelectInventory(i);
                    ListInventoryButtons->SetIsOpen(false);
                    return FReply::Handled();
                })
                .Content()[
                    SNew(SScaleBox)[

                        SNew(STextBlock)
                            .TextStyle(FEditorStyle::Get(), "ContentBrowser.TopBar.Font")
                            .Text(FText::FromString( Inventors[i]->GetFName().ToString()))
                    ].HAlign(HAlign_Left)
                ]
        ];
    }

    return SNew(SBox)
        [   
            ListButtoms.ToSharedRef()
        ];
}

TSharedRef<SWidget> UInventoryWidget::RebuildWidget()
{
    Super::RebuildWidget();

    FSlateColorBrush* BrushButtons = new FSlateColorBrush(FLinearColor(0.0f, 0.0f, 0.0f));
    FSlateColorBrush* BrushInventory = new FSlateColorBrush(FLinearColor(0.01f, 0.01f, 0.01f));

    SAssignNew(Recalculation,SHorizontalBox) 
        + SHorizontalBox::Slot()
        .AutoWidth()
        .Padding(FMargin(3, 3, 10, 3))
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Center)[
            SAssignNew(MassText, STextBlock)
                .TextStyle(FEditorStyle::Get(), "ContentBrowser.TopBar.Font")
                .Text(FText::FromString(""))
        ]
        + SHorizontalBox::Slot()
        .AutoWidth()
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Center)[
            SNew(SButton)
                .ButtonStyle(FEditorStyle::Get(), "FlatButton.Success")
                .ContentPadding(FMargin(12, 2))
                .OnClicked_UObject(this, &UInventoryWidget::RecalculationMass)
                .Content()[
                    SNew(STextBlock)
                        .TextStyle(FEditorStyle::Get(), "ContentBrowser.TopBar.Font")
                        .Text(FText::FromString("Recalculation Mass"))
                    ]
         ];

    TSharedPtr<SHorizontalBox> TitlePanel;
   
    SAssignNew(TitlePanel,SHorizontalBox)
        
        + SHorizontalBox::Slot()
        .AutoWidth()
        .Padding(FMargin(3, 3,10,3))
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Center)[

            SAssignNew(ListInventoryButtons, SComboButton)
                .ButtonStyle(FEditorStyle::Get(), "FlatButton.Success")
                .ForegroundColor(FLinearColor::White)
                .OnGetMenuContent_UObject(this, &UInventoryWidget::GetListInventors)
                .HasDownArrow(true)
                .ContentPadding(FMargin(3, 3))
                .ButtonContent()
                [
                    SNew(STextBlock)
                        .TextStyle(FEditorStyle::Get(), "ContentBrowser.TopBar.Font")
                        .Text(FText::FromString("Components"))
                ]
        ]
        + SHorizontalBox::Slot()
        .AutoWidth()
        .Padding(FMargin(3, 3, 10, 3))
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Center)[
            SAssignNew(TextNameActor, STextBlock)
                .TextStyle(FEditorStyle::Get(), "ContentBrowser.TopBar.Font")
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
        ];
}

void UInventoryWidget::RemoveFromParent()
{
    Super::RemoveFromParent();

    Inventors.Empty();

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
#undef LOCTEXT_NAMESPACE