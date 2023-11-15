// Copyright Hoang Dep Trai Bo Doi The

#include "Player/GASPlayerState.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/GASAbilitySystemComponentBase.h"
#include "AbilitySystem/GASAttributeSet.h"

AGASPlayerState::AGASPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UGASAbilitySystemComponentBase>("Ability System Comp");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<UGASAttributeSet>("Attribute Set");
	AttributeSet->InitHitPoint(50.f);
	AttributeSet->InitMaxHitPoint(100.f);
	AttributeSet->InitMana(50.f);
	AttributeSet->InitMaxMana(100.f);
}

void AGASPlayerState::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->SetOwnerActor(this);
}

UAbilitySystemComponent* AGASPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
