#include "CycleFuelSubsystem.h"
#include "CycleFuel.h"

void UCycleFuelSubsystem::BindPlayerActions(const AFGCharacterPlayer* CharacterPlayer,
                                            UEnhancedInputComponent* EnhancedInputComponent)
{
	const UInputAction* Input = UFGInputLibrary::FindInputActionByMappingName(
		CharacterPlayer->GetController<APlayerController>(), FName(TEXT("CycleKey"))).LoadSynchronous();
	EnhancedInputComponent->BindAction(Input, ETriggerEvent::Triggered, this, &UCycleFuelSubsystem::ChangeFuel,
	                                   CharacterPlayer);
}

void UCycleFuelSubsystem::ChangeFuel(const FInputActionValue& ActionValue, const AFGCharacterPlayer* CharacterPlayer)
{
	if (!ActionValue.IsNonZero())
		return;

	const UFGInventoryComponentEquipment* Slot = CharacterPlayer->GetEquipmentSlot(EEquipmentSlot::ES_BACK);
	AFGEquipment* Equipment = Slot->GetEquipmentInSlot();
	if(!Equipment) return;
	TArray<TSubclassOf<UFGItemDescriptor>> Consumables;
	Equipment->GetSupportedConsumableTypes(Consumables);
	const TSubclassOf<UFGItemDescriptor> SelectedConsumable = Equipment->GetSelectedConsumableType();
	UFGInventoryComponent* Inventory = CharacterPlayer->GetInventory();
	Consumables = Consumables.FilterByPredicate([Inventory](const TSubclassOf<UFGItemDescriptor> Consumable) { return Inventory->HasItems(Consumable, 1);});
	if(Consumables.Num() == 0) return;
	if(Consumables.Num() == 1) Equipment->SetSelectedConsumableType(Consumables[0]);
	else Equipment->SetSelectedConsumableType(Consumables[(Consumables.IndexOfByKey(SelectedConsumable) + 1) % Consumables.Num()]);

	UE_LOG(CycleFuel, Verbose, TEXT("Hello World!"));
}
