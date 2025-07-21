// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePlayerController.h"
#include "ThirdPersonController.generated.h"

/**
 * 
 */
UCLASS()
class BASEPROTOTYPE_API AThirdPersonController : public ABasePlayerController
{
	GENERATED_BODY()

public:

protected:
	virtual void SetupInputComponent() override;

private:

	void Interact();
	UPROPERTY(EditDefaultsOnly, Category = "Base Prototype|Inputs|Input Actions")
	TObjectPtr<UInputAction> InteractAction;
};
