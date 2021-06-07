// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "SimpleTrigger.generated.h"

UCLASS()
class UNIDAD5_API ASimpleTrigger : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASimpleTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Interface methods
	void OnInteract(AActor* Caller);
	void OnFocusStart();
	void OnFocusEnd();

};
