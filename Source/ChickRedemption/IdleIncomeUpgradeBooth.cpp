// Fill out your copyright notice in the Description page of Project Settings.

#include "IdleIncomeUpgradeBooth.h"
#include "ChickRedemptionCharacter.h"
#include "InteractableActor.h"
#include "Engine.h"



void AIdleIncomeUpgradeBooth::UpdateStat(AChickRedemptionCharacter* StatsRef)
{
	Super::UpdateStat(StatsRef);

	int32 CurrentIncome = StatsRef->getIncome();
	int32 NewIncome = CurrentIncome * 1.3;

	StatsRef->setIncome(NewIncome);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Income Increased by 1.3x!");
}

