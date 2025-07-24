// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/OverlapItems/OverlapItem.h"

#include "AbilitySystemInterface.h"
#include "AbilitySystem/Attributes/BaseAttributeSet.h"
#include "Components/SphereComponent.h"


AOverlapItem::AOverlapItem()
{
	PrimaryActorTick.bCanEverTick = false;
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void AOverlapItem::BeginPlay()
{
	Super::BeginPlay();
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AOverlapItem::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AOverlapItem::EndOverlap);
}

void AOverlapItem::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//TODO: Change this to apply a Gameplay Effect. For now, using const_cast as a hack!
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UBaseAttributeSet* BaseAttributeSet = Cast<UBaseAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UBaseAttributeSet::StaticClass()));

		UBaseAttributeSet* MutableAuraAttributeSet = const_cast<UBaseAttributeSet*>(BaseAttributeSet);
		MutableAuraAttributeSet->SetHealth(BaseAttributeSet->GetHealth() + 25.f);
		Destroy();
	}
}

void AOverlapItem::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}