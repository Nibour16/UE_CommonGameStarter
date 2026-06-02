#include "StarterWithCpp.h"

#include "GameStarterSetting.h"
#include "StarterBlueprintPreloadConfig.h"
#include "GameStarterAssetTypes.h"

#include "Engine/AssetManager.h"
#include "Engine/StreamableManager.h"

#define LOCTEXT_NAMESPACE "FStarterWithCppModule"

void FStarterWithCppModule::StartupModule()
{
    UAssetManager::CallOrRegister_OnCompletedInitialScan(
        FSimpleMulticastDelegate::FDelegate::CreateRaw(
            this, &FStarterWithCppModule::OnAssetManagerReady));
}

void FStarterWithCppModule::OnAssetManagerReady()
{   
    UAssetManager& AssetManager = UAssetManager::Get();

    // Ensure Asset Manager is initialized
    AssetManager.StartInitialLoading();

    PreloadBlueprintClasses(AssetManager);
}

void FStarterWithCppModule::PreloadBlueprintClasses(UAssetManager& AssetManager)
{
    UE_LOG(LogTemp, Log, TEXT("[BlueprintBootstrap] Start Blueprint Warmup"));

    const UGameStarterSetting* Settings = GetDefault<UGameStarterSetting>();

    const FPrimaryAssetId ConfigId(
        GameStarterAssetTypes::PreloadConfig, Settings->BlueprintPreloadConfigName);

    if (!ConfigId.IsValid())
    {
        UE_LOG(LogTemp, Error, TEXT("[BlueprintBootstrap] Invalid ConfigId"));
        return;
    }

    TSharedPtr<FStreamableHandle> Handle = AssetManager.LoadPrimaryAsset(ConfigId);

    if (!Handle.IsValid())
    {
        UE_LOG(LogTemp, Error, TEXT("[BlueprintBootstrap] LoadPrimaryAsset failed"));
        return;
    }

    Handle->WaitUntilComplete();

    UObject* Obj = Handle.IsValid() ? Handle->GetLoadedAsset() : nullptr;

    if (!Obj)
    {
        UE_LOG(LogTemp, Error, TEXT("[BlueprintBootstrap] PrimaryAsset loaded but object is NULL"));
        return;
    }

    UStarterBlueprintPreloadConfig* Config = Cast<UStarterBlueprintPreloadConfig>(Obj);

    if (!Config)
    {
        UE_LOG(LogTemp, Error, TEXT("[BlueprintBootstrap] Failed to load preload config"));
        return;
    }

    UE_LOG(LogTemp, Log, TEXT("[BlueprintBootstrap] Classes Count = %d"), Config->ClassesToPreload.Num());

    // Config Data is gotten, preload classes from data
    for (const TSoftClassPtr<UObject>& SoftClass : Config->ClassesToPreload)
    {
        UClass* LoadedClass = SoftClass.LoadSynchronous();

        if (!LoadedClass)
        {
            UE_LOG(LogTemp, Warning, TEXT("[BlueprintBootstrap] Failed to load class %s"),
                *SoftClass.ToSoftObjectPath().ToString());

            continue;
        }

        LoadedClass->GetDefaultObject();

        UE_LOG(LogTemp, Log,
            TEXT("[BlueprintBootstrap] Preloaded %s"), *LoadedClass->GetName());
    }
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_PRIMARY_GAME_MODULE(FStarterWithCppModule, StarterWithCpp, "StarterWithCpp");