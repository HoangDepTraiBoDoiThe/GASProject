// Copyright Hoang Dep Trai Bo Doi The

#include "AbilitySystem/EffectActor/GASEffectActor.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffectTypes.h"

// Sets default values
AGASEffectActor::AGASEffectActor()
{
	PrimaryActorTick.bCanEverTick = true;

	CreateDefaultSubobject<USceneComponent>("Root component");

}

void AGASEffectActor::BeginPlay()
{
	Super::BeginPlay();

	
}

void AGASEffectActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGASEffectActor::OnBeginOverlap(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffect)
{
	bool bShouldApply = InfiniteGameplayEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap ||
		HasDurationGameplayEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap ||
		InstanceGameplayEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap;
	if (!bShouldApply) return;
	
	IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(TargetActor);
	if (!AbilitySystemInterface) return;
	checkf(GameplayEffect, TEXT("EffectActor's GamePlayEffect is null"))
	
	UAbilitySystemComponent* AbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	FGameplayEffectContextHandle GameplayEffectContextHandle = AbilitySystemComponent->MakeEffectContext();
	GameplayEffectContextHandle.AddSourceObject(this);
	FGameplayEffectSpecHandle GamePlayEffectSpecHandle = AbilitySystemComponent->MakeOutgoingSpec(GameplayEffect, GamePlayEffectLevel, GameplayEffectContextHandle);
	FActiveGameplayEffectHandle ActiveGameplayEffectHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*GamePlayEffectSpecHandle.Data.Get());

	if (InfiniteGameplayEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap && GamePlayEffectSpecHandle.Data
		.Get()->Def->DurationPolicy == EGameplayEffectDurationType::Infinite)
	{
		ActiveEffectHandles.Add(AbilitySystemComponent, ActiveGameplayEffectHandle);
	}
}

void AGASEffectActor::OnEndOverlap(AActor* TargetActor)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (InfiniteGameplayEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap && IsValid(TargetASC) && ActiveEffectHandles.Num() > 0)
	{
		TArray<UAbilitySystemComponent*> RemoveAfterWork;
		for (auto& HandlePair : ActiveEffectHandles)
		{
			if (HandlePair.Key == TargetASC)
			{
				HandlePair.Key->RemoveActiveGameplayEffect(HandlePair.Value, 1);
				RemoveAfterWork.AddUnique(HandlePair.Key);
			}
		}
		RemoveAfterWork.Empty();
	}
}


