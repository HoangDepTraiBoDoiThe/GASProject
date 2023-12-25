// Copyright Hoang Dep Trai Bo Doi The

#include "Player/GASPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Character/PlayerCharacter.h"
#include "Input/GASEnhancedInputComponent.h"
#include "Interface/Interaction/IEnemyInterface.h"

void AGASPlayerController::BeginPlay()
{
	Super::BeginPlay();

	bShowMouseCursor = true;
	CurrentMouseCursor = EMouseCursor::Hand;

	FInputModeGameAndUI InputModeGameAndUI;
	InputModeGameAndUI.SetHideCursorDuringCapture(false);
	InputModeGameAndUI.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(InputModeGameAndUI);
}

void AGASPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputLocalPlayerSubsystem* EnhancedInputLocalPlayer = ULocalPlayer::GetSubsystem<
		UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	EnhancedInputLocalPlayer->AddMappingContext(InputMappingContext, 0);
	UGASEnhancedInputComponent* EnhancedInputComponent = CastChecked<UGASEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(IAMove, ETriggerEvent::Triggered, this, &ThisClass::InputActionMove);
	EnhancedInputComponent->BindCustomInputs(InputDataAsset, this, &ThisClass::InputPressedFunc, &ThisClass::InputReleasedFunc, &ThisClass::InputHeldedFunc);
}

void AGASPlayerController::InputPressedFunc(FGameplayTag GameplayTag)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Black, FString::Printf(TEXT("%s"), *GameplayTag.ToString()));
}

void AGASPlayerController::InputReleasedFunc(FGameplayTag GameplayTag)
{
}

void AGASPlayerController::InputHeldedFunc(FGameplayTag GameplayTag)
{
}

void AGASPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	CursorTrace();
}

APlayerCharacter* AGASPlayerController::GetPlayerCharacter()
{
	if (!PlayerCharacter)
	{
		PlayerCharacter = CastChecked<APlayerCharacter>(GetPawn());
	}	
	return PlayerCharacter;
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

void AGASPlayerController::CursorTrace()
{
	FHitResult HitResult;
	GetHitResultUnderCursor(ECC_Visibility, false, HitResult);

	LastFrameUnderTrace = CurrentFrameUnderTrace;
	CurrentFrameUnderTrace = Cast<IEnemyInterface>(HitResult.GetActor());

	if (LastFrameUnderTrace == nullptr)
	{
		if (CurrentFrameUnderTrace)
		{
			CurrentFrameUnderTrace->HighlightEnemy();
		}
		else if (CurrentFrameUnderTrace == nullptr)
		{
			// TODO: Nothing
		}
	}
	else if (LastFrameUnderTrace)
	{
		if (CurrentFrameUnderTrace)
		{
			if (CurrentFrameUnderTrace == LastFrameUnderTrace)
			{
				CurrentFrameUnderTrace->HighlightEnemy();
			}
			else if (CurrentFrameUnderTrace != LastFrameUnderTrace)
			{
				CurrentFrameUnderTrace->HighlightEnemy();
				LastFrameUnderTrace->UnHighlightEnemy();
			}
		}
		else if (CurrentFrameUnderTrace == nullptr)
		{
			LastFrameUnderTrace->UnHighlightEnemy();
		}
	}
}
