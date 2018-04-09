// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "PlayModeBooth.generated.h"

/**
 * 
 */
UCLASS()
class CHICKREDEMPTION_API APlayModeBooth : public AInteractableActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Play Mode")
		AActor* PlayLocation;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health Booster")
		float costIncrease = 150;

	virtual void UpdateStat(AChickRedemptionCharacter* StatsRef) override;

	virtual void UpdateText(float cost) override;

	virtual void UpdateCost() override;

	FString UIText;
	
};
