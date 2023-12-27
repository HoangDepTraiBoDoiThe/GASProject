// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GASAbilitySystemComponentBase.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FGameplayEffectTagsDelegate, const FGameplayTagContainer&)

/**
 * 
 */
UCLASS()
class GASPROJECT_API UGASAbilitySystemComponentBase : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void AbilityActorInfoSet();
	void AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>&);
	void AbilityInputPressed(FGameplayTag& InputTag);
	void AbilityInputHeld(const FGameplayTag& InputTag);
	void AbilityInputReleased(FGameplayTag& InputTag);
	virtual void BeginPlay() override;

	FGameplayEffectTagsDelegate GameplayEffectTagsDelegate;
	
protected:
	void GameplayEffectApplied(UAbilitySystemComponent* TargetASC, const FGameplayEffectSpec& SourceGES, FActiveGameplayEffectHandle ActiveGameplayEffectHandle);

	
};
