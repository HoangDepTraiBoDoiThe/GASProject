// Copyright Hoang Dep Trai Bo Doi The


#include "AbilitySystem/GASAttributeSet.h"

#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

UGASAttributeSet::UGASAttributeSet()
{
	InitHitPoint(100.f);
}

void UGASAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, HitPoint, COND_None, REPNOTIFY_Always)

}

void UGASAttributeSet::OnRep_HitPoint(const FGameplayAttributeData OldValue) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, HitPoint, OldValue)
}
