// Copyright Hoang Dep Trai Bo Doi The

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UI/WidgetController/GASWidgetController.h"
#include "GASBlueprintFunctionLibrary.generated.h"

class UAttributeMenuWidgetController;
class UOverlayWidgetController;
/**
 * 
 */
UCLASS()
class GASPROJECT_API UGASBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static UOverlayWidgetController* GetOverlayWidgetController(const UObject* WorldObjectContext);
	UFUNCTION(BlueprintCallable)
	static UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const UObject* WorldObjectContext);

private:
	static FWidgetControllerStruct ConstructWidgetControllerStruct(const UObject* WorldObjectContext);
	
};
