// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomMovementComponent.h"

void UCustomMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	HookQueryParams.AddIgnoredActor(GetOwner());
}

void UCustomMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//ACameraActor
	/*FVector Start = UpdatedComponent->GetComponentLocation();
	FVector End = UpdatedComponent->GetForwardVector()*500;
	FHitResult HookHit;

	GetWorld()->LineTraceSingleByChannel(HookHit, Start, End, ECC_WorldStatic, HookQueryParams);
	if (HookHit.IsValidBlockingHit()) {
		DrawDebugSphere(GetWorld(), HookHit.Location, 10, 1, FColor::Red, false, 5, 1, 5);
	}*/
	

}

void UCustomMovementComponent::try_hook()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("World delta for current frame equals %f"), GetWorld()->TimeSeconds));
}
