//Copyright(c) 2022, Viktor.F.P
#pragma once
#include "CoreMinimal.h"
#include "Widgets/Docking/SDockableTab.h"
#include "Widgets/Docking/SDockTabStack.h"
#include "Widgets/Docking/SDockTab.h"

#include "Modules/ModuleInterface.h"

class FInventoryEditorModule : public IModuleInterface
{
public:

	TSharedPtr<class FItemAsset_Action> ItemAssetAction;

	TSharedPtr<FTabManager> TabManager;

	TSharedPtr<FTabManager::FLayout> TabManagerLayout;

	class UEditorWidget* CreatedUMGWidget;

	class UBrowserAssetsWidget* BrowserAssetsWidget;

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void AddMenuEntry(FMenuBuilder& MenuBuilder);
	void RegisterEditor();
	void UpdateRespawnListIfNeeded(TSharedRef<SDockTab> TabBeingClosed);
	void ChangeTabWorld(UWorld* World, EMapChangeType MapChangeType);

	TSharedRef<SDockTab> OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs);
	TSharedRef<SDockTab> OnRegisterBrowserAssetsTab(const FSpawnTabArgs& SpawnTabArgs);
	TSharedRef<SDockTab> OnRegisterInventoryTab(const FSpawnTabArgs& SpawnTabArgs);
};