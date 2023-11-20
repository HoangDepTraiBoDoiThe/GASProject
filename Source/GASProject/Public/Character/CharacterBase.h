// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

class UGameplayEffect;
class UGASAttributeSet;
class UAttributeSet;
class UAbilitySystemComponent;

UCLASS(Abstract)
class GASPROJECT_API ACharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ACharacterBase();

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilitySystemInfor();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual void OnRep_PlayerState() override;
	void SetDefaultAttribute(TSubclassOf<UGameplayEffect> DefaultAttributeGE, int32 Level);
	virtual void InitializeDefaultAttribute();

	int CharacterLevel{0};
	
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	TObjectPtr<UGASAttributeSet> AttributeSet;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributeClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameplayEffect> DefaultSecondaryAttributeClass;
};
