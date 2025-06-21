//Copyright(c) 2022 - 2025, Viktor.F.P

#include "UMGEditor/BrowserAssetsWidget.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "SlotsWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Widgets/Layout/SWrapBox.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Misc/EngineVersionComparison.h"

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

#if UE_VERSION_OLDER_THAN(5, 1, 1)
    Filter.ClassNames.Add(UItemAsset::StaticClass()->GetFName());
#elif UE_VERSION_NEWER_THAN(5, 1, 1)
    Filter.ClassPaths.Add(UItemAsset::StaticClass()->GetClassPathName());
#endif

    Filter.PackagePaths.Add("/Game");
    Filter.bRecursivePaths = true;
    Filter.bRecursiveClasses = true;

    TArray<FAssetData> Assets;
    AssetRegistryModule.Get().GetAssets(Filter, Assets);

    for (auto& Element : Assets)
    {
        if (UItemAsset* Asset = Cast<UItemAsset>(Element.GetAsset())) {

            USlotAssetWidget* NewSlotAsset = WidgetTree->ConstructWidget<USlotAssetWidget>(USlotAssetWidget::StaticClass(), FName(*FString::Printf(TEXT("C_UAssetWidget_%s"), *Asset->GetName())));

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
    return SNew(SVerticalBox)

        + SVerticalBox::Slot()
        .AutoHeight()
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Bottom)[
            SNew(SButton)
                .ButtonStyle(FEditorStyle::Get(), "FlatButton.Success")
                .ContentPadding(FMargin(12, 2))
                .OnClicked_UObject(this, &UBrowserAssetsWidget::OoClickUpData)
                .HAlign(HAlign_Center)
                .VAlign(VAlign_Center)
                [
                    SNew(STextBlock)
                        .TextStyle( FEditorStyle::Get(), "ContentBrowser.TopBar.Font")
                        .Text(FText::FromString("Up Assets"))
                ]
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
        .HAlign(HAlign_Fill)
        .VAlign(VAlign_Fill)[
            SNew(SScrollBox)
                + SScrollBox::Slot()
                .HAlign(HAlign_Fill)
                .VAlign(VAlign_Fill)[
                    SAssignNew(ListAsset, SWrapBox)
                        .Orientation(EOrientation::Orient_Horizontal)
                        .InnerSlotPadding(FVector2D(6.f))
                        .UseAllottedSize(true)
                       
                ]
        ];
}