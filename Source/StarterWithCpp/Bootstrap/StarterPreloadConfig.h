#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "StarterPreloadConfig.generated.h"

UCLASS()
class STARTERWITHCPP_API UStarterPreloadConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Startup | Asset Bootstrap")
	TArray<TSoftClassPtr<UObject>> ClassesToPreload;
};
