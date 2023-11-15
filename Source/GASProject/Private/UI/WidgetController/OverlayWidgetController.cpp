// Copyright Hoang Dep Trai Bo Doi The


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/GASAbilitySystemComponentBase.h"
#include "AbilitySystem/GASAttributeSet.h"

void UOverlayWidgetController::BroadCastInitProperties()
{
	Super::BroadCastInitProperties();

	UGASAttributeSet* AttributeSet = Cast<UGASAttributeSet>(WidgetControllerStruct.AttributeSet);
	HitPointDelegate.Broadcast(AttributeSet->GetHitPoint());
	MaxHitPointDelegate.Broadcast(AttributeSet->GetMaxHitPoint());

	ManaDelegate.Broadcast(AttributeSet->GetMana());
	MaxManaDelegate.Broadcast(AttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BroadCastOnGameplayAttributeValueChange()
{
	UGASAbilitySystemComponentBase* AbilitySystemComponentBase = Cast<UGASAbilitySystemComponentBase>(WidgetControllerStruct.AbilitySystemComponent);
	const UGASAttributeSet* AttributeSet = Cast<UGASAttributeSet>(WidgetControllerStruct.AttributeSet);

	if (AbilitySystemComponentBase && AttributeSet)
	{
		AbilitySystemComponentBase->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHitPointAttribute()).AddUObject(this, &UOverlayWidgetController::OnHitPointValueChange);
	}
}

void UOverlayWidgetController::OnHitPointValueChange(const FOnAttributeChangeData& Data) const
{
	HitPointDelegate.Broadcast(Data.NewValue);
}
