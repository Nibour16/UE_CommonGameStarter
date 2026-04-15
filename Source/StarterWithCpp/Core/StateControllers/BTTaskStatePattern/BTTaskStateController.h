#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlueprintBase.h"
#include "BTTaskStateContext.h"
#include "BTTaskStateController.generated.h"

class UBaseState;
class UStateMachineInstance;

/**
 * A state-driven Blueprint-based Behavior Tree task,
 * designed for Blueprint workflow extension.
 *
 * Extends Unreal Behavior Tree execution using a state machine pattern.
 * All execution semantics (e.g. FinishExecute / FinishAbort) strictly follow native BT rules.
 *
 * NOTE:
 * This is a thin abstraction layer over BTTask_BlueprintBase that does NOT alter core BT behavior.
 */
UCLASS(Abstract, Blueprintable)
class STARTERWITHCPP_API UBTTaskStateController : public UBTTask_BlueprintBase, public IBTTaskStateContext
{
	GENERATED_BODY()

	UBTTaskStateController();

	virtual EBTNodeResult::Type ExecuteTask(
		UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual void OnTaskFinished(
		UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTNodeResult::Type TaskResult) override;
public:
	virtual void RequestFinish(bool bSuccess) override;
	virtual void RequestAbort() override;
	virtual bool IsExecuting() const override;
	virtual bool IsAborting() const override;

protected:
	virtual void TickTask(
		UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UFUNCTION(
		BlueprintImplementableEvent, Category = AI, meta = (DisplayName = "Receive On State Entered"))
	void ReceiveOnStateEntered(AActor* OwnerActor);

	UFUNCTION(
		BlueprintImplementableEvent, Category = AI, meta = (DisplayName = "Receive On State Entered AI"))
	void ReceiveOnStateEnteredAI(AAIController* OwnerController, APawn* ControlledPawn);

	UPROPERTY(EditAnywhere, Category = "General Setting", meta = (AllowAbstract = false))
	TArray<TSubclassOf<UBaseState>> States;

	UPROPERTY(BlueprintReadOnly, Category = "State Machine")
	UStateMachineInstance* StateMachine;

private:
	// Devlog: Logic is copied from the parent cpp, may causes issues in the future version
	void DispatchExecutionOnStateEntered();
};