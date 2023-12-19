// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCamera.h"
#include "GameFramework/GameModeBase.h"
#include "ChessBoardGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CHESSBOARDGAME_API AChessBoardGameMode : public AGameModeBase
{
	GENERATED_BODY()

public :
	void InitGameState() override;

	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<APlayerCamera> CustomPawn;
};
