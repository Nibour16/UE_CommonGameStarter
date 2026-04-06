#include "GameStateController.h"
#include "StateMachine/StateMachineInstance.h"

AGameStateController::AGameStateController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGameStateController::BeginPlay()
{
	Super::BeginPlay();

	StateMachine = NewObject<UStateMachineInstance>(this);

	StateMachine->Initialize(this);

	StateMachine->RegisterStates(States, this);

	StateMachine->SetDefaultState();
}

void AGameStateController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (StateMachine)
		StateMachine->Tick(DeltaTime);
}

void AGameStateController::ChangeState(TSubclassOf<UBaseState> InState)
{
	if (StateMachine)
		StateMachine->SetState(InState);
}