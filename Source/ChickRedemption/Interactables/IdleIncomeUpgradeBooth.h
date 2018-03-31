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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Income Generator")
		float incomeMultiplier = 1.3;

	virtual void UpdateStat(AChickRedemptionCharacter* StatsRef) override;
	
	virtual void UpdateText(float cost) override;

	FString UIText;
};
