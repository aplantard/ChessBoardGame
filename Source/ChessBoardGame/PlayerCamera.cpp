// Fill out your copyright notice in the Description page of Project Settings.
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "PlayerCamera.h"

// Sets default values
APlayerCamera::APlayerCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("mainCamera"));
	RootComponent = PlayerCamera;
	

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer())
		{
			if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				if (!InputMapping.IsNull())
				{
					InputSystem->AddMappingContext(InputMapping.LoadSynchronous(), 0);
				}
			}
		}
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

	UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);

	Input->BindAction(IA_Camera_Move::, ETriggerEvent::Triggered, this, &APlayerCamera::Move);
}

void APlayerCamera::Move(const FInputActionValue& Value)
{	
	FVector ForwardVector = GetActorForwardVector();
	AddMovementInput(ForwardVector, Value);
}

