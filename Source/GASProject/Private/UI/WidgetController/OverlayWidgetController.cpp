// Copyright Hoang Dep Trai Bo Doi The


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/GASAttributeSet.h"

void UOverlayWidgetController::BroadCastInitProperties()
{
	Super::BroadCastInitProperties();

	UGASAttributeSet* AttributeSet = Cast<UGASAttributeSet>(WidgetControllerStruct.AttributeSet);
	HitPointDelegate.Broadcast(AttributeSet->GetHitPoint());
	MaxHitPointDelegate.Broadcast(AttributeSet->GetMaxHitPoint());
}
