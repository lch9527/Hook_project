// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "CustomMovementComponent.h"
#include "Components/PrimitiveComponent.h"
#include "CMC_projectCharacter.generated.h"


UCLASS(config=Game)
class ACMC_projectCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Hook, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Hook_start;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Hook, meta = (AllowPrivateAccess = "true"))
		bool Is_hooking = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Hook, meta = (AllowPrivateAccess = "true"))
		class URadialForceComponent* Hook_force;


public:
	ACMC_projectCharacter(const FObjectInitializer& ObjectInitializer);
	
	

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
			

protected:

	FCollisionQueryParams HookQueryParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectQueries;

	EObjectTypeQuery Hook_target;

	FHitResult HookHit;

	
	FHitResult* tmp_hit;

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

	virtual void Tick(float DeltaTime);
	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly)
	class UCustomMovementComponent* CustomMovementComponent;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION(BlueprintPure)
	FORCEINLINE UCustomMovementComponent * GetCustomCharacterMovement() const { return CustomMovementComponent; }



	UFUNCTION(BlueprintCallable)
		void Try_hook();

	UFUNCTION(BlueprintCallable)
		void Stop_hook();
	

};

