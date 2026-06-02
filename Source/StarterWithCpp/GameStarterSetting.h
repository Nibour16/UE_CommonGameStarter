#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "GameStarterSetting.generated.h"

UCLASS(Config = Game, DefaultConfig)
class STARTERWITHCPP_API UGameStarterSetting : public UDeveloperSettings
{
	GENERATED_BODY()

public:
    UPROPERTY(Config, EditAnywhere, Category = "Bootstrap")
    FName BlueprintPreloadConfigName = NAME_None;
};
