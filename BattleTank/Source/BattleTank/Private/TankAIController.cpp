// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AIControlledTank = GetPawn();

	auto AimingComponent = AIControlledTank->FindComponentByClass<UTankAimingComponent>();

	if (PlayerTank)
	{
		//Move Towards Player Tank
		MoveToActor(PlayerTank, AcceptanceRadius);

		//Aim at the player tank
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		//Fire at player tank if ready
		AimingComponent->Fire();
	}
}