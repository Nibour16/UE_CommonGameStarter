#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "BaseRegistrySubsystem.generated.h"

class IRegistrableItem;

UCLASS(Abstract)
class STARTERWITHCPP_API UBaseRegistrySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

protected:
	enum class ERegistryResult : uint8
	{
		Success,
		AlreadyRegistered,
		DuplicateClass,
		Invalid
	};

	// Registry Data
	UPROPERTY()
	TArray<TObjectPtr<UObject>> RegisteredItems;

	// Registrable Interface Resolve
	bool IsRegistrableItem(UObject* Item) const;

	// Life Cycle
	virtual void Deinitialize() override;

	virtual ERegistryResult Register_Internal(UObject* Item);

	UObject* GetItemByClass(TSubclassOf<UObject> Class) const;

	virtual void RegisterItem(UObject* Item);

	virtual void RegisterAllItemsInWorld(TSubclassOf<AActor> DesiredClassType);

	virtual void UnregisterItem(UObject* Item);

	virtual void UnregisterAllItems();

	virtual void CleanupInvalidItems();
};
