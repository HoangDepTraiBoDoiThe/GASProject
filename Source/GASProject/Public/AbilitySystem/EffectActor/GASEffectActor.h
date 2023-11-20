// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "GASEffectActor.generated.h"

class UAbilitySystemComponent;

UENUM(BlueprintType)
enum class EEffectApplicationPolicy
{
	ApplyOnOverlap,
	ApplyOnEndOverlap,
	DoNotApply
};

UENUM(BlueprintType)
enum class EEffectRemovalPolicy
{
	RemoveOnEndOverlap,
	DoNotRemove
};

class UGameplayEffect;

UCLASS()
class GASPROJECT_API AGASEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AGASEffectActor();
	virtual void Tick(float DeltaTime) override;
	
protected:
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable)
	void OnBeginOverlap(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffect);
	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* TargetActor);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GamePlay Effect")
	TSubclassOf<UGameplayEffect> HasDurationGamePlayEffectClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GamePlay Effect")
	EEffectApplicationPolicy HasDurationGameplayEffectApplicationPolicy {EEffectApplicationPolicy::DoNotApply};
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GamePlay Effect")
	TSubclassOf<UGameplayEffect> InfiniteGamePlayEffectClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GamePlay Effect")
	EEffectApplicationPolicy InfiniteGameplayEffectApplicationPolicy {EEffectApplicationPolicy::DoNotApply};
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GamePlay Effect")
	EEffectRemovalPolicy InfiniteGameplayEffectRemovalPolicy {EEffectRemovalPolicy::DoNotRemove};
	TMap<UAbilitySystemComponent*, FActiveGameplayEffectHandle> ActiveEffectHandles;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GamePlay Effect")
	TSubclassOf<UGameplayEffect> InstanceGamePlayEffectClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GamePlay Effect")
	EEffectApplicationPolicy InstanceGameplayEffectApplicationPolicy {EEffectApplicationPolicy::DoNotApply};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GamePlay Effect")
	float GamePlayEffectLevel{1};
};
