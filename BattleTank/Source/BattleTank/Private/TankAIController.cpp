// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerController();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller does not found a Tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller found: %s"), *(PlayerTank->GetName()))
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerController())
	{
		//Move Towards Player Tank

		//Aim at the player tank
		GetAIControlledTank()->AimAt(GetPlayerController()->GetActorLocation());

		//Fire at player tank if ready
	}
}

ATank * ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerController() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	return Cast<ATank>(PlayerPawn);
}