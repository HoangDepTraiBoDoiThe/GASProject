// Copyright Hoang Dep Trai Bo Doi The


#include "Character/EnemyCharacter.h"

#include "AbilitySystem/GASAbilitySystemComponentBase.h"
#include "AbilitySystem/GASAttributeSet.h"

AEnemyCharacter::AEnemyCharacter()
{
	AbilitySystemComponent = CreateDefaultSubobject<UGASAbilitySystemComponentBase>("Ability System Comp");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<UGASAttributeSet>("Attribute Set");
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void AEnemyCharacter::InitAbilitySystemInfo()
{
}

void AEnemyCharacter::HighlightEnemy()
{
	DrawDebugCapsule(GetWorld(), GetActorLocation(), 5.f, 20.f, GetActorRotation().Quaternion(), FColor::Red);
	UE_LOG(LogTemp, Warning, TEXT("HithtLighting"))
}

void AEnemyCharacter::UnHighlightEnemy()
{
}
