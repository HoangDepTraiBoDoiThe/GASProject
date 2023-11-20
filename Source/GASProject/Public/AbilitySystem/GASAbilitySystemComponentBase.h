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
	virtual void BeginPlay() override;

	FGameplayEffectTagsDelegate GameplayEffectTagsDelegate;
	
protected:
	void GameplayEffectApplied(UAbilitySystemComponent* TargetASC, const FGameplayEffectSpec& SourceGES, FActiveGameplayEffectHandle ActiveGameplayEffectHandle);

	
};
