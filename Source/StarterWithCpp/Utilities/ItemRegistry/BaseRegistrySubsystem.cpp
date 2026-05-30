#include "BaseRegistrySubsystem.h"
#include <Kismet/GameplayStatics.h>
#include "RegistrableItem.h"

bool UBaseRegistrySubsystem::IsRegistrableItem(UObject* Item) const
{
    if (Item && Item->Implements<URegistrableItem>())
        return true;

    return false;
}

void UBaseRegistrySubsystem::Deinitialize()
{
	UnregisterAllItems();
}

UBaseRegistrySubsystem::ERegistryResult UBaseRegistrySubsystem::Register_Internal(UObject* Item)
{
    if (!IsValid(Item)) return ERegistryResult::Invalid;

    for (UObject* Existing : RegisteredItems)
    {
        if (!IsValid(Existing))
        {
            continue;
        }

        if (Existing == Item)
        {
            return ERegistryResult::AlreadyRegistered;
        }

        if (Existing->GetClass() == Item->GetClass())
        {
            return ERegistryResult::DuplicateClass;
        }
    }

    RegisteredItems.AddUnique(Item);
    return ERegistryResult::Success;
}

UObject* UBaseRegistrySubsystem::GetItemByClass(TSubclassOf<UObject> Class) const
{
    if (Class)
    {
        for (UObject* Item : RegisteredItems)
        {
            if (IsValid(Item) && Item->IsA(Class))
                return Item;
        }
    }
    
    UE_LOG(LogTemp, Error, TEXT("Registry: Failed to found the item by this class type input"))
    return nullptr;
}

void UBaseRegistrySubsystem::RegisterItem(UObject* Item)
{
    ERegistryResult Result = Register_Internal(Item);

    switch (Result)
    {
    case ERegistryResult::Success:
        if (IsRegistrableItem(Item))
            IRegistrableItem::Execute_OnRegistered(Item, this);
        break;

    case ERegistryResult::DuplicateClass:
        if (IsRegistrableItem(Item))
            IRegistrableItem::Execute_OnRegistrationFailed(Item, this);
        break;

    case ERegistryResult::AlreadyRegistered:
        break;

    case ERegistryResult::Invalid:
        UE_LOG(LogTemp, Warning, TEXT("Registry: Invalid Manager passed in, now it is removed"));
        if (IsRegistrableItem(Item))
            IRegistrableItem::Execute_OnRegistrationFailed(Item, this);
        break;

    default:
        UE_LOG(LogTemp, Warning, TEXT("Unhandled Registry Result: %d"), (int32)Result);
        break;
    }
}

void UBaseRegistrySubsystem::RegisterAllItemsInWorld(TSubclassOf<AActor> DesiredClassType)
{
    CleanupInvalidItems();

    TArray<AActor*> FoundActors;

    UGameplayStatics::GetAllActorsOfClass(GetWorld(), DesiredClassType, FoundActors);

    for (AActor* Actor : FoundActors)
    {
        if (!Actor) continue;

        RegisterItem(Actor);
    }
}

void UBaseRegistrySubsystem::UnregisterItem(UObject* Item)
{
    if (!IsValid(Item)) return;
    
    if (IsRegistrableItem(Item))
        IRegistrableItem::Execute_OnUnregistered(Item, this);

    RegisteredItems.Remove(Item);
}

void UBaseRegistrySubsystem::UnregisterAllItems()
{
    TArray<UObject*> ItemsToRemove = RegisteredItems;
    
    for (UObject* Existing : ItemsToRemove)
    {
        UnregisterItem(Existing);
    };
}

void UBaseRegistrySubsystem::CleanupInvalidItems()
{
    RegisteredItems.RemoveAll(
        [](const TObjectPtr<UObject>& Item) { return !IsValid(Item); });
}
