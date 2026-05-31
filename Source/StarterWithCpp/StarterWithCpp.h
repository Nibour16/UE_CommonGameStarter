#pragma once

#include "CoreMinimal.h"

class IAssetRegistry;

class FStarterWithCppModule : public FDefaultGameModuleImpl
{
public:
	virtual void StartupModule() override;

private:
	TArray<UClass*> PreparedPreloadClasses = { USubsystem::StaticClass() };

	IAssetRegistry& GetAssetRegistry() const;
	TArray<FAssetData> ResolveAssetsFromRegistry() const;

	void PreloadBlueprintClasses();
	bool IsPreloadableClass(UClass* Class, bool IncludeBaseClass) const;
};