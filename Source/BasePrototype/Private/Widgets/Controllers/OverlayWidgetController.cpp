// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Controllers/OverlayWidgetController.h"

#include "AbilitySystem/Attributes/BaseAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UBaseAttributeSet* AuraAttributeSet = CastChecked<UBaseAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UBaseAttributeSet* AuraAttributeSet = CastChecked<UBaseAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	AuraAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	AuraAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}


