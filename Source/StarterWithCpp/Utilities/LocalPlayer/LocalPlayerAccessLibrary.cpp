#include "LocalPlayerAccessLibrary.h"

#include "AccessHelpers/WorldAccessHelper.h"

ULocalPlayer* ULocalPlayerAccessLibrary::GetLocalPlayerFromController(APlayerController* PlayerController)
{
	if (!PlayerController) return nullptr;

	return PlayerController->GetLocalPlayer();
}

ULocalPlayer* ULocalPlayerAccessLibrary::GetLocalPlayerFromPawn(APawn* Pawn)
{
	if (!Pawn) return nullptr;

	APlayerController* PC = Cast<APlayerController>(Pawn->GetController());

	if (!PC) return nullptr;
	
	return PC->GetLocalPlayer();
}

TArray<ULocalPlayer*> ULocalPlayerAccessLibrary::GetLocalPlayers(UObject* WorldContextObject)
{
	UWorld* World = FWorldAccessHelper::GetWorldFromContext(WorldContextObject);
	
	UGameInstance* GI = World->GetGameInstance();

	if (!GI) return {};

	return GI->GetLocalPlayers();
}
