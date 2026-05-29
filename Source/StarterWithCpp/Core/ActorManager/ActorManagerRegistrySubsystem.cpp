#include "ActorManagerRegistrySubsystem.h"
#include "ActorManagerBase.h"

TArray<AActorManagerBase*> UActorManagerRegistrySubsystem::GetManagers()
{
    TArray<AActorManagerBase*> Managers;

    Algo::TransformIf(
        RegisteredItems, Managers,
        [](UObject* Item) -> bool
        {
            return Cast<AActorManagerBase>(Item) != nullptr;
        },
        [](UObject* Item) -> AActorManagerBase*
        {
            return Cast<AActorManagerBase>(Item);
        }
    );
    
    return Managers;
}

AActorManagerBase* UActorManagerRegistrySubsystem::GetManagerByClass(TSubclassOf<AActorManagerBase> Class)
{
    return Cast<AActorManagerBase>(GetItemByClass(Class));
}

void UActorManagerRegistrySubsystem::RegisterAllManagersInWorld()
{
    RegisterAllItemsInWorld(AActorManagerBase::StaticClass());
}

void UActorManagerRegistrySubsystem::RegisterManager(AActorManagerBase* Manager)
{
    RegisterItem(Manager);
}

void UActorManagerRegistrySubsystem::UnregisterManager(AActorManagerBase* Manager)
{
    UnregisterItem(Manager);
}
