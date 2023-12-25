// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "PlayerCharacter.generated.h"

class UInputDataAsset;
class AGASPlayerController;
class AGASHUD;
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
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	
protected:
	virtual void InitAbilitySystemInfo() override;
	
	UPROPERTY(EditAnywhere, Category = "PlayerCharacter")
	UCameraComponent* PlayerCam;

	UPROPERTY(EditAnywhere, Category = "PlayerCharacter")
	USpringArmComponent* SpringArmComponent;

	TObjectPtr<AGASPlayerController> GASPlayerController;
	TObjectPtr<AGASHUD> GASHud;

private:
	
};
