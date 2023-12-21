// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Data/AttributeInfo.h"
#include "UI/WidgetController/GASWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"

class UGASUserWidget;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttributeMenuChangeValueDelegateSignature, FAttributeInfoStruct,
                                            AttributeInformation);

/**
 * 
 */
UCLASS(Blueprintable)
class GASPROJECT_API UAttributeMenuWidgetController : public UGASWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadCastInitAttributesValue() override;
	virtual void BroadCastOnGameplayAttributeValueChange() override;

	UPROPERTY(BlueprintAssignable)
	FAttributeMenuChangeValueDelegateSignature AttributeDelegateValueChange;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UAttributeInfo> AttributeInfo;

};
