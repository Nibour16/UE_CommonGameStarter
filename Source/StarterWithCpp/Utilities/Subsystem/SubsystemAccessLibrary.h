#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "SubsystemAccessLibrary.generated.h"

class UBlueprintableGISubsystem;
class UBlueprintableWorldSubsystem;

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

	UFUNCTION(
		BlueprintPure, Category = "Subsystem",
		meta = (WorldContext = "WorldContextObject", DeterminesOutputType = "Class"))
	static UBlueprintableWorldSubsystem* GetBlueprintableWorldSubsystem(
		UObject* WorldContextObject, TSubclassOf<UBlueprintableWorldSubsystem> Class);

private:
	static UWorld* GetWorld(UObject* WorldContextObject);
};
