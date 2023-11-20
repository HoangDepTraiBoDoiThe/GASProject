// Copyright Hoang Dep Trai Bo Doi The


#include "Character/CharacterBase.h"

#include "AbilitySystemComponent.h"

ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACharacterBase::InitAbilitySystemInfor()
{

}

UAbilitySystemComponent* ACharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ACharacterBase::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
}

void ACharacterBase::SetDefaultAttribute(TSubclassOf<UGameplayEffect> DefaultAttributeGE, int32 Level)
{
	checkf(AbilitySystemComponent, TEXT("AbilitySystemComponent not availible yet"))
	checkf(AbilitySystemComponent, TEXT("DefaultAttributeGE not valid to call"))
	FGameplayEffectContextHandle GEContextHandle = AbilitySystemComponent->MakeEffectContext();
	GEContextHandle.AddSourceObject(this);
	FGameplayEffectSpecHandle GESpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributeGE, Level, GEContextHandle);
	AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*GESpecHandle.Data.Get());
}

void ACharacterBase::InitializeDefaultAttribute()
{
	SetDefaultAttribute(DefaultSecondaryAttributeClass, CharacterLevel);
	SetDefaultAttribute(DefaultPrimaryAttributeClass, CharacterLevel);
}


