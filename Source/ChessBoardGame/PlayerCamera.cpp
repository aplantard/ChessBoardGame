// Fill out your copyright notice in the Description page of Project Settings.
#include "PlayerCamera.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"


// Sets default values
APlayerCamera::APlayerCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("springArmComponent"));
	SpringArmComponent->bDoCollisionTest = false;
	RootComponent = PlayerCamera;

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("mainCamera"));
	PlayerCamera->SetupAttachment(SpringArmComponent);

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("floatingPawnMovement"));
}

void APlayerCamera::PawnClientRestart()
{
	Super::PawnClientRestart();

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer())
		{
			if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				InputSystem->ClearAllMappings();

				if (!InputMapping.IsNull())
				{
					InputSystem->AddMappingContext(InputMapping.LoadSynchronous(), 100);
				}
			}
		}

		PlayerController->bShowMouseCursor = true;
	}
}

// Called when the game starts or when spawned
void APlayerCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
	
// Called to bind functionality to input
void APlayerCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (MoveInputAction)
	{
		Input->BindAction(MoveInputAction.LoadSynchronous(), ETriggerEvent::Triggered, this, &APlayerCamera::Move);
	}
}

void APlayerCamera::Move(const FInputActionValue& Value)
{	
	FVector MovementVector = Value.Get<FVector>();
	FVector ForwardVector = GetActorForwardVector();
	FVector RightVector = GetActorRightVector();

	FVector UpDownVector = FVector(ForwardVector.X, ForwardVector.Y, 0);
	FVector RightLeftVector = FVector(RightVector.X, RightVector.Y, 0);

	AddMovementInput(UpDownVector, MovementVector.Y * CameraMovementSpeed);
	AddMovementInput(RightLeftVector, MovementVector.X * CameraMovementSpeed);
}

