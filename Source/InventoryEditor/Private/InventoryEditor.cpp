//Copyright(c) 2022, Viktor.F.P

#include "Inventory.h"
#include "InventoryEditorStyle.h"

#define LOCTEXT_NAMESPACE "InventoryEditor"

class FInventoryEditorModule
	: public IModuleInterface
{
public:

	virtual void StartupModule() override
	{
		
		FInventoryEditorStyle::Get();
	}

	virtual void ShutdownModule() override
	{
	
	}
};

IMPLEMENT_MODULE(FInventoryEditorModule, InventoryEditor);

#undef LOCTEXT_NAMESPACE
