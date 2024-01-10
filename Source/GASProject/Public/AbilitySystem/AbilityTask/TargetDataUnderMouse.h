// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "TargetDataUnderMouse.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUnderMouseDataDelegate, const FGameplayAbilityTargetDataHandle&, TargetHitData);
/**
 * 
 */
UCLASS()
class GASPROJECT_API UTargetDataUnderMouse : public UAbilityTask
{
	GENERATED_BODY()

public:
	/* comment why we need this:
	 * This is a helper function to create a TargetDataUnderMouse that can be used in blueprints
	 */
	UFUNCTION(BlueprintCallable, Category = "Ability|Task", meta = (DisplayName = "Taget Data Under Mouse", HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
	static UTargetDataUnderMouse* CreateTargetDataUnderMouse(UGameplayAbility* OwningAbility);
	
	UPROPERTY(BlueprintAssignable)
	FUnderMouseDataDelegate OnTargetDataReady;

private:
	virtual void Activate() override;

	void SendTargetData() const;
	void OnReceiveTargetData(const FGameplayAbilityTargetDataHandle&, FGameplayTag) const;
};
