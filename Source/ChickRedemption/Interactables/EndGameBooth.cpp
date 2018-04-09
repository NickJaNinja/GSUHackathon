// Fill out your copyright notice in the Description page of Project Settings.

#include "EndGameBooth.h"
#include "InteractableActor.h"
#include "ChickRedemptionCharacter.h"
#include "Engine.h"

void AEndGameBooth::UpdateStat(AChickRedemptionCharacter * StatsRef)
{
	Super::UpdateStat(StatsRef);

	//Show UI
	GetWorld()->GetTimerManager().SetTimer(_loopTimerHandle, this, &AEndGameBooth::Quit, 4.0f, false);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "The game will now exit. Loser.");
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "You won! Thanks for playing!");
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "The reward is that you now know where not to waste your time!");

	
}


void AEndGameBooth::UpdateText(float cost)
{
	//Show UI
	FString StationName = ("Press 'E' to escape this hell.\n Cost: " + FString::SanitizeFloat(cost));
	UIText = StationName;
	InteractableUI->SetText(UIText);

}

void AEndGameBooth::Quit()
{
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
}