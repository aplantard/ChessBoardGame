// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid.h"

AGrid::AGrid()
{
	Grid = (FCell*) malloc(SizeX * SizeY * sizeof(FCell));
	FVector GridPos = GetActorLocation();

	for (int I = 0; I < SizeX; ++I)
	{
		float PosX = ((I * CellSize) % SizeX) + (float)(CellSize / 2.f);

		for (int J = 0; J < SizeY; ++J)
		{
			float PosY = ((J * CellSize) % SizeY) + (float)(CellSize / 2.f);

			Grid[I][J] = FCell(FVector(PosX, PosY, GridPos.Y));
		}
	}
}

AGrid::~AGrid()
{
}
