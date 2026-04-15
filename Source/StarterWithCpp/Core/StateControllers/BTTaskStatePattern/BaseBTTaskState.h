#pragma once

#include "CoreMinimal.h"
#include "StateMachine/BaseState.h"
#include "BaseBTTaskState.generated.h"

class IBTTaskStateContext;

UCLASS()
class STARTERWITHCPP_API UBaseBTTaskState : public UBaseState
{
	GENERATED_BODY()

public:
	virtual void Initialize(UObject* InOwner, UStateMachine* InStateMachine) override;

protected:
	UFUNCTION(BlueprintCallable, Category = "AI|Behavior Tree")
	void FinishExecute(bool bSuccess);

	UFUNCTION(BlueprintCallable, Category = "AI|Behavior Tree")
	void FinishAbort();

	UFUNCTION(BlueprintCallable, Category = "AI|Behavior Tree")
	bool IsTaskExecuting() const;

	UFUNCTION(BlueprintCallable, Category = "AI|Behavior Tree")
	bool IsTaskAborting() const;

	IBTTaskStateContext* Context = nullptr;
};
