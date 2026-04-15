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

	UFUNCTION(BlueprintCallable, Category = "State Machine", meta = (DisplayName = "Change State"))
	void SetState(TSubclassOf<UBaseState> NewStateClass);

	UFUNCTION(BlueprintPure, Category = "State Machine", meta = (DisplayName = "Get Current State"))
	UBaseState* GetCurrentState() const { return CurrentState; }

	void RegisterState(TSubclassOf<UBaseState> StateClass, UBaseState* StateInstance);
	void ClearStates();

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
