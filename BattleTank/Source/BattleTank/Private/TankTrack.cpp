// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	//UE_LOG(LogTemp, Warning, TEXT("Tick Ticking"))

	//Calculate SlippageSpeed
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	//WorkOut Required Acceleration to this frame to correct
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
	//Calculate and apply sideway for (F = mass * Accleration)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; //Coz Two Tracks
	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetThrottle(float throttle)
{
	auto ForceApplied = GetForwardVector() * throttle * TrackMaxThrottleForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}