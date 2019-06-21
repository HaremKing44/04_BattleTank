// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "Engine/World.h"
#include"Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	//called every frame
	virtual void Tick(float DeltaTime) override;

private:

	ATank* GetControlledTank() const;

	void AimTowardCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditAnywhere)
	   float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	   float CrossHairYLocation = 0.33333;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector& LookDirection, FVector& OutHitLocation) const;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.0;

};