#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ComponentStateController.generated.h"

class UStateMachineInstance;
class UBaseState;

UCLASS( Abstract, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class STARTERWITHCPP_API UComponentStateController : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UComponentStateController();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "State Controller",
		meta = (DisplayName = "Construct"))
	void BeforeStateConstruction();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	UPROPERTY(EditAnywhere, Category = "General Setting", meta= (AllowAbstract = false))
	TArray<TSubclassOf<UBaseState>> States;

	UPROPERTY(BlueprintReadOnly, Category = "State Machine")
	UStateMachineInstance* StateMachine;
};
