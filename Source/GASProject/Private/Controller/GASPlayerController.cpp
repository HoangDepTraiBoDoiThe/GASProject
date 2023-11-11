// Copyright Hoang Dep Trai Bo Doi The

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Controller/GASPlayerController.h"

#include "Kismet/KismetMathLibrary.h"

void AGASPlayerController::BeginPlay()
{
	Super::BeginPlay();

	bShowMouseCursor = true;
	CurrentMouseCursor = EMouseCursor::Hand;
	
}

void AGASPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputLocalPlayerSubsystem* EnhancedInputLocalPlayer = ULocalPlayer::GetSubsystem<
		UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	EnhancedInputLocalPlayer->AddMappingContext(InputMappingContext, 0);
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(IAMove, ETriggerEvent::Triggered,this, &ThisClass::InputActionMove);
}

void AGASPlayerController::InputActionMove(const FInputActionValue& InputActionValue)
{
	FVector2d Value = InputActionValue.Get<FVector2d>();

	FRotator Rotation = FRotator(0.f, GetControlRotation().Yaw, 0.f);
	FVector ForwardVector = FRotationMatrix(Rotation).GetUnitAxis(EAxis::X);
	FVector RightVector = FRotationMatrix(Rotation).GetUnitAxis(EAxis::Y);
	
	GetPawn()->AddMovementInput(ForwardVector, Value.Y);
	GetPawn()->AddMovementInput(RightVector, Value.X);
}
