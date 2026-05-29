#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemRegistry/RegistrableItem.h"
#include "ActorManagerBase.generated.h"

UCLASS(Blueprintable, BlueprintType, Abstract)
class STARTERWITHCPP_API AActorManagerBase : public AActor, public IRegistrableItem
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorManagerBase();

	virtual void OnUnregistered_Implementation(UObject* Registrar) override;
	virtual void OnRegistrationFailed_Implementation(UObject* Registrar) override;

protected:
	UPROPERTY(EditAnywhere, Category = "General Setting")
	bool bDestroyIfDuplicated = true;

	UPROPERTY(EditAnywhere, Category = "General Setting")
	bool bDestroyIfUnregistered = true;
};
