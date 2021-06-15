// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageZone.h"
#include "U5PlayerController.h"


void ADamageZone::CausePainTo(class AActor* Other)
{
	AU5PlayerController* PlayerController = Cast<AU5PlayerController>(Other);

	if (PlayerController) 
	{		
		PlayerController->ReceiveDamage(DamagePerSec);
	}
}
