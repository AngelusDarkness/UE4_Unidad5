// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "CustomGameState.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FCounterChanged, int);

/**
 * 
 */
UCLASS()
class UNIDAD5_API ACustomGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	
	FCounterChanged& OnDeathsChanged() { return DeathsChanged; };
	FCounterChanged& OnItemsChanged() { return ItemsChanged; };	
	
	void HandleDeaths();
	void HandleItem();

protected:	

	FCounterChanged DeathsChanged;
	FCounterChanged ItemsChanged;	
	
	int ItemsCollected;
	int DeathsCounter;

};
