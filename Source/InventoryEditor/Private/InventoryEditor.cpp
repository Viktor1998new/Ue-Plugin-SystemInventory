//© Viktor F. P., 2022

#include "Inventory.h"
#include "InventoryEditorStyle.h"

#define LOCTEXT_NAMESPACE "InventoryEditor"
/**
 * Implements the ActorSequenceEditor module.
 */
class FInventoryEditorModule
	: public IModuleInterface
{
public:
	//FInventoryEditorModule();

	virtual void StartupModule() override
	{
		// Register styles
		FInventoryEditorStyle::Get();
	}

	virtual void ShutdownModule() override
	{
	
	}
};

IMPLEMENT_MODULE(FInventoryEditorModule, InventoryEditor);

#undef LOCTEXT_NAMESPACE
