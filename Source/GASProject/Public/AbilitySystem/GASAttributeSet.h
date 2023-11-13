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
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxHitPoint)
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, HitPoint)

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	UPROPERTY(ReplicatedUsing = OnRep_HitPoint, BlueprintReadOnly, Category = Attribute)
	FGameplayAttributeData HitPoint;

	UPROPERTY(ReplicatedUsing = OnRep_MaxHitPoint)
	FGameplayAttributeData MaxHitPoint;
	
	UFUNCTION()
	void OnRep_HitPoint(const FGameplayAttributeData OldHitPoint) const;
	UFUNCTION()
	void OnRep_MaxHitPoint(const FGameplayAttributeData OldMaxHitPoint) const;
};
