// Copyright Epic Games, Inc. All Rights Reserved.

#include "Unidad5GameMode.h"
#include "Unidad5Character.h"
#include "UObject/ConstructorHelpers.h"

AUnidad5GameMode::AUnidad5GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
