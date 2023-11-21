// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GASCombatInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGASCombatInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GASPROJECT_API IGASCombatInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual int32 GetCharacterLevel();
};
