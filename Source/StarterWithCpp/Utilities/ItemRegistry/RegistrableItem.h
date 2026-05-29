#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RegistrableItem.generated.h"

// This class does not need to be modified.
UINTERFACE()
class URegistrableItem : public UInterface
{
	GENERATED_BODY()
};

class STARTERWITHCPP_API IRegistrableItem
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
    UFUNCTION(BlueprintNativeEvent)
    void OnRegistered(UObject* Registrar);
    virtual void OnRegistered_Implementation(UObject* Registrar) {}

    UFUNCTION(BlueprintNativeEvent)
    void OnUnregistered(UObject* Registrar);
    virtual void OnUnregistered_Implementation(UObject* Registrar) {}

    UFUNCTION(BlueprintNativeEvent)
    void OnRegistrationFailed(UObject* Registrar);
    virtual void OnRegistrationFailed_Implementation(UObject* Registrar) {}
};
