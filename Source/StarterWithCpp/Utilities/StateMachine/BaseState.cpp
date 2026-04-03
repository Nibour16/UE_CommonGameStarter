#include "BaseState.h"
#include "StateMachine.h"

void UBaseState::Initialize(UObject* InOwner, UStateMachine* InStateMachine)
{
	Owner = InOwner;
	StateMachine = InStateMachine;
}

