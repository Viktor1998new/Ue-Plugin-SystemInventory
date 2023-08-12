// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "EditorWidget.h"

#include "Inventory.h"
#include "InventorySettings.h"

#include "Editor.h"
#include "Editor/EditorEngine.h"
#include "GameFramework/Actor.h"
#include "Editor/UnrealEdEngine.h"
#include "Widgets/SBoxPanel.h"
#include "Engine/Selection.h"

#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SConstraintCanvas.h"
#include "InventoryUMG/InventoryGrid.h"
#include "InventoryUMG/InventoryList.h"
#include "Widgets/Layout/SSpacer.h"
#include "Widgets/Layout/SWidgetSwitcher.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Components/VerticalBox.h"
#include "InventoryUMG/InventoryGrid.h"
#include "SlotsWidget.h"
#include "Widgets/Layout/SScaleBox.h"
#include "Components/ScaleBox.h"
#include "Components/ScaleBoxSlot.h"
#include "Widgets/Layout/SWrapBox.h"
#include "Brushes/SlateColorBrush.h"
#include "AssetRegistry/AssetRegistryModule.h"

bool HasInventoryFlag(EInventoryFlag Contains) 
{
    return EnumHasAnyFlags((EInventoryFlag)UInventorySettings::Get()->InventoryFlags, Contains);
}

TSharedRef<SWidget> UEditorWidget::RebuildWidget()
{
    FSlateColorBrush* BrushButtons =new  FSlateColorBrush(FLinearColor(0.0f, 0.0f, 0.0f));
    FSlateColorBrush* MyBrush = new FSlateColorBrush(FLinearColor(0.07f, 0.07f, 0.07f));

    FSlateFontInfo ButtonFont = FCoreStyle::GetDefaultFontStyle("Roboto", 12);

    TSharedPtr<SButton> ButtonList = SNew(SButton)
        .OnClicked_UObject(this, &UEditorWidget::SwitchList)
        .Content()[
            SNew(STextBlock)
                .Font(ButtonFont)
                .Text(FText::FromString("List"))
        ];

    TSharedPtr<SButton> ButtonGrid = SNew(SButton)
        .OnClicked_UObject(this, &UEditorWidget::SwitchGrid)
        .Content()[
            SNew(STextBlock)
                .Font(ButtonFont)
                .Text(FText::FromString("Grid"))
        ];


    TSharedPtr<SHorizontalBox> ButtonsPanel = SNew(SHorizontalBox)
        + SHorizontalBox::Slot()
            .FillWidth(1.0f)
            .HAlign(HAlign_Left)
            .VAlign(VAlign_Fill)
            [
                ButtonList.ToSharedRef()
            ]

        + SHorizontalBox::Slot()
            .FillWidth(1.0f)
            .HAlign(HAlign_Left)
            .VAlign(VAlign_Fill)
            [
                ButtonGrid.ToSharedRef()
            ];


    TSharedPtr<SBorder> L_Border = SNew(SBorder)
        .BorderImage(MyBrush)
        .Content()[
            SNew(SVerticalBox)
                + SVerticalBox::Slot()
                .AutoHeight()
                .VAlign(VAlign_Fill)
                .HAlign(HAlign_Fill)
                [
                    SNew(SBorder)
                    .BorderImage(BrushButtons)
                .Content()[

                    ButtonsPanel.ToSharedRef()
                ].HAlign(HAlign_Right)
           ]

            + SVerticalBox::Slot()
                .AutoHeight()
                .VAlign(VAlign_Fill)
                .HAlign(HAlign_Fill)[
                    SNew(SSpacer)
                        .Size(FVector2D(1.0f, 9.0f))
                ]

            + SVerticalBox::Slot()
                    .FillHeight(1.0f)
                    .VAlign(VAlign_Fill)
                    .HAlign(HAlign_Fill)[
                        SNew(SScrollBox)
                            + SScrollBox::Slot()
                            .HAlign(HAlign_Fill)
                            .VAlign(VAlign_Fill)[
                                SAssignNew(ListInventory,SVerticalBox)
                    ]
                 ]
        ];

    MyPanel = SNew(SConstraintCanvas)
        + SConstraintCanvas::Slot()
        .Anchors(FAnchors(0.0f, 0.0f, 1.0f, 1.0f))
        .Offset(FMargin(0.0f))
        [
            L_Border.ToSharedRef()
        ];

	return MyPanel.ToSharedRef();
}

void UEditorWidget::AddSelect(TArray<UObject*> NewSelectActors)
{
    for (auto& NewSelect : NewSelectActors) {

        if (CurrentSelectActors.Find(NewSelect) == INDEX_NONE) {
            
            if (AActor* SelecActor = Cast<AActor>(NewSelect)) {

                if (UInventoryComponent* NewInventory = Cast<UInventoryComponent>(SelecActor->GetComponentByClass(UInventoryComponent::StaticClass()))) {
                    
                    UInventoryWidget* InventoryWidget = CreateWidget<UInventoryWidget>(this, UInventoryWidget::StaticClass());
                    
                    ListInventory->AddSlot()
                        .AutoHeight()
                        .VAlign(VAlign_Top)
                        .HAlign(HAlign_Left)
                        .Padding(FMargin(0.0f,0.0f,0.0f,0.0f))
                        .AttachWidget(InventoryWidget->TakeWidget());

                    InventoryWidget->SetInventory(NewInventory, Panel);
                    Inventorys.Add(SelecActor, InventoryWidget);
                }
            }
        }
    }

    CurrentSelectActors = NewSelectActors;
}

void UEditorWidget::RemoveSelect(TArray<UObject*> NewSelectActors)
{
    for (auto& Select : CurrentSelectActors) {

        if (NewSelectActors.Find(Select) == INDEX_NONE) {
            if (AActor* SelectActor = Cast<AActor>(Select)) {
                if (Inventorys.Find(SelectActor)) {
                    UInventoryWidget* InventoryWidget = Inventorys[SelectActor];
                    ListInventory->RemoveSlot(InventoryWidget->TakeWidget());
                    InventoryWidget->RemoveFromParent();
                    Inventorys.Remove(SelectActor);
                }
            }
        }
    }

    CurrentSelectActors = NewSelectActors;
}

void UEditorWidget::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	MyPanel.Reset();
}

void UEditorWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    TArray<UObject*> L_Select = GetSelectedActors();

    if (L_Select.Num() > CurrentSelectActors.Num()) {
        AddSelect(L_Select);
    }
    else if (L_Select.Num() == CurrentSelectActors.Num()) {
        if (L_Select.Num() == 1 && CurrentSelectActors.Num() == 1) {
            if (L_Select[0] != CurrentSelectActors[0]) {

                if (AActor* SelectActor = Cast<AActor>(CurrentSelectActors[0])) {
                    if (Inventorys.Find(SelectActor)) {
                        UInventoryWidget* InventoryWidget = Inventorys[SelectActor];
                        ListInventory->RemoveSlot(InventoryWidget->TakeWidget());
                        InventoryWidget->RemoveFromParent();
                        Inventorys.Remove(SelectActor);
                        CurrentSelectActors = L_Select;
                    }
                }

                if (AActor* SelecActor = Cast<AActor>(L_Select[0])) {

                    if (UInventoryComponent* NewInventory = Cast<UInventoryComponent>(SelecActor->GetComponentByClass(UInventoryComponent::StaticClass()))) {

                        UInventoryWidget* InventoryWidget = CreateWidget<UInventoryWidget>(this, UInventoryWidget::StaticClass());

                        ListInventory->AddSlot()
                            .AutoHeight()
                            .VAlign(VAlign_Top)
                            .HAlign(HAlign_Left)
                            .Padding(FMargin(0.0f, 0.0f, 0.0f, 0.0f))
                            .AttachWidget(InventoryWidget->TakeWidget());

                        InventoryWidget->SetInventory(NewInventory, Panel);
                        Inventorys.Add(SelecActor, InventoryWidget);
                        CurrentSelectActors = L_Select;
                    }
                }
            }
        }
    }
    else if (L_Select.Num() < CurrentSelectActors.Num()) {
        RemoveSelect(L_Select);

        if (L_Select.Num() == 1) {

            if (CurrentSelectActors.Find(L_Select[0]) == INDEX_NONE) {
                    
                if (AActor* SelecActor = Cast<AActor>(L_Select[0])) {

                    if (UInventoryComponent* NewInventory = Cast<UInventoryComponent>(SelecActor->GetComponentByClass(UInventoryComponent::StaticClass()))) {

                        UInventoryWidget* InventoryWidget = CreateWidget<UInventoryWidget>(this, UInventoryWidget::StaticClass());

                        ListInventory->AddSlot()
                            .AutoHeight()
                            .VAlign(VAlign_Fill)
                            .HAlign(HAlign_Left)
                            .Padding(FMargin(0.0f, 0.0f, 0.0f, 0.0f))
                            .AttachWidget(InventoryWidget->TakeWidget());

                        InventoryWidget->SetInventory(NewInventory, Panel);
                        Inventorys.Add(SelecActor, InventoryWidget);
                        CurrentSelectActors = L_Select;
                    }
                }
            }
        }
    }
}

FReply UEditorWidget::SwitchList()
{
    Panel = 1;
    for (auto& Element : Inventorys) {
        Element.Value->SwitchPanel(Panel);
    }

    return FReply::Handled();
}

FReply UEditorWidget::SwitchGrid()
{
    Panel = 0;
    for (auto& Element : Inventorys) {
        Element.Value->SwitchPanel(Panel);
    }

    return FReply::Handled();
}

TArray<UObject*> UEditorWidget::GetSelectedActors()
{
    UEditorEngine* EditorEngine = Cast<UEditorEngine>(GEngine);
    if (!EditorEngine)
    {
        return TArray<UObject*>();
    }

    USelection* Selection = EditorEngine->GetSelectedActors();
    if (!Selection)
    {
        return TArray<UObject*>();
    }

    TArray<UObject*> SelectedActors;
    Selection->GetSelectedObjects(AActor::StaticClass(), SelectedActors);

    return SelectedActors;
}

FReply UInventoryWidget::RecalculationMass()
{
    if (HasInventoryFlag(EInventoryFlag::Mass))
        MassText->SetText(FText::Format(FText::FromString("Mass: {0}"), FText::AsNumber(Inventory->CurrentMassa)));

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
        InventoryList->SetInventory(Inventory);
        InventoryGrid->SetInventory(nullptr);
        break;
    }
}

bool UInventoryWidget::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
    if (Panel != 1)
        return false;

    if (auto Operation = Cast<UEditor_DragNewItem>(InOperation)) {
        int32 L_Index;
        return Inventory->AddSlot(Operation->Slot, true, L_Index);
    }

    return false;
}

void UInventoryWidget::SetInventory(UInventoryComponent* NewInventory, uint8 NewPanel)
{
    Inventory = NewInventory;

    SwitchPanel(NewPanel);

    TextNameActor->SetText(FText::Format(FText::FromString("Actor name: {0}"), FText::FromString(Inventory->GetOwner()->GetName())));

    if (HasInventoryFlag(EInventoryFlag::Mass)) {
        Recalculation->SetVisibility(EVisibility::Visible);
        MassText->SetText(FText::Format(FText::FromString("Mass: {0}"), FText::AsNumber(Inventory->CurrentMassa)));
    }
    else {
        Recalculation->SetVisibility(EVisibility::Hidden);
    }
}

TSharedRef<SWidget> UInventoryWidget::RebuildWidget()
{
    FSlateColorBrush* BrushButtons = new FSlateColorBrush(FLinearColor(0.0f, 0.0f, 0.0f));
    FSlateColorBrush* BrushInventory = new FSlateColorBrush(FLinearColor(0.01f, 0.01f, 0.01f));
    
    FSlateFontInfo TextFont = FCoreStyle::GetDefaultFontStyle("Roboto", 12);
    FSlateFontInfo ButtonFont = FCoreStyle::GetDefaultFontStyle("Roboto", 12);

    TSharedPtr<SHorizontalBox> TitlePanel = SNew(SHorizontalBox)
        + SHorizontalBox::Slot()
            .AutoWidth()
            .HAlign(HAlign_Fill)
            .VAlign(VAlign_Center)[
                SAssignNew(TextNameActor, STextBlock)
                    .Font(TextFont)
            ]
        + SHorizontalBox::Slot()
             .AutoWidth()[
                SNew(SSpacer).Size(FVector2D(5.0f,0.0f))
                        
            ]

        + SHorizontalBox::Slot()
            .AutoWidth()
            .HAlign(HAlign_Fill)
            .VAlign(VAlign_Center)[
                SAssignNew(Recalculation, SHorizontalBox)
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
          ]
      ];

    TSharedPtr<SBorder> BorderButtons = SNew(SBorder)
        .BorderImage(BrushButtons)
        .Content()[
            TitlePanel.ToSharedRef()
        ];

      UScaleBox * InventoryGridUWidget = NewObject<UScaleBox>(this);
       
      InventoryGrid = NewObject<UInventoryGrid>(InventoryGridUWidget);
      InventoryGrid->NoneSlot = USlotNoneWidget::StaticClass();
      InventoryGrid->ItemSlot = USlotItemWidget::StaticClass();
    
      auto SlotGrid = Cast<UScaleBoxSlot>(InventoryGridUWidget->AddChild(InventoryGrid));
      SlotGrid->SetHorizontalAlignment(HAlign_Fill);
      SlotGrid->SetVerticalAlignment(VAlign_Fill);

      UScaleBox* InventoryListUWidget = NewObject<UScaleBox>(this);
      InventoryList = NewObject<UInventoryList>(InventoryListUWidget);
      InventoryList->SizeSlot = 62.0f;
      InventoryList->ItemSlot = USlotItemListWidget::StaticClass();

      auto SlotList = Cast<UScaleBoxSlot>(InventoryListUWidget->AddChild(InventoryList));
      SlotList->SetHorizontalAlignment(HAlign_Fill);
      SlotList->SetVerticalAlignment(VAlign_Fill);

    MyPanel = SNew(SVerticalBox)
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
                    + SWidgetSwitcher::Slot()[
                        InventoryGridUWidget->TakeWidget()
                    ]

                + SWidgetSwitcher::Slot()[
                        InventoryListUWidget->TakeWidget()
                    ]
                ]
        ]
        + SVerticalBox::Slot()
        .AutoHeight()[
            SNew(SSpacer).Size(FVector2D(0.0f, 10.0f))

    ];

    return MyPanel.ToSharedRef();
}

FReply UBrowserAssetsWidget::OoClickUpData()
{
    if (Slots.IsValidIndex(0)) {
        for (auto Element : Slots) {
            ListAsset.ToSharedRef()->RemoveSlot(Element->TakeWidget());

        }
        Slots.Empty();
    }
    GenerationSlots();

    return FReply::Handled();
}

void UBrowserAssetsWidget::GenerationSlots()
{
    FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
    FARFilter Filter;
    Filter.ClassNames.Add(UItemAsset::StaticClass()->GetFName());
    Filter.PackagePaths.Add("/Game");
    Filter.bRecursivePaths = true;
    Filter.bRecursiveClasses = true;

    TArray<FAssetData> Assets;
    AssetRegistryModule.Get().GetAssets(Filter, Assets);

    for (auto& Element : Assets)
    {
        if (UItemAsset* Asset = Cast<UItemAsset>(Element.GetAsset())) {

            USlotAssetWidget* NewSlotAsset = CreateWidget<USlotAssetWidget>(this, USlotAssetWidget::StaticClass());

            ListAsset.ToSharedRef()->AddSlot()
                [NewSlotAsset->TakeWidget()];

            NewSlotAsset->SetAssetItem(Asset);
            Slots.Add(NewSlotAsset);
        }
    }
}

void UBrowserAssetsWidget::NativePreConstruct()
{
    GenerationSlots();
}

TSharedRef<SWidget> UBrowserAssetsWidget::RebuildWidget()
{
    FSlateFontInfo ButtonFont = FCoreStyle::GetDefaultFontStyle("Roboto", 12);

    TSharedPtr<SButton> ButtonUpData = SNew(SButton)
        .OnClicked_UObject(this, &UBrowserAssetsWidget::OoClickUpData)
        .Content()[
            SNew(STextBlock)
                .Font(ButtonFont)
                .Text(FText::FromString("ButtonUpData"))
        ].HAlign(HAlign_Center).VAlign(VAlign_Center);

    return SNew(SVerticalBox)
        + SVerticalBox::Slot()
        .FillHeight(1.0f)
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Fill)[
            SNew(SScrollBox)
                + SScrollBox::Slot()
                .HAlign(HAlign_Fill)
                .VAlign(VAlign_Fill)[
                    SAssignNew(ListAsset, SWrapBox)
                        .Orientation(EOrientation::Orient_Horizontal)
                        .InnerSlotPadding(FVector2D(6.f))
                        .UseAllottedWidth(true)
                ]
        ]
        
        + SVerticalBox::Slot()
        .AutoHeight()
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Bottom)[
            ButtonUpData.ToSharedRef()
        ];
}
