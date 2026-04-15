#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "StateMachineInstance.generated.h"

class UStateMachine;
class UBaseState;

UCLASS()
class STARTERWITHCPP_API UStateMachineInstance : public UObject
{
	GENERATED_BODY()

public:
	void Initialize(UObject* InOwner);
	void Tick(float DeltaTime);

	void RegisterStates(
		const TArray<TSubclassOf<UBaseState>>& InStateClasses,
		UObject* Owner);

	void SetDefaultState();

	UFUNCTION(BlueprintCallable, Category = "State Machine", meta = (DisplayName = "Change State"))
	void SetState(TSubclassOf<UBaseState> NewStateClass);

	UFUNCTION(BlueprintPure, Category = "State Machine", meta = (DisplayName = "Get Current State"))
	UBaseState* GetCurrentState();

	void Shutdown();

private:
	UStateMachine* GetStateMachine() const { return StateMachine; }

	UPROPERTY()
	UStateMachine* StateMachine;

	UPROPERTY()
	TArray<TSubclassOf<UBaseState>> StateClasses;
};
