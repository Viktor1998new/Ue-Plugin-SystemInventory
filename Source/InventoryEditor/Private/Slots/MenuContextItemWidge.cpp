//Copyright(c) 2022 - 2025, Viktor.F.P
#include "SlotsWidget.h"
#include "Brushes/SlateColorBrush.h"
#include "PropertyEditorModule.h"
#include "IPropertyTable.h"
#include "InventoryLibrary.h"
#include <ISinglePropertyView.h>

FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

FString GetJsonSlot(const FInventorySlot Slot)
{
	if (!IsValid(Slot.ItemAsset) || !IsValid(Slot.ItemAsset->StructType) || Slot.ItemData.IsEmpty()) {
		return FString();
	}

	FString Return_Value;

	if (FJsonObjectConverter::UStructToJsonObjectString(Slot.ItemAsset->StructType->GetSuperStruct(), Slot.ItemAsset->StructType, Return_Value, 0, 0)) {

		return Return_Value;
	}

	return FString();
}

FString GetJsonString(UScriptStruct* Struct)
{
	if (!IsValid(Struct))
		return FString();

	uint8* DefaultStructInstance = (uint8*)FMemory::Malloc(Struct->GetStructureSize());
	Struct->InitializeDefaultValue(DefaultStructInstance);

	FString L_Return;

	if (FJsonObjectConverter::UStructToJsonObjectString(Struct, DefaultStructInstance, L_Return, 0, 0)) {

		FMemory::Free(DefaultStructInstance);
		return L_Return;
	}

	FMemory::Free(DefaultStructInstance);
	return FString();

}

void UMenuContextItemWidget::CheckSettingsData(FInventorySlot InventorySlot) {

	if (GetJsonSlot(InventorySlot).IsEmpty()) {
		ItemSettings->Data = GetJsonString(InventorySlot.ItemAsset->StructType);

	}
	else {
		ItemSettings->Data = InventorySlot.ItemData;
	}
}

void UMenuContextItemWidget::OnChangingProperties(const FPropertyChangedEvent& Property)
{
	if (!Inventory)
		return;

	FInventorySlot L_SlotItem = Inventory->GetItem(Index);
	FInventorySlot L_NewSlotItem = L_SlotItem;

	L_NewSlotItem.ItemData = ItemSettings->Data;

	if (ItemSettings->Asset->SlotItemData.MaxStack < ItemSettings->Count)
		ItemSettings->Count = ItemSettings->Asset->SlotItemData.MaxStack;

	L_NewSlotItem.Count = L_NewSlotItem.ItemAsset->SlotItemData.StackItem ? ItemSettings->Count : 1;

	if (!Inventory->SetSlot(Index, L_NewSlotItem)) {

		CheckSettingsData(L_SlotItem);

		return;
	}
}

void UMenuContextItemWidget::SetItem(TSharedPtr<class SMenuAnchor> MewMenu, UInventoryComponent* NewInventory, int32 NewIndex)
{

	if(!IsValid(ItemSettings))
		ItemSettings = NewObject<UItemSettings>();

	FInventorySlot L_SlotItem = NewInventory->GetItem(NewIndex);
	ItemSettings->Index = NewIndex;
	ItemSettings->Asset = L_SlotItem.ItemAsset;
	ItemSettings->Count = L_SlotItem.Count;
	CheckSettingsData(L_SlotItem);

	Inventory = NewInventory;
	Index = NewIndex;
	Menu = MewMenu;
}

TSharedRef<SWidget> UMenuContextItemWidget::RebuildWidget()
{
	if (!ItemSettings->Asset) {
		ItemSettings->Asset = Inventory->GetItem(Index).ItemAsset;
	}

	FDetailsViewArgs DetailsViewArgs;

	DetailsViewArgs.bCustomNameAreaLocation = true;
	DetailsViewArgs.bUpdatesFromSelection = false;
	DetailsViewArgs.bLockable = false;
	DetailsViewArgs.bAllowSearch = false;
	DetailsViewArgs.bShowPropertyMatrixButton = false;
	DetailsViewArgs.NameAreaSettings = FDetailsViewArgs::ObjectsUseNameArea;
	DetailsViewArgs.bShowCustomFilterOption = false;
	DetailsViewArgs.bShowOptions = false;
	DetailsViewArgs.bShowScrollBar = false;
	
	TSharedPtr<IDetailsView> MyDetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);
 	MyDetailsView->SetObject(ItemSettings);
	
	MyDetailsView->OnFinishedChangingProperties().AddUObject(this, &UMenuContextItemWidget::OnChangingProperties);

	return SNew(SBox)[
		MyDetailsView.ToSharedRef()
	];
}