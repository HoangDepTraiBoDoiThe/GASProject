// Copyright Hoang Dep Trai Bo Doi The


#include "AbilitySystem/MMC/IntelligentMMC.h"

#include "AbilitySystem/GASAttributeSet.h"

UIntelligentMMC::UIntelligentMMC()
{
	IntelligentCaptureDefinition.bSnapshot = false;
	IntelligentCaptureDefinition.AttributeSource = EGameplayEffectAttributeCaptureSource::Source;
	IntelligentCaptureDefinition.AttributeToCapture = UGASAttributeSet::GetIntelligentAttribute();

	RelevantAttributesToCapture.Add(IntelligentCaptureDefinition);
}

float UIntelligentMMC::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	FAggregatorEvaluateParameters EvaluateParameters;

	float IntelMag;
	GetCapturedAttributeMagnitude(IntelligentCaptureDefinition, Spec, EvaluateParameters, IntelMag);

	return IntelMag;
}
