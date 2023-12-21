// Copyright Hoang Dep Trai Bo Doi The


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "GASGameplayTags.h"
#include "AbilitySystem/GASAttributeSet.h"
#include "UI/Widget/GASUserWidget.h"

void UAttributeMenuWidgetController::BroadCastInitAttributesValue()
{
	Super::BroadCastInitAttributesValue();
	checkf(AttributeInfo, TEXT("AttributeInfo Was not availible, set it in the editor"))

	for (auto& Pair : WidgetControllerStruct.AttributeSet->GameplayAttributeByTag)
	{
		FAttributeInfoStruct Info = AttributeInfo->FindAttributeInfoForTag(Pair.Key);
		Info.AttributeValue = Pair.Value().GetNumericValue(WidgetControllerStruct.AttributeSet);
		AttributeDelegateValueChange.Broadcast(Info);
	}
}

void UAttributeMenuWidgetController::BroadCastOnGameplayAttributeValueChange()
{
	Super::BroadCastOnGameplayAttributeValueChange();

	for (auto& Pair : WidgetControllerStruct.AttributeSet->GameplayAttributeByTag)
	{
		WidgetControllerStruct.AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
			[this, Pair] (const FOnAttributeChangeData& Data)
			{
				FAttributeInfoStruct Info = AttributeInfo->FindAttributeInfoForTag(Pair.Key);
				Info.AttributeValue = Data.NewValue;
				AttributeDelegateValueChange.Broadcast(Info);
			}
		);
	}
}
