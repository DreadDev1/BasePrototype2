﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "TopDownCharacter.generated.h"

UCLASS()
class BASEPROTOTYPE_API ATopDownCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:

	ATopDownCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
protected:

private:
	void InitAbilityActorInfo();
	
};
