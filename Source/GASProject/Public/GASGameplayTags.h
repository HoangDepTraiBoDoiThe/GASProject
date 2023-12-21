// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

struct FGameplayTag;
/**
 * 
 */
struct FGASGameplayTags
{
public:
	static FGASGameplayTags& Get() { return GASGameplayTags; }
	static void InitializeGASGameplayTags();

	/*
	 *	Vital attributes
	 */
	FGameplayTag Attribute_Vital_HitPoint;
	FGameplayTag Attribute_Vital_Mana;

	/*
	 *	Primary attributes
	 */
	FGameplayTag Attribute_Primary_Intelligence;
	FGameplayTag Attribute_Primary_Strength;
	FGameplayTag Attribute_Primary_Vigor;
	FGameplayTag Attribute_Primary_Resilience;
	
	/*
	 *	Secondary attributes
	 */
	FGameplayTag Attribute_Secondary_Armor;
	FGameplayTag Attribute_Secondary_ArmorPenetration;
	FGameplayTag Attribute_Secondary_BlockChance;
	FGameplayTag Attribute_Secondary_CriticalHitChance;
	FGameplayTag Attribute_Secondary_CriticalHitDamage;
	FGameplayTag Attribute_Secondary_CriticalHitResistance;
	FGameplayTag Attribute_Secondary_HealthRegeneration;
	FGameplayTag Attribute_Secondary_ManaRegeneration;
	FGameplayTag Attribute_Secondary_MaxHitPoint;
	FGameplayTag Attribute_Secondary_MaxMana;


private:
	static FGASGameplayTags GASGameplayTags;

};
