// Copyright Hoang Dep Trai Bo Doi The

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Character/EnemyCharacter.h"
#include "Interface/Interaction/IEnemyInterface.h"
#include "Kismet/KismetMathLibrary.h"
#include "Controller/GASPlayerController.h"

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
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(IAMove, ETriggerEvent::Triggered,this, &ThisClass::InputActionMove);
}

void AGASPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	CursorTrace();
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

	if (HitResult.GetActor())
	{
		IEnemyInterface* a = Cast<IEnemyInterface>(HitResult.GetActor());
		if (a)
		{
			//x
		}
	}

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
