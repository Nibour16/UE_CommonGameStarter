#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "StateMachine.generated.h"

class UBaseState;

UCLASS()
class STARTERWITHCPP_API UStateMachine : public UObject
{
	GENERATED_BODY()
	
public:
	void Initialize(UObject* InOwner);
	void Tick(float DeltaTime);

	UFUNCTION(BlueprintCallable)
	void SetState(TSubclassOf<UBaseState> NewStateClass);

	UFUNCTION(BlueprintPure)
	UBaseState* GetCurrentState() const { return CurrentState; }

	void RegisterState(TSubclassOf<UBaseState> StateClass, UBaseState* StateInstance);

private:
	UPROPERTY()
	TMap<TSubclassOf<UBaseState>, UBaseState*> StateData;

	UPROPERTY()
	UBaseState* CurrentState;

	UPROPERTY()
	UBaseState* PendingState;

	UPROPERTY()
	UObject* Owner;

	bool bIsSwitchingState = false;

	void HandleStateChange(UBaseState* NewState);
};
