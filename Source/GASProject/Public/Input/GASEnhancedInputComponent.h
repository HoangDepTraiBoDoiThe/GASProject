// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "InputDataAsset.h"
#include "GASEnhancedInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class GASPROJECT_API UGASEnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
	
public:
	template <class UserClass, typename PressedFuncType, typename ReleasedFuncType, typename HeldFuncType>
	void BindCustomInputs(const UInputDataAsset* InputDataAsset, UserClass* Object, PressedFuncType, ReleasedFuncType, HeldFuncType);
	
protected:
	
	
private:
	
};

template <class UserClass, typename PressedFuncType, typename ReleasedFuncType, typename HeldFuncType>
void UGASEnhancedInputComponent::BindCustomInputs(const UInputDataAsset* InputDataAsset, UserClass* Object, PressedFuncType PressedFunc,
	ReleasedFuncType ReleasedFunc, HeldFuncType HeldFunc)
{
	if (!InputDataAsset) return;
	for (auto& [InputTag, InputAction] : InputDataAsset->FInputData)
	{
		if (!InputTag.IsValid() || !InputAction)
			continue;
		BindAction(InputAction, ETriggerEvent::Completed, Object, ReleasedFunc, InputTag);
		BindAction(InputAction, ETriggerEvent::Triggered, Object, HeldFunc, InputTag);
		BindAction(InputAction, ETriggerEvent::Started, Object, PressedFunc, InputTag);
	}
}