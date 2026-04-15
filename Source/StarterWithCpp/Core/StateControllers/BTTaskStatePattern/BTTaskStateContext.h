#pragma once

#include "UObject/Interface.h"
#include "BTTaskStateContext.generated.h"

UINTERFACE(MinimalAPI)
class UBTTaskStateContext : public UInterface
{
	GENERATED_BODY()
};

class IBTTaskStateContext
{
	GENERATED_BODY()

public:
	virtual void RequestFinish(bool bSuccess) = 0;
	virtual void RequestAbort() = 0;

	virtual bool IsExecuting() const = 0;
	virtual bool IsAborting() const = 0;
};