// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputModifiers.h"
#include "InputModifierMouseOnEdge.generated.h"

/**
 * 
 */
UCLASS()
class CHESSBOARDGAME_API UInputModifierMouseOnEdge : public UInputModifier
{
	GENERATED_BODY()
	
	virtual FInputActionValue ModifyRaw_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue CurrentValue, float DeltaTime) override;
};
