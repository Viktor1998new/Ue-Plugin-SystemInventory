//Copyright(c) 2022 - 2025, Viktor.F.P

#include "InventoryToolKit.h"
#include "Components/InventoryComponent.h"
#include "Engine/SCS_Node.h"
#include "UMGEditor/EditorInventoryWidget.h"
#include "UMGEditor/BrowserAssetsWidget.h"
#include "FileHelpers.h"
#include "SSCSEditor.h"
#include "LevelEditor.h"

#define LOCTEXT_NAMESPACE "GenericEditor"

const FName PropertiesTabId(TEXT("GenericEditor_Properties"));
const FName BrowserAssetsTabId(TEXT("BrowserAssets"));
const FName InventoryTabId(TEXT("InventoryTab"));
const FName ComponentsTabId(TEXT("ComponentsTab"));
const FName MyToolbarTabId(TEXT("Toolbar"));
const FName SimpleEditorAppIdentifier(TEXT("GenericEditorApp"));

FLevelEditorModule& LevelEditor = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");

FInventoryToolKit::FInventoryToolKit()
{
	HandleChangeTabWorld = LevelEditor.OnMapChanged().AddRaw(this, &FInventoryToolKit::ChangeTabWorld);
}

FInventoryToolKit::~FInventoryToolKit()
{
	if (BrowserAssetsTab.IsValid()) {

		BrowserAssetsTab->Rename(nullptr, GetTransientPackage(), REN_DoNotDirty);
		BrowserAssetsTab.Reset();
	}

	if (InventoryTab.IsValid()) {

		InventoryTab->Rename(nullptr, GetTransientPackage(), REN_DoNotDirty);
		InventoryTab.Reset();
	}

	LevelEditor.OnMapChanged().Remove(HandleChangeTabWorld);
}

FName FInventoryToolKit::GetToolkitFName() const
{
	return FName();
}

FText FInventoryToolKit::GetBaseToolkitName() const
{
	return FText();
}

FText FInventoryToolKit::GetToolkitName() const
{
	const UObject* EditingObject = GetEditingObject();

	check(EditingObject != NULL);

	FString L_Name =GetLabelForObject(EditingObject).ToString();
	L_Name.RemoveFromEnd(TEXT("_C"));
	return FText::FromString(L_Name);
}

FText FInventoryToolKit::GetToolkitToolTipText() const
{
	const UObject* EditingObject = GetEditingObject();

	check(EditingObject != NULL);

	FString L_Name = GetLabelForObject(EditingObject).ToString();
	L_Name.RemoveFromEnd(TEXT("_C"));
	return FText::FromString(L_Name);
}

FLinearColor FInventoryToolKit::GetWorldCentricTabColorScale() const
{
	return FLinearColor();
}

FString FInventoryToolKit::GetWorldCentricTabPrefix() const
{
	return FString();
}

void FInventoryToolKit::SaveAsset_Execute()
{
	if (EditingObjects.Num() == 0)
	{
		return;
	}

	TArray<UObject*> ObjectsToSave;
	GetSaveableObjects(ObjectsToSave);

	if (ObjectsToSave.Num() == 0)
	{
		return;
	}

	TArray<UPackage*> PackagesToSave;

	for (UObject* Object : ObjectsToSave)
	{
		if ((Object == nullptr) || !Object->IsAsset())
		{
			// Log an invalid object but don't try to save it
			UE_LOG(LogInventoryEditor, Log, TEXT("Invalid object to save: %s"), (Object != nullptr) ? *Object->GetFullName() : TEXT("Null Object"));
		}
		else
		{
			PackagesToSave.Add(Object->GetOutermost());
		}
	}

	FEditorFileUtils::PromptForCheckoutAndSave(PackagesToSave, bCheckDirtyOnAssetSave, /*bPromptToSave=*/ false);
}

TSharedRef<SDockTab> FInventoryToolKit::SpawnBrowserAssetsTab(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == BrowserAssetsTabId);

	UWorld* World = GEditor->GetEditorWorldContext().World();
	if (World)
	{
		if (!BrowserAssetsTab.IsValid())
		{
			BrowserAssetsTab = CreateWidget<UBrowserAssetsWidget>(World, UBrowserAssetsWidget::StaticClass());
		}
	}

	TSharedRef<SDockTab> Tab = SNew(SDockTab)
		.Label(LOCTEXT("ComponentsTitle", "Browser"))
		.TabColorScale(GetTabColorScale())
		[
			BrowserAssetsTab->TakeWidget()
		];

	Tab->SetTabIcon(FEditorStyle::GetBrush("ContentBrowser.AssetTreeFolderOpen"));

	return Tab;
}

TSharedRef<SDockTab> FInventoryToolKit::SpawnInventoryTab(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == InventoryTabId);

	UWorld* World = GEditor->GetEditorWorldContext().World();
	if (World)
	{
		if (!InventoryTab.IsValid())
		{
			InventoryTab = CreateWidget<UEditorInventoryWidget>(World, UEditorInventoryWidget::StaticClass());
		}
	}

	TSharedRef<SDockTab> Tab = SNew(SDockTab)
		.Label(LOCTEXT("InventoryTitle", "Inventory"))
		.TabColorScale(GetTabColorScale())
		[
			InventoryTab->TakeWidget()
		];

	Tab->SetTabIcon(FEditorStyle::GetBrush("Kismet.AllClasses.ArrayVariableIcon"));
	if (EditingObjects.Num() == 1) {
		SelectComponent = Cast<UInventoryComponent>(EditingObjects[0]);
		InventoryTab->SetInventory(SelectComponent);
		DetailsView->SetObject(SelectComponent);
	}

	return Tab;
}

TSharedRef<SDockTab> FInventoryToolKit::SpawnComponentsTab(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == ComponentsTabId);

	TSharedRef<SDockTab> Tab = SNew(SDockTab)
		.Label(LOCTEXT("ComponentsTitle", "Components"))
		.TabColorScale(GetTabColorScale())
		[
			SCSEditorTab.ToSharedRef()
		];

	Tab->SetTabIcon(FEditorStyle::GetBrush("FullBlueprintEditor.SwitchToComponentsMode.Small"));

	return Tab;
}

TSharedRef<SDockTab> FInventoryToolKit::SpawnPropertiesTab(const FSpawnTabArgs& Args)
{
	check(Args.GetTabId() == PropertiesTabId);

	TSharedRef<SDockTab> Tab = SNew(SDockTab)
		.Label(LOCTEXT("DetailsTitle", "Details"))
		.TabColorScale(GetTabColorScale())
		[
			DetailsView.ToSharedRef()
		];

	Tab->SetTabIcon(FEditorStyle::GetBrush("GenericEditor.Tabs.Properties"));

	return Tab;
}

void FInventoryToolKit::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(LOCTEXT("WorkspaceMenu_GenericAssetEditor", "Asset Editor"));

	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(PropertiesTabId, FOnSpawnTab::CreateSP(this, &FInventoryToolKit::SpawnPropertiesTab))
		.SetDisplayName(LOCTEXT("PropertiesTab", "Details"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef());

	InTabManager->RegisterTabSpawner(BrowserAssetsTabId, FOnSpawnTab::CreateRaw(this, &FInventoryToolKit::SpawnBrowserAssetsTab))
		.SetDisplayName(LOCTEXT("BrowserAssetsTab", "BrowserAssets"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef());
	
	InTabManager->RegisterTabSpawner(InventoryTabId, FOnSpawnTab::CreateRaw(this, &FInventoryToolKit::SpawnInventoryTab))
		.SetDisplayName(LOCTEXT("InventoryTab", "Inventory"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef());

	InTabManager->RegisterTabSpawner(ComponentsTabId, FOnSpawnTab::CreateRaw(this, &FInventoryToolKit::SpawnComponentsTab))
		.SetDisplayName(LOCTEXT("ComponentsTab", "Components"))
		.SetGroup(WorkspaceMenuCategory.ToSharedRef());
}

void FInventoryToolKit::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

	InTabManager->UnregisterTabSpawner(PropertiesTabId);
	InTabManager->UnregisterTabSpawner(BrowserAssetsTabId);
	InTabManager->UnregisterTabSpawner(InventoryTabId);
	InTabManager->UnregisterTabSpawner(ComponentsTabId);

}


void FInventoryToolKit::SaveAssetAs_Execute()
{
	return;
}


void FInventoryToolKit::InitEditor(const EToolkitMode::Type Mode, const TSharedPtr< class IToolkitHost >& InitToolkitHost,  UObject* ObjectsToEdit, FGetDetailsViewObjects GetDetailsViewObjects) {
	
	BPClass = Cast<UBlueprintGeneratedClass>(ObjectsToEdit);
		
	if(BPClass)
	{
		const TArray<USCS_Node*>& AllSCSNodes = BPClass->SimpleConstructionScript->GetAllNodes();

		for (const USCS_Node* NodeItr : AllSCSNodes)
		{
			if (NodeItr->ComponentClass->IsChildOf(UInventoryComponent::StaticClass()))
			{
				EditingObjects.Add(NodeItr->GetActualComponentTemplate(BPClass));
			}
		}
	}

	GEditor->GetEditorSubsystem<UImportSubsystem>()->OnAssetPostImport.AddSP(this, &FInventoryToolKit::HandleAssetPostImport);
	GEditor->OnObjectsReplaced().AddSP(this, &FInventoryToolKit::OnObjectsReplaced);

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FDetailsViewArgs DetailsViewArgs;
	DetailsViewArgs.bUpdatesFromSelection = false;
	DetailsViewArgs.bLockable = false;
	DetailsViewArgs.NameAreaSettings = FDetailsViewArgs::ComponentsAndActorsUseNameArea;
	DetailsViewArgs.bHideSelectionTip = true;
	
	DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);

	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = CreateLayout();

	SAssignNew(SCSEditorTab, SSCSEditor)
		.AllowEditing(false)
		.ActorContext(BPClass->ClassDefaultObject)
		.ComponentTypeFilter(UInventoryComponent::StaticClass())
		.OnSelectionUpdated(SSCSEditor::FOnSelectionUpdated::CreateRaw(this, &FInventoryToolKit::OnSelectionComponent));

	FAssetEditorToolkit::InitAssetEditor(Mode, InitToolkitHost, SimpleEditorAppIdentifier, StandaloneDefaultLayout, true, true, ObjectsToEdit);

	if (DetailsView.IsValid())
	{
		DetailsView->OnFinishedChangingProperties().AddRaw(this, &FInventoryToolKit::OnChangingProperties);
	}
}

void FInventoryToolKit::OnSelectionComponent(const TArray<FSCSEditorTreeNodePtrType>& SelectComponents) {

	if (SelectComponents.IsValidIndex(0))
	{
		DetailsView->SetObject(SelectComponents[0]->GetComponentTemplate());
		SelectComponent = Cast<UInventoryComponent>(SelectComponents[0]->GetComponentTemplate());
		InventoryTab->SetInventory(Cast<UInventoryComponent>(SelectComponents[0]->GetComponentTemplate()));
		return;
	}

	SelectComponent = nullptr;
	InventoryTab->SetInventory(nullptr);
}

 TSharedRef<FTabManager::FLayout> FInventoryToolKit::CreateLayout() const {

	 return FTabManager::NewLayout("Standalone_AssetInventoroEditor_Layout_v3")
		->AddArea
		(
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.1f)
				->SetHideTabWell(true)
				->AddTab(MyToolbarTabId, ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewSplitter()
				->SetOrientation(Orient_Horizontal)
				->Split
				(
					FTabManager::NewSplitter()
					->SetOrientation(Orient_Vertical)
					->Split
					(
						FTabManager::NewStack()
						->AddTab(InventoryTabId, ETabState::OpenedTab)
					)
					->Split
					(
						FTabManager::NewStack()
						->AddTab(BrowserAssetsTabId, ETabState::OpenedTab)
					)
				)
				->Split
				(
					FTabManager::NewSplitter()
					->SetOrientation(Orient_Vertical)
					->SetSizeCoefficient(0.4f)
					->Split
					(
						FTabManager::NewStack()
						->SetSizeCoefficient(0.3f)
						->AddTab(ComponentsTabId, ETabState::OpenedTab)
					)
					->Split
					(
						FTabManager::NewStack()
						->AddTab(PropertiesTabId, ETabState::OpenedTab)
					)


				)
			)
		);
}

void FInventoryToolKit::OnChangingProperties(const FPropertyChangedEvent& Property) {
	InventoryTab->SetInventory(Cast<UInventoryComponent>(SelectComponent));
}

void FInventoryToolKit::HandleAssetPostImport(UFactory* InFactory, UObject* InObject)
{
	if (EditingObjects.Contains(InObject))
	{
		DetailsView->SetObjects(EditingObjects);
	}
}

void FInventoryToolKit::OnObjectsReplaced(const TMap<UObject*, UObject*>& ReplacementMap)
{
	bool bChangedAny = false;

	// Refresh our details view if one of the objects replaced was in the map. This gets called before the reinstance GC fixup, so we might as well fixup EditingObjects now too
	for (int32 i = 0; i < EditingObjects.Num(); i++)
	{
		UObject* SourceObject = EditingObjects[i];
		UObject* ReplacedObject = ReplacementMap.FindRef(SourceObject);

		if (ReplacedObject && ReplacedObject != SourceObject)
		{
			EditingObjects[i] = ReplacedObject;
			bChangedAny = true;
		}
	}

	if (bChangedAny)
	{
		DetailsView->SetObjects(EditingObjects);
	}
}


TSharedRef<FInventoryToolKit> FInventoryToolKit::CreateEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, UObject* ObjectsToEdit, FGetDetailsViewObjects GetDetailsViewObjects)
{
	TSharedRef< FInventoryToolKit > NewEditor(new FInventoryToolKit());
	NewEditor->InitEditor(Mode, InitToolkitHost, ObjectsToEdit, GetDetailsViewObjects);
	return NewEditor;
}

void FInventoryToolKit::ChangeTabWorld(UWorld* World, EMapChangeType MapChangeType)
{
	CloseWindow();
}

#undef LOCTEXT_NAMESPACE