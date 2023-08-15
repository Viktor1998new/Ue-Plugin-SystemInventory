//Copyright(c) 2022, Viktor.F.P

#include "Inventory.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/Docking/SDockableTab.h"
#include "Widgets/Docking/SDockTabStack.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SSplitter.h"
#include "Runtime/Slate/Private/Framework/Docking/SDockingArea.h"
#include "Widgets/SOverlay.h"
#include "Widgets/SWindow.h"
#include "EditorWidget.h"
#include "LevelEditor.h"
#include "Editor.h"
#include "InventoryEditorStyle.h"
#include "Framework/Notifications/NotificationManager.h"
#include "D:\Program Files\Epic Games\UE_4.27\Engine\Source\Runtime\UMG\Public\Blueprint\WidgetTree.h"
#define LOCTEXT_NAMESPACE "InventoryEditor"

class FInventoryEditorModule
	: public IModuleInterface
{
public:

	TSharedPtr<FTabManager> TabManager;

	TSharedPtr<FTabManager::FLayout> TabManagerLayout;

	UEditorWidget* CreatedUMGWidget;

	UBrowserAssetsWidget* BrowserAssetsWidget;

	virtual void StartupModule() override
	{
		FLevelEditorModule& LevelEditor = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
		LevelEditor.OnMapChanged().AddRaw(this, &FInventoryEditorModule::ChangeTabWorld);

		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension(
			"LevelEditor",
			EExtensionHook::After,
			NULL,
			FMenuExtensionDelegate::CreateRaw(this, &FInventoryEditorModule::AddMenuEntry));
		
		LevelEditor.GetMenuExtensibilityManager()->AddExtender(MenuExtender);

		FInventoryEditorStyle::Get();
        
	}


	void AddMenuEntry(FMenuBuilder& MenuBuilder)
	{
		MenuBuilder.BeginSection("InventoryMenu", TAttribute<FText>(FText::FromString("Inventory")));
		{
			// Create a Submenu inside of the Section
			MenuBuilder.AddMenuEntry(FText::FromString("Editor Inventory"),
				FText::FromString("Open Inventory Editor"),
				FSlateIcon(),
				FUIAction(FExecuteAction::CreateRaw(this, &FInventoryEditorModule::RegisterEditor)));
		}
		MenuBuilder.EndSection();
	}

	void RegisterEditor() {
	
		FGlobalTabmanager::Get()->RegisterNomadTabSpawner("InventoryEditorTabName", FOnSpawnTab::CreateRaw(this, &FInventoryEditorModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("InventoryEditor", "InventoryEditor"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

		FGlobalTabmanager::Get()->RegisterNomadTabSpawner("Inventory", FOnSpawnTab::CreateRaw(this, &FInventoryEditorModule::OnRegisterInventoryTab))
		.SetDisplayName(LOCTEXT("Inventory", "Inventory"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

		FGlobalTabmanager::Get()->RegisterNomadTabSpawner("BrowserAssets", FOnSpawnTab::CreateRaw(this, &FInventoryEditorModule::OnRegisterBrowserAssetsTab))
		.SetDisplayName(LOCTEXT("BrowserAssets", "BrowserAssets"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

		FGlobalTabmanager::Get()->TryInvokeTab(FTabId("InventoryEditorTabName"));
	}

	TSharedRef<SDockTab> OnRegisterBrowserAssetsTab(const FSpawnTabArgs& SpawnTabArgs) {
	
		UWorld* World = GEditor->GetEditorWorldContext().World();
		if (World)
		{
			if (BrowserAssetsWidget)
			{
				BrowserAssetsWidget->Rename(nullptr, GetTransientPackage(), REN_DoNotDirty);
				BrowserAssetsWidget = nullptr;
			}
			BrowserAssetsWidget = CreateWidget<UBrowserAssetsWidget>(World, UBrowserAssetsWidget::StaticClass());
		}

		return SNew(SDockTab)
			.TabRole(ETabRole::NomadTab)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			[
				BrowserAssetsWidget->TakeWidget()
			]
			];
	}

	TSharedRef<SDockTab> OnRegisterInventoryTab(const FSpawnTabArgs& SpawnTabArgs) {
		
		UWorld* World = GEditor->GetEditorWorldContext().World();
		if (World)
		{
			if (CreatedUMGWidget)
			{
				CreatedUMGWidget->Rename(nullptr, GetTransientPackage(), REN_DoNotDirty);
				CreatedUMGWidget = nullptr;
			}
			CreatedUMGWidget = CreateWidget<UEditorWidget>(World, UEditorWidget::StaticClass());
		}

		if (CreatedUMGWidget)
		{
			return SNew(SDockTab)
				.TabRole(ETabRole::NomadTab)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
				.HAlign(HAlign_Fill)
				[
					CreatedUMGWidget->TakeWidget()
				]
				];
		}
		else
		{
			return  SNew(SDockTab)
				.TabRole(ETabRole::NomadTab);
		}
	}

	void UpdateRespawnListIfNeeded(TSharedRef<SDockTab> TabBeingClosed)
	{
		if (CreatedUMGWidget)
		{
			CreatedUMGWidget->Rename(nullptr, GetTransientPackage());
			CreatedUMGWidget = nullptr;
		}

		if (BrowserAssetsWidget)
		{
			BrowserAssetsWidget->Rename(nullptr, GetTransientPackage());
			BrowserAssetsWidget = nullptr;
		}
	}

	TSharedRef<SDockTab> OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
	{
		const TSharedRef<SDockTab> NomadTab = SNew(SDockTab)
			.TabRole(ETabRole::NomadTab);
		
		NomadTab->SetOnTabClosed(SDockTab::FOnTabClosedCallback::CreateRaw(this, &FInventoryEditorModule::UpdateRespawnListIfNeeded));

		if (!TabManager.IsValid())
		{
			TabManager = FGlobalTabmanager::Get()->NewTabManager(NomadTab);
		}

		if (!TabManagerLayout.IsValid())
		{
			TabManagerLayout = FTabManager::NewLayout("InventoryEditorWindow")
				->AddArea
				(
					FTabManager::NewPrimaryArea()
					->SetOrientation(Orient_Vertical)
					->Split
					(
						FTabManager::NewStack()
						->SetSizeCoefficient(.4f)
						->AddTab("Inventory", ETabState::OpenedTab)
					)
					->Split
					(
						FTabManager::NewStack()
						->SetSizeCoefficient(.4f)
						->AddTab("BrowserAssets", ETabState::OpenedTab)
					)
				);
		}

		TSharedRef<SWidget> TabContents = TabManager->RestoreFrom(TabManagerLayout.ToSharedRef(), TSharedPtr<SWindow>(),false, EOutputCanBeNullptr::IfNoTabValid).ToSharedRef();

		NomadTab->SetContent(TabContents);

		return NomadTab;
	}


	void ChangeTabWorld(UWorld* World, EMapChangeType MapChangeType)
	{
		if (MapChangeType == EMapChangeType::TearDownWorld) {

			if (CreatedUMGWidget)
			{
				CreatedUMGWidget->Rename(nullptr, GetTransientPackage(), REN_DoNotDirty);
				CreatedUMGWidget = nullptr;
			}

			if (BrowserAssetsWidget)
			{
				BrowserAssetsWidget->Rename(nullptr, GetTransientPackage(), REN_DoNotDirty);
				BrowserAssetsWidget = nullptr;
			}
		}
	}

	virtual void ShutdownModule() override
	{
		FGlobalTabmanager::Get()->UnregisterNomadTabSpawner("InventoryEditorTabName");
	}

};

IMPLEMENT_MODULE(FInventoryEditorModule, InventoryEditor);

#undef LOCTEXT_NAMESPACE
