// Fill out your copyright notice in the Description page of Project Settings.


#include "U5PlayerController.h"
#include "Components/CapsuleComponent.h"
#include "Interactable.h"

// Sets default values
AU5PlayerController::AU5PlayerController()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	TriggerCapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));
	TriggerCapsuleComponent->SetCollisionProfileName(TEXT("Trigger"));
	TriggerCapsuleComponent->SetupAttachment(RootComponent);

	TriggerCapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AU5PlayerController::OnTriggerStart);
	TriggerCapsuleComponent->OnComponentEndOverlap.AddDynamic(this, &AU5PlayerController::OnTriggerEnd);

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon Mesh"));	
	WeaponMesh->SetupAttachment(GetMesh(), TEXT("hand_rSocket"));
}


// Called when the game starts or when spawned
void AU5PlayerController::BeginPlay()
{
	Super::BeginPlay();
	
}

void AU5PlayerController::Move(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AU5PlayerController::Jump()
{
	Super::Jump();
	IsJumpButtonDown = true;
}

void AU5PlayerController::StopJumping()
{
	Super::StopJumping();
	IsJumpButtonDown = false;
}

void AU5PlayerController::OnTriggerStart(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{		
	IInteractable* Interactable = Cast<IInteractable>(OtherActor);
	if (Interactable)
	{		
		IInteractable::Execute_OnFocusStart(OtherActor);	
		CurrentInteractableOnFocus = Interactable;
	}
}

void AU5PlayerController::OnTriggerEnd(UPrimitiveComponent* OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{	
	IInteractable* Interactable = Cast<IInteractable>(OtherActor);
	if (Interactable)
	{	
		IInteractable::Execute_OnFocusEnd(OtherActor);
		CurrentInteractableOnFocus = nullptr;
	}
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

	PlayerInputComponent->BindAxis("MoveRight", this, &AU5PlayerController::Move);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AU5PlayerController::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AU5PlayerController::StopJumping);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AU5PlayerController::Interact);
}

void AU5PlayerController::Interact()
{
	if (CurrentInteractableOnFocus) 
	{
		AActor* OriginalActor = Cast<AActor>(CurrentInteractableOnFocus);
		if (OriginalActor) 
		{
			IInteractable::Execute_OnInteract(OriginalActor, this);
		}		
	}
}

void AU5PlayerController::EquipWeapon(UStaticMesh* NewWeaponMesh)
{
	WeaponMesh->SetStaticMesh(NewWeaponMesh);
}

