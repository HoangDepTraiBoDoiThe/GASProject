// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/GASWidgetController.h"
#include "OverlayWidgetController.generated.h"

class UAttributeMenuWidgetController;
class UGASUserWidget;

USTRUCT(BlueprintType)
struct FGameplayTagRespondMessageStruct : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag MessageTag = FGameplayTag();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText Message = FText();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UGASUserWidget> MessageWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* Image = nullptr;
};

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttributeChangeValueDelegateSignature, float, NewVlue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameplayEffectMessageDataRow, FGameplayTagRespondMessageStruct, MessageDataRow);

UCLASS()
class GASPROJECT_API UOverlayWidgetController : public UGASWidgetController
{
	GENERATED_BODY()

public:
#pragma region Delegate
	UPROPERTY(BlueprintAssignable)
	FAttributeChangeValueDelegateSignature StrengthDelegate;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangeValueDelegateSignature IntelligentDelegate;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangeValueDelegateSignature VigorDelegate;
	
	UPROPERTY(BlueprintAssignable)
	FAttributeChangeValueDelegateSignature HitPointDelegate;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangeValueDelegateSignature MaxHitPointDelegate;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangeValueDelegateSignature ManaDelegate;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangeValueDelegateSignature MaxManaDelegate;

	UPROPERTY(BlueprintAssignable)
	FGameplayEffectMessageDataRow GameplayEffectMessageDataRow;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UDataTable> MessageWidgetDataTable;
	
	virtual void BroadCastInitAttributesValue() override;
	
	virtual void BroadCastOnGameplayAttributeValueChange() override;

	template<typename T>
	static T* GetDataTableRow(UDataTable* DataTable, const FGameplayTag& GameplayTag);
};

template <typename T>
T* UOverlayWidgetController::GetDataTableRow(UDataTable* DataTable, const FGameplayTag& GameplayTag)
{
	return DataTable->FindRow<T>(GameplayTag.GetTagName(), TEXT(""));
}
