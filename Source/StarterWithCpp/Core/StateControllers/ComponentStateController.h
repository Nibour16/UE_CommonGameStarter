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

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "State Controller")
	void ChangeState(TSubclassOf<UBaseState> InState);

protected:
	UPROPERTY(EditAnywhere, Category = "General Setting", meta= (AllowAbstract = false))
	TArray<TSubclassOf<UBaseState>> States;

private:
	UPROPERTY()
	UStateMachineInstance* StateMachine;
};
