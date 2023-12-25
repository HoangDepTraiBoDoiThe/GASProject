// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "GASGameplayTags.h"
#include "Engine/DataAsset.h"
#include "InputDataAsset.generated.h"

class UInputAction;

USTRUCT(BlueprintType)
struct FInputDataAssetStruct
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = Input)
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* InputAction;
};

/**
 * 
 */
UCLASS()
class GASPROJECT_API UInputDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = Input)
	TArray<FInputDataAssetStruct> FInputData;
};
