//Copyright(c) 2022, Viktor.F.P

#include "Inventory.h"
#include "InventorySettings.h"
#include "Developer/Settings/Public/ISettingsModule.h"
#include "Engine/World.h"

#define LOCTEXT_NAMESPACE "FInventoryModule"
DEFINE_LOG_CATEGORY(LogInventory)

void FInventoryModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	ModuleSettings  = GetMutableDefault<UInventorySettings>();

	// Register settings
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Engine", "Inventory",
			LOCTEXT("RuntimeSettingsName", "Inventory"),
			LOCTEXT("RuntimeSettingsDescription", "Configure Inventory plugin"),
			ModuleSettings);
	}
}

void FInventoryModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Engine", "Inventory");
	}
}

UInventorySettings* FInventoryModule::GetSettings() const
{
	check(ModuleSettings);
	return ModuleSettings;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FInventoryModule, Inventory)

