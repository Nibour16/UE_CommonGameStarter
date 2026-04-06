#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StateControllerAccessLibrary.generated.h"

class AGameStateController;

UCLASS()
class STARTERWITHCPP_API UStateControllerAccessLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "State Controller", 
		meta=(DisplayName = "Get Game State Controller", WorldContext = "WorldContextObject"))
	static AGameStateController* GetGameStateController(const UObject* WorldContextObject);
};
