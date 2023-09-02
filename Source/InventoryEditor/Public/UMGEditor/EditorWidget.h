//Copyright(c) 2022, Viktor.F.P

#pragma once

#include "CoreMinimal.h"
#include "UMG/Public/Blueprint/UserWidget.h"
#include "Input/Reply.h"
#include "EditorWidget.generated.h"

class UInventoryWidget;

UCLASS()
class INVENTORYEDITOR_API UEditorWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	bool EnableTick = true;

	TSharedPtr<class STextBlock> Text;
	TSharedPtr<class SVerticalBox> ListInventory;

	TArray<UObject*> CurrentSelectActors;

	uint8 Panel;

	TMap<AActor*,UInventoryWidget*> Inventorys;

	void AddSelect(TArray<UObject*> NewSelectActors);

	void RemoveSelect(TArray<UObject*> NewSelectActors);

	void ReleaseSlateResources(bool bReleaseChildren) override;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	FReply SwitchList();

	FReply SwitchGrid();

	TArray<UObject*> GetSelectedActors();

protected:

	TSharedPtr<class SConstraintCanvas> MyPanel;

	// UWidget interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
	
	virtual void PostRename(UObject* OldOuter, const FName OldName) override;
};
