// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TopDownController.h"

#include "Interaction/HighlightInterface.h"

void ATopDownController::BeginPlay()
{
	Super::BeginPlay();

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void ATopDownController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	CursorTraceCharacter();
	CursorTraceItem();
}

void ATopDownController::CursorTraceCharacter()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(HighlightTraceChannel, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastCharacter = ThisCharacter;
	ThisCharacter = CursorHit.GetActor();

	if (LastCharacter == nullptr)
	{
		if (ThisCharacter != nullptr)
		{
			// Case B
			ThisCharacter->HighlightActor();
		}
		else
		{
			// Case A - both are null, do nothing
		}
	}
	else // LastActor is valid
	{
		if (ThisCharacter == nullptr)
		{
			// Case C
			LastCharacter->UnHighlightActor();
		}
		else // both actors are valid
		{
			if (LastCharacter != ThisCharacter)
			{
				// Case D
				LastCharacter->UnHighlightActor();
				ThisCharacter->HighlightActor();
			}
			else
			{
				// Case E - do nothing
			}
		}
	}
}

void ATopDownController::CursorTraceItem()
{
	FHitResult CursorHitItem;
	GetHitResultUnderCursor(ItemTraceChannel, false, CursorHitItem);
	if (!CursorHitItem.bBlockingHit && LastItem == nullptr) return;
	
	LastItem = ThisItem;
	ThisItem = CursorHitItem.GetActor();


	if (LastItem == nullptr)
	{
		if (ThisItem!= nullptr)
		{
			// Case B
			ThisItem->HighlightActor();
			UE_LOG(LogTemp, Warning, TEXT("Started tracing a new Actor."))
		}
		else
		{
			
		}
	}
	else // LastActor is valid
	{
		if (ThisItem == nullptr)
		{
			// Case C
			LastItem->UnHighlightActor();
			UE_LOG(LogTemp, Warning, TEXT("Stopped tracing a new Actor."))
		}
		else // both actors are valid
		{
			if (LastItem != ThisItem)
			{
				// Case D
				LastItem->UnHighlightActor();
				ThisItem->HighlightActor();
			}
			else
			{
				// Case E - do nothing
			}
		}
	}
}
