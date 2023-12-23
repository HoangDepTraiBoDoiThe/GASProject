// Copyright Hoang Dep Trai Bo Doi The


#include "AbilitySystem/GASAbilitySystemComponentBase.h"

void UGASAbilitySystemComponentBase::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UGASAbilitySystemComponentBase::GameplayEffectApplied);
}

void UGASAbilitySystemComponentBase::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& AbilityClasses)
{
	for (const TSubclassOf<UGameplayAbility> AbilityClass : AbilityClasses)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass);
		GiveAbilityAndActivateOnce(AbilitySpec);
	}
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
