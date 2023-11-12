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

void ACharacterBase::InitAbilityActorInfor(AActor* OwnerActor, AActor* AvatarActor)
{
	check(AbilitySystemComponent)
	AbilitySystemComponent->SetOwnerActor(OwnerActor);
	AbilitySystemComponent->SetAvatarActor(AvatarActor);
}

UAbilitySystemComponent* ACharacterBase::GetAbilitySystemComponent() const
{
}

void ACharacterBase::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
}


