// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grid.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum ECellType
{
	Square UMETA(DisplayName = "Square"),
	Hexagon UMETA(DisplayName = "Hexagon"),
	None UMETA(DisplayName = "None")
};


struct FCell
{
	FVector Position = FVector();

	FCell() {};

	FCell(FVector Position);

};


UCLASS()
class CHESSBOARDGAME_API AGrid : public AActor
{
	GENERATED_BODY()

public:
	AGrid();
	~AGrid();

	FCell (*Grid) = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SizeX = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SizeY = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CellSize= 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TEnumAsByte<ECellType> Type = ECellType::Square;

};
