// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayModeBooth.h"
#include "ChickRedemptionCharacter.h"
#include "InteractableActor.h"
#include "Engine.h"
#include "Runtime/Engine/Classes/Engine/TargetPoint.h"

void APlayModeBooth::UpdateStat(AChickRedemptionCharacter * StatsRef)
{
	Super::UpdateStat(StatsRef);
	
	if (PlayLocation != NULL)
	{
		StatsRef->SetActorLocation(PlayLocation->GetActorLocation());
		//Set isPlaying to true here
		//Call a function that sets isPlaying to true while also cueing the animation, disabling input, etc.
		StatsRef->EnterPlay();
	}
	
}

void APlayModeBooth::UpdateText(float cost)
{
	float RoundedCost = FMath::RoundHalfToZero(cost);
	FString FloatAsString = FString::SanitizeFloat(cost);
	FString StationName = ("Press 'E' to enter the fight.\n Cost: " + FloatAsString);
	UIText = StationName;
	InteractableUI->SetText(UIText);

}
