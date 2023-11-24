// Copyright Hoang Dep Trai Bo Doi The


#include "AbilitySystem/MMC/HitPointRegenerationMMC.h"

#include "AbilitySystem/GASAttributeSet.h"
#include "Interface/GASCombatInterface.h"

UHitPointRegenerationMMC::UHitPointRegenerationMMC()
{
	ArmorCaptureDefinition.bSnapshot = false;
	ArmorCaptureDefinition.AttributeSource = EGameplayEffectAttributeCaptureSource::Source;
	ArmorCaptureDefinition.AttributeToCapture = UGASAttributeSet::GetHealthRegenerationAttribute();

	RelevantAttributesToCapture.Add(ArmorCaptureDefinition);
}

float UHitPointRegenerationMMC::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	float ResilienceMag = 0.f;
	GetCapturedAttributeMagnitude(ArmorCaptureDefinition, Spec, EvaluateParameters, ResilienceMag);

	IGASCombatInterface* Character = Cast<IGASCombatInterface>(Spec.GetContext().GetSourceObject());
	
	float Coefficient = 0.5f;
	float BaseHPRegent = 10.f;
	float CharacterLevel = Character->GetCharacterLevel();
	float CalResult = ResilienceMag * Coefficient * CharacterLevel + BaseHPRegent;
	return CalResult;
}
