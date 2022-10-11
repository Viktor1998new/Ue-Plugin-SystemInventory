// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameFramework/Actor.h"
#include "ItemActor.generated.h"

USTRUCT(BlueprintType)
struct INVENTORY_API FItemData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|ItemActor|Slot")
		FText NameItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|ItemActor|Slot")
		UTexture2D* ImageItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|ItemActor|Slot")
		FIntPoint SizeSlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|ItemActor|Slot")
		float MassItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|ItemActor|Slot")
		bool StackItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|ItemActor|Slot")
		bool NoneData = false;
};

UCLASS(BlueprintType, Blueprintable)
class INVENTORY_API UItemAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ItemAsset")
		TSubclassOf<AItemActor> ClassItemActor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ItemAsset")
		FItemData SlotItemData;
	 
};

UCLASS(abstract, BlueprintType)
class INVENTORY_API AItemActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ExposeOnSpawn = "true"), Category = "ItemActor")
		UItemAsset* ItemAsset;

	// Sets default values for this actor's properties
	AItemActor();

	UFUNCTION(BlueprintCallable, Category = "ItemActor")
		virtual void SetData(const FString &NewData);

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "InitData"), Category = "ItemActor")
		void ReceiveInitData(const FString& Data);

	UFUNCTION(BlueprintCallable, Category = "ItemActor")
		virtual FString GetData();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "GetData"), Category = "ItemActor")
		void ReceiveGetData(FString& Data);
};
