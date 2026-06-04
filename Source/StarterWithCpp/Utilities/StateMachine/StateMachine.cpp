#include "StateMachine.h"
#include "BaseState.h"

void UStateMachine::Initialize(UObject* InOwner)
{
	Owner = InOwner;
}

void UStateMachine::Tick(float DeltaTime)
{
	if (CurrentState)
		CurrentState->UpdateState(DeltaTime);

	if (PendingState)
	{
		HandleStateChange(PendingState);
		PendingState = nullptr;
	}
}

void UStateMachine::SetState(TSubclassOf<UBaseState> NewStateClass)
{
	if (!StateData.Contains(NewStateClass)) 
	{ 
		UE_LOG(LogTemp, Error, TEXT("[State Machine] Class is not found in the State Data: %s"), 
			*Owner->GetName());
		return; 
	}

	UBaseState* NewState = StateData[NewStateClass];

	if (bIsSwitchingState)
	{
		PendingState = NewState;
		
		UE_LOG(LogTemp, Warning, TEXT("[State Machine] State is still Switching: %s"), *Owner->GetName());
		return;
	}

	HandleStateChange(NewState);
}

void UStateMachine::HandleStateChange(UBaseState* NewState)
{
	bIsSwitchingState = true;

	if (CurrentState)
		CurrentState->ExitState();

	CurrentState = NewState;

	if (CurrentState)
		CurrentState->EnterState();

	bIsSwitchingState = false;
}

void UStateMachine::RegisterState(TSubclassOf<UBaseState> StateClass, UBaseState* StateInst)
{
	if (!StateData.Contains(StateClass))
		StateData.Add(StateClass, StateInst);
}

void UStateMachine::ClearStates()
{
	StateData.Reset();
	CurrentState = nullptr;
}