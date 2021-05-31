// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleElevator.h"

// Sets default values
ASimpleElevator::ASimpleElevator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneComponent"));
	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	
	ElevatorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ElevatorMesh"));	
		
	ElevatorTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("ElevatorTrigger"));
	//Bind to Overlap event.
	ElevatorTrigger->OnComponentBeginOverlap.AddDynamic(this, &ASimpleElevator::OnTrigger);
	
}

// Called when the game starts or when spawned
void ASimpleElevator::BeginPlay()
{
	Super::BeginPlay();

	
	ElevatorMesh->SetWorldLocation(SplineComponent->GetLocationAtSplinePoint(0, ESplineCoordinateSpace::World));
	int AmountOfCheckpoints = SplineComponent->GetNumberOfSplinePoints();
	
	for (size_t i = 0; i < AmountOfCheckpoints; i++)
	{
		Checkpoints.Add(SplineComponent->GetLocationAtSplinePoint(i, ESplineCoordinateSpace::World));
	}
	
	CurrentCheckpoint = 1;
	
}


void ASimpleElevator::OnTrigger(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{		
	bCanMove = OtherActor->ActorHasTag("Player");
}

// Called every frame
void ASimpleElevator::Tick(float DeltaTime)
{
	if (!bCanMove)
		return

	Super::Tick(DeltaTime);

	if (WaitTime > 0)
	{
		WaitTime -= DeltaTime;
		return;
	}

	FVector CurrentLocation = ElevatorMesh->K2_GetComponentLocation();
	FVector CurrentCheckpointLocation = Checkpoints[CurrentCheckpoint];

	float DistanceToCheckpoint = FVector::Distance(CurrentLocation, CurrentCheckpointLocation);
	FVector DirectionVector = CurrentCheckpointLocation - CurrentLocation;
	DirectionVector.Normalize();


	if (DistanceToCheckpoint > Speed * DeltaTime)
	{
		CurrentLocation += DirectionVector * Speed * DeltaTime;
		ElevatorMesh->SetWorldLocation(CurrentLocation);
	}
	else
	{
		ElevatorMesh->SetWorldLocation(Checkpoints[CurrentCheckpoint]);
		CurrentCheckpoint++;

		if (CurrentCheckpoint >= Checkpoints.Num())
		{						
			bCanMove = false;
		}
	}
}

