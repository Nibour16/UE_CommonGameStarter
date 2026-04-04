#include "SubsystemRegistry.h"

#include "Engine/World.h"
#include "Engine/GameInstance.h"

#include "Subsystems/BlueprintableGISubsystem.h"

// Define cached datas
TMap< TWeakObjectPtr<UGameInstance>, 
	TMap<UClass*, TWeakObjectPtr<UBlueprintableGISubsystem>> >
	FSubsystemRegistry::CachedGI;	// Cached Game Instance Subsystem Data

// Basic Data Cache Logic
template<typename OwnerType, typename SubsystemType>
SubsystemType* FSubsystemRegistry::GetCachedSubsystem(
	TMap<TWeakObjectPtr<OwnerType>, TMap<UClass*, TWeakObjectPtr<SubsystemType>>>& Cache,
	OwnerType* Owner,
	UClass* Class,
	TFunction<SubsystemType* ()> Getter )
{
	if (!Owner || !Class) return nullptr; // If owner or class is not found

	// Check Cached Data
	if (auto* InnerMap = Cache.Find(Owner))	// Check if the owner exist
	{
		if (auto* Found = InnerMap->Find(Class)) // Check if there is a cached subsystem
		{
			if (Found->IsValid())
				return Found->Get(); // if the subsystem is valid, return this one
			else
				InnerMap->Remove(Class); // if find one but not valid, remove it and continue
		}
	}

	SubsystemType* Subsystem = Getter(); // Get Subsystem

	// Cache Subsystem
	if (Subsystem)	// If the subsystem get is valid
		Cache.FindOrAdd(Owner).FindOrAdd(Class, Subsystem);	// Do cache by using FindOrAdd function

	return Subsystem;	// Return this subsystem
}

bool FSubsystemRegistry::ResolveSubsystemContext(
	UObject* WorldContextObject,
	UClass* Class,
	UGameInstance*& OutGI)
{
	OutGI = nullptr; // Default is null for output game instance

	// Check validation of world context and the class
	if (!WorldContextObject || !Class) return false;

	// Check if the class is the correct child
	if (!Class->IsChildOf(UBlueprintableGISubsystem::StaticClass()))
		return false;

	// Check if the world is exist
	UWorld* World = WorldContextObject->GetWorld();	// Get world from world context
	if (!World) return false;

	// Check validation of game instance
	UGameInstance* GI = World->GetGameInstance();
	if (!GI) return false;

	OutGI = GI;	// This subsystem context is valid, assign the game instance
	return true; // Pass
}

// Get Game Instance Subsystem Logic
UBlueprintableGISubsystem* FSubsystemRegistry::GetGISubsystem(
	UObject* WorldContextObject,
	UClass* Class)
{
	UGameInstance* GI = nullptr;

	if (!ResolveSubsystemContext(WorldContextObject, Class, GI))
		return nullptr;

	return GetCachedSubsystem<UGameInstance, UBlueprintableGISubsystem>(
		CachedGI,
		GI,
		Class,
		[GI, Class]()
		{
			return Cast<UBlueprintableGISubsystem>(
				GI->GetSubsystemBase(Class));
		});
}