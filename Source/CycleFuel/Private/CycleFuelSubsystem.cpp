#include "CycleFuelSubsystem.h"
#include "CycleFuel.h"
#include "FGGameUI.h"
#include "FGJetPack.h"

void UCycleFuelSubsystem::BindPlayerActions(AFGCharacterPlayer* CharacterPlayer,
                                            UEnhancedInputComponent* EnhancedInputComponent)
{
	const UInputAction* CycleKey = UFGInputLibrary::FindInputActionByMappingName(
		CharacterPlayer->GetController<APlayerController>(),
		FName(TEXT("CycleKey"))
	).LoadSynchronous();
	EnhancedInputComponent->BindAction(
		CycleKey,
		ETriggerEvent::Triggered,
		this,
		&UCycleFuelSubsystem::ChangeFuel,
		CharacterPlayer
	);
}

// ReSharper disable once CppMemberFunctionMayBeStatic
void UCycleFuelSubsystem::ChangeFuel(const FInputActionValue& ActionValue, AFGCharacterPlayer* CharacterPlayer)
{
	if (!ActionValue.IsNonZero())
		return;

	const UFGInventoryComponentEquipment* Slot = CharacterPlayer->GetEquipmentSlot(EEquipmentSlot::ES_BACK);
	AFGEquipment* Equipment = Slot->GetEquipmentInSlot();
	if (!Equipment) return;

	TArray<TSubclassOf<UFGItemDescriptor>> Consumables;
	Equipment->GetSupportedConsumableTypes(Consumables);
	const TSubclassOf<UFGItemDescriptor> SelectedConsumable = Equipment->GetSelectedConsumableType();
	UFGInventoryComponent* Inventory = CharacterPlayer->GetInventory();
	Consumables = Consumables.FilterByPredicate([Inventory](const TSubclassOf<UFGItemDescriptor> Consumable)
	{
		return Inventory->HasItems(Consumable, 1);
	});

	switch (Consumables.Num())
	{
	case 0:
		return;
	case 1:
		Equipment->SetSelectedConsumableType(Consumables[0]);
		break;
	default:
		Equipment->SetSelectedConsumableType(
			Consumables[(Consumables.IndexOfByKey(SelectedConsumable) + 1) % Consumables.Num()]);
		break;
	}
}
