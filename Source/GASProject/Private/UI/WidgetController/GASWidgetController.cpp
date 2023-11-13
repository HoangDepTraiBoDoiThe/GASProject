// Copyright Hoang Dep Trai Bo Doi The


#include "UI/WidgetController/GASWidgetController.h"

void UGASWidgetController::InitWidgetControllerStruct(FWidgetControllerStruct NewWidgetControllerStruct)
{
	WidgetControllerStruct = FWidgetControllerStruct(NewWidgetControllerStruct.PlayerController,
	                                                 NewWidgetControllerStruct.PlayerState,
	                                                 NewWidgetControllerStruct.AbilitySystemComponent,
	                                                 NewWidgetControllerStruct.AttributeSet);
}

void UGASWidgetController::BroadCastInitProperties()
{
}
