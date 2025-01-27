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
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Control|Input Actions")
	UInputAction* CycleKey = nullptr;

	void BindPlayerActions(const AFGCharacterPlayer* CharacterPlayer, UEnhancedInputComponent* EnhancedInputComponent);
	void ChangeFuel(const FInputActionValue& ActionValue, const AFGCharacterPlayer* CharacterPlayer);
};
