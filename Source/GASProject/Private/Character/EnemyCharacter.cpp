// Copyright Hoang Dep Trai Bo Doi The


#include "Character/EnemyCharacter.h"

AEnemyCharacter::AEnemyCharacter()
{
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyCharacter::HighlightEnemy()
{
	DrawDebugCapsule(GetWorld(), GetActorLocation(), 5.f, 20.f, GetActorRotation().Quaternion(), FColor::Red);
	UE_LOG(LogTemp, Warning, TEXT("HithtLighting"))
}

void AEnemyCharacter::UnHighlightEnemy()
{
}
