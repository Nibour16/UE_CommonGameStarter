#pragma once

#include "CoreMinimal.h"
#include "ItemRegistry/BaseRegistrySubsystem.h"
#include "ActorManagerRegistrySubsystem.generated.h"

class AActorManagerBase;

UCLASS()
class STARTERWITHCPP_API UActorManagerRegistrySubsystem : public UBaseRegistrySubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Actor Manager")
	TArray<AActorManagerBase*> GetManagers();

	UFUNCTION(BlueprintPure, Category = "Actor Manager", meta = (DeterminesOutputType = "Class"))
	AActorManagerBase* GetManagerByClass(TSubclassOf<AActorManagerBase> Class);
	
	UFUNCTION(BlueprintCallable, Category = "Manager Registration")
	void RegisterAllManagersInWorld();

	UFUNCTION(BlueprintCallable, Category = "Manager Registration")
	void RegisterManager(AActorManagerBase* Manager);

	UFUNCTION(BlueprintCallable, Category = "Manager Registration")
	void UnregisterManager(AActorManagerBase* Manager);
};
