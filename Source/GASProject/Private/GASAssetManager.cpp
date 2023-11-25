// Copyright Hoang Dep Trai Bo Doi The


#include "GASAssetManager.h"

#include "GASGameplayTags.h"

const UGASAssetManager& UGASAssetManager::Get()
{
	UGASAssetManager* AssetManager = Cast<UGASAssetManager>(GEngine->AssetManager);
	return *AssetManager;
}

void UGASAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FGASGameplayTags::InitializeGASGameplayTags();
}
