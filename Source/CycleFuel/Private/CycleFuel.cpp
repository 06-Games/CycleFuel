// Copyright Epic Games, Inc. All Rights Reserved.

#include "CycleFuel.h"
#include "CycleFuelSubsystem.h"
//#pragma optimize("", off)

#define LOCTEXT_NAMESPACE "FCycleFuelModule"
DEFINE_LOG_CATEGORY(CycleFuel);

void FCycleFuelModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	OnInputInitializedHandle = AFGCharacterPlayer::OnPlayerInputInitialized.AddLambda(
		[this](AFGCharacterPlayer* CharacterPlayer, UInputComponent* InputComponent)
		{
			if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
				if (UCycleFuelSubsystem* Subsystem = CharacterPlayer->GetWorld()->GetSubsystem<UCycleFuelSubsystem>())
					Subsystem->BindPlayerActions(CharacterPlayer, EnhancedInputComponent);
		});
}

void FCycleFuelModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	AFGCharacterPlayer::OnPlayerInputInitialized.Remove(OnInputInitializedHandle);
	OnInputInitializedHandle.Reset();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FCycleFuelModule, CycleFuel)
