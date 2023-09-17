// Copyright Epic Games, Inc. All Rights Reserved.

#include "Assets_ValidationGameMode.h"
#include "Assets_ValidationCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAssets_ValidationGameMode::AAssets_ValidationGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
