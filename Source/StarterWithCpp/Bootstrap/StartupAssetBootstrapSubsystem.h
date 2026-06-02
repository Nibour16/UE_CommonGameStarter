#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "StartupAssetBootstrapSubsystem.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnAssetBootstrapCompleted);

UCLASS()
class STARTERWITHCPP_API UStartupAssetBootstrapSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

public:
    FOnAssetBootstrapCompleted OnBootstrapCompleted;

    virtual void Initialize(FSubsystemCollectionBase& Collection) override;

protected:
    void HandleBootstrap();
};
