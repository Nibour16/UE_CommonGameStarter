#include "StateMachineInstance.h"
#include "StateMachine.h"
#include "BaseState.h"

void UStateMachineInstance::Initialize(UObject* InOwner)
{
	StateMachine = NewObject<UStateMachine>(this);
	StateMachine->Initialize(InOwner);
}

void UStateMachineInstance::Tick(float DeltaTime)
{
	if (StateMachine)
		StateMachine->Tick(DeltaTime);
}

void UStateMachineInstance::RegisterStates(
	const TArray<TSubclassOf<UBaseState>>& InStateClasses,
	UObject* Owner)
{
	if (!StateClasses.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("States already registered!"));
		return;
	}
	
	if (!StateMachine) return;

	TSet<TSubclassOf<UBaseState>> Unique;

	for (const auto& StateClass : InStateClasses)
	{
		if (!StateClass || Unique.Contains(StateClass)) continue;

		Unique.Add(StateClass);

		UBaseState* State = NewObject<UBaseState>(this, StateClass);
		State->Initialize(Owner, StateMachine);

		StateMachine->RegisterState(StateClass, State);
	}

	StateClasses = InStateClasses;
}

void UStateMachineInstance::SetState(TSubclassOf<UBaseState> NewStateClass)
{
	if (StateMachine)
		StateMachine->SetState(NewStateClass);
}

void UStateMachineInstance::SetDefaultState()
{
	bool bIsValidStateClasses = false;
	
	for (const auto& StateClass : StateClasses)
	{
		if (StateClass)
		{
			SetState(StateClass);
			bIsValidStateClasses = true;
			break;
		}
	}

	if (!bIsValidStateClasses)
		UE_LOG(LogTemp, Warning, TEXT("No valid default state found!"));
}

UBaseState* UStateMachineInstance::GetCurrentState()
{
	if (StateMachine)
		return StateMachine->GetCurrentState();

	return nullptr;
}

void UStateMachineInstance::Shutdown()
{
	GetCurrentState()->ExitState();

	if (StateMachine)
		StateMachine->ClearStates();
}