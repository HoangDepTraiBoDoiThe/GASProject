// Copyright Hoang Dep Trai Bo Doi The


#include "UI/HUD/GASHUD.h"

#include "Blueprint/UserWidget.h"
#include "GameFramework/Character.h"
#include "Player/GASPlayerController.h"
#include "UI/Widget/GASUserWidget.h"
#include "UI/WidgetController/GASWidgetController.h"
#include "UI/WidgetController/OverlayWidgetController.h"

void AGASHUD::BeginPlay()
{
	Super::BeginPlay();
}

void AGASHUD::InitWidgetController(FWidgetControllerStruct WidgetControllerStruct)
{
	checkf(OverlayProgressWidgetClass, TEXT("OverlayProgressWidgetClass is a nullptr, pls make sure to add it in the editor."))
	OverlayProgressWidget = Cast<UGASUserWidget>(CreateWidget(GetWorld(), OverlayProgressWidgetClass));
	OverlayProgressWidget->AddToViewport();

	WidgetController = NewObject<UOverlayWidgetController>(this, WidgetControllerClass);
	WidgetController->InitWidgetControllerStruct(WidgetControllerStruct);

	if (WidgetController && OverlayProgressWidget)
	{
		OverlayProgressWidget->SetWidgetController(WidgetController);
		WidgetController->BroadCastInitProperties();
		WidgetController->BroadCastOnGameplayAttributeValueChange();
	}
}
