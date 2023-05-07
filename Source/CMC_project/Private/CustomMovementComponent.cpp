// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomMovementComponent.h"

void UCustomMovementComponent::OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity)
{
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


