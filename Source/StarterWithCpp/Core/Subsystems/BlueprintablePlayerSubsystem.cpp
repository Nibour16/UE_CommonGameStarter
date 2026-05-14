#include "BlueprintablePlayerSubsystem.h"

// Implement Life Cycle
void UBlueprintablePlayerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	OnInitialize();
}

void UBlueprintablePlayerSubsystem::Deinitialize()
{
	OnDeinitialize();

	Super::Deinitialize();
}

// Implement Owning properties
ULocalPlayer* UBlueprintablePlayerSubsystem::GetOwningLocalPlayer() const
{
    ULocalPlayer* LocalPlayer = GetLocalPlayer();

    if (!LocalPlayer) return nullptr;
    
    return LocalPlayer;
}

APlayerController* UBlueprintablePlayerSubsystem::GetOwningPlayerController() const
{
    ULocalPlayer* LocalPlayer = GetOwningLocalPlayer();

    if (!LocalPlayer) return nullptr;

    return LocalPlayer->GetPlayerController(GetWorld());
}

APawn* UBlueprintablePlayerSubsystem::GetOwningPawn() const
{
    APlayerController* PC = GetOwningPlayerController();

    if (!PC) return nullptr;

    return PC->GetPawn();
}
