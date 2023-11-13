// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GASHUD.generated.h"

class UOverlayWidgetController;
struct FWidgetControllerStruct;
class UGASWidgetController;
class UGASUserWidget;
/**
 * 
 */
UCLASS()
class GASPROJECT_API AGASHUD : public AHUD
{
	GENERATED_BODY()

public:
	TObjectPtr<UOverlayWidgetController> GetWidgetController() const {return WidgetController;}
	void InitWidgetController(FWidgetControllerStruct WidgetControllerStruct);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = Widget)
	TSubclassOf<UGASUserWidget> OverlayProgressWidgetClass;
	UPROPERTY()
	TObjectPtr<UGASUserWidget> OverlayProgressWidget;
	
	UPROPERTY(EditAnywhere, Category = Widget)
	TSubclassOf<UGASWidgetController> WidgetControllerClass;
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> WidgetController;

};
