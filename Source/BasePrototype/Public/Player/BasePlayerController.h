// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class BASEPROTOTYPE_API ABasePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ABasePlayerController();
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
private:

   	UPROPERTY(EditDefaultsOnly, Category = "Base Prototype|Inputs|Input Mapping Context")
   	TArray<TObjectPtr<UInputMappingContext>> DefaultIMCs;
   	
   	void Move(const FInputActionValue& InputActionValue);
    UPROPERTY(EditDefaultsOnly, Category="Base Prototype|Inputs|Input Actions")
    TObjectPtr<UInputAction> MoveAction;
    
    void Look(const FInputActionValue& InputActionValue);
    UPROPERTY(EditDefaultsOnly, Category="Base Prototype|Inputs|Input Actions")
    TObjectPtr<UInputAction> LookAction;
};
