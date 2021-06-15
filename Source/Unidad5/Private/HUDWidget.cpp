// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDWidget.h"
#include "CustomGameState.h"

void UHUDWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	auto* GameState = GetWorld()->GetGameState<ACustomGameState>();

	if (GameState != nullptr) 
	{
		GameState->OnItemsChanged().AddUObject(this, &UHUDWidget::OnItemsChanged);
	}
	
}
