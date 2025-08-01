	// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/EffectsActor.h"
#include "GameFramework/Actor.h"
#include "Interaction/HighlightInterface.h"
#include "BaseItem.generated.h"

class UGameplayEffect;

UCLASS()
class BASEPROTOTYPE_API ABaseItem : public AEffectsActor, public IHighlightInterface
{
	GENERATED_BODY()

public:
	ABaseItem();
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

protected:
	virtual void BeginPlay() override;
	virtual void OnOverlap(AActor* TargetActor) override;

	/** Highlight Interface Implementation */
	UPROPERTY(EditDefaultsOnly, Category = "Base Prototype|Items|Scene")
	USceneComponent* SceneComponent;
	UPROPERTY(EditDefaultsOnly, Category = "Base Prototype|Items|Mesh")
	UStaticMeshComponent* ItemMesh;
	/** Highlight Interface Implementation */
};
