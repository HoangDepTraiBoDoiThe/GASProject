// Copyright Hoang Dep Trai Bo Doi The

#include "AbilitySystem/GASAbilitySystemComponentBase.h"
#include "AbilitySystem/Ability/MyGameplayAbility.h"

void UGASAbilitySystemComponentBase::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UGASAbilitySystemComponentBase::ClientRPCGameplayEffectApplied);
}

void UGASAbilitySystemComponentBase::BeginPlay()
{
	Super::BeginPlay();
}

void UGASAbilitySystemComponentBase::ClientRPCGameplayEffectApplied_Implementation(UAbilitySystemComponent* TargetASC,
														   const FGameplayEffectSpec& SourceGES,
														   FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{
	FGameplayTagContainer GameplayTagContainer;
	SourceGES.GetAllAssetTags(GameplayTagContainer);
	GameplayEffectTagsDelegate.Broadcast(GameplayTagContainer);
}

void UGASAbilitySystemComponentBase::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& AbilityClasses)
{
	for (const TSubclassOf<UGameplayAbility> AbilityClass : AbilityClasses)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass);
		if (const UMyGameplayAbility* MyGameplayAbility = Cast<UMyGameplayAbility>(AbilitySpec.Ability))
		{
			AbilitySpec.DynamicAbilityTags.AddTag(MyGameplayAbility->StartupGameplayTag);
			GiveAbility(AbilitySpec);
		}
	}
}

void UGASAbilitySystemComponentBase::AbilityInputPressed(FGameplayTag& InputTag)
{
}

void UGASAbilitySystemComponentBase::AbilityInputHeld(const FGameplayTag& InputTag)
{
	for (FGameplayAbilitySpec& spec : GetActivatableAbilities())
	{
		check(spec.Ability)
		if (!spec.DynamicAbilityTags.HasTagExact(InputTag)) continue;
		
		AbilitySpecInputPressed(spec);
		if (!spec.IsActive())
		{
			TryActivateAbility(spec.Handle);
		}
	}
}

void UGASAbilitySystemComponentBase::AbilityInputReleased(FGameplayTag& InputTag)
{
	for (FGameplayAbilitySpec& spec : GetActivatableAbilities())
	{
		check(spec.Ability)
		if (!spec.DynamicAbilityTags.HasTagExact(InputTag)) continue;
		
		if (spec.Ability->IsActive())
		{
			AbilitySpecInputReleased(spec);
		}
	}
}

