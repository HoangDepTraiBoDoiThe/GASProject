// Copyright Hoang Dep Trai Bo Doi The


#include "..\Public\GASGameplayTags.h"
#include "GameplayTagsManager.h"


void FGASGameplayTags::InitializeGASGameplayTags()
{
	/*
	 *	Vital attributes
	 */
	GASGameplayTags.Attribute_Vital_HitPoint = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Vital.HitPoint"), FString("Numeric representation of a character's life force, indicating the amount of damage they can endure before succumbing to defeat."));

	GASGameplayTags.Attribute_Vital_Mana = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Vital.Mana"), FString("Magical energy or power, associated with casting spells or performing supernatural actions like casting spells"));
	/*
	*	Primary attributes
	*/
	GASGameplayTags.Attribute_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Primary.Intelligence"), FString("Directly affect maximum mana and mana regeneration."));

	GASGameplayTags.Attribute_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Primary.Strength"), FString("Influence physical power."));

	GASGameplayTags.Attribute_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Primary.Resilience"), FString("Impacts the character's resistances, including 'Armor' and 'Armor penetration.'"));

	GASGameplayTags.Attribute_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Primary.Vigor"), FString("Impacts the character's 'Maximum HitPoint' and 'Heal Regeneration.'"));

	/*
	*	Secondary attributes
	*/
	GASGameplayTags.Attribute_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Secondary.Armor"), FString("Impacted by 'Resilience'. Reduces damage taken. Improve 'Block Chance' and 'Critical Hit Res'."));
	
	GASGameplayTags.Attribute_Secondary_ArmorPenetration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Secondary.ArmorPenetration"), FString("Impacted by 'Resilience'. Ignore percentage of enemy 'Armor'. Increases 'Critical Hit Chance'."));
	
	GASGameplayTags.Attribute_Secondary_BlockChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Secondary.BlockChance"), FString("Impacted by 'Armor'. Chance to cut damage in half"));	

	GASGameplayTags.Attribute_Secondary_CriticalHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Secondary.CriticalHitChance"), FString("Impacted by 'ArmorPenetration'. Chance to double plus Critical Hit bonus."));	

	GASGameplayTags.Attribute_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Secondary.CriticalHitDamage"), FString("Impacted by 'ArmorPenetration'. Chance to plus damage."));	

	GASGameplayTags.Attribute_Secondary_CriticalHitResistance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Secondary.CriticalHitResistance"), FString("Impacted by 'Armor'. Reduces the critical hit chance of attacking enemies."));	

	GASGameplayTags.Attribute_Secondary_HealthRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Secondary.HealthRegeneration"), FString("Impacted by 'Vigor'. Amount of 'HitPoint' regenerated every 1 second"));
	
	GASGameplayTags.Attribute_Secondary_ManaRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Secondary.ManaRegeneration"), FString("Impacted by 'Intelligence'. Amount of 'Mana' regenerated every 1 second"));	

	GASGameplayTags.Attribute_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Secondary.MaxMana"), FString("Impacted by 'Intelligence'. Maximum amount of 'Mana' obtainable"));	

	GASGameplayTags.Attribute_Secondary_MaxHitPoint = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Secondary.MaxHitPoint"), FString("Impacted by 'Vigor'. Maximum amount of 'Hit Point' obtainable"));	



	
}
