// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ChickRedemptionCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteract, FVector, Location);

UCLASS(config=Game)
class AChickRedemptionCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	float timeHolder = 0.f;
	long long int income;
	long long int gold;
	double health;
	int attack;
	int defense;
	int armor;

protected:

	/** Called for side to side input */
	void MoveRight(float Val);

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

	virtual void Tick(float DeltaTime) override;

	void Interact();


public:
	AChickRedemptionCharacter();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	UPROPERTY(VisibleAnywhere, BlueprintAssignable, Category = "Event Dispatcher")
		FOnInteract OnInteract;

	void addGold(const AChickRedemptionCharacter & c);

	FORCEINLINE long long int getIncome() const { return income; };
	FORCEINLINE float getTimeHolder() const { return timeHolder; }
	FORCEINLINE long long int getGold() const { return gold; }
	FORCEINLINE double getHealth() const { return health; }
	FORCEINLINE int getAttack() const { return attack; }
	FORCEINLINE int getDefense() const { return defense; }
	FORCEINLINE int getArmor() const { return armor; }

	FORCEINLINE void setIncome(long long int i) { income = i; }
	FORCEINLINE void setTimeHolder(float t) { timeHolder = t; }
	FORCEINLINE void setGold(long long int g) { gold = g; }
	FORCEINLINE void setHealth(double h) { health = h; }
	FORCEINLINE void setAttack(int a){ attack = a; }
	FORCEINLINE void setDefense(int d) { defense = d; }
	FORCEINLINE void setArmor(int a) { armor = a; }
};
