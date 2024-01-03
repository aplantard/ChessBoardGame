// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputTriggers.h"
#include "MouseOnScreenEdge.generated.h"

/**
 * 
 */
UCLASS()
class CHESSBOARDGAME_API UMouseOnScreenEdge : public UInputTrigger
{
	GENERATED_BODY()
	
	virtual ETriggerState UpdateState_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue ModifiedValue, float DeltaTime) override;
	virtual ETriggerType GetTriggerType_Implementation() const override { return ETriggerType::Explicit; }
};
