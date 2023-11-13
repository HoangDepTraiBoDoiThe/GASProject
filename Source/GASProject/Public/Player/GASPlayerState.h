// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "GASPlayerState.generated.h"

class UGASAttributeSet;
class UAttributeSet;
class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class GASPROJECT_API AGASPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AGASPlayerState();
	virtual void BeginPlay() override;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
	FORCEINLINE UGASAttributeSet* GetAttributeSet() const {return AttributeSet;}

protected:
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	TObjectPtr<UGASAttributeSet> AttributeSet;
};
