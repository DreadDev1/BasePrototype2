﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "Interaction/HighlightInterface.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class BASEPROTOTYPE_API AEnemyCharacter : public ABaseCharacter, public IHighlightInterface
{
	GENERATED_BODY()
public:
	AEnemyCharacter();

	/** Highlight Interface Implementation */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/** Highlight Interface Implementation */

protected:
	virtual void BeginPlay() override;

};
