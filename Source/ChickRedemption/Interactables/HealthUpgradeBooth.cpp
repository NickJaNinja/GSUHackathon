// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthUpgradeBooth.h"
#include "ChickRedemptionCharacter.h"
#include "InteractableActor.h"
#include "Engine.h"

void AHealthUpgradeBooth::UpdateStat(AChickRedemptionCharacter* StatsRef)
{
	Super::UpdateStat(StatsRef);

	float CurrentHealth = StatsRef->getMaxHealth();
	float NewHealth = CurrentHealth + healthIncrease;

	StatsRef->setMaxHealth(NewHealth);
	float RoundedHealth = FMath::RoundHalfToZero(NewHealth);
	FString HealthMultiplierText = FString::SanitizeFloat(RoundedHealth);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "New Health: " + HealthMultiplierText + "!");
}

void AHealthUpgradeBooth::UpdateText(float cost)
{
	float RoundedCost = FMath::RoundHalfToZero(cost);
	FString FloatAsString = FString::SanitizeFloat(RoundedCost);
	FString StationName = ("Press 'E' to upgrade.\nHealth Booster\n Cost: " + FloatAsString);
	UIText = StationName;
	InteractableUI->SetText(UIText);

}



