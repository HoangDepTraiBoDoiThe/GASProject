// Copyright Hoang Dep Trai Bo Doi The


#include "AbilitySystem/Projectile/Projectile.h"

#include "GameFramework/ProjectileMovementComponent.h"

AProjectile::AProjectile()
{
	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>("Niagara Component");
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile Movement Component");
	ProjectileMovementComponent->InitialSpeed = 500.f;
	ProjectileMovementComponent->MaxSpeed = 500.f;
	bReplicates = true;
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

