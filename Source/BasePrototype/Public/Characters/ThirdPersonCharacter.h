// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "ThirdPersonCharacter.generated.h"

UCLASS()
class BASEPROTOTYPE_API AThirdPersonCharacter : public ABaseCharacter
{
	GENERATED_BODY()
public:
	AThirdPersonCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
protected:

private:
	void InitAbilityActorInfo();

	
};
