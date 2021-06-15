// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PainCausingVolume.h"
#include "DamageZone.generated.h"

/**
 * 
 */
UCLASS()
class UNIDAD5_API ADamageZone : public APainCausingVolume
{
	GENERATED_BODY()
	
protected:
	virtual void CausePainTo(class AActor* Other) override;
};
