// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponPickup.h"
#include "U5PlayerController.h"
#include "Interactable.h"


// Sets default values
AWeaponPickup::AWeaponPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon"));

}

// Called when the game starts or when spawned
void AWeaponPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeaponPickup::OnInteract_Implementation(AActor* Caller)
{		
	AU5PlayerController* PlayerController = Cast<AU5PlayerController>(Caller);

	if (PlayerController) 
	{
		SetActorHiddenInGame(true);
		PlayerController->EquipWeapon(WeaponMesh->GetStaticMesh());
	}
}

