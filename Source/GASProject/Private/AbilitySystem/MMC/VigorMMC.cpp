// Copyright Hoang Dep Trai Bo Doi The


#include "AbilitySystem/MMC/VigorMMC.h"

#include "AbilitySystem/GASAttributeSet.h"

UVigorMMC::UVigorMMC()
{
	AttributeCaptureDefinition.AttributeToCapture = UGASAttributeSet::GetVigorAttribute();
	AttributeCaptureDefinition.AttributeSource = EGameplayEffectAttributeCaptureSource::Source;
	AttributeCaptureDefinition.bSnapshot = false;
}

float UVigorMMC::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const FGameplayTagContainer* TargetTagContainer = Spec.CapturedTargetTags.GetAggregatedTags();
	const FGameplayTagContainer* SourceTagContainer = Spec.CapturedSourceTags.GetAggregatedTags();
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.TargetTags = TargetTagContainer;
	EvaluateParameters.SourceTags = SourceTagContainer;
	float VigorMagnitude;
	GetCapturedAttributeMagnitude(AttributeCaptureDefinition, Spec,EvaluateParameters, VigorMagnitude );

	return VigorMagnitude * 100 + 100;
}
