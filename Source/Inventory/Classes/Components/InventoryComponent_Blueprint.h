#pragma once
#include "CoreMinimal.h"
#include "InventoryComponent.h"
#include "InventoryComponent_Blueprint.generated.h"

UCLASS(Abstract, ClassGroup = (Inventory), meta = (BlueprintSpawnableComponent), Blueprintable, BlueprintType)
class INVENTORY_API UInventoryComponent_Blueprint : public UInventoryComponent {

	GENERATED_BODY()

public:

	virtual	bool AddSlot(FInventorySlot NewSlot, bool FindPositionSlot, int32& Index) override;

	virtual bool SetSlot(int32 Index, FInventorySlot NewValue) override;

protected:

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Add Slot"))
	bool ReceiveAddSlot(FInventorySlot NewSlot, bool FindPositionSlot, int32& Index);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Set Slot"))
	bool ReceiveSetSlot(int32 Index, FInventorySlot NewValue);
};