//Copyright(c) 2022 - 2024, Viktor.F.P


#include "InventorySettings.h"

UInventorySettings::UInventorySettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	InventoryFlags = uint8(EInventoryFlag::Stack | EInventoryFlag::LimitY);
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
}
#endif