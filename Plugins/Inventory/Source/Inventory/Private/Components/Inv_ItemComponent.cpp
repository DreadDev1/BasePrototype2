﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Inv_ItemComponent.h"

UInv_ItemComponent::UInv_ItemComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PickupMessage = FString("E - Pick Up");
}
