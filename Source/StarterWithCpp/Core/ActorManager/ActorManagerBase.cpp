#include "ActorManagerBase.h"

// Sets default values
AActorManagerBase::AActorManagerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AActorManagerBase::OnUnregistered_Implementation()
{
	if (bDestroyIfUnregistered)
		Destroy();
}

void AActorManagerBase::OnRegistrationFailed_Implementation()
{
	if (bDestroyIfDuplicated)
		Destroy();
}