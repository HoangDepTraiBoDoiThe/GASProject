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

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	UPROPERTY(ReplicatedUsing = OnRep_HitPoint, BlueprintReadOnly, Category = Attribute)
	FGameplayAttributeData HitPoint;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, HitPoint)
	
	UFUNCTION()
	void OnRep_HitPoint(const FGameplayAttributeData OldValue) const;
};
