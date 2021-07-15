// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGameState.h"


void ACustomGameState::HandleDeaths()
{
	DeathsCounter++;
	DeathsChanged.Broadcast(DeathsCounter);
}

void ACustomGameState::HandleItem()
{
	ItemsCollected++;
	ItemsChanged.Broadcast(ItemsCollected);	
}


