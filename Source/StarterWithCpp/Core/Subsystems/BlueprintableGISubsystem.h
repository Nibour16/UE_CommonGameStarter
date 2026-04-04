#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "BlueprintableGISubsystem.generated.h"

#define GI_SUBSYSTEM_CATEGORY "Game Instance Subsystem"

UCLASS(Abstract, Blueprintable)
class STARTERWITHCPP_API UBlueprintableGISubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

protected:
	UFUNCTION(
		BlueprintNativeEvent, 
		Category = GI_SUBSYSTEM_CATEGORY,
		meta = (DisplayName = "Initialized"))
	void OnInitialize();
	virtual void OnInitialize_Implementation();

	UFUNCTION(
		BlueprintNativeEvent,
		Category = GI_SUBSYSTEM_CATEGORY,
		meta = (DisplayName = "Deinitialization"))
	void OnDeinitialize();
	virtual void OnDeinitialize_Implementation();
};