// Copyright Hoang Dep Trai Bo Doi The

#include "PlayerState/GASPlayerState.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/GASAbilitySystemComponentBase.h"

AGASPlayerState::AGASPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UGASAbilitySystemComponentBase>("Ability System Comp");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<UAttributeSet>("Attribute Set");
}

void AGASPlayerState::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->SetOwnerActor(this);
}
