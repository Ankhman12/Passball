// Copyright Epic Games, Inc. All Rights Reserved.

#include "Passball_v2GameMode.h"
#include "Passball_v2HUD.h"
#include "APassball_v2Character.h"
#include "UObject/ConstructorHelpers.h"

APassball_v2GameMode::APassball_v2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = APassball_v2HUD::StaticClass();
}
