// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "GASPlayerState.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class GASPROJECT_API AGASPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AGASPlayerState();
	virtual void BeginPlay() override;
	
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	TObjectPtr<UAttributeSet> AttributeSet;
};
