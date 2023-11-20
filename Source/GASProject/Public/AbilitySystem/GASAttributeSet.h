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

UCLASS()
class GASPROJECT_API UGASAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UGASAttributeSet();
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Strength)
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Intelligent);
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Vigor)
	
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxHitPoint)
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, HitPoint)
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Mana)
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxMana)

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

#pragma region Primary attributes

	UPROPERTY(ReplicatedUsing = OnRep_Strength, BlueprintReadOnly, EditAnywhere)
	FGameplayAttributeData Strength;

	UPROPERTY(ReplicatedUsing = OnRep_Intellegence, EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData Intelligent;

	UPROPERTY(ReplicatedUsing = OnRep_Vigor, EditAnywhere, BlueprintReadOnly)
	FGameplayAttributeData Vigor;

	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength);
	UFUNCTION()
	void OnRep_Intelligent(const FGameplayAttributeData& OldIntelligent);
	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& OldVigor);
	
#pragma endregion Primary attributes
	
#pragma region Vital attributes
	UPROPERTY(ReplicatedUsing = OnRep_HitPoint, BlueprintReadOnly, Category = Attribute)
	FGameplayAttributeData HitPoint;
	UPROPERTY(ReplicatedUsing = OnRep_MaxHitPoint)
	FGameplayAttributeData MaxHitPoint;

	UPROPERTY(ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;
	UPROPERTY(ReplicatedUsing = OnRep_MaxMana)
	FGameplayAttributeData MaxMana;

	UFUNCTION()
	void OnRep_HitPoint(const FGameplayAttributeData& OldHitPoint) const;
	UFUNCTION()
	void OnRep_MaxHitPoint(const FGameplayAttributeData& OldMaxHitPoint) const;
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana);
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana);
#pragma endregion Vital attributes

};
