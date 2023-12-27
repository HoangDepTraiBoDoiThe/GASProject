// Copyright Hoang Dep Trai Bo Doi The

#include "Player/GASPlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameplayAbilityBlueprint.h"
#include "NavigationPath.h"
#include "NavigationSystem.h"
#include "AbilitySystem/GASAbilitySystemComponentBase.h"
#include "Character/PlayerCharacter.h"
#include "Components/SplineComponent.h"
#include "Input/GASEnhancedInputComponent.h"
#include "Interface/Interaction/IEnemyInterface.h"

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
		bTargeting = CurrentEnemy ? true : false;
		bAutoRunning = false;
	}
}

void AGASPlayerController::InputReleasedFunc(FGameplayTag GameplayTag)
{
	if (!isASC_Valid()) return;
	ASC->AbilityInputReleased(GameplayTag);
	if (!GameplayTag.MatchesTagExact(FGASGameplayTags::Get().Control_LMB))
	{
		ASC->AbilityInputHeld(GameplayTag);
		return;
	}

	if (FollowTime <= ShortPressThreshold)
	{
		FHitResult HitResult;
		GetHitResultUnderCursor(ECC_Visibility, false, HitResult);
		if (HitResult.bBlockingHit)
		{
			if (UNavigationPath* NavigationPath = UNavigationSystemV1::FindPathToLocationSynchronously(this, GetPlayerCharacter()->GetActorLocation(), HitResult.ImpactPoint))
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

	FHitResult HitResult;
	GetHitResultUnderCursor(ECC_Visibility, false, HitResult);
	if (HitResult.bBlockingHit)
	{
		FollowTime += GetWorld()->GetDeltaSeconds();
		CachedDestination = (HitResult.ImpactPoint - GetPlayerCharacter()->GetActorLocation()).GetSafeNormal();
		GetPawn()->AddMovementInput(CachedDestination);
	}
}

bool AGASPlayerController::isASC_Valid()
{
	if (!ASC)
	{
		ASC = Cast<UGASAbilitySystemComponentBase>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn()));
	}
	return ASC != nullptr;
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

	IEnemyInterface* PreviousEnemy = LastFrameUnderTrace;
	CurrentEnemy = Cast<IEnemyInterface>(HitResult.GetActor());

	LastFrameUnderTrace = CurrentEnemy;

	if (PreviousEnemy != CurrentEnemy)
	{
		if (PreviousEnemy)
		{
			PreviousEnemy->UnHighlightEnemy();
		}

		if (CurrentEnemy)
		{
			CurrentEnemy->HighlightEnemy();
		}
	}
	else if (CurrentEnemy)
	{
		CurrentEnemy->HighlightEnemy();
	}
}
