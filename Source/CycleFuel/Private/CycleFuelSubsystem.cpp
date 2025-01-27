#include "CycleFuelSubsystem.h"

#include "CycleFuel.h"

void UCycleFuelSubsystem::BindPlayerActions(const AFGCharacterPlayer* CharacterPlayer,
                                            UEnhancedInputComponent* EnhancedInputComponent)
{
	const UInputAction* input = UFGInputLibrary::FindInputActionByMappingName(
		CharacterPlayer->GetController<APlayerController>(), FName(TEXT("CycleKey"))).LoadSynchronous();
	EnhancedInputComponent->BindAction(input, ETriggerEvent::Triggered, this, &UCycleFuelSubsystem::ChangeFuel);
}

void UCycleFuelSubsystem::ChangeFuel(const FInputActionValue& ActionValue)
{
	if (!ActionValue.IsNonZero())
		return;

	// Do your cool stuff here!
	UE_LOG(CycleFuel, Verbose, TEXT("Hello World!"));
}
