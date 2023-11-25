// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "GASAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class GASPROJECT_API UGASAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	static const UGASAssetManager& Get();

protected:
	virtual void StartInitialLoading();
	
};
