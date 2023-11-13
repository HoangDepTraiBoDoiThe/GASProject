// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
/**
 * 
 */
UCLASS()
class GASPROJECT_API APlayerCharacter : public ACharacterBase
{
	GENERATED_BODY()

public:
	APlayerCharacter();
	virtual void BeginPlay() override;
	void SetupAbilityActorInfor();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	
protected:
	
	
	UPROPERTY(EditAnywhere, Category = "PlayerCharacter")
	UCameraComponent* PlayerCam;

	UPROPERTY(EditAnywhere, Category = "PlayerCharacter")
	USpringArmComponent* SpringArmComponent;


private:
	
};
