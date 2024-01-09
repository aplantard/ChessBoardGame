// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputTriggers.h"
#include "InputTriggerMouseOnScreenEdge.generated.h"

/**
 * 
 */
UCLASS()
class CHESSBOARDGAME_API UInputTriggerMouseOnScreenEdge : public UInputTrigger
{
	GENERATED_BODY()

	UInputTriggerMouseOnScreenEdge();
	
	virtual ETriggerState UpdateState_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue ModifiedValue, float DeltaTime) override;
	virtual ETriggerType GetTriggerType_Implementation() const override { return ETriggerType::Explicit; }
};
