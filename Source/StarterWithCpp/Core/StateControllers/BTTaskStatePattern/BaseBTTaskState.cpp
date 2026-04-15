#include "BaseBTTaskState.h"
#include "BTTaskStateContext.h"

void UBaseBTTaskState::Initialize(UObject* InOwner, UStateMachine* InStateMachine)
{
	// Ensure context is ready before blueprint initialization 
	Context = Cast<IBTTaskStateContext>(InOwner);

	Super::Initialize(InOwner, InStateMachine);
}

void UBaseBTTaskState::FinishExecute(bool bSuccess)
{
	if (Context)
		Context->RequestFinish(bSuccess);
}

void UBaseBTTaskState::FinishAbort()
{
	if (Context)
		Context->RequestAbort();
}

bool UBaseBTTaskState::IsTaskExecuting() const
{
	if (!Context) return false;

	return Context->IsExecuting();
}

bool UBaseBTTaskState::IsTaskAborting() const
{
	if (!Context) return false;

	return Context->IsAborting();
}