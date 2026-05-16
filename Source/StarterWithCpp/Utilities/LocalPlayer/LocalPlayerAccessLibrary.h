#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LocalPlayerAccessLibrary.generated.h"

UCLASS()
class STARTERWITHCPP_API ULocalPlayerAccessLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "Local Player")
	static ULocalPlayer* GetLocalPlayerFromController(APlayerController* PlayerController);

	UFUNCTION(BlueprintPure, Category = "Local Player")
	static ULocalPlayer* GetLocalPlayerFromPawn(APawn* Pawn);

	UFUNCTION(BlueprintPure, Category = "Local Player", meta = (WorldContext = "WorldContextObject"))
	static TArray<ULocalPlayer*> GetLocalPlayers(UObject* WorldContextObject);
};
