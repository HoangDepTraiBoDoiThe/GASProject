// Copyright Hoang Dep Trai Bo Doi The


#include "Character/PlayerCharacterAnimInstance.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

UPlayerCharacterAnimInstance::UPlayerCharacterAnimInstance()
{
	
}

void UPlayerCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if (!PawnOwner)
	{
		PawnOwner = Cast<APawn>(TryGetPawnOwner());
	}
}

void UPlayerCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	CalculateGroundSpeed();
}

void UPlayerCharacterAnimInstance::CalculateGroundSpeed()
{
	if (!Check_PlayerMovementComp()) return;
	GroundSpeed = UKismetMathLibrary::VSizeXY(CharacterMovementComponent->Velocity);
}

bool UPlayerCharacterAnimInstance::Check_PlayerMovementComp()
{
	if (PawnOwner && !CharacterMovementComponent)
	{
		CharacterMovementComponent = CastChecked<UCharacterMovementComponent>(PawnOwner->GetMovementComponent());
	}

	return IsValid(CharacterMovementComponent);
}


