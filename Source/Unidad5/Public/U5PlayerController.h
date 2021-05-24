// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "U5PlayerController.generated.h"

UCLASS()
class UNIDAD5_API AU5PlayerController : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AU5PlayerController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Allow only lateral movement.
	void Move(float value);
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	
};
