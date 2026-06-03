#include "StartupAssetBootstrapSubsystem.h"

#include "GameStarterSetting.h"
#include "StarterPreloadConfig.h"

void UStartupAssetBootstrapSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    
    HandleBootstrap();
}

void UStartupAssetBootstrapSubsystem::HandleBootstrap()
{
    UE_LOG(LogTemp, Log, TEXT("[Startup Asset Bootstrap] Start Blueprint Warmup"));

    const UGameStarterSetting* Settings = GetDefault<UGameStarterSetting>();

    UStarterPreloadConfig* Config = Settings->GetPreloadConfig();

    if (!Config)
    {
        UE_LOG(LogTemp, Error, TEXT("[Startup Asset Bootstrap] Failed to load preload config"));
        return;
    }

    UE_LOG(LogTemp, Log, TEXT("[Startup Asset Bootstrap] Classes Count = %d"), Config->ClassesToPreload.Num());

    // Config Data is gotten, preload classes from data
    for (const TSoftClassPtr<UObject>& SoftClass : Config->ClassesToPreload)
    {
        if (SoftClass.IsNull()) continue;
        
        UClass* LoadedClass = SoftClass.LoadSynchronous();

        if (!LoadedClass)
        {
            UE_LOG(LogTemp, Warning, TEXT("[Startup Asset Bootstrap] Failed to load class %s"),
                *SoftClass.ToSoftObjectPath().ToString());

            continue;
        }

        LoadedClass->GetDefaultObject();

        UE_LOG(LogTemp, Log,
            TEXT("[Startup Asset Bootstrap] Preloaded %s"), *LoadedClass->GetName());
    }

    OnBootstrapCompleted.Broadcast();
}