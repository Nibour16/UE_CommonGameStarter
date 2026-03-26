#include "BPSubsystemAccessLibrary.h"

#include "Engine/World.h"
#include "Engine/GameInstance.h"

#include "SubsystemRegistry.h"

UGameInstanceSubsystem* UBPSubsystemAccessLibrary::GetGameInstanceSubsystem(
    UObject* WorldContextObject,
    TSubclassOf<UGameInstanceSubsystem> Class)
{
    return FSubsystemRegistry::GetGISubsystem( WorldContextObject, Class.Get() );
}