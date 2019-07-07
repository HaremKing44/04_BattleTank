// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevation(float RelativeSpeed)
{
	//Move the barrel right amount this frame
	//Give a maximum elevation speed and frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto ElevationChange = RelativeSpeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto ClampElevation = FMath::Clamp<float>(RawNewElevation, MinimumElevationDegree, MaximunElevationDegree);

	SetRelativeRotation(FRotator(ClampElevation, 0, 0));
}