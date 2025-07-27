// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Controllers/OverlayWidgetController.h"

#include "AbilitySystem/Attributes/BaseAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UBaseAttributeSet* AuraAttributeSet = CastChecked<UBaseAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());
}
