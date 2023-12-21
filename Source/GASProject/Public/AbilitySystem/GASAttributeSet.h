// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "GASAttributeSet.generated.h"

/**
 * 
 */
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

struct FGASGameplayTags;

UCLASS()
class GASPROJECT_API UGASAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UGASAttributeSet();

	TMap<FGameplayTag, TBaseStaticDelegateInstance<FGameplayAttribute(), FDefaultDelegateUserPolicy>::FFuncPtr> GameplayAttributeByTag;
	
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Strength)
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Intelligent);
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Vigor)
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Resillience)

	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxHitPoint)
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, HitPoint)
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Mana)
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxMana)
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Armor)
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, ArmorPenetration)
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, BlockChance)
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, CriticalHitChance)
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, CriticalHitDamage)
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, CriticalHitResistance)
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, HealthRegeneration)
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, ManaRegeneration)

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

#pragma region Primary attributes

	UPROPERTY(ReplicatedUsing = OnRep_Strength, BlueprintReadOnly, EditAnywhere)
	FGameplayAttributeData Strength;

	UPROPERTY(ReplicatedUsing = OnRep_Intelligent, EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData Intelligent;

	UPROPERTY(ReplicatedUsing = OnRep_Vigor, EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData Vigor;

	UPROPERTY(ReplicatedUsing = OnRep_Resillience, EditDefaultsOnly, BlueprintReadOnly)
	FGameplayAttributeData Resillience;

	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength);
	UFUNCTION()
	void OnRep_Intelligent(const FGameplayAttributeData& OldIntelligent);
	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& OldVigor);
	UFUNCTION()
	void OnRep_Resillience(const FGameplayAttributeData& OldResillience);
	
#pragma endregion Primary attributes
	
#pragma region Secondary attributes
	UPROPERTY(ReplicatedUsing = OnRep_HitPoint, BlueprintReadOnly, Category = Attribute)
	FGameplayAttributeData HitPoint;
	
	UPROPERTY(ReplicatedUsing = OnRep_MaxHitPoint)
	FGameplayAttributeData MaxHitPoint;	

	UPROPERTY(ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;	

	UPROPERTY(ReplicatedUsing = OnRep_MaxMana)
	FGameplayAttributeData MaxMana;
	
	UPROPERTY(ReplicatedUsing = OnRep_Armor, EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData Armor;

	UPROPERTY(ReplicatedUsing = OnRep_ArmorPenetration, EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData ArmorPenetration;

	UPROPERTY(ReplicatedUsing = OnRep_BlockChance, EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData BlockChance;

	UPROPERTY(ReplicatedUsing = OnRep_CriticalHitChance, EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData CriticalHitChance;

	UPROPERTY(ReplicatedUsing = OnRep_CriticalHitDamage, EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData CriticalHitDamage;

	UPROPERTY(ReplicatedUsing = OnRep_CriticalHitResistance, EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData CriticalHitResistance;

	UPROPERTY(ReplicatedUsing = OnRep_HealthRegeneration, EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData HealthRegeneration;

	UPROPERTY(ReplicatedUsing = OnRep_ManaRegeneration, EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData ManaRegeneration;
	
	UFUNCTION()
	void OnRep_HitPoint(const FGameplayAttributeData& OldHitPoint) const;
	UFUNCTION()
	void OnRep_MaxHitPoint(const FGameplayAttributeData& OldMaxHitPoint) const;
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana);
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana);
	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor);
	UFUNCTION()
	void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration);
	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance);
	UFUNCTION()
	void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance);
	UFUNCTION()
	void OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage);
	UFUNCTION()
	void OnRep_CriticalHitResistance(const FGameplayAttributeData& OlCriticalHitResistance);
	UFUNCTION()
	void OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration);
	UFUNCTION()
	void OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration);
#pragma endregion Vital attributes

};
