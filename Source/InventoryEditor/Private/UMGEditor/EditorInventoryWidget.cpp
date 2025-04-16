//Copyright(c) 2022 - 2025, Viktor.F.P

#include "UMGEditor/EditorInventoryWidget.h"
#include "UMGEditor/InventoryWidget.h"

#include "InventorySettings.h"
#include "Components/InventoryComponent.h"

#include "Editor.h"
#include "Editor/EditorEngine.h"
#include "GameFramework/Actor.h"
#include "Editor/UnrealEdEngine.h"
#include "Engine/Selection.h"
#include "Blueprint/WidgetTree.h"

#include "Widgets/Layout/SScaleBox.h"
#include "Widgets/Layout/SConstraintCanvas.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Brushes/SlateColorBrush.h"
#include <EditorFontGlyphs.h>

TSharedRef<SWidget> UEditorInventoryWidget::RebuildWidget()
{
    FSlateColorBrush* BrushButtons = new  FSlateColorBrush(FLinearColor(0.0f, 0.0f, 0.0f));
    FSlateColorBrush* MyBrush = new FSlateColorBrush(FLinearColor(0.07f, 0.07f, 0.07f));

    FSlateFontInfo ButtonFont = FCoreStyle::GetDefaultFontStyle("Roboto", 12);

    ButtonList = SNew(SButton)
        .ButtonStyle(FEditorStyle::Get(), "FlatButton")
        .ContentPadding(FMargin(12, 2))
        .OnClicked_UObject(this, &UEditorInventoryWidget::SwitchList)
        .Content()[
            SNew(SScaleBox)[
                SNew(SHorizontalBox)
                    + SHorizontalBox::Slot()
                    .VAlign(VAlign_Center)
                    .HAlign(HAlign_Left)
                    .AutoWidth()
                    [
                        SNew(STextBlock)
                            .TextStyle(FEditorStyle::Get(), "ContentBrowser.TopBar.Font")
                            .Font(FEditorStyle::Get().GetFontStyle("FontAwesome.11"))
                            .Text(FEditorFontGlyphs::Circle)
                    ]
                    + SHorizontalBox::Slot()
                    .HAlign(HAlign_Fill)
                    .VAlign(VAlign_Fill)
                    [
                        SNew(STextBlock)
                            .TextStyle(FEditorStyle::Get(), "ContentBrowser.TopBar.Font")
                            .Text(FText::FromString("List"))
                    ]
            ]
        ];

        ButtonGrid = SNew(SButton)
        .IsEnabled(false)
        .ButtonStyle(FEditorStyle::Get(), "FlatButton")
        .ContentPadding(FMargin(12, 2))
        .OnClicked_UObject(this, &UEditorInventoryWidget::SwitchGrid)
        [
            SNew(SScaleBox)[
                SNew(SHorizontalBox)
                    + SHorizontalBox::Slot()
                    .VAlign(VAlign_Center)
                    .HAlign(HAlign_Left)
                    .AutoWidth()
                    [
                        SNew(STextBlock)
                            .TextStyle(FEditorStyle::Get(), "ContentBrowser.TopBar.Font")
                            .Font(FEditorStyle::Get().GetFontStyle("FontAwesome.11"))
                            .Text(FEditorFontGlyphs::Circle)
                    ]

                    // Save All Text
                    + SHorizontalBox::Slot()
                    .HAlign(HAlign_Fill)
                    .VAlign(VAlign_Fill)
                    [
                        SNew(STextBlock)
                            .TextStyle(FEditorStyle::Get(), "ContentBrowser.TopBar.Font")
                            .Text(FText::FromString("Grid"))
                    ]
            ]
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
                + SVerticalBox::Slot()[
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
                                    SAssignNew(ListInventory, SVerticalBox)
                                ]
                        ]
                ]
                + SVerticalBox::Slot()
                .AutoHeight()
                .VAlign(VAlign_Bottom)
                .HAlign(HAlign_Fill)[
                    SNew(STextBlock)
                        .TextStyle(FEditorStyle::Get(), "ContentBrowser.TopBar.Font")
                        .Text(FText::FromString("Drag: LMB, Menu: RMB, Rotate item: Drag + Left Shift, Remove item: LMB + Left ctrl"))
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

void UEditorInventoryWidget::PostRename(UObject* OldOuter, const FName OldName)
{
    CurrentSelectActors.Empty();
    ListInventory->ClearChildren();
    Inventorys.Empty();
}

void UEditorInventoryWidget::SetSelecEvent() {

    UEditorEngine* EditorEngine = Cast<UEditorEngine>(GEngine);
 
    if (!EditorEngine) return;
  
    USelection* Selection = EditorEngine->GetSelectedActors();
   
    if (!Selection) return;

    OnSelect(nullptr);

    OnSelectHandle = Selection->SelectionChangedEvent.AddUFunction(this, FName("OnSelect"));

    IsSelecEvent = true;
}

void UEditorInventoryWidget::AddInventory(AActor* NewActor)
{
    TArray<UInventoryComponent*> L_Components;

    for (auto Element : NewActor->GetComponents())
    {
        if (UInventoryComponent* NewInventory = Cast<UInventoryComponent>(Element)) {
            L_Components.Add(NewInventory);
        }
    }

    if (L_Components.Num() == 0) {
        return;
    }

    UInventoryWidget* InventoryWidget = WidgetTree->ConstructWidget<UInventoryWidget>(UInventoryWidget::StaticClass(), FName(*FString::Printf(TEXT("C_UInventoryWidget_%s"), *NewActor->GetName())));

    ListInventory->AddSlot()
        .AutoHeight()
        .VAlign(VAlign_Top)
        .HAlign(HAlign_Fill)
        .Padding(FMargin(0.0f, 0.0f, 0.0f, 20.0f))
        .AttachWidget(InventoryWidget->TakeWidget());

    if (L_Components.Num() == 1) {
        InventoryWidget->SetInventory(L_Components[0], Panel);

    } else if (L_Components.Num() >= 1) {

        InventoryWidget->SetInventory(L_Components, Panel);
    }
    
    Inventorys.Add(NewActor, InventoryWidget);
    CurrentSelectActors.Add(NewActor);
}

void UEditorInventoryWidget::NativeDestruct()
{
    CurrentSelectActors.Empty();
    ListInventory->ClearChildren();
    Inventorys.Empty();

    if (!IsSelecEvent)
        return;

    UEditorEngine* EditorEngine = Cast<UEditorEngine>(GEngine);
    if (!EditorEngine) return;

    USelection* Selection = EditorEngine->GetSelectedActors();
    if (!Selection) return;

    Selection->SelectionChangedEvent.Remove(OnSelectHandle);
}

void UEditorInventoryWidget::OnSelect(UObject* NewSelect)
{
    TArray<UObject*> L_Select = GetSelectedActors();

    if (L_Select.Num() == 0 && CurrentSelectActors.Num() == 0)
        return;

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
                    }
                }
                CurrentSelectActors.Empty();

                AddInventory(Cast<AActor>(L_Select[0]));
            }
        }
    }
    else if (L_Select.Num() < CurrentSelectActors.Num()) {

        RemoveSelect(L_Select);

        if (L_Select.Num() == 1) {

            if (CurrentSelectActors.Find(L_Select[0]) == INDEX_NONE) {

                AddInventory(Cast<AActor>(L_Select[0]));
            }
        }
    }
}

void UEditorInventoryWidget::OnNoneSelect() {
    OnSelect(nullptr);
}

void UEditorInventoryWidget::SetInventory(UInventoryComponent* NewInventory) {

    if (SinglInventory) {
        SinglInventory->SetInventory(NewInventory, Panel);
        SinglInventory->IsListInventors = false;
        return;
    }

    SinglInventory = WidgetTree->ConstructWidget<UInventoryWidget>(UInventoryWidget::StaticClass(), FName(*FString::Printf(TEXT("C_UInventoryWidget_%s"), *NewInventory->GetName())));
    
     ListInventory->AddSlot()
        .AutoHeight()
        .VAlign(VAlign_Top)
        .HAlign(HAlign_Fill)
        .Padding(FMargin(0.0f, 0.0f, 0.0f, 0.0f))
        .AttachWidget(SinglInventory->TakeWidget());

     SinglInventory->SetInventory(NewInventory, Panel);
}

void UEditorInventoryWidget::AddSelect(TArray<UObject*> NewSelectActors)
{
    for (auto& NewSelect : NewSelectActors) {

        if (CurrentSelectActors.Find(NewSelect) == INDEX_NONE) {
            

            AddInventory(Cast<AActor>(NewSelect));
        }
    }

    CurrentSelectActors = NewSelectActors;
}

void UEditorInventoryWidget::RemoveSelect(TArray<UObject*> NewSelectActors)
{
    for (auto& Select : CurrentSelectActors) {

        if (!IsValid(Select))
            continue;

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

void UEditorInventoryWidget::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	MyPanel.Reset();
}

FReply UEditorInventoryWidget::SwitchList()
{
    Panel = 1;

    ButtonGrid->SetEnabled(true);
    ButtonList->SetEnabled(false);

    if (IsValid(SinglInventory))
    {
        SinglInventory->SwitchPanel(Panel);
        return FReply::Handled();
    }

    for (auto& Element : Inventorys) {
        Element.Value->SwitchPanel(Panel);
    }

    return FReply::Handled();
}

FReply UEditorInventoryWidget::SwitchGrid()
{
    Panel = 0;

    ButtonGrid->SetEnabled(false);
    ButtonList->SetEnabled(true);

    if (IsValid(SinglInventory))
    {
        SinglInventory->SwitchPanel(Panel);
        return FReply::Handled();
    }

    for (auto& Element : Inventorys) {
        Element.Value->SwitchPanel(Panel);
    }

    return FReply::Handled();
}

TArray<UObject*> UEditorInventoryWidget::GetSelectedActors()
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