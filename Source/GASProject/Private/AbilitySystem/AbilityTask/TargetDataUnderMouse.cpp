// Copyright Hoang Dep Trai Bo Doi The


#include "AbilitySystem/AbilityTask/TargetDataUnderMouse.h"

UTargetDataUnderMouse* UTargetDataUnderMouse::CreateTargetDataUnderMouse(UGameplayAbility* OwningAbility)
{
	UTargetDataUnderMouse* MyObj = NewAbilityTask<UTargetDataUnderMouse>(OwningAbility);
	return MyObj;
}

void UTargetDataUnderMouse::Activate()
{
	FHitResult HitResult;
	Ability->GetCurrentActorInfo()->PlayerController->GetHitResultUnderCursorByChannel(
		UEngineTypes::ConvertToTraceType(ECC_Visibility), true, HitResult);
	OnTargetDataReady.Broadcast(HitResult);
}

