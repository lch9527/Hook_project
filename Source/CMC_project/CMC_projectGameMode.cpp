// Copyright Epic Games, Inc. All Rights Reserved.

#include "CMC_projectGameMode.h"
#include "CMC_projectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACMC_projectGameMode::ACMC_projectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
