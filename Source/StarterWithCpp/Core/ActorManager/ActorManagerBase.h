// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorManagerBase.generated.h"

UCLASS(Blueprintable, BlueprintType, Abstract)
class STARTERWITHCPP_API AActorManagerBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorManagerBase();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Manager Registration")
	void OnRegistered();

	UFUNCTION(BlueprintNativeEvent, Category = "Manager Registration")
	void OnUnregistered();
	void OnUnregistered_Implementation();

	UFUNCTION(BlueprintNativeEvent, Category = "Manager Registration")
	void OnRegistrationFailed();

protected:
	UPROPERTY(EditAnywhere, Category = "General Setting")
	bool bDestroyIfDuplicated = true;

	UPROPERTY(EditAnywhere, Category = "General Setting")
	bool bDestroyIfUnregistered = true;
};
