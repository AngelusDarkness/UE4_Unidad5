// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "Components/BoxComponent.h"
#include "WeaponPickup.generated.h"

UCLASS()
class UNIDAD5_API AWeaponPickup : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponPickup();

protected:	

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxComponent;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UStaticMeshComponent* WeaponMesh;	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Interface methods
	void OnInteract(AActor* Caller);
	virtual void OnInteract_Implementation(AActor* Caller) override;

	void OnFocusStart();
	void OnFocusEnd();
};
