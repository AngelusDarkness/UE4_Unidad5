// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interactable.h"
#include "U5PlayerController.generated.h"

UCLASS()
class UNIDAD5_API AU5PlayerController : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AU5PlayerController();

protected:
	IInteractable* CurrentInteractableOnFocus;

	

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Allow only lateral movement.
	void Move(float Value);
	
	virtual void Jump() override;
	virtual void StopJumping() override;

	UFUNCTION()
	void OnTriggerStart(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnTriggerEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	void Interact();	
	
public:	
	UPROPERTY(BlueprintReadOnly)
	bool IsJumpButtonDown;

	UPROPERTY(BlueprintReadWrite)
	bool CanMove;

	UPROPERTY(EditAnywhere, Category = "Triggers")
	UCapsuleComponent* TriggerCapsuleComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(EditAnywhere)
	float CurrentHealth = 100;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintImplementableEvent)
	void Respawn();
	
	void EquipWeapon(UStaticMesh* NewWeaponMesh);
	void ReceiveDamage(float Damage);

};
