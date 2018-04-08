// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactables/InteractableActor.h"
#include "EndGameBooth.generated.h"

/**
 * 
 */
UCLASS()
class CHICKREDEMPTION_API AEndGameBooth : public AInteractableActor
{
	GENERATED_BODY()

	virtual void UpdateStat(AChickRedemptionCharacter* StatsRef) override;

	FString UIText;
	
	virtual void UpdateText(float cost) override;

	
};
