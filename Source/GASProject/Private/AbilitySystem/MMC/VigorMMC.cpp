// Copyright Hoang Dep Trai Bo Doi The


#include "AbilitySystem/MMC/VigorMMC.h"

#include "AbilitySystem/GASAttributeSet.h"
#include "Interface/GASCombatInterface.h"

UVigorMMC::UVigorMMC()
{
	AttributeCaptureDefinition.AttributeToCapture = UGASAttributeSet::GetVigorAttribute();
	AttributeCaptureDefinition.AttributeSource = EGameplayEffectAttributeCaptureSource::Source;
	AttributeCaptureDefinition.bSnapshot = false;

	RelevantAttributesToCapture.Add(AttributeCaptureDefinition);
}

float UVigorMMC::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const FGameplayTagContainer* TargetTagContainer = Spec.CapturedTargetTags.GetAggregatedTags();
	const FGameplayTagContainer* SourceTagContainer = Spec.CapturedSourceTags.GetAggregatedTags();
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.TargetTags = TargetTagContainer;
	EvaluateParameters.SourceTags = SourceTagContainer;
	float VigorMagnitude;
	GetCapturedAttributeMagnitude(AttributeCaptureDefinition, Spec, EvaluateParameters, VigorMagnitude );

	IGASCombatInterface* Character = Cast<IGASCombatInterface>(Spec.GetContext().GetSourceObject());
	checkf(Character, TEXT("Unable to get CombatInterface in VigorMMC"))

	int CharacterLevel = Character->GetCharacterLevel();
	float BaseValue = 100.f;
	float Coefficient = 0.5f;
	
	float CalResult = VigorMagnitude * Coefficient * CharacterLevel + BaseValue;
	return CalResult;
}
