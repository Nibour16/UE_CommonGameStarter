#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "GameStateController.generated.h"

class UStateMachineInstance;
class UBaseState;

UCLASS()
class STARTERWITHCPP_API AGameStateController : public AGameStateBase
{
	GENERATED_BODY()

public:
	AGameStateController();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, Category = "State Controller", 
		meta = (DisplayName = "Construct"))
	void BeforeStateConstruction();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, Category = "General Setting", meta = (AllowAbstract = false))
	TArray<TSubclassOf<UBaseState>> States;

	UPROPERTY(BlueprintReadOnly, Category = "State Machine")
	UStateMachineInstance* StateMachine;
};
