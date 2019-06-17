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

ATank * ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerController() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	return Cast<ATank>(PlayerPawn);
}