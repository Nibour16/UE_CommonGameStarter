#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "SubsystemAccessLibrary.generated.h"

class UBlueprintableGISubsystem;
class UBlueprintableWorldSubsystem;
class UBlueprintablePlayerSubsystem;

UCLASS()
class STARTERWITHCPP_API USubsystemAccessLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	// All Blueprint Subsystem Accessors created here
public:
	// Game Instance Subsystem
	UFUNCTION(
		BlueprintPure, Category="Subsystem", 
		meta = (WorldContext="WorldContextObject", DeterminesOutputType="Class"))
	static UBlueprintableGISubsystem* GetBlueprintableGISubsystem(
		UObject* WorldContextObject, TSubclassOf<UBlueprintableGISubsystem> Class);

	// World Subsystem
	UFUNCTION(
		BlueprintPure, Category = "Subsystem",
		meta = (WorldContext = "WorldContextObject", DeterminesOutputType = "Class"))
	static UBlueprintableWorldSubsystem* GetBlueprintableWorldSubsystem(
		UObject* WorldContextObject, TSubclassOf<UBlueprintableWorldSubsystem> Class);

	// Local Player Subsystem
	UFUNCTION(
		BlueprintPure, Category = "Subsystem",
		meta = (WorldContext = "WorldContextObject", DeterminesOutputType = "Class"))
	static UBlueprintablePlayerSubsystem* GetBlueprintablePlayerSubsystem(
		ULocalPlayer* LocalPlayer, TSubclassOf<UBlueprintablePlayerSubsystem> Class);

	// Helper Functions
private:
	static UWorld* GetWorld(UObject* WorldContextObject);
};
