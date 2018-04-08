// Fill out your copyright notice in the Description page of Project Settings.

#include "EndGameBooth.h"
#include "InteractableActor.h"
#include "ChickRedemptionCharacter.h"
#include "Engine.h"

void AEndGameBooth::UpdateStat(AChickRedemptionCharacter * StatsRef)
{
	Super::UpdateStat(StatsRef);

	//Show UI
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Game End!");
	
}


void AEndGameBooth::UpdateText(float cost)
{
	//Show UI
	FString StationName = ("Press 'E' to escape this hell.\n Cost: " + FString::SanitizeFloat(cost));
	UIText = StationName;
	InteractableUI->SetText(UIText);

}
