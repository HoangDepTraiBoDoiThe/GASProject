// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GASHUD.generated.h"

class UAttributeMenuWidgetController;
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
	TObjectPtr<UOverlayWidgetController> GetWidgetController() const {return OverlayWidgetController;}
	void InitWidgetController(FWidgetControllerStruct WidgetControllerStruct);
	UOverlayWidgetController* GetOverlayWidgetController(FWidgetControllerStruct WidgetControllerStruct);
	UAttributeMenuWidgetController* GetAttributeMenuWidgetController(FWidgetControllerStruct WidgetControllerStruct);

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<UGASUserWidget> OverlayProgressWidget;
	UPROPERTY(EditAnywhere, Category = Widget)
	TSubclassOf<UGASUserWidget> OverlayProgressWidgetClass;
	
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;
	UPROPERTY(EditAnywhere, Category = Widget)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

	UPROPERTY(EditAnywhere, Category = Widget)
	TSubclassOf<UAttributeMenuWidgetController> AttributeMenuWidgetControllerClass;
	UPROPERTY()
	TObjectPtr<UAttributeMenuWidgetController> AttributeMenuWidgetController;

};
