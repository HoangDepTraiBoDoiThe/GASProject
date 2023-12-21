// Copyright Hoang Dep Trai Bo Doi The


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/GASAbilitySystemComponentBase.h"
#include "AbilitySystem/GASAttributeSet.h"

void UOverlayWidgetController::BroadCastInitAttributesValue()
{
	Super::BroadCastInitAttributesValue();

	if (const UGASAttributeSet* AttributeSet = Cast<UGASAttributeSet>(WidgetControllerStruct.AttributeSet))
	{
		HitPointDelegate.Broadcast(AttributeSet->GetHitPoint());
		MaxHitPointDelegate.Broadcast(AttributeSet->GetMaxHitPoint());

		ManaDelegate.Broadcast(AttributeSet->GetMana());
		MaxManaDelegate.Broadcast(AttributeSet->GetMaxMana());
	}
}

void UOverlayWidgetController::BroadCastOnGameplayAttributeValueChange()
{
	UGASAbilitySystemComponentBase* AbilitySystemComponentBase = Cast<UGASAbilitySystemComponentBase>(
		WidgetControllerStruct.AbilitySystemComponent);
	const UGASAttributeSet* AttributeSet = Cast<UGASAttributeSet>(WidgetControllerStruct.AttributeSet);

	if (AbilitySystemComponentBase && AttributeSet)
	{
		AbilitySystemComponentBase->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetStrengthAttribute()).
		                            AddLambda(
			                            [this](const FOnAttributeChangeData& Data)
			                            {
				                            StrengthDelegate.Broadcast(Data.NewValue);
			                            }
		                            );
		AbilitySystemComponentBase->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetStrengthAttribute()).
		                            AddLambda(
			                            [this](const FOnAttributeChangeData& Data)
			                            {
				                            IntelligentDelegate.Broadcast(Data.NewValue);
			                            }
		                            );
		AbilitySystemComponentBase->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetStrengthAttribute()).
		                            AddLambda(
			                            [this](const FOnAttributeChangeData& Data)
			                            {
				                            VigorDelegate.Broadcast(Data.NewValue);
			                            }
		                            );
		AbilitySystemComponentBase->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHitPointAttribute()).
		                            AddLambda(
			                            [this](const FOnAttributeChangeData& Data)
			                            {
				                            HitPointDelegate.Broadcast(Data.NewValue);
			                            }
		                            );
		AbilitySystemComponentBase->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxHitPointAttribute()).
		                            AddLambda(
			                            [this](const FOnAttributeChangeData& Data)
			                            {
				                            MaxHitPointDelegate.Broadcast(Data.NewValue);
			                            }
		                            );
		AbilitySystemComponentBase->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetManaAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				ManaDelegate.Broadcast(Data.NewValue);
			}
		);
		AbilitySystemComponentBase->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxManaAttribute()).
		                            AddLambda(
			                            [this](const FOnAttributeChangeData& Data)
			                            {
				                            MaxManaDelegate.Broadcast(Data.NewValue);
			                            }
		                            );

		Cast<UGASAbilitySystemComponentBase>(AbilitySystemComponentBase)->GameplayEffectTagsDelegate.AddLambda(
			[this](const FGameplayTagContainer& GameplayTags)
			{
				FGameplayTag Tag2Compare = FGameplayTag::RequestGameplayTag("Message");
				for (auto& Tag : GameplayTags)
				{
					if (Tag.MatchesTag(Tag2Compare))
					{
						FGameplayTagRespondMessageStruct* Row = GetDataTableRow<FGameplayTagRespondMessageStruct>(
							MessageWidgetDataTable, Tag);
						GameplayEffectMessageDataRow.Broadcast(*Row);
					}
				}
			}
		);
	}
}
