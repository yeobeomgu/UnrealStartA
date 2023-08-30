// Copyright Epic Games, Inc. All Rights Reserved.

#include "LineTraceObjectGameMode.h"
#include "LineTraceObjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALineTraceObjectGameMode::ALineTraceObjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
