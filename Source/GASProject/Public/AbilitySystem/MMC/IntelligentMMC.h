// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "IntelligentMMC.generated.h"

/**
 * 
 */
UCLASS()
class GASPROJECT_API UIntelligentMMC : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

	UIntelligentMMC();

public:
	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
	FGameplayEffectAttributeCaptureDefinition IntelligentCaptureDefinition;
};
