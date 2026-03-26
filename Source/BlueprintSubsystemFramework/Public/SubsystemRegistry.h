#pragma once

#include "CoreMinimal.h"

#include "Subsystems/GameInstanceSubsystem.h"

class BLUEPRINTSUBSYSTEMFRAMEWORK_API FSubsystemRegistry
{
public:
	// Get Game Instance Subsystem
	static UGameInstanceSubsystem* GetGISubsystem(UObject* WorldContextObject, UClass* Class);

private:
	// Base logic that gets cached subsystem data
	template<typename OwnerType, typename SubsystemType>
	static SubsystemType* GetCachedSubsystem(
		TMap<TWeakObjectPtr<OwnerType>, TMap<UClass*, TWeakObjectPtr<SubsystemType>>>& Cache,
		OwnerType* Owner,
		UClass* Class,
		TFunction<SubsystemType* ()> Getter );

	static bool ResolveSubsystemContext(
		UObject* WorldContextObject,
		UClass* Class,
		UGameInstance*& OutGI );
	
	// Cached subsystems, collected as a map (dictionary in C#)
	// Game Instance Subsystem Cached Data
	static TMap<
		TWeakObjectPtr<UGameInstance>, 
		TMap< UClass*, TWeakObjectPtr<UGameInstanceSubsystem> >
	> CachedGI;
};