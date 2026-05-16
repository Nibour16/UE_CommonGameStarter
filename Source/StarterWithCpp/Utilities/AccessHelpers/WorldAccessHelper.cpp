#include "WorldAccessHelper.h"

UWorld* FWorldAccessHelper::GetWorldFromContext(UObject* WorldContextObject)
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