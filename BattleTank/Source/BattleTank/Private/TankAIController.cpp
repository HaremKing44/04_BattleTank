// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AIControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		//Move Towards Player Tank
		MoveToActor(PlayerTank, AcceptanceRadius);

		//Aim at the player tank
		AIControlledTank->AimAt(PlayerTank->GetActorLocation());

		//Fire at player tank if ready
		AIControlledTank->Fire();
	}
}