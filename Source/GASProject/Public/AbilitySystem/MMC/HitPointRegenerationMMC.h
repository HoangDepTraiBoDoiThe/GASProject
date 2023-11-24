// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "HitPointRegenerationMMC.generated.h"

/**
 * 
 */
UCLASS()
class GASPROJECT_API UHitPointRegenerationMMC : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
	UHitPointRegenerationMMC();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

	FGameplayEffectAttributeCaptureDefinition ArmorCaptureDefinition;
};
