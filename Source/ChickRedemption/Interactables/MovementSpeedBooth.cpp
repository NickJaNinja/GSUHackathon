// Fill out your copyright notice in the Description page of Project Settings.

#include "MovementSpeedBooth.h"
#include "InteractableActor.h"
#include "ChickRedemptionCharacter.h"
#include "Engine.h"

void AMovementSpeedBooth::UpdateStat(AChickRedemptionCharacter* StatsRef)
{
	Super::UpdateStat(StatsRef);

	float NewSpeed = (StatsRef->GetCharacterMovement()->MaxWalkSpeed + movementMultiplier);
	StatsRef->GetCharacterMovement()->MaxWalkSpeed = NewSpeed;

	float RoundedSpeed = FMath::RoundHalfToZero(NewSpeed);
	FString MoveSpeedText = FString::SanitizeFloat(RoundedSpeed);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "New Speed: " + MoveSpeedText + "!");
}

void AMovementSpeedBooth::UpdateText(float cost)
{
	float RoundedCost = FMath::RoundHalfToZero(cost);
	FString FloatAsString = FString::SanitizeFloat(RoundedCost);
	FString StationName = ("Press 'E' to upgrade.\nMoveSpeed Upgrade\n Cost: " + FloatAsString);
	UIText = StationName;
	InteractableUI->SetText(UIText);
	
}


