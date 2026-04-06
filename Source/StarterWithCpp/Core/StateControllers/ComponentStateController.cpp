#include "ComponentStateController.h"
#include "StateMachine/StateMachineInstance.h"

UComponentStateController::UComponentStateController()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UComponentStateController::BeginPlay()
{
	Super::BeginPlay();

	StateMachine = NewObject<UStateMachineInstance>(this);

	StateMachine->Initialize(this);

	BeforeStateConstruction();

	StateMachine->RegisterStates(States, this);

	StateMachine->SetDefaultState();
}

void UComponentStateController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (StateMachine)
		StateMachine->Tick(DeltaTime);
}

void UComponentStateController::ChangeState(TSubclassOf<UBaseState> InState)
{
	if (StateMachine)
		StateMachine->SetState(InState);
}

UBaseState* UComponentStateController::GetCurrentState()
{
	if (StateMachine)
		return StateMachine->GetCurrentState();

	return nullptr;
}