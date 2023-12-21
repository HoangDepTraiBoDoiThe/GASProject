// Copyright Hoang Dep Trai Bo Doi The


#include "UI/HUD/GASHUD.h"

#include "Blueprint/UserWidget.h"
#include "GameFramework/Character.h"
#include "Player/GASPlayerController.h"
#include "UI/Widget/GASUserWidget.h"
#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "UI/WidgetController/GASWidgetController.h"
#include "UI/WidgetController/OverlayWidgetController.h"

void AGASHUD::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGASHUD::InitWidgetController(FWidgetControllerStruct WidgetControllerStruct)
{
	if (!GetOwningPlayerController()->IsLocalPlayerController()) return;
	checkf(OverlayProgressWidgetClass, TEXT("OverlayProgressWidgetClass is a nullptr, pls make sure to set it in the editor."))
	OverlayProgressWidget = Cast<UGASUserWidget>(CreateWidget(GetWorld(), OverlayProgressWidgetClass));
	OverlayProgressWidget->AddToViewport();

	GetOverlayWidgetController(WidgetControllerStruct);
	GetAttributeMenuWidgetController(WidgetControllerStruct);

	if (OverlayWidgetController && OverlayProgressWidget)
	{
		OverlayProgressWidget->SetWidgetController(OverlayWidgetController);
		OverlayWidgetController->BroadCastInitAttributesValue();
		OverlayWidgetController->BroadCastOnGameplayAttributeValueChange();
	}
}

UOverlayWidgetController* AGASHUD::GetOverlayWidgetController(FWidgetControllerStruct WidgetControllerStruct)
{
	if (!OverlayWidgetController)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->InitWidgetControllerStruct(WidgetControllerStruct);
		return OverlayWidgetController.Get();
	}

	return OverlayWidgetController.Get();
}

UAttributeMenuWidgetController* AGASHUD::GetAttributeMenuWidgetController(FWidgetControllerStruct WidgetControllerStruct)
{
	if (!AttributeMenuWidgetController)
	{
		AttributeMenuWidgetController = NewObject<UAttributeMenuWidgetController>(this, AttributeMenuWidgetControllerClass);
		AttributeMenuWidgetController->InitWidgetControllerStruct(WidgetControllerStruct);
		return AttributeMenuWidgetController.Get();
	}

	return AttributeMenuWidgetController.Get();
}
