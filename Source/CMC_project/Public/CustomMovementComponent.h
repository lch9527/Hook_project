// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"

#include "CustomMovementComponent.generated.h"

UENUM(BlueprintType)
enum ECustomMovementMode
{
	CMOVE_Hooking     UMETA(DisplayName = "Hooking"),
	CMOVE_MAX		  UMETA(Hidden),
};
/**
 * 
 */
UCLASS()
class CMC_PROJECT_API UCustomMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

private:

	virtual void OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity) override;

	void SweepAndStoreWallHits();

	UPROPERTY(Category = "Character Movement: Hook", EditAnywhere)
	int CollisionCapsuleRadius = 50;

	UPROPERTY(Category = "Character Movement: Hook", EditAnywhere)
	int CollisionCapsuleHalfHeight = 72;

	TArray<FHitResult> CurrentWallHits;


	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	
};
