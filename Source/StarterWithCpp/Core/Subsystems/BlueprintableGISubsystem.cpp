#include "BlueprintableGISubsystem.h"

void UBlueprintableGISubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	OnInitialize();
}

void UBlueprintableGISubsystem::Deinitialize()
{
	OnDeinitialize();

	Super::Deinitialize();
}
