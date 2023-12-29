// Copyright Hoang Dep Trai Bo Doi The

#include "Player/GASPlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "NavigationPath.h"
#include "NavigationSystem.h"
#include "AbilitySystem/GASAbilitySystemComponentBase.h"
#include "AbilitySystem/GASAttributeSet.h"
#include "Character/PlayerCharacter.h"
#include "Components/SplineComponent.h"
#include "Input/GASEnhancedInputComponent.h"
#include "Interface/Interaction/IEnemyInterface.h"

class AGASPlayerState;

AGASPlayerController::AGASPlayerController()
{
	Spline = CreateDefaultSubobject<USplineComponent>("Spline");
}

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
	EnhancedInputComponent->BindCustomInputs(InputDataAsset, this, &ThisClass::InputPressedFunc,
	                                         &ThisClass::InputReleasedFunc, &ThisClass::InputHeldFunc);
}

void AGASPlayerController::InputPressedFunc(FGameplayTag GameplayTag)
{
	if (GameplayTag.MatchesTagExact(FGASGameplayTags::Get().Control_LMB))
	{
		bTargeting = CurrentFrameUnderTrace ? true : false;
		bAutoRunning = false;
	}
}

void AGASPlayerController::InputReleasedFunc(FGameplayTag GameplayTag)
{
	if (!isASC_Valid()) return;
	if (!GameplayTag.MatchesTagExact(FGASGameplayTags::Get().Control_LMB))
	{
		ASC->AbilityInputHeld(GameplayTag);
		return;
	}

	if (FollowTime <= ShortPressThreshold)
	{
		if (MouseTraceResult.bBlockingHit)
		{
			if (UNavigationPath* NavigationPath = UNavigationSystemV1::FindPathToLocationSynchronously(this, GetPlayerCharacter()->GetActorLocation(), MouseTraceResult.ImpactPoint))
			{
				Spline->ClearSplinePoints();
				for (FVector& Point : NavigationPath->PathPoints)
				{
					Spline->AddSplinePoint(Point, ESplineCoordinateSpace::World);
					DrawDebugCapsule(GetWorld(), Point, 5.f, 5.f, FQuat(FRotator::ZeroRotator), FColor::Black, false, 5.f);
				}
			}
		}
	}

	FollowTime = 0;
}

void AGASPlayerController::InputHeldFunc(FGameplayTag GameplayTag)
{
	if (!isASC_Valid()) return;

	if (!GameplayTag.MatchesTagExact(FGASGameplayTags::Get().Control_LMB) || bTargeting)
	{
		ASC->AbilityInputHeld(GameplayTag);
		return;
	}

	if (MouseTraceResult.bBlockingHit)
	{
		FollowTime += GetWorld()->GetDeltaSeconds();
		CachedDestination = (MouseTraceResult.ImpactPoint - GetPlayerCharacter()->GetActorLocation()).GetSafeNormal();
		GetPawn()->AddMovementInput(CachedDestination);
	}
}

bool AGASPlayerController::isASC_Valid()
{
	if (!ASC) ASC = Cast<UGASAbilitySystemComponentBase>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn()));
	return ASC != nullptr;
}

void AGASPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	CursorTrace();
}

void AGASPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	GetPlayerCharacter()->InitAbilitySystemInfo();
	GetPlayerCharacter()->AddCharacterAbilities();
}

void AGASPlayerController::AcknowledgePossession(APawn* P)
{
	Super::AcknowledgePossession(P);

	GetPlayerCharacter()->InitAbilitySystemInfo();
}

APlayerCharacter* AGASPlayerController::GetPlayerCharacter()
{
	if (!PlayerCharacter) PlayerCharacter = CastChecked<APlayerCharacter>(GetPawn());
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
	GetHitResultUnderCursor(ECC_Visibility, false, MouseTraceResult);
	PreviousFrameUnderTrace = CurrentFrameUnderTrace;
	CurrentFrameUnderTrace = Cast<IEnemyInterface>(MouseTraceResult.GetActor());

	if (PreviousFrameUnderTrace != CurrentFrameUnderTrace)
	{
		if (PreviousFrameUnderTrace) PreviousFrameUnderTrace->UnHighlightEnemy();
		if (CurrentFrameUnderTrace) CurrentFrameUnderTrace->HighlightEnemy();
	}
	else if (CurrentFrameUnderTrace)
	{
		CurrentFrameUnderTrace->HighlightEnemy();
	}
}
