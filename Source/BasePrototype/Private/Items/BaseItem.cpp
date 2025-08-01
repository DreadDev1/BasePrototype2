// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/BaseItem.h"
#include "BasePrototype/BasePrototype.h"

// Sets default values
ABaseItem::ABaseItem()
{
	PrimaryActorTick.bCanEverTick = false;
	SetRootComponent(SceneComponent);
}

void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseItem::HighlightActor()
{
	ItemMesh->SetRenderCustomDepth(true);
	ItemMesh->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}
void ABaseItem::UnHighlightActor()
{
	ItemMesh->SetRenderCustomDepth(false);
}

void ABaseItem::OnOverlap(AActor* TargetActor)
{
	ApplyEffectToTarget(TargetActor, InstantGameplayEffect);
	ApplyEffectToTarget(TargetActor, DurationGameplayEffect);
}

