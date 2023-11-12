// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IEnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GASPROJECT_API IEnemyInterface
{
	GENERATED_BODY()

public:
	virtual void HighlightEnemy() = 0;
	virtual void UnHighlightEnemy() = 0;
};
