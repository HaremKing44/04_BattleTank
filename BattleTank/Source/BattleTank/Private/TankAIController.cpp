// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankAimingComponent.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);

	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		//Subscribe our local method to the Tank's Death event.
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnTankDeath);
	}
}

void ATankAIController::OnTankDeath()
{
	GetPawn()->DetachFromControllerPendingDestroy();
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

		//Fire if state is locked state
		if (AimingComponent->GetFiringState() == EFiringState::locked)
		{
			AimingComponent->Fire();  //Fire at player tank if ready
		}
	}
}


