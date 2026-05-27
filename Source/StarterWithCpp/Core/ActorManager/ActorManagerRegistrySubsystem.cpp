#include "ActorManagerRegistrySubsystem.h"
#include "ActorManagerBase.h"
#include <Kismet/GameplayStatics.h>

AActorManagerBase* UActorManagerRegistrySubsystem::GetManagerByClass(TSubclassOf<AActorManagerBase> Class)
{
    for (AActorManagerBase* Manager : RegisteredManagers)
    {
        if (IsValid(Manager) && Manager->IsA(Class))
            return Cast<AActorManagerBase>(Manager);
    }

    return nullptr;
}

UActorManagerRegistrySubsystem::ERegistryResult 
UActorManagerRegistrySubsystem::Register_Internal(AActorManagerBase* Manager)
{
    if (!IsValid(Manager)) return ERegistryResult::Invalid;
    
    for (AActorManagerBase* Existing : RegisteredManagers)
    {   
        if (!IsValid(Existing))
        {
            continue;
        }

        if (Existing == Manager)
        {
            return ERegistryResult::AlreadyRegistered;
        }

        if (Existing->GetClass() == Manager->GetClass())
        {
            return ERegistryResult::DuplicateClass;
        }
    }

    RegisteredManagers.AddUnique(Manager);
    return ERegistryResult::Success;
}

void UActorManagerRegistrySubsystem::RegisterAllManagersInWorld()
{
    CleanupInvalidManagers();
    
    TArray<AActor*> FoundActors;

    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActorManagerBase::StaticClass(), FoundActors);

    for (AActor* Actor : FoundActors)
    {
        AActorManagerBase* Manager = Cast<AActorManagerBase>(Actor);

        if (!Manager) continue;

        RegisterManager(Manager);
    }
}

void UActorManagerRegistrySubsystem::RegisterManager(AActorManagerBase* Manager)
{
    ERegistryResult Result = Register_Internal(Manager);

    switch (Result)
    {
    case ERegistryResult::Success:
        Manager->OnRegistered();
        break;

    case ERegistryResult::DuplicateClass:
        Manager->OnRegistrationFailed();
        break;

    case ERegistryResult::AlreadyRegistered:
        break;

    case ERegistryResult::Invalid:
        UE_LOG(LogTemp, Warning, TEXT("Registry: Invalid Manager passed in, now it is removed"));
        break;

    default:
        UE_LOG(LogTemp, Warning, TEXT("Unhandled Registry Result: %d"), (int32)Result);
        break;
    }
}

void UActorManagerRegistrySubsystem::UnregisterAllManagers()
{
    if (RegisteredManagers.IsEmpty()) return;
    
    for (AActorManagerBase* Existing : RegisteredManagers)
    {
        UnregisterManager(Existing);
    };
}

void UActorManagerRegistrySubsystem::UnregisterManager(AActorManagerBase* Manager)
{
    if (!IsValid(Manager)) return;
    
    Manager->OnUnregistered();
    RegisteredManagers.Remove(Manager);
}

void UActorManagerRegistrySubsystem::Deinitialize()
{
    UnregisterAllManagers();
    Super::Deinitialize();
}

void UActorManagerRegistrySubsystem::CleanupInvalidManagers()
{
    RegisteredManagers.RemoveAll(
        [](const TObjectPtr<AActorManagerBase>& Manager) { return !IsValid(Manager); });
}
