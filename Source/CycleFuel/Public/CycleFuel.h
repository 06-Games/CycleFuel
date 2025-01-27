// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "FGPlayerController.h"

DECLARE_LOG_CATEGORY_EXTERN(CycleFuel, Verbose, All);

class FCycleFuelModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	FDelegateHandle OnInputInitializedHandle;
};
