// Copyright Hoang Dep Trai Bo Doi The


#include "GASBlueprintFunctionLibrary.h"

#include "Kismet/GameplayStatics.h"
#include "Player/GASPlayerController.h"
#include "Player/GASPlayerState.h"
#include "UI/HUD/GASHUD.h"
#include "UI/WidgetController/GASWidgetController.h"

UOverlayWidgetController* UGASBlueprintFunctionLibrary::GetOverlayWidgetController(const UObject* WorldObjectContext)
{
	FWidgetControllerStruct WidgetControllerStruct = ConstructWidgetControllerStruct(WorldObjectContext);
	return WidgetControllerStruct.PlayerController->GetHUD<AGASHUD>()->GetOverlayWidgetController(WidgetControllerStruct);
}

UAttributeMenuWidgetController* UGASBlueprintFunctionLibrary::GetAttributeMenuWidgetController(
	const UObject* WorldObjectContext)
{
	FWidgetControllerStruct WidgetControllerStruct = ConstructWidgetControllerStruct(WorldObjectContext);
	return WidgetControllerStruct.PlayerController->GetHUD<AGASHUD>()->GetAttributeMenuWidgetController(WidgetControllerStruct);
}

FWidgetControllerStruct UGASBlueprintFunctionLibrary::ConstructWidgetControllerStruct(const UObject* WorldObjectContext)
{
	AGASPlayerController* PC = Cast<AGASPlayerController>(UGameplayStatics::GetPlayerController(WorldObjectContext, 0));
	AGASPlayerState* PS = PC->GetPlayerState<AGASPlayerState>();
	UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
	UGASAttributeSet* AS = PS->GetAttributeSet();
	FWidgetControllerStruct WidgetControllerStruct(PC, PS, ASC, AS);
	return WidgetControllerStruct;
}
