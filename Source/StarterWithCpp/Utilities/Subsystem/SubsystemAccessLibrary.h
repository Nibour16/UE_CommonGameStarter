#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "Subsystems/BlueprintableGISubsystem.h"

#include "SubsystemAccessLibrary.generated.h"

UCLASS()
class STARTERWITHCPP_API USubsystemAccessLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// Game Instance Subsystem
	UFUNCTION(
		BlueprintPure, Category="Subsystem", 
		meta = (WorldContext="WorldContextObject", DeterminesOutputType="Class"))
	static UBlueprintableGISubsystem* GetBlueprintableGISubsystem(
		UObject* WorldContextObject, TSubclassOf<UBlueprintableGISubsystem> Class);
};
