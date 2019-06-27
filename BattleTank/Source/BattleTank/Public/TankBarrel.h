// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	

public:
	void Elevation(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxDegreePerSecond = 20.;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaximunElevationDegree = 40.;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinimumElevationDegree = 0.;
};
