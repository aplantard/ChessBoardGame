// Fill out your copyright notice in the Description page of Project Settings.


#include "ChessBoardGameMode.h"

void AChessBoardGameMode::InitGameState()
{
	Super::InitGameState();

	// Set Default pawn

	if (DefaultPawnClass == APlayerCamera::StaticClass())
	{
		DefaultPawnClass = CustomPawn;
	}
}
