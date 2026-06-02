#pragma once

#include "CoreMinimal.h"

class UAssetManager;

class FStarterWithCppModule : public FDefaultGameModuleImpl
{
public:
	virtual void StartupModule() override;

private:
	void OnAssetManagerReady();
	void PreloadBlueprintClasses(UAssetManager& AssetManager);
};