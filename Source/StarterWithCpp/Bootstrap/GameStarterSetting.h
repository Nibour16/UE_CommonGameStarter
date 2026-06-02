#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "StarterPreloadConfig.h"
#include "GameStarterSetting.generated.h"

UCLASS(Config = Game, DefaultConfig)
class STARTERWITHCPP_API UGameStarterSetting : public UDeveloperSettings
{
	GENERATED_BODY()

protected:
    UPROPERTY(Config, EditAnywhere, Category = "Startup | Asset Bootstrap")
    TSoftObjectPtr<UStarterPreloadConfig> PreloadConfig;

public:
    UStarterPreloadConfig* GetPreloadConfig() const;
};
