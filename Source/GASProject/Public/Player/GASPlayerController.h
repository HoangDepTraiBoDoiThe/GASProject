// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "GASGameplayTags.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "GASPlayerController.generated.h"

class UGASAbilitySystemComponentBase;
class UInputDataAsset;
class APlayerCharacter;
class IEnemyInterface;
/**
 * 
 */
class UInputAction;
class UInputMappingContext;

UCLASS()
class GASPROJECT_API AGASPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	bool isASC_Valid();
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	virtual void Tick(float DeltaSeconds) override;

	void InputPressedFunc(FGameplayTag);
	void InputReleasedFunc(FGameplayTag);
	void InputHeldFunc(FGameplayTag);
	APlayerCharacter* GetPlayerCharacter();
	UPROPERTY()
	APlayerCharacter* PlayerCharacter;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputDataAsset* InputDataAsset;
	
	UPROPERTY(EditAnywhere, Category= "Character")
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, Category= "Character")
	UInputAction* IAMove;

	IEnemyInterface* CurrentFrameUnderTrace;
	IEnemyInterface* LastFrameUnderTrace;

	UPROPERTY()
	UGASAbilitySystemComponentBase* ASC;

	UFUNCTION()
	void InputActionMove(const FInputActionValue& InputActionValue);
	void CursorTrace();
};
