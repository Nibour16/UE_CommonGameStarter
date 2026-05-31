#include "StarterWithCpp.h"

#include "AssetRegistry/AssetRegistryModule.h"
#include "AssetRegistry/IAssetRegistry.h"
#include "Engine/Blueprint.h"
#include "UObject/UObjectGlobals.h"
#include "UObject/Class.h"

void FStarterWithCppModule::StartupModule()
{
    IAssetRegistry& Registry = GetAssetRegistry();
    
    if (Registry.IsLoadingAssets())
    {
        Registry.OnFilesLoaded().AddRaw(this, &FStarterWithCppModule::PreloadBlueprintClasses);
    }
    else
    {
        PreloadBlueprintClasses();
    }
}

IMPLEMENT_PRIMARY_GAME_MODULE( FStarterWithCppModule, StarterWithCpp, "StarterWithCpp" );

IAssetRegistry& FStarterWithCppModule::GetAssetRegistry() const
{
    static IAssetRegistry& Registry =
        FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();

    return Registry;
}

TArray<FAssetData> FStarterWithCppModule::ResolveAssetsFromRegistry() const
{
    FARFilter Filter;
    Filter.PackagePaths.Add("/Game");
    Filter.bRecursivePaths = true;

    TArray<FAssetData> Assets;
    GetAssetRegistry().GetAssets(Filter, Assets);

    UE_LOG(LogTemp, Log, TEXT("[BlueprintBootstrap] Found Assets = %d"), Assets.Num());

    return Assets;
}

void FStarterWithCppModule::PreloadBlueprintClasses()
{
    UE_LOG(LogTemp, Log, TEXT("[BlueprintBootstrap] Start Blueprint Warmup"));

    TArray<FAssetData> Assets = ResolveAssetsFromRegistry();
    TArray<UClass*> WarmedClasses;

    for (const FAssetData& Asset : Assets)
    {
        // Blueprint Class Only
        if (!Asset.TagsAndValues.Contains("GeneratedClass")) continue;

        FString ClassPath;
        if (!Asset.GetTagValue("GeneratedClass", ClassPath)) continue;

        // Soft Class Load
        UClass* Class = LoadObject<UClass>(nullptr, *ClassPath);

        // Ensure this class is preloadable
        if (!IsPreloadableClass(Class, true)) continue;

        // Only desired targets for CDO warmup
        const UObject* CDO = Class->GetDefaultObject();
        WarmedClasses.AddUnique(Class);

        // Print Warmed Classes
        UE_LOG(LogTemp, Log, TEXT("[BlueprintBootstrap] Warmed: %s"), *Class->GetName());
    }

    // Print Numbers for warmed classes
    UE_LOG(LogTemp, Log, TEXT("[BlueprintBootstrap] Total Warmed Classes: %d"), WarmedClasses.Num());
}

bool FStarterWithCppModule::IsPreloadableClass(UClass* Class, bool IncludeBaseClass = true) const
{
    if (!Class) return false;

    for (UClass* BaseClass : PreparedPreloadClasses)
    {
        if (!BaseClass) continue;

        if (Class == BaseClass && IncludeBaseClass) return true;
        
        if (Class->IsChildOf(BaseClass)) return true;
    }

    return false;
}