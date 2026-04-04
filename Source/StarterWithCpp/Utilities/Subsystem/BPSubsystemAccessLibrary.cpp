#include "BPSubsystemAccessLibrary.h"

#include "Engine/World.h"
#include "Engine/GameInstance.h"

#include "Subsystem/SubsystemRegistry.h"

UBlueprintableGISubsystem* UBPSubsystemAccessLibrary::GetBlueprintableGISubsystem(
    UObject* WorldContextObject,
    TSubclassOf<UBlueprintableGISubsystem> Class)
{
    return FSubsystemRegistry::GetGISubsystem( WorldContextObject, Class.Get() );
}