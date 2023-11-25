// Copyright Hoang Dep Trai Bo Doi The


#include "AbilitySystem/Data/AttributeInfo.h"

#include "GameplayTagContainer.h"

FAttributeInfoStruct UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bShouldLogNotFound) const
{
	for (const auto& AttributeInfo : AttributeInformation)
	{
		if (AttributeTag.MatchesTagExact(AttributeInfo.AttributeGameplayTag))
		{
			return AttributeInfo;
		}
	}

	if (bShouldLogNotFound)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,
		                                 FString::Printf(
			                                 TEXT("Can't find tag [%s] on attributeinfo [%s]"),
			                                 *AttributeTag.ToString(), *GetNameSafe(this)));
	}
	
	return FAttributeInfoStruct();
}
