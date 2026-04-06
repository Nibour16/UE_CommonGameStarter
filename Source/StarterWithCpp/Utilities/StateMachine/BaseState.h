#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BaseState.generated.h"

class UStateMachine;

UCLASS(Blueprintable, Abstract)
class STARTERWITHCPP_API UBaseState : public UObject
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(UObject* InOwner, UStateMachine* InStateMachine);

	UFUNCTION(BlueprintImplementableEvent)
	void EnterState();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateState(float DeltaTime);

	UFUNCTION(BlueprintImplementableEvent)
	void ExitState();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	UObject* Owner;

	UPROPERTY()
	UStateMachine* StateMachine;

	UFUNCTION(BlueprintImplementableEvent, Category = "State")
	void OnInitialize();
};
