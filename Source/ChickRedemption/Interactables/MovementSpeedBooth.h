// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactables/InteractableActor.h"
#include "MovementSpeedBooth.generated.h"

/**
 * 
 */
UCLASS()
class CHICKREDEMPTION_API AMovementSpeedBooth : public AInteractableActor
{
	GENERATED_BODY()

public: 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
		float movementIncrease = 1.3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
		float frictionIncrease = 1000;

	virtual void UpdateStat(AChickRedemptionCharacter* StatsRef) override;

	virtual void UpdateText(float cost) override;

	FString UIText;
	
	
	
};
