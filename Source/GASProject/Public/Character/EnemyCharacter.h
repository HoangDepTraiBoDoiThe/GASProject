// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Interface/Interaction/IEnemyInterface.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GASPROJECT_API AEnemyCharacter : public ACharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AEnemyCharacter();
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfor(AActor* OwnerActor, AActor* AvatarActor) override;

	virtual void HighlightEnemy() override;
	virtual void UnHighlightEnemy() override;
};
