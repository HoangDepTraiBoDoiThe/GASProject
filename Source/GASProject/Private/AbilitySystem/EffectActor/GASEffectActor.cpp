// Copyright Hoang Dep Trai Bo Doi The

#include "AbilitySystem/EffectActor/GASEffectActor.h"

#include "AbilitySystemBlueprintLibrary.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"

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

void AGASEffectActor::ApplyGamePlayEffect2Actor(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffect)
{
	IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(TargetActor);
	if (!AbilitySystemInterface) return;
	
	checkf(GameplayEffect, TEXT("EffectActor's GamePlayEffect is null"))
	
	UAbilitySystemComponent* AbilitySystemComponent = 
		UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);

	FGameplayEffectContextHandle GameplayEffectContextHandle = AbilitySystemComponent->MakeEffectContext();
	GameplayEffectContextHandle.AddSourceObject(this);
	FGameplayEffectSpecHandle GamePlayEffectSpecHandle = AbilitySystemComponent->MakeOutgoingSpec(GameplayEffect, 1.f, GameplayEffectContextHandle);
	AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*GamePlayEffectSpecHandle.Data.Get());
}

