// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GASUserWidget.generated.h"

class UGASWidgetController;
/**
 * 
 */
UCLASS()
class GASPROJECT_API UGASUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UGASWidgetController* NewWidgetController);
	
protected:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UGASWidgetController> WidgetController;

	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
	
};
