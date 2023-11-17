// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GASEffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class GASPROJECT_API AGASEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AGASEffectActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void ApplyGamePlayEffect2Actor(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffect);

};
