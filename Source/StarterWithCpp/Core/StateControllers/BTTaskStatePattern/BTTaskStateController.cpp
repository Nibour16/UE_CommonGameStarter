#include "BTTaskStateController.h"

#include "AIController.h"
#include "BehaviorTree/BTFunctionLibrary.h"
#include "BTTaskStateContext.h"

#include "StateMachine/StateMachineInstance.h"

UBTTaskStateController::UBTTaskStateController()
{
	bCreateNodeInstance = true;
}

EBTNodeResult::Type UBTTaskStateController::ExecuteTask(
	UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (CurrentCallResult != EBTNodeResult::InProgress) return CurrentCallResult;

	StateMachine = NewObject<UStateMachineInstance>(this);
	StateMachine->Initialize(this);

	StateMachine->RegisterStates(States, this);
	StateMachine->SetDefaultState();

	DispatchExecutionOnStateEntered();

	return CurrentCallResult;
}

void UBTTaskStateController::OnTaskFinished(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTNodeResult::Type TaskResult)
{
	if (StateMachine)
	{
		StateMachine->Shutdown();
		StateMachine = nullptr;
	}

	Super::OnTaskFinished(OwnerComp, NodeMemory, TaskResult);
}

void UBTTaskStateController::TickTask(
	UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	if (StateMachine)
		StateMachine->Tick(DeltaSeconds);
}

// Devlog: Logic is copied from the parent cpp, may causes issues in the future version
void UBTTaskStateController::DispatchExecutionOnStateEntered()
{
	if (ReceiveExecuteImplementations != FBTNodeBPImplementationHelper::NoImplementation)
	{
		bStoreFinishResult = true;

		if (AIOwner != nullptr && (ReceiveExecuteImplementations & FBTNodeBPImplementationHelper::AISpecific))
		{
			ReceiveOnStateEnteredAI(AIOwner, AIOwner->GetPawn());
		}
		else if (ReceiveExecuteImplementations & FBTNodeBPImplementationHelper::Generic)
		{
			ReceiveOnStateEntered(ActorOwner);
		}

		bStoreFinishResult = false;
	}
}

void UBTTaskStateController::RequestFinish(bool bSuccess)
{
	FinishExecute(bSuccess);
}

void UBTTaskStateController::RequestAbort()
{
	FinishAbort();
}

bool UBTTaskStateController::IsExecuting() const
{
	return IsTaskExecuting();
}

bool UBTTaskStateController::IsAborting() const
{
	return IsTaskAborting();
}