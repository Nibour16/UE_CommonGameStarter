#include "StateControllerAccessLibrary.h"
#include "StateControllers/GameStateController.h"

AGameStateController* UStateControllerAccessLibrary::GetGameStateController(
	const UObject* WorldContextObject)
{
	if (!WorldContextObject) return nullptr;

	if (UWorld* World = WorldContextObject->GetWorld())
		return World->GetGameState<AGameStateController>();

	return nullptr;
}
