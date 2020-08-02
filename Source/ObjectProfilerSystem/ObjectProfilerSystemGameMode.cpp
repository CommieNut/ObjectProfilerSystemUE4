// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ObjectProfilerSystemGameMode.h"
#include "ObjectProfilerSystemHUD.h"
#include "ObjectProfilerSystemCharacter.h"
#include "UObject/ConstructorHelpers.h"

AObjectProfilerSystemGameMode::AObjectProfilerSystemGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	// HUDClass = AObjectProfilerSystemHUD::StaticClass();
}
