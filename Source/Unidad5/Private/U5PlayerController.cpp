// Fill out your copyright notice in the Description page of Project Settings.


#include "U5PlayerController.h"

// Sets default values
AU5PlayerController::AU5PlayerController()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AU5PlayerController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AU5PlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AU5PlayerController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

