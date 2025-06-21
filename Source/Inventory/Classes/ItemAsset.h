//Copyright(c) 2022 - 2025, Viktor.F.P

#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "ItemAsset.generated.h"

USTRUCT(BlueprintType)
struct INVENTORY_API FItemData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|ItemActor|Slot")
	FText NameItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|ItemActor|Slot")
	UTexture2D* ImageItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|ItemActor|Slot")
	FIntPoint SizeSlot = FIntPoint(1);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|ItemActor|Slot")
	float MassItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|ItemActor|Slot")
	bool StackItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|ItemActor|Slot")
	int32 MaxStack = 1;
};

UCLASS(BlueprintType, Blueprintable, meta = (ShortTooltip = "Base class for storing item information."))
class INVENTORY_API UItemAsset : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, NoClear, BlueprintReadOnly, Category = "ItemAsset", meta = (MustImplement = ItemInterface))
	TSubclassOf<AActor> ClassItemActor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ItemAsset")
	UScriptStruct* StructType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ItemAsset")
	FGameplayTagContainer Tags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ItemAsset")
	FItemData SlotItemData;

};

UINTERFACE(MinimalAPI, Blueprintable)
class UItemInterface : public UInterface
{
	GENERATED_BODY()
};

class IItemInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ItemInterface")
		void SetData(const FString& NewData);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ItemInterface")
		FString GetData() const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "ItemInterface")
		UItemAsset* GetItemAsset() const;
};

UCLASS(abstract, BlueprintType, meta = (DeprecationMessage = "Class deprecated, Please use the new API 'ItemInterface'"))
class INVENTORY_API AItemActor : public AActor, public IItemInterface
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ExposeOnSpawn = "true"), Category = "ItemActor")
	UItemAsset* ItemAsset;

	virtual UItemAsset* GetItemAsset_Implementation() const override {
		return ItemAsset;
	};
};
