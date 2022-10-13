//Copyright(c) 2022, Viktor.F.P
#pragma once
#include "CoreMinimal.h"
#include "UObject/Script.h"
#include "UObject/ObjectMacros.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InventoryLibrary.generated.h"

UCLASS()
class INVENTORY_API UInventoryLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    ///** Starts an analytics session without any custom attributes specified */
    UFUNCTION(BlueprintCallable, Category = "InventoryLibrary")
        static FString DataItem(TMap<FString,FString> MapDataItem);

    UFUNCTION(BlueprintCallable, Category = "InventoryLibrary")
      static TMap<FString, FString> DataItemToMap(FString DataItem);

    UFUNCTION(BlueprintCallable, Category = "InventoryLibrary")
        static TMap<FString, FString> DataItemSetValue(TMap<FString, FString> MapDataItem, FString Key, FString NewValue);
};