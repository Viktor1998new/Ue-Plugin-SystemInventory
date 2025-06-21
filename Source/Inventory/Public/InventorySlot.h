//Copyright(c) 2022 - 2025, Viktor.F.P
#pragma once
#include "CoreMinimal.h"
#include "ItemAsset.h"
#include "InventorySlot.generated.h"

USTRUCT(BlueprintType)
struct INVENTORY_API FInventorySlot
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Slot")
		UItemAsset* ItemAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Slot")
		FIntPoint PositionSlot = FIntPoint::ZeroValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Slot")
		FString ItemData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Slot")
		int32 Count = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory|Slot")
		bool IsRotate = false;
	
	UPROPERTY(BlueprintReadOnly, Category = "Inventory|Slot")
		bool IgnorePositoin = false;

	bool IsPosition(FIntPoint Position, FIntPoint Size);

	bool operator == (const FInventorySlot& A) const {

		return ItemAsset == A.ItemAsset && ItemData == A.ItemData;
	}

	void operator ++() {
		Count++;
	}

	void operator --() {
		Count--;
	}

	FIntPoint GetSize();

	FIntPoint GetSize(bool NewRotate);

	FItemData& GetData();

private:

	bool IsRang(int Value,int Pos, int Min, int Max);

};