// Copyright Hoang Dep Trai Bo Doi The


#include "AbilitySystem/Ability/MyGameplayAbility.h"

#include "AbilitySystem/Projectile/Projectile.h"
#include "Character/PlayerCharacter.h"
#include "Kismet/KismetSystemLibrary.h"

void UMyGameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                         const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                         const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	FTransform Transform;
	Transform.SetLocation(Cast<APlayerCharacter>(GetAvatarActorFromActorInfo())->GetWeaponSpawnPoint());
	AProjectile* Projectile = GetWorld()->SpawnActorDeferred<AProjectile>(ProjectileClass, Transform, GetAvatarActorFromActorInfo(),
	                                            Cast<APawn>(GetAvatarActorFromActorInfo()));
	Projectile->FinishSpawning(Transform);
	UKismetSystemLibrary::PrintString(this, FString("Ability Activated"));
}
