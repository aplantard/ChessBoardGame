// Fill out your copyright notice in the Description page of Project Settings.
#include "PlayerCamera.h"

// Sets default values
APlayerCamera::APlayerCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("mainCamera"));
	RootComponent = PlayerCamera;
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

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerCamera::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerCamera::MoveRight);

}

void APlayerCamera::MoveForward(float Value)
{
	FVector ActorLocation = GetActorLocation();
	ActorLocation.X += Value;
	SetActorLocation(ActorLocation);
}

void APlayerCamera::MoveRight(float Value)
{
	FVector ActorLocation = GetActorLocation();
	ActorLocation.Y += Value;
	SetActorLocation(ActorLocation);
}

