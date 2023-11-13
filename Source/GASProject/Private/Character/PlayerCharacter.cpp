// Copyright Hoang Dep Trai Bo Doi The


#include "Character/PlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/GASPlayerState.h"

APlayerCharacter::APlayerCharacter()
{

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	PlayerCam = CreateDefaultSubobject<UCameraComponent>("Player Camera");
	PlayerCam->SetupAttachment(SpringArmComponent);
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	SetupAbilityActorInfor();
}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	SetupAbilityActorInfor();
}

void APlayerCharacter::SetupAbilityActorInfor()
{
	AGASPlayerState* GASPlayerState = Cast<AGASPlayerState>(GetPlayerState());
	check(GASPlayerState)
	GASPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(GASPlayerState, this);
	AbilitySystemComponent = GASPlayerState->GetAbilitySystemComponent();
	AttributeSet = GASPlayerState->GetAttributeSet();
}
