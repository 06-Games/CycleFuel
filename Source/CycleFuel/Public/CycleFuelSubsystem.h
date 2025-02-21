#pragma once

#include "CoreMinimal.h"
#include "FGPlayerController.h"
#include "Input/FGEnhancedInputComponent.h"
#include "CycleFuelSubsystem.generated.h"

UCLASS(BlueprintType)
class CYCLEFUEL_API UCycleFuelSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	void BindPlayerActions(AFGCharacterPlayer* CharacterPlayer, UEnhancedInputComponent* EnhancedInputComponent);
	void ChangeFuel(const FInputActionValue& ActionValue, AFGCharacterPlayer* CharacterPlayer);
};
