// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid.h"

AGrid::AGrid()
{
	FVector GridPos = GetActorLocation();

	for (int I = 0; I < SizeX; ++I)
	{
		TArray<FCell> Column;

		float PosX = ((I * CellSize) % SizeX) + (float)(CellSize / 2.f);

		for (int J = 0; J < SizeY; ++J)
		{
			float PosY = ((J * CellSize) % SizeY) + (float)(CellSize / 2.f);

			Column.Push(FCell(FVector(PosX, PosY, GridPos.Y)));
		}
		Grid.Push(Column);
	}
}

AGrid::~AGrid()
{
}

void AGrid::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	FProperty* ChangedProperty = PropertyChangedEvent.Property;

	FVector GridPos = GetActorLocation();

	if (ChangedProperty)
	{
		if (ChangedProperty->GetFName() == GET_MEMBER_NAME_STRING_CHECKED(AGrid, SizeX))
		{
			const unsigned int PreviousSizeX = Grid.Num();
			const unsigned int DiffSizeX = SizeX - PreviousSizeX;

			if (DiffSizeX > 0)
			{
				for (unsigned int I = 0; I < DiffSizeX; ++I)
				{
					TArray<FCell> Column;

					float PosX = (((PreviousSizeX + I) * CellSize) % SizeX) + (float)(CellSize / 2.f);

					for (int J = 0; J < SizeY; ++J)
					{
						float PosY = ((J * CellSize) % SizeY) + (float)(CellSize / 2.f);

						Column.Push(FCell(FVector(PosX, PosY, GridPos.Y)));
					}
					Grid.Push(Column);
				}
			}
			else
			{
				Grid.SetNum(PreviousSizeX + DiffSizeX);
			}
		}

		if (ChangedProperty->GetFName() == GET_MEMBER_NAME_STRING_CHECKED(AGrid, SizeY))
		{
			if (SizeX >= 0)
			{
				const unsigned int PreviousSizeY = Grid[0].Num();
				const unsigned int DiffSizeY = SizeY - PreviousSizeY;

				if (DiffSizeY > 0)
				{
					for (int I = 0; I < SizeX; ++I)
					{
						float PosX = ((I * CellSize) % SizeX) + (float)(CellSize / 2.f);

						for (unsigned int J = 0; J < DiffSizeY; ++J)
						{
							float PosY = (((PreviousSizeY + J) * CellSize) % SizeY) + (float)(CellSize / 2.f);
							Grid[I].Push(FCell(FVector(PosX, PosY, GridPos.Y)));
						}
					}
				}
				else
				{
					for (int I = 0; I < SizeX; ++I)
					{
						Grid[I].SetNum(PreviousSizeY + DiffSizeY);
					}
				}
			}
		}

		if (ChangedProperty->GetFName() == GET_MEMBER_NAME_STRING_CHECKED(AGrid, CellSize))
		{
			for (int I = 0; I < SizeX; ++I)
			{
				float PosX = ((I * CellSize) % SizeX) + (float)(CellSize / 2.f);

				for (int J = 0; J < SizeY; ++J)
				{
					float PosY = ((J * CellSize) % SizeY) + (float)(CellSize / 2.f);

					Grid[I][J].Position = FVector(PosX, PosY, GridPos.Y);
				}
			}
		}
	}
}
