#include "CycleFuel.h"
#include "CycleFuelSubsystem.h"

#define LOCTEXT_NAMESPACE "FCycleFuelModule"

void FCycleFuelModule::StartupModule()
{
	OnInputInitializedHandle = AFGCharacterPlayer::OnPlayerInputInitialized.AddLambda(
		[this](const AFGCharacterPlayer* CharacterPlayer, UInputComponent* InputComponent)
		{
			if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
				if (UCycleFuelSubsystem* Subsystem = CharacterPlayer->GetWorld()->GetSubsystem<UCycleFuelSubsystem>())
					Subsystem->BindPlayerActions(CharacterPlayer, EnhancedInputComponent);
		});
}

void FCycleFuelModule::ShutdownModule()
{
	AFGCharacterPlayer::OnPlayerInputInitialized.Remove(OnInputInitializedHandle);
	OnInputInitializedHandle.Reset();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FCycleFuelModule, CycleFuel)
