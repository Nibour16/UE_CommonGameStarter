#include "SubsystemAccessLibrary.h"

#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include <Kismet/GameplayStatics.h>
#include "AccessHelpers/WorldAccessHelper.h"

#include "Subsystems/BlueprintableGISubsystem.h"
#include "Subsystems/BlueprintableWorldSubsystem.h"
#include "Subsystems/BlueprintablePlayerSubsystem.h"

// Imeplement Blueprint Subsystem Accessers
UBlueprintableGISubsystem* USubsystemAccessLibrary::GetBlueprintableGISubsystem(
    UObject* WorldContextObject,
    TSubclassOf<UBlueprintableGISubsystem> Class)
{
    UGameInstance* GI = FWorldAccessHelper::GetWorldFromContext(WorldContextObject)->GetGameInstance();
    if (!GI || !Class) return nullptr;
    
    return Cast<UBlueprintableGISubsystem>(GI->GetSubsystemBase(Class));
}

UBlueprintableWorldSubsystem* USubsystemAccessLibrary::GetBlueprintableWorldSubsystem(
    UObject* WorldContextObject,
    TSubclassOf<UBlueprintableWorldSubsystem> Class)
{
    UWorld* World = FWorldAccessHelper::GetWorldFromContext(WorldContextObject);
    if (!World || !Class) return nullptr;

    return Cast<UBlueprintableWorldSubsystem>(World->GetSubsystemBase(Class));
}

UBlueprintablePlayerSubsystem* USubsystemAccessLibrary::GetBlueprintablePlayerSubsystem(
    ULocalPlayer* LocalPlayer,
    TSubclassOf<UBlueprintablePlayerSubsystem> Class)
{
    if (!LocalPlayer || !Class) return nullptr;

    return Cast<UBlueprintablePlayerSubsystem>(LocalPlayer->GetSubsystemBase(Class));
}