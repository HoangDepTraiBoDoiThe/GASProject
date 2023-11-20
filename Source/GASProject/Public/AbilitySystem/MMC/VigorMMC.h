// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "VigorMMC.generated.h"

/**
 * 
 */
UCLASS()
class GASPROJECT_API UVigorMMC : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
	UVigorMMC();

protected:
	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

	FGameplayEffectAttributeCaptureDefinition AttributeCaptureDefinition;
	
};
