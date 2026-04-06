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

	UFUNCTION(BlueprintImplementableEvent, Category = "State", meta = (DisplayName = "Enter State"))
	void EnterState();

	UFUNCTION(BlueprintImplementableEvent, Category = "State", meta = (DisplayName = "Update State"))
	void UpdateState(float DeltaTime);

	UFUNCTION(BlueprintImplementableEvent, Category = "State", meta = (DisplayName = "Exit State"))
	void ExitState();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	UObject* Owner;

	UPROPERTY()
	UStateMachine* StateMachine;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Initialize"))
	void OnInitialize();
};
