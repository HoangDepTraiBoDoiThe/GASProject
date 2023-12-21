// Copyright Hoang Dep Trai Bo Doi The


#include "UI/Widget/GASUserWidget.h"

#include "UI/WidgetController/OverlayWidgetController.h"

void UGASUserWidget::SetWidgetController(UGASWidgetController* NewWidgetController)
{
	WidgetController = NewWidgetController;
	WidgetControllerSet();
}

