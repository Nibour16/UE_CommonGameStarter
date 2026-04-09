#include "SubsystemAccessLibrary.h"

#include "Engine/World.h"
#include "Engine/GameInstance.h"

#include "Subsystems/BlueprintableGISubsystem.h"
#include "Subsystems/BlueprintableWorldSubsystem.h"

UBlueprintableGISubsystem* USubsystemAccessLibrary::GetBlueprintableGISubsystem(
    UObject* WorldContextObject,
    TSubclassOf<UBlueprintableGISubsystem> Class)
{
    UGameInstance* GI = GetWorld(WorldContextObject)->GetGameInstance();
    if (!GI) return nullptr;
    
    return Cast<UBlueprintableGISubsystem>(GI->GetSubsystemBase(Class));
}

UBlueprintableWorldSubsystem* USubsystemAccessLibrary::GetBlueprintableWorldSubsystem(
    UObject* WorldContextObject,
    TSubclassOf<UBlueprintableWorldSubsystem> Class)
{
    UWorld* World = GetWorld(WorldContextObject);
    if (!World) return nullptr;

    return Cast<UBlueprintableWorldSubsystem>(World->GetSubsystemBase(Class));
}

UWorld* USubsystemAccessLibrary::GetWorld(UObject* WorldContextObject)
{
    if (!WorldContextObject)
    {
        ensureMsgf(false, TEXT("World Context Object is null"));
        return nullptr;
    }

    UWorld* World = WorldContextObject->GetWorld();

    if (!World)
    {
        ensureMsgf(false, TEXT("Failed to get World from World Context Object"));
        return nullptr;
    }
    
    return World;
}