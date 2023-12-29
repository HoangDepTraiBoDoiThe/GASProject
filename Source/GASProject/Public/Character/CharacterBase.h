// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "Interface/GASCombatInterface.h"
#include "CharacterBase.generated.h"

class UGameplayAbility;
class UGameplayEffect;
class UGASAttributeSet;
class UAttributeSet;
class UAbilitySystemComponent;

UCLASS(Abstract)
class GASPROJECT_API ACharacterBase : public ACharacter, public IAbilitySystemInterface, public IGASCombatInterface
{
	GENERATED_BODY()

public:
	ACharacterBase();

	virtual void InitializeDefaultAttribute();
	virtual void AddCharacterAbilities();

	void SetAbilitySystemComponent(UAbilitySystemComponent* ASC) {AbilitySystemComponent = ASC;}
	void SetAttributeSet(UGASAttributeSet* attributeSet) {AttributeSet = attributeSet;}
	[[nodiscard]] TObjectPtr<UGASAttributeSet> GetAttributeSet() const
	{
		return AttributeSet;
	}

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilitySystemInfo();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual void OnRep_PlayerState() override;
	void SetDefaultAttribute(TSubclassOf<UGameplayEffect> DefaultAttributeGE, int32 Level);
	FORCEINLINE virtual int32 GetCharacterLevel() override {return CharacterLevel;}

	UPROPERTY(EditAnywhere, Category = "Character Properties")
	int CharacterLevel{0};
	
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	TObjectPtr<UGASAttributeSet> AttributeSet;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributeClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameplayEffect> DefaultSecondaryAttributeClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameplayEffect> DefaultVitalAttributeClass;

	UPROPERTY(EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> CharacterAbilities;
};
