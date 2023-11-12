//Copyright(c) 2022, Viktor.F.P
#include "InventoryLibrary.h"
#include "InventorySettings.h"

FString UInventoryLibrary::DataItem(TMap<FString, FString> MapDataItem){

	TArray<FString> L_ReturnValue; 

	TArray<FString> Keys;

	MapDataItem.GetKeys(Keys);

	for (FString Key : Keys) {

		TArray<FString> NewValue;

		NewValue.Add(Key);
		NewValue.Add(MapDataItem[Key]);

		L_ReturnValue.Add(FString::Join(NewValue,TEXT(":")));
	}

	return FString::Join(L_ReturnValue, TEXT(","));
}

TMap<FString, FString> UInventoryLibrary::DataItemToMap(FString DataItem) {

	TMap<FString, FString> L_ReturnValue;

	TArray<FString> SeparatedStrings;

	DataItem.ParseIntoArray(SeparatedStrings, TEXT(","), true);

	for (FString Value : SeparatedStrings) {

		TArray<FString> NewMap;

		Value.ParseIntoArray(NewMap, TEXT(":"), true);
		
		if(NewMap.IsValidIndex(1))
			L_ReturnValue.Add(NewMap[0], NewMap[1]);
	}

	return L_ReturnValue;
}

TMap<FString, FString> UInventoryLibrary::DataItemSetValue(TMap<FString, FString> MapDataItem, FString Key, FString NewValue) {

	FString * ValueKey = MapDataItem.Find(Key);

	if (ValueKey != nullptr)
		MapDataItem[Key] = NewValue;

	return MapDataItem;
}

FIntPoint UInventoryLibrary::GetSlotSize(FInventorySlot Slot)
{
	return Slot.GetSize();
}

FItemData UInventoryLibrary::GetItemData(FInventorySlot Slot)
{
	return Slot.ItemAsset->SlotItemData;
}


UInventorySettings* UInventoryLibrary::GetInventorySetting()
{
	return UInventorySettings::Get();
}