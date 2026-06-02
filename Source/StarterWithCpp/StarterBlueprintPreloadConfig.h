#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameStarterAssetTypes.h"

#include "StarterBlueprintPreloadConfig.generated.h"

UCLASS()
class STARTERWITHCPP_API UStarterBlueprintPreloadConfig : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		FPrimaryAssetId Id(GameStarterAssetTypes::PreloadConfig, GetFName());

		return Id;
	}

	UPROPERTY(EditAnywhere, Category = "Blueprint Bootstrap")
	TArray<TSoftClassPtr<UObject>> ClassesToPreload;
};
