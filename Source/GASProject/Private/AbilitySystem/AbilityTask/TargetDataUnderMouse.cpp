// Copyright Hoang Dep Trai Bo Doi The


#include "AbilitySystem/AbilityTask/TargetDataUnderMouse.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"

/* Why we need this:
 * This is a helper function to create a TargetDataUnderMouse that can be used in blueprints
 * Create a new object of this class and return it. I mean we need a instance of this class to use it right.
 */
UTargetDataUnderMouse* UTargetDataUnderMouse::CreateTargetDataUnderMouse(UGameplayAbility* OwningAbility)
{
	UTargetDataUnderMouse* MyObj = NewAbilityTask<UTargetDataUnderMouse>(OwningAbility);
	return MyObj;
}

void UTargetDataUnderMouse::Activate()
{
	if (Ability->GetCurrentActorInfo()->IsLocallyControlled())
	{
		/* Why:
		 * Send the target data to the server if we are the client and locally controlled.
		 */
		SendTargetData();
	}
	else
	{
		/* Else:
		 * Register a callback to receive the target data when it comes from the server.
		 */
		AbilitySystemComponent->AbilityTargetDataSetDelegate(Ability->GetCurrentAbilitySpecHandle(),
		                                                     GetActivationPredictionKey()).AddUObject(this, &ThisClass::OnReceiveTargetData);
		const bool bSuccess = AbilitySystemComponent->CallReplicatedTargetDataDelegatesIfSet(Ability->GetCurrentAbilitySpecHandle(), GetActivationPredictionKey());
		if (!bSuccess)
		{
			/* Why:
			 * If the target data is not set, we need to wait for it to be set.
			 */
			SetWaitingOnRemotePlayerData();
		}
	}
}

// A function that has to predict things needs a ScopedPredictionWindow for prediction to work properly. if it has this `AbilitySystemComponent->ScopedPredictionKey`
void UTargetDataUnderMouse::SendTargetData() const
{
	FScopedPredictionWindow ScopedPredictionWindow(AbilitySystemComponent.Get(), GetActivationPredictionKey());
	FHitResult HitResult;
	Ability->GetCurrentActorInfo()->PlayerController->GetHitResultUnderCursorByChannel(
		UEngineTypes::ConvertToTraceType(ECC_Visibility), true, HitResult);

	FGameplayAbilityTargetData_SingleTargetHit* Data = new FGameplayAbilityTargetData_SingleTargetHit(HitResult);
	FGameplayAbilityTargetDataHandle* DataHandle = new FGameplayAbilityTargetDataHandle(Data);

	// Send the target data to the server using a serverRPC function.
	AbilitySystemComponent->ServerSetReplicatedTargetData(Ability->GetCurrentAbilitySpecHandle(),
	                                                      GetActivationPredictionKey(),
	                                                      *DataHandle,
	                                                      FGameplayTag(),
	                                                      AbilitySystemComponent->ScopedPredictionKey);
	if (ShouldBroadcastAbilityTaskDelegates()) // To make sure if the ability is still active, etc.
	{
		OnTargetDataReady.Broadcast(*DataHandle);
	}
}

// This is called when the server Received the target data from the client.
void UTargetDataUnderMouse::OnReceiveTargetData(const FGameplayAbilityTargetDataHandle& TargetDataHandle, FGameplayTag GameplayTag) const
{
	AbilitySystemComponent->ConsumeAllReplicatedData(Ability->GetCurrentAbilitySpecHandle(), GetActivationPredictionKey()); // clear the replicated data
	if (ShouldBroadcastAbilityTaskDelegates()) // To make sure if the ability is still active, etc.
	{
		OnTargetDataReady.Broadcast(TargetDataHandle);
	}
}

