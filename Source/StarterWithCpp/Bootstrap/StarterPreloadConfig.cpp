#include "StarterPreloadConfig.h"

#if WITH_EDITOR
void UStarterPreloadConfig::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);

    if (PropertyChangedEvent.ChangeType & EPropertyChangeType::ArrayAdd) return;

    ClassesToPreload.RemoveAll(
        [](const TSoftClassPtr<UObject>& SoftClass) { return SoftClass.IsNull(); });
}
#endif