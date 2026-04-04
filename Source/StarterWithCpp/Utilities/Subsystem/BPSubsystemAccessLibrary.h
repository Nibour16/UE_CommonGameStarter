#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "Subsystems/BlueprintableGISubsystem.h"

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
	static UBlueprintableGISubsystem* GetBlueprintableGISubsystem(
		UObject* WorldContextObject, TSubclassOf<UBlueprintableGISubsystem> Class);
};
