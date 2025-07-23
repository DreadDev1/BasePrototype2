// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePlayerController.h"
#include "ThirdPersonController.generated.h"

class ABaseCharacter;

UCLASS()
class BASEPROTOTYPE_API AThirdPersonController : public ABasePlayerController
{
	GENERATED_BODY()
	AThirdPersonController();

public:

protected:
	virtual void SetupInputComponent() override;
	virtual void Tick(float DeltaSeconds) override;
	void TraceForItem();
	void TraceForCharacter();
	UPROPERTY(EditDefaultsOnly, Category = "Base Prototype|TraceChannels")
	double TraceLength;
	TScriptInterface<IHighlightInterface> ThisActor;
	TScriptInterface<IHighlightInterface> LastActor;
	// Character trace variables
	TScriptInterface<IHighlightInterface> ThisCharacter;
	TScriptInterface<IHighlightInterface> LastCharacter;

private:

	void Interact();
	UPROPERTY(EditDefaultsOnly, Category = "Base Prototype|Inputs|Input Actions")
	TObjectPtr<UInputAction> InteractAction;
};
