// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "IdleIncomeUpgradeBooth.generated.h"

/**
 * 
 */
UCLASS()
class CHICKREDEMPTION_API AIdleIncomeUpgradeBooth : public AInteractableActor
{
	GENERATED_BODY()

public:

	virtual void UpdateStat(AChickRedemptionCharacter* StatsRef) override;
	
	
};
