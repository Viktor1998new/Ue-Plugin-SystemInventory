//Copyright(c) 2022 - 2025, Viktor.F.P
#pragma once

#include "CoreMinimal.h"
#include "Toolkits/IToolkitHost.h"
#include "Toolkits/AssetEditorToolkit.h"
#include "SSCSEditor.h"
#include "PropertyEditorDelegates.h"

class IDetailsView;
class SDockableTab;

class INVENTORYEDITOR_API FInventoryToolKit : public FAssetEditorToolkit {

public:
	/** Delegate that, given an array of assets, returns an array of objects to use in the details view of an FSimpleAssetEditor */
	DECLARE_DELEGATE_RetVal_OneParam(TArray<UObject*>, FGetDetailsViewObjects, const TArray<UObject*>&);

    FInventoryToolKit();
    ~FInventoryToolKit();

    virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& TabManager) override;
    virtual void UnregisterTabSpawners(const TSharedRef<class FTabManager>& TabManager) override;

    // Inherited via FAssetEditorToolkit
    virtual FName GetToolkitFName() const override;
    virtual FText GetBaseToolkitName() const override;
    virtual FText GetToolkitName() const override;
    virtual FText GetToolkitToolTipText() const override;
    virtual FLinearColor GetWorldCentricTabColorScale() const override;
    virtual FString GetWorldCentricTabPrefix() const override;
    virtual void SaveAsset_Execute() override;
    virtual void SaveAssetAs_Execute() override;

	TSharedRef<SDockTab> SpawnBrowserAssetsTab(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnInventoryTab(const FSpawnTabArgs& Args);
    TSharedRef<SDockTab> SpawnComponentsTab(const FSpawnTabArgs& Args);
    TSharedRef<SDockTab> SpawnPropertiesTab(const FSpawnTabArgs& Args);

	void InitEditor(const EToolkitMode::Type Mode, const TSharedPtr< class IToolkitHost >& InitToolkitHost, UObject* ObjectsToEdit, FGetDetailsViewObjects GetDetailsViewObjects);
    void OnSelectionComponent(const TArray<FSCSEditorTreeNodePtrType>& SelectComponents);
    TSharedRef<FTabManager::FLayout> CreateLayout() const;
    void OnChangingProperties(const FPropertyChangedEvent& Property);
    void HandleAssetPostImport(UFactory* InFactory, UObject* InObject);
    void OnObjectsReplaced(const TMap<UObject*, UObject*>& ReplacementMap);
	static TSharedRef<FInventoryToolKit> CreateEditor(const EToolkitMode::Type Mode, const TSharedPtr< IToolkitHost >& InitToolkitHost, UObject* ObjectsToEdit, FGetDetailsViewObjects GetDetailsViewObjects = FGetDetailsViewObjects());
    void ChangeTabWorld(UWorld* World, EMapChangeType MapChangeType);

private:

    FDelegateHandle HandleChangeTabWorld;
    class UBlueprintGeneratedClass* BPClass;
    class UInventoryComponent* SelectComponent;
    TWeakObjectPtr<class UEditorInventoryWidget> InventoryTab;
    TWeakObjectPtr<class UBrowserAssetsWidget> BrowserAssetsTab;

    TSharedPtr<SDockableTab> PropertiesTab;
    TSharedPtr<SSCSEditor> SCSEditorTab;
    TSharedPtr<IDetailsView> DetailsView;
    TArray<UObject*> EditingObjects;
};