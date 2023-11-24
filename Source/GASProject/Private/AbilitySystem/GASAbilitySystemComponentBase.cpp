// Copyright Hoang Dep Trai Bo Doi The


#include "AbilitySystem/GASAbilitySystemComponentBase.h"

void UGASAbilitySystemComponentBase::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UGASAbilitySystemComponentBase::GameplayEffectApplied);
}

void UGASAbilitySystemComponentBase::BeginPlay()
{
	Super::BeginPlay();

}

void UGASAbilitySystemComponentBase::GameplayEffectApplied(UAbilitySystemComponent* TargetASC, const FGameplayEffectSpec& SourceGES, FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{
	FGameplayTagContainer GameplayTagContainer;
	SourceGES.GetAllAssetTags(GameplayTagContainer);
	GameplayEffectTagsDelegate.Broadcast(GameplayTagContainer);
}
