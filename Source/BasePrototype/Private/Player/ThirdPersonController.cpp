// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ThirdPersonController.h"

#include "EnhancedInputComponent.h"

void AThirdPersonController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &AThirdPersonController::Interact);
}

void AThirdPersonController::Interact()
{
	UE_LOG(LogTemp, Log, TEXT("Primary Interact"))
}
