// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TANKTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTANKTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Rotation(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere)
		float DegRotationPerSecond = 20.;
};
