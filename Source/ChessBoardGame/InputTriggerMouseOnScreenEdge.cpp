// Fill out your copyright notice in the Description page of Project Settings.


#include "InputTriggerMouseOnScreenEdge.h"
#include "Engine/World.h"

ETriggerState UInputTriggerMouseOnScreenEdge::UpdateState_Implementation(const UEnhancedPlayerInput* PlayerInput, FInputActionValue ModifiedValue, float DeltaTime)
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

			if (CursorPosOnViewportX > 0.98f || CursorPosOnViewportX < 0.02f)
			{
				return ETriggerState::Triggered;
			}

			if (CursorPosOnViewportY > 0.98f || CursorPosOnViewportY < 0.02f)
			{
				return ETriggerState::Triggered;
			}
		}
	}

	return ETriggerState::None;
}