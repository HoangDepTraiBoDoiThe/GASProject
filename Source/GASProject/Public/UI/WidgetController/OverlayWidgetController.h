// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/GASWidgetController.h"
#include "OverlayWidgetController.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHitPointDelegateSignature, float, hitPoint);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMaxHitPointDelegateSignature, float, maxHitPoint);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FManaDelegateSignature, float, mana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMaxManaDelegateSignature, float, maxMana);

UCLASS()
class GASPROJECT_API UOverlayWidgetController : public UGASWidgetController
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FHitPointDelegateSignature HitPointDelegate;
	UPROPERTY(BlueprintAssignable)
	FMaxHitPointDelegateSignature MaxHitPointDelegate;

	UPROPERTY(BlueprintAssignable)
	FManaDelegateSignature ManaDelegate;
	UPROPERTY(BlueprintAssignable)
	FMaxManaDelegateSignature MaxManaDelegate;
	
	virtual void BroadCastInitProperties() override;
	
	virtual void BroadCastOnGameplayAttributeValueChange() override;
	void OnHitPointValueChange(const FOnAttributeChangeData& Data) const;
	
};
