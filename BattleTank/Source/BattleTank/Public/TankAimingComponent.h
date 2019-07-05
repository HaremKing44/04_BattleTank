// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameFramework/Actor.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	locked
};

class UTankBarrel; /*Forward Declaration*/  class UTANKTurret;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Aiming Setup")
		void Initialize(UTankBarrel* BarrelToSet, UTANKTurret* TurretToSet);

public:
	void AimAt(FVector HitLocation, float LaunchSpeed);
		
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringState FiringState = EFiringState::locked;

private:
	UTankBarrel* Barrel = nullptr;
	UTANKTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
