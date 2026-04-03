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

	StateMachine->Initialize(GetOwner());

	StateMachine->RegisterStates(States, GetOwner());

	StateMachine->SetDefaultState();
}

void UComponentStateController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (StateMachine)
		StateMachine->Tick(DeltaTime);
}

