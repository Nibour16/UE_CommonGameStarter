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

void UBlueprintableGISubsystem::OnInitialize_Implementation()
{
	
}

void UBlueprintableGISubsystem::OnDeinitialize_Implementation()
{

}
