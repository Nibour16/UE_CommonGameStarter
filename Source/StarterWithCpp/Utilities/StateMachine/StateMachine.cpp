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
	if (!StateData.Contains(NewStateClass)) return;

	UBaseState* NewState = StateData[NewStateClass];

	if (bIsSwitchingState)
	{
		PendingState = NewState;
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