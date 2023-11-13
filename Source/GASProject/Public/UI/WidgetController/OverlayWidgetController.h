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

UCLASS()
class GASPROJECT_API UOverlayWidgetController : public UGASWidgetController
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FHitPointDelegateSignature HitPointDelegate;
	UPROPERTY(BlueprintAssignable)
	FMaxHitPointDelegateSignature MaxHitPointDelegate;
	
	virtual void BroadCastInitProperties() override;
};
