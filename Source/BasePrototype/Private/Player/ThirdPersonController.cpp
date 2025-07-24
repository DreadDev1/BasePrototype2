// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ThirdPersonController.h"
#include "EnhancedInputComponent.h"
#include "Interaction/HighlightInterface.h"
#include "Kismet/GameplayStatics.h"


AThirdPersonController::AThirdPersonController()
{
	TraceLength = 500.f;
}

void AThirdPersonController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &AThirdPersonController::Interact);
}

void AThirdPersonController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	TraceForItem();
	TraceForCharacter();
}

void AThirdPersonController::TraceForItem()
{
	if (!IsValid(GEngine) || !IsValid(GEngine->GameViewport)) return;
	FVector2D ViewportSize;
	GEngine->GameViewport->GetViewportSize(ViewportSize);
	const FVector2D ViewportCenter = ViewportSize / 2.f;
	FVector TraceStart;
	FVector Forward;
	if (!UGameplayStatics::DeprojectScreenToWorld(this, ViewportCenter, TraceStart, Forward)) return;

	const FVector TraceEnd = TraceStart + Forward * TraceLength;
	FHitResult ItemHitResult;
	GetWorld()->LineTraceSingleByChannel(ItemHitResult, TraceStart, TraceEnd, ItemTraceChannel);

	LastItem = ThisItem;
	ThisItem = ItemHitResult.GetActor();

	if (ThisItem == LastItem) return;
	
	if (ThisItem)
	{
		ThisItem->HighlightActor();
	}
	
	if (LastItem)
	{
		LastItem->UnHighlightActor();
	}
}

void AThirdPersonController::TraceForCharacter()
{
	if (!IsValid(GEngine) || !IsValid(GEngine->GameViewport)) return;
	FVector2D ViewportSize;
	GEngine->GameViewport->GetViewportSize(ViewportSize);
	const FVector2D ViewportCenter = ViewportSize / 2.f;
	FVector TraceStart;
	FVector Forward;
	if (!UGameplayStatics::DeprojectScreenToWorld(this, ViewportCenter, TraceStart, Forward)) return;

	const FVector TraceEnd = TraceStart + Forward * TraceLength;
	FHitResult CharacterHitResult;
	GetWorld()->LineTraceSingleByChannel(CharacterHitResult, TraceStart, TraceEnd, HighlightTraceChannel);

	LastCharacter = ThisCharacter;
	ThisCharacter = CharacterHitResult.GetActor();

	if (ThisCharacter == LastCharacter) return;

	if (ThisCharacter)
	{
		ThisCharacter->HighlightActor();
	}

	if (LastCharacter)
	{
		LastCharacter->UnHighlightActor();
	}
}

void AThirdPersonController::Interact()
{
	UE_LOG(LogTemp, Log, TEXT("Primary Interact"))
}
