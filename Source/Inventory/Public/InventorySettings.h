//Copyright(c) 2022 - 2025, Viktor.F.P
#pragma once
#include "Inventory.h"
#include "Misc/EngineVersionComparison.h"
#include "InventorySettings.generated.h"

#if UE_VERSION_OLDER_THAN(5, 7, 0)
    #define UE_SETTINGS_PROPERTY UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (BitmaskEnum = "EInventoryFlag"))
#else
    #define UE_SETTINGS_PROPERTY UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (BitmaskEnum = "/Script/Inventory.EInventoryFlag"))
#endif

UENUM(BlueprintType, meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class EInventoryFlag : uint8
{
    None = 0 UMETA(hidden),

    Position = 0x01 << 0,
    Size     = 0x01 << 1,
    Mass     = 0x01 << 2,
    LimitY   = 0x01 << 3,
    OnlyX    = 0x01 << 4
};

ENUM_CLASS_FLAGS(EInventoryFlag)

UCLASS(config = Engine, defaultconfig)
class INVENTORY_API UInventorySettings : public UObject {

    GENERATED_UCLASS_BODY()

        virtual void PostInitProperties() override;

#if WITH_EDITOR
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

public:

	UE_SETTINGS_PROPERTY
        int32 InventoryFlags;

    static UInventorySettings* Get() {
        return FInventoryModule::Get().GetSettings();
    }

    bool HasInventoryFlag(EInventoryFlag Contains)
    {
        return EnumHasAnyFlags<EInventoryFlag>((EInventoryFlag)InventoryFlags, Contains);
    }
};

#define HasInventoryFlag(Flag) UInventorySettings::Get()->HasInventoryFlag(Flag)