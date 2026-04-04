#pragma once

#include "CoreMinimal.h"
#include "Subsystems/BlueprintableGISubsystem.h"
#include "GISubsystemStateController.generated.h"

UCLASS(Abstract, Blueprintable)
class STARTERWITHCPP_API UGISubsystemStateController : public UBlueprintableGISubsystem
{
	GENERATED_BODY()

protected:
	virtual void OnInitialize_Implementation() override;
	virtual void OnDeinitialize_Implementation() override;
};
