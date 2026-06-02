#include "GameStarterSetting.h"

UStarterPreloadConfig* UGameStarterSetting::GetPreloadConfig() const
{
	return PreloadConfig.LoadSynchronous();
}
