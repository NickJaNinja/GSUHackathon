// Fill out your copyright notice in the Description page of Project Settings.

#include "IdleIncomeUpgradeBooth.h"
#include "ChickRedemptionCharacter.h"
#include "InteractableActor.h"
#include "Engine.h"



void AIdleIncomeUpgradeBooth::UpdateStat(AChickRedemptionCharacter* StatsRef)
{
	Super::UpdateStat(StatsRef);

	int32 CurrentIncome = StatsRef->getIncome();
	int32 NewIncome = CurrentIncome * 2;

	StatsRef->setIncome(NewIncome);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Income Increased by 1.3x!");
}

void AIdleIncomeUpgradeBooth::UpdateText(int32 cost)
{
	//Super::UpdateText(cost);
	FString IntAsString = FString::FromInt(cost);
	FString StationName = ("Press 'E' to upgrade.\nIncome Booster\n Cost: " + IntAsString);
	UIText = StationName;
	InteractableUI->SetText(UIText);

}