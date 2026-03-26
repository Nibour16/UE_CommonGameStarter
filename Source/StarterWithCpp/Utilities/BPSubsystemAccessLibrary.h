#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "Subsystems/GameInstanceSubsystem.h"

#include "BPSubsystemAccessLibrary.generated.h"

UCLASS()
class STARTERWITHCPP_API UBPSubsystemAccessLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// Game Instance Subsystem
	UFUNCTION(
		BlueprintPure, Category="Subsystem", 
		meta = (WorldContext="WorldContextObject", DeterminesOutputType="Class"))
	static UGameInstanceSubsystem* GetGameInstanceSubsystem(
		UObject* WorldContextObject, TSubclassOf<UGameInstanceSubsystem> Class);
};
