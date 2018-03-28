// Fill out your copyright notice in the Description page of Project Settings.

#include "IdleIncomeUpgradeBooth.h"
#include "ChickRedemptionCharacter.h"
#include "InteractableActor.h"
#include "Engine.h"



void AIdleIncomeUpgradeBooth::UpdateStat(AChickRedemptionCharacter* StatsRef)
{
	Super::UpdateStat(StatsRef);

	float CurrentIncome = StatsRef->getIncome();
	float NewIncome = CurrentIncome * incomeMultiplier;

	StatsRef->setIncome(NewIncome);
	FString IncomeMultiplierText = FString::SanitizeFloat(incomeMultiplier);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Income increased by " + IncomeMultiplierText +"!");
}

void AIdleIncomeUpgradeBooth::UpdateText(float cost)
{
	float RoundedCost = FMath::RoundHalfToZero(cost);
	FString FloatAsString = FString::SanitizeFloat(cost);
	FString StationName = ("Press 'E' to upgrade.\nIncome Booster\n Cost: " + FloatAsString);
	UIText = StationName;
	InteractableUI->SetText(UIText);

}