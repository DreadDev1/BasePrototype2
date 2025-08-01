// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/EffectsActor.h"
#include "DamageArea.generated.h"

UCLASS()
class BASEPROTOTYPE_API ADamageArea : public AEffectsActor
{
	GENERATED_BODY()

public:
	ADamageArea();
	virtual void OnOverlap(AActor* TargetActor) override;
	virtual void OnEndOverlap(AActor* TargetActor) override;

protected:
	virtual void BeginPlay() override;

};
