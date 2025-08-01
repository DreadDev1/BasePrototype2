﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HighlightInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UHighlightInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BASEPROTOTYPE_API IHighlightInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void HighlightActor() { };
	virtual void UnHighlightActor() { };
};
