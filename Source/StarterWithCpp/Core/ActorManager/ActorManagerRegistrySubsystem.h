#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "ActorManagerRegistrySubsystem.generated.h"

class AActorManagerBase;

UCLASS()
class STARTERWITHCPP_API UActorManagerRegistrySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
private:
	enum class ERegistryResult : uint8
	{
		Success,
		AlreadyRegistered,
		DuplicateClass,
		Invalid
	};

	ERegistryResult Register_Internal(AActorManagerBase* Manager);

public:
	UPROPERTY(BlueprintReadOnly, Category = "Actor Manager")
	TArray<TObjectPtr<AActorManagerBase>> RegisteredManagers;

	UFUNCTION(BlueprintPure, Category = "Actor Manager")
	AActorManagerBase* GetManagerByClass(TSubclassOf<AActorManagerBase> Class);
	
	UFUNCTION(BlueprintCallable, Category = "Manager Registration")
	void RegisterAllManagersInWorld();

	UFUNCTION(BlueprintCallable, Category = "Manager Registration")
	void RegisterManager(AActorManagerBase* Manager);

	UFUNCTION(BlueprintCallable, Category = "Manager Registration")
	void UnregisterManager(AActorManagerBase* Manager);

protected:
	virtual void Deinitialize() override;

	void UnregisterAllManagers();

	void CleanupInvalidManagers();
};
