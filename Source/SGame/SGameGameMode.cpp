// Copyright Epic Games, Inc. All Rights Reserved.

#include "SGameGameMode.h"
#include "SGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASGameGameMode::ASGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
