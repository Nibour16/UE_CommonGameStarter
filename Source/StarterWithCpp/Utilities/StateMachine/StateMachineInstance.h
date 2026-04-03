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

	void SetState(TSubclassOf<UBaseState> NewStateClass);
	void SetDefaultState();

	UStateMachine* GetStateMachine() const { return StateMachine; }

private:
	UPROPERTY()
	UStateMachine* StateMachine;

	UPROPERTY()
	TArray<TSubclassOf<UBaseState>> StateClasses;
};
