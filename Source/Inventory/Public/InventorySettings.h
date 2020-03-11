// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InventorySettings.generated.h"

/**
 * 
 */

UCLASS(config = Engine, defaultconfig)
class INVENTORY_API UInventorySettings : public UObject {

    GENERATED_UCLASS_BODY()

        virtual void PostInitProperties() override;

#if WITH_EDITOR
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

public:

    UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category = "InventorySettings")
        bool SizeSlot;

    UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category = "InventorySettings")
        bool PositionSlot;

    UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category = "InventorySettings")
        bool StackItems;

    UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category = "InventorySettings")
        bool MassItems;

    UPROPERTY(config, EditAnywhere, BlueprintReadOnly, Category = "InventorySettings")
        bool LimitSlotY;

};