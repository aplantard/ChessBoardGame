// Fill out your copyright notice in the Description page of Project Settings.


#include "InputModifierMouseOnEdge.h"

FInputActionValue UInputModifierMouseOnEdge::ModifyRaw_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue CurrentValue, float DeltaTime)
{
	if (IsValid(GEngine) && IsValid(GEngine->GameViewport))
	{
		FViewport* CurrentViewPort = GEngine->GameViewport->Viewport;
		FIntPoint ViewSize = CurrentViewPort->GetSizeXY();
		FIntPoint MousePos;
		CurrentViewPort->GetMousePos(MousePos);

		if (MousePos != FIntPoint::NoneValue)
		{
			FIntPoint CursorPosOnViewPort = MousePos / ViewSize;

			float CursorPosOnViewportX = (float)MousePos.X / (float)ViewSize.X;
			float CursorPosOnViewportY = (float)MousePos.Y / (float)ViewSize.Y;

			FVector CurrentInputValue = CurrentValue.Get<FVector>();

			if (CursorPosOnViewportX > 0.98f)
			{
				CurrentInputValue.X = 1;
			}
			else if (CursorPosOnViewportX < 0.02f)
			{
				CurrentInputValue.X = -1;
			}

			if (CursorPosOnViewportY > 0.98f)
			{
				CurrentInputValue.Y = -1;
			}
			else if (CursorPosOnViewportY < 0.02f)
			{
				CurrentInputValue.Y = 1;
			}

			CurrentValue = CurrentInputValue;

			return CurrentValue;
		}

		return CurrentValue;
	}

	return CurrentValue;
}