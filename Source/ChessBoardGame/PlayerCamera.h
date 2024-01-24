// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerCamera.generated.h"

class USpringArmComponent;
class UFloatingPawnMovement;
class UInputMappingContext;
class UCameraComponent;
class UInputAction;
struct FInputActionValue;

UCLASS()
class CHESSBOARDGAME_API APlayerCamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess="true"))
	UCameraComponent* PlayerCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UFloatingPawnMovement* FloatingPawnMovement;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	float CameraMovementSpeed = 1000.f;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	float CameraZoomSpeed = 15.f;

	UPROPERTY(EditAnywhere, Category = "Input")
	TSoftObjectPtr<UInputMappingContext> InputMapping;

	UPROPERTY(EditAnywhere, Category = "Input")
	TSoftObjectPtr<UInputAction> MoveInputAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TSoftObjectPtr<UInputAction> ZoomInputAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TSoftObjectPtr<UInputAction> RotateInputAction;

	void Move(const FInputActionValue& Value);
	void Zoom(const FInputActionValue& Value);
	void Rotate(const FInputActionValue& Value);
};
