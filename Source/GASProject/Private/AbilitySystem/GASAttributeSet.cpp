// Copyright Hoang Dep Trai Bo Doi The


#include "AbilitySystem/GASAttributeSet.h"

#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "GASGameplayTags.h"
#include "Net/UnrealNetwork.h"

FGASGameplayTags FGASGameplayTags::GASGameplayTags;

UGASAttributeSet::UGASAttributeSet()
{
	GameplayAttributeByTag.Add(FGASGameplayTags::Get().Attribute_Primary_Vigor, GetVigorAttribute);
	GameplayAttributeByTag.Add(FGASGameplayTags::Get().Attribute_Primary_Strength, GetStrengthAttribute);
	GameplayAttributeByTag.Add(FGASGameplayTags::Get().Attribute_Primary_Intelligence, GetIntelligentAttribute);
	GameplayAttributeByTag.Add(FGASGameplayTags::Get().Attribute_Primary_Resilience, GetResillienceAttribute);
	
	GameplayAttributeByTag.Add(FGASGameplayTags::Get().Attribute_Secondary_Armor, GetArmorAttribute);
	GameplayAttributeByTag.Add(FGASGameplayTags::Get().Attribute_Secondary_ArmorPenetration, GetArmorPenetrationAttribute);
	GameplayAttributeByTag.Add(FGASGameplayTags::Get().Attribute_Secondary_BlockChance, GetBlockChanceAttribute);
	GameplayAttributeByTag.Add(FGASGameplayTags::Get().Attribute_Secondary_CriticalHitChance, GetCriticalHitChanceAttribute);
	GameplayAttributeByTag.Add(FGASGameplayTags::Get().Attribute_Secondary_CriticalHitDamage, GetCriticalHitDamageAttribute);
	GameplayAttributeByTag.Add(FGASGameplayTags::Get().Attribute_Secondary_CriticalHitResistance, GetCriticalHitResistanceAttribute);
	GameplayAttributeByTag.Add(FGASGameplayTags::Get().Attribute_Secondary_HealthRegeneration, GetHealthRegenerationAttribute);
	GameplayAttributeByTag.Add(FGASGameplayTags::Get().Attribute_Secondary_ManaRegeneration, GetManaRegenerationAttribute);
	GameplayAttributeByTag.Add(FGASGameplayTags::Get().Attribute_Secondary_MaxMana, GetMaxManaAttribute);
	GameplayAttributeByTag.Add(FGASGameplayTags::Get().Attribute_Secondary_MaxHitPoint, GetMaxHitPointAttribute);
}

void UGASAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, HitPoint, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxHitPoint, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Mana, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxMana, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Strength, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Intelligent, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Vigor, COND_None, REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Resillience, COND_None, REPNOTIFY_Always)

	
}

void UGASAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
}

void UGASAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

#pragma region Primary attributes
void UGASAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Strength, OldStrength)
}

void UGASAttributeSet::OnRep_Intelligent(const FGameplayAttributeData& OldIntelligent)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Intelligent, OldIntelligent)
}

void UGASAttributeSet::OnRep_Vigor(const FGameplayAttributeData& OldVigor)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Vigor, OldVigor)
}

void UGASAttributeSet::OnRep_Resillience(const FGameplayAttributeData& OldResillience)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Resillience, OldResillience)
}
#pragma endregion Primary attributes

#pragma region Secondary attributes
void UGASAttributeSet::OnRep_HitPoint(const FGameplayAttributeData& OldValue) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, HitPoint, OldValue)
}

void UGASAttributeSet::OnRep_MaxHitPoint(const FGameplayAttributeData& OldMaxHitPoint) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxHitPoint, OldMaxHitPoint)
}

void UGASAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Mana, OldMana)
}

void UGASAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxMana, OldMaxMana)
}

void UGASAttributeSet::OnRep_Armor(const FGameplayAttributeData& OldArmor)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Armor, OldArmor)
}

void UGASAttributeSet::OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, ArmorPenetration, OldArmorPenetration)
}

void UGASAttributeSet::OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, BlockChance, OldBlockChance)
}

void UGASAttributeSet::OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, CriticalHitChance, OldCriticalHitChance)
}

void UGASAttributeSet::OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, CriticalHitDamage, OldCriticalHitDamage)
}

void UGASAttributeSet::OnRep_CriticalHitResistance(const FGameplayAttributeData& OlCriticalHitResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, CriticalHitResistance, OlCriticalHitResistance)
}

void UGASAttributeSet::OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, HealthRegeneration, OldHealthRegeneration)
}

void UGASAttributeSet::OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, ManaRegeneration, OldManaRegeneration)
}
#pragma endregion Secondary attributes
