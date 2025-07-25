// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/HUD/BaseHUD.h"
#include "Widgets/BaseUserWidget.h"

void ABaseHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
