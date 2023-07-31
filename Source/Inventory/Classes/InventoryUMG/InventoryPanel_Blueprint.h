//Copyright(c) 2022, Viktor.F.P

#include "InventoryPanel.h"
#include "InventoryPanel_Blueprint.generated.h"

UCLASS(Abstract, Blueprintable, BlueprintType)
class INVENTORY_API UInventoryPanel_Blueprint : public UInventoryPanel
{
	GENERATED_UCLASS_BODY()
public:
	
	virtual void SetInventory(UInventoryComponent* NewInventory) override;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "InitInventory"), Category = "InventoryPanel")
		void ReceiveInitInventory(UInventoryComponent* NewInventory);

	virtual void OnChangeSlot(int32 Index, FInventorySlot NewData, ETypeSetItem Type) override;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnChangeSlot"), Category = "InventoryPanel")
		void ReceiveOnChangeSlot(int32 Index, FInventorySlot NewData, ETypeSetItem Type);

	UFUNCTION(BlueprintCallable, Category = "InventoryPanel|Slot")
		void SetSlotMargin(UInventoryPanelSlot* ChangeSlot, FMargin NewMargin);

};