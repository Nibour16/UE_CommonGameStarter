#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "BlueprintableWorldSubsystem.generated.h"

UCLASS(Abstract, Blueprintable)
class STARTERWITHCPP_API UBlueprintableWorldSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

protected:
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

};
