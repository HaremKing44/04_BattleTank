// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	

public:
	UFUNCTION(BlueprintCallable, Category = "Input")
		void SetThrottle(float throttle);

	UPROPERTY(EditDefaultsonly)
		float TrackMaxThrottleForce = 400000;

private:

	UTankTrack();

	virtual void BeginPlay() override;

	void ApplySidewaysForce();
	void DriveTrack();

	float CurrentThrottle = 0;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NirmalImpulse, const FHitResult& Hit);
};
