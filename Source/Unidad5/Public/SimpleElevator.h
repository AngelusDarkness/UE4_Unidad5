// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "Components/BoxComponent.h"
#include "SimpleElevator.generated.h"

UCLASS()
class UNIDAD5_API ASimpleElevator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASimpleElevator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;		

	UFUNCTION()
	void OnTrigger(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere)
	USceneComponent* DefaultSceneComponent;
	
	UPROPERTY(EditAnywhere)
	USplineComponent* SplineComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ElevatorMesh;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* ElevatorTrigger;

	UPROPERTY()
	TArray<FVector> Checkpoints;

	UPROPERTY(EditAnywhere)
	int CurrentCheckpoint;

	UPROPERTY(EditAnywhere)
	float Speed;
	
	UPROPERTY(EditDefaultsOnly)
	float MaxWaitTime;

	
	bool bCanMove = false;
	float Threshold;
	float WaitTime;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	
};
