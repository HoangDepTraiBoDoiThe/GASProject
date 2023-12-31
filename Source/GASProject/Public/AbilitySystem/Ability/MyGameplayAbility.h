// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "MyGameplayAbility.generated.h"

class AProjectile;
/**
 * 
 */
UCLASS()
class GASPROJECT_API UMyGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	[[nodiscard]] FGameplayTag GetStartupGameplayTag() const
	{
		return StartupGameplayTag;
	}

protected:
	UPROPERTY(EditAnywhere, Category = "Gameplay Tag")
	FGameplayTag StartupGameplayTag;

	UPROPERTY(EditAnywhere, Category = Projectile)
	TSubclassOf<AProjectile> ProjectileClass;

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	                             const FGameplayAbilityActivationInfo ActivationInfo,
	                             const FGameplayEventData* TriggerEventData) override;

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void SpawnProjectile();
};
