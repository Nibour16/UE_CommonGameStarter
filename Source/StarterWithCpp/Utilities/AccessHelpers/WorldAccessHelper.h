#pragma once

#include "CoreMinimal.h"

class STARTERWITHCPP_API FWorldAccessHelper
{
public:
    static UWorld* GetWorldFromContext(UObject* WorldContextObject);
};
