//Copyright(c) 2022 - 2025, Viktor.F.P

#include "InventoryEditor.h"
#include "CoreMinimal.h"
#include "Widgets/SWindow.h"
#include "UMGEditor/EditorInventoryWidget.h"
#include "UMGEditor/BrowserAssetsWidget.h"
#include "LevelEditor.h"
#include "Editor.h"
#include "InventoryEditorStyle.h"
#include "ItemAsset_Action.h"
#include "Widgets/Docking/SDockTab.h"
#include "ContentBrowserModule.h"
#include "Components/InventoryComponent.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Engine/SCS_Node.h"
#include "InventoryToolKit.h"

IMPLEMENT_MODULE(FInventoryEditorModule, InventoryEditor);

static const FName TabInventoryName = "Inventory";
static const FName TabBrowserAssetsName = "BrowserAssets";

#define LOCTEXT_NAMESPACE "InventoryEditor"
DEFINE_LOG_CATEGORY(LogInventoryEditor)

void FInventoryEditorModule::StartupModule()
{
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	EAssetTypeCategories::Type CustomAssetCategory = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("InventoryCategory")), LOCTEXT("InventoryCategory", "Inventory"));

	TSharedRef<FItemAsset_Action> AssetTypeActions = MakeShareable(new FItemAsset_Action());
	AssetTypeActions->AssetCategory = CustomAssetCategory;

	AssetTools.RegisterAssetTypeActions(AssetTypeActions);
	ItemAssetAction = AssetTypeActions;

	FLevelEditorModule& LevelEditor = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	HandleChangeTabWorld = LevelEditor.OnMapChanged().AddRaw(this, &FInventoryEditorModule::ChangeTabWorld);

	TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
	MenuExtender->AddMenuExtension(
		"LevelEditor",
		EExtensionHook::After,
		NULL,
		FMenuExtensionDelegate::CreateRaw(this, &FInventoryEditorModule::AddMenuEntry));

	LevelEditor.GetMenuExtensibilityManager()->AddExtender(MenuExtender);

	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
	TArray<FContentBrowserMenuExtender_SelectedAssets>& MenuExtenders = ContentBrowserModule.GetAllAssetViewContextMenuExtenders();

	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");

	MenuExtenders.Add(FContentBrowserMenuExtender_SelectedAssets::CreateRaw(this, &FInventoryEditorModule::AddAssetMenu));
	FInventoryEditorStyle::Get();
}

TSharedRef<FExtender> FInventoryEditorModule::AddAssetMenu(const TArray<FAssetData>& InAssetData) {

	TSharedRef<FExtender> B_MenuExtender = MakeShareable(new FExtender);

	TArray<UObject*> InSupportedObjects;
	for (FAssetData AssetDataX : InAssetData) {
		if (!AssetDataX.GetClass()->IsChildOf(AActor::StaticClass())) {

			UObject* LoadedObject = AssetDataX.GetAsset();

			if (Cast<UBlueprint>(LoadedObject)) {
				if (auto bp = Cast<UBlueprint>(LoadedObject)->GeneratedClass)
				{
					UBlueprintGeneratedClass* BPClass = Cast<UBlueprintGeneratedClass>(bp);
					const TArray<USCS_Node*>& AllSCSNodes = BPClass->SimpleConstructionScript->GetAllNodes();

					for (const USCS_Node* NodeItr : AllSCSNodes)
					{
						if (NodeItr->ComponentClass->IsChildOf(UInventoryComponent::StaticClass()))
						{
							InSupportedObjects.Add(bp);
							break;
						}
					}
				}
			}
		}
	}

	if (InSupportedObjects.Num() == 0) {
		return B_MenuExtender;
	}

	B_MenuExtender->AddMenuExtension(
		"CommonAssetActions",
		EExtensionHook::After,
		NULL,
		FMenuExtensionDelegate::CreateLambda([&, this, InSupportedObjects](FMenuBuilder& MenuBuilder) {

			MenuBuilder.AddMenuEntry(LOCTEXT("InventoryEditor", "InventoryEditor"),
				LOCTEXT("OpenInventoryEditor", "Open Inventory Editor"),
				FSlateIcon(),
				FUIAction(FExecuteAction::CreateLambda([this, InSupportedObjects]() {
					for (auto L_OpenAsset : InSupportedObjects)
					{
						FInventoryToolKit::CreateEditor(EToolkitMode::Standalone, TSharedPtr<IToolkitHost>(), L_OpenAsset);
					}
					})));
			})
	);
	return B_MenuExtender;

}

void FInventoryEditorModule::AddMenuEntry(FMenuBuilder& MenuBuilder)
{
	MenuBuilder.BeginSection("InventoryMenu", LOCTEXT("Inventory", "Inventory"));
	{
		MenuBuilder.AddMenuEntry(LOCTEXT("InventoryEditor", "InventoryEditor"),
			LOCTEXT("OpenInventoryEditor", "Open Inventory Editor"),
			FSlateIcon(),
			FUIAction(FExecuteAction::CreateRaw(this, &FInventoryEditorModule::RegisterEditor)));
	}
	MenuBuilder.EndSection();
}

void FInventoryEditorModule::RegisterEditor() {

	if (!TabManager.IsValid()) {
		FGlobalTabmanager::Get()->RegisterNomadTabSpawner("InventoryEditorTabName", FOnSpawnTab::CreateRaw(this, &FInventoryEditorModule::OnSpawnPluginTab))
			.SetDisplayName(LOCTEXT("InventoryEditor", "InventoryEditor"))
			.SetMenuType(ETabSpawnerMenuType::Hidden);
	}

	FGlobalTabmanager::Get()->TryInvokeTab(FTabId("InventoryEditorTabName"));
}

TSharedRef<SDockTab> FInventoryEditorModule::OnRegisterBrowserAssetsTab(const FSpawnTabArgs& SpawnTabArgs) {

	UWorld* World = GEditor->GetEditorWorldContext().World();
	if (World)
	{
		if (BrowserAssetsTab)
		{
			BrowserAssetsTab->Rename(nullptr, GetTransientPackage(), REN_DoNotDirty);
			BrowserAssetsTab = nullptr;
		}
		BrowserAssetsTab = CreateWidget<UBrowserAssetsWidget>(World, UBrowserAssetsWidget::StaticClass());
	}

	auto L_Dock = SNew(SDockTab)
		.TabRole(ETabRole::NumRoles)
		[
			SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.HAlign(HAlign_Fill)
				[
					BrowserAssetsTab->TakeWidget()
				]
		];

	L_Dock->SetTabManager(TabManager);

	return L_Dock;
}

TSharedRef<SDockTab> FInventoryEditorModule::OnRegisterInventoryTab(const FSpawnTabArgs& SpawnTabArgs) {

	UWorld* World = GEditor->GetEditorWorldContext().World();
	if (World)
	{
		if (InventoryTab)
		{
			InventoryTab->Rename(nullptr, GetTransientPackage(), REN_DoNotDirty);
			InventoryTab = nullptr;
		}
		InventoryTab = CreateWidget<UEditorInventoryWidget>(World, UEditorInventoryWidget::StaticClass());
	}

	auto L_Dock = SNew(SDockTab)
		.TabRole(ETabRole::NumRoles)
		[
			SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.HAlign(HAlign_Fill)
				[
					InventoryTab->TakeWidget()
				]
		];

	InventoryTab->SetSelecEvent();

	L_Dock->SetTabManager(TabManager);

	return L_Dock;
}

void FInventoryEditorModule::UpdateRespawnListIfNeeded(TSharedRef<SDockTab> TabBeingClosed)
{
	if (InventoryTab)
	{
		InventoryTab->Rename(nullptr, GetTransientPackage());
		InventoryTab = nullptr;
	}

	if (BrowserAssetsTab)
	{
		BrowserAssetsTab->Rename(nullptr, GetTransientPackage());
		BrowserAssetsTab = nullptr;
	}
}

TSharedRef<SDockTab> FInventoryEditorModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	const TSharedRef<SDockTab> NomadTab = SNew(SDockTab)
		.TabRole(ETabRole::MajorTab);

	NomadTab->SetOnTabClosed(SDockTab::FOnTabClosedCallback::CreateRaw(this, &FInventoryEditorModule::UpdateRespawnListIfNeeded));

	TabManager = FGlobalTabmanager::Get()->NewTabManager(NomadTab);

	TabManagerLayout = FTabManager::NewLayout("InventoryEditorWindow")
		->AddArea
		(
			FTabManager::NewPrimaryArea()
			->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewStack()
				->AddTab(TabInventoryName, ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(.4f)
				->AddTab(TabBrowserAssetsName, ETabState::OpenedTab)
			)
		);

	TabManager.Get()->RegisterTabSpawner(TabInventoryName, FOnSpawnTab::CreateRaw(this, &FInventoryEditorModule::OnRegisterInventoryTab))
		.SetDisplayName(LOCTEXT("Inventory", "Inventory"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

	TabManager.Get()->RegisterTabSpawner(TabBrowserAssetsName, FOnSpawnTab::CreateRaw(this, &FInventoryEditorModule::OnRegisterBrowserAssetsTab))
		.SetDisplayName(LOCTEXT("BrowserAssets", "BrowserAssets"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

	TSharedRef<SWidget> TabContents = TabManager->RestoreFrom(TabManagerLayout.ToSharedRef(), TSharedPtr<SWindow>(), false, EOutputCanBeNullptr::IfNoTabValid).ToSharedRef();

	NomadTab->SetContent(TabContents);
	MainTab = NomadTab;

	return NomadTab;
}


void FInventoryEditorModule::ChangeTabWorld(UWorld* World, EMapChangeType MapChangeType)
{
	if (MapChangeType == EMapChangeType::TearDownWorld)
	{
		if (MainTab.IsValid())
		{
			if (InventoryTab) {
				InventoryTab->RemoveSelect(TArray<UObject*>());
				InventoryTab->Rename(nullptr, GetTransientPackage());
				InventoryTab = nullptr;
			}

			if (BrowserAssetsTab) {
				BrowserAssetsTab->Rename(nullptr, GetTransientPackage());
				BrowserAssetsTab = nullptr;
			}

			MainTab.Pin()->SetContent(SNullWidget::NullWidget);
			MainTab.Pin()->RequestCloseTab();

		}
	}
}

void FInventoryEditorModule::ShutdownModule()
{
	if (!FModuleManager::Get().IsModuleLoaded("AssetTools")) return;

	FAssetToolsModule::GetModule().Get().UnregisterAssetTypeActions(ItemAssetAction.ToSharedRef());

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner("InventoryEditorTabName");

	FLevelEditorModule& LevelEditor = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	LevelEditor.OnMapChanged().Remove(HandleChangeTabWorld);

}

#undef LOCTEXT_NAMESPACE