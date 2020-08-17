// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySettings.h"

UInventorySettings::UInventorySettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SizeSlot = false;
	StackItems = true;
	MassItems = false;
	LimitSlotY = true;

}

void UInventorySettings::PostInitProperties()
{
	Super::PostInitProperties();

}

#if WITH_EDITOR
void UInventorySettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	//UE_LOG(RHLogGeneral, Warning, TEXT("EditSetting"));

	if (PropertyChangedEvent.Property)
	{
		if (PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(UInventorySettings, SizeSlot) &&
			PropertyChangedEvent.ChangeType != EPropertyChangeType::Interactive)
		{
			UE_LOG(LogInventory, Warning, TEXT("Set value - WTH_SLOTSIZE"));
			// @TODO Update in-editor fog layers
		}
	}
}
#endif