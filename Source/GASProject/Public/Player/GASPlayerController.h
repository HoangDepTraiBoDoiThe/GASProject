// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "GASPlayerController.generated.h"

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

	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, Category= "Character")
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, Category= "Character")
	UInputAction* IAMove;

	IEnemyInterface* CurrentFrameUnderTrace;
	IEnemyInterface* LastFrameUnderTrace;

	UFUNCTION()
	void InputActionMove(const FInputActionValue& InputActionValue);
	void CursorTrace();
};
