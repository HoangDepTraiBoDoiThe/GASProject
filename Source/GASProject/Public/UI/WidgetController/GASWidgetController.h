// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "UObject/NoExportTypes.h"
#include "GASWidgetController.generated.h"

class UGASAttributeSet;
class UAttributeSet;
class UAbilitySystemComponent;
class AGASPlayerState;
class AGASPlayerController;
/**
 * 
 */
USTRUCT(BlueprintType)
struct FWidgetControllerStruct
{
	GENERATED_BODY()

	FWidgetControllerStruct() {};
	FWidgetControllerStruct(AGASPlayerController* PC, AGASPlayerState* PS, UAbilitySystemComponent* ASC,
	                       UGASAttributeSet* AS) : PlayerController(PC), PlayerState(PS), AbilitySystemComponent(ASC),
	                                            AttributeSet(AS) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<AGASPlayerController> PlayerController = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<AGASPlayerState> PlayerState = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UGASAttributeSet> AttributeSet = nullptr;	
};



UCLASS(BlueprintType, Blueprintable)
class GASPROJECT_API UGASWidgetController : public UObject
{
	GENERATED_BODY()

public:
	void InitWidgetControllerStruct(FWidgetControllerStruct NewWidgetControllerStruct);
	
	virtual void BroadCastInitProperties();
	
protected:
	FWidgetControllerStruct WidgetControllerStruct;

};
