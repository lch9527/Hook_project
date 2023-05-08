// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomMovementComponent.h"

void UCustomMovementComponent::OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity)
{
	if (Is_hooking) {
		SetMovementMode(EMovementMode::MOVE_Custom, ECustomMovementMode::CMOVE_Hooking);
	}

	Super::OnMovementUpdated(DeltaSeconds, OldLocation, OldVelocity);
}

void UCustomMovementComponent::SweepAndStoreWallHits()
{
}

void UCustomMovementComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UCustomMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//ACameraActor


}

void UCustomMovementComponent::PhysCustom(float deltaTime, int32 Iterations)
{
	if (CustomMovementMode == ECustomMovementMode::CMOVE_Hooking)
	{
		PhysHooking(deltaTime, Iterations);
	}

	Super::PhysCustom(deltaTime, Iterations);


}

void UCustomMovementComponent::PhysHooking(float deltaTime, int32 Iterations)
{
		if (deltaTime < MIN_TICK_TIME)
		{
			return;
		}
		RestorePreAdditiveRootMotionVelocity();
		
		const float Friction = 2.0f;
		CalcVelocity(deltaTime, Friction, true, GetMaxBrakingDeceleration());
		ApplyRootMotionToVelocity(deltaTime);
		Iterations++;
		bJustTeleported = false;
		FVector OldLocation = UpdatedComponent->GetComponentLocation();
		// Location Change
		const FVector Adjusted = Velocity * deltaTime;
		FHitResult Hit(1.f);

		// Important!! Moves component by given Location Change and rotates by given rotation.
		// Handles penetrations.
		SafeMoveUpdatedComponent(Adjusted, UpdatedComponent->GetComponentQuat(), true, Hit);
		// If Hit.Time >= 1.f, didn't hit anything.
		if (Hit.Time < 1.f)
		{
			bool bSteppedUp = false;
			
			/* Ignore */
			if (!bSteppedUp)
			{
				// Handles blocking/physics interaction.
				HandleImpact(Hit, deltaTime, Adjusted);
				// Slides along collision. Specially important for climbing to feel good.
				SlideAlongSurface(Adjusted, (1.f - Hit.Time), Hit.Normal, Hit, true);
			}
		}
		// Velocity based on distance traveled.
		if (!bJustTeleported && !HasAnimRootMotion() && !CurrentRootMotion.HasOverrideVelocity())
		{
			Velocity = (UpdatedComponent->GetComponentLocation() - OldLocation) / deltaTime;
		}
		

}

bool UCustomMovementComponent::IsHook() const
{
	return Is_hooking;
}


