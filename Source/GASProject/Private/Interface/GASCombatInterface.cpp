// Copyright Hoang Dep Trai Bo Doi The


#include "Interface/GASCombatInterface.h"

// Add default functionality here for any IGASCombatInterface functions that are not pure virtual.
int32 IGASCombatInterface::GetCharacterLevel()
{
	return 0;
}

FVector IGASCombatInterface::GetWeaponSpawnPoint()
{
	return FVector::Zero();
}
