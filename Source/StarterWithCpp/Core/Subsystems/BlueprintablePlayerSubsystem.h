#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "BlueprintablePlayerSubsystem.generated.h"

UCLASS(Abstract, Blueprintable)
class STARTERWITHCPP_API UBlueprintablePlayerSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

protected:
	// Life Cycle
	UFUNCTION(
		BlueprintImplementableEvent,
		Category = GI_SUBSYSTEM_CATEGORY,
		meta = (DisplayName = "Initialize"))
	void OnInitialize();

	UFUNCTION(
		BlueprintImplementableEvent,
		Category = GI_SUBSYSTEM_CATEGORY,
		meta = (DisplayName = "Deinitialize"))
	void OnDeinitialize();

public:
	// Owning Properties
	UFUNCTION(BlueprintPure)
	ULocalPlayer* GetOwningLocalPlayer() const;

	UFUNCTION(BlueprintPure)
	APlayerController* GetOwningPlayerController() const;

	UFUNCTION(BlueprintPure)
	APawn* GetOwningPawn() const;
};
