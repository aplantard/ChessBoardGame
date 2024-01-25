// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

UENUM(BlueprintType)
enum CellType
{
	Square UMETA(DisplayName = "Square"),
	Hexagon UMETA(DisplayName = "Hexagon"),
	None UMETA(DisplayName = "None")
};


struct Cell
{
	FVector Position = FVector();

	FRotator Orientation = FRotator();



	Cell();

	Cell(FVector Position)

};


UCLASS()
class CHESSBOARDGAME_API Grid : public AActor
{
	GENERATED_BODY()

public:
	Grid();
	~Grid();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	unsigned int SizeX = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	unsigned int SizeX = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	unsigned int CellSize= 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	CellType Type = CellType::Square;

	void newGrid()
};
