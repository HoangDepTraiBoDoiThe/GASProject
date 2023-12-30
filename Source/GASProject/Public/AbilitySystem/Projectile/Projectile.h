// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NiagaraComponent.h"
#include "Projectile.generated.h"


class UProjectileMovementComponent;

UCLASS()
class GASPROJECT_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectile();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = Projectile)
	TObjectPtr<UNiagaraSystem> NiagaraTest;

	UPROPERTY(EditAnywhere, Category = Projectile)
	TObjectPtr<UNiagaraComponent> NiagaraComponent;
	
	UPROPERTY(EditAnywhere, Category = Projectile)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;
};
