#include "BlueprintableWorldSubsystem.h"

void UBlueprintableWorldSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	OnInitialize();
}

void UBlueprintableWorldSubsystem::Deinitialize()
{
	OnDeinitialize();

	Super::Deinitialize();
}