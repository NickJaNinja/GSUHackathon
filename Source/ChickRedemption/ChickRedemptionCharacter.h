// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ChickRedemptionCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteract, AChickRedemptionCharacter*, Character);

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
	int32 income;
	int32 gold;
	float health;
	int32 attack;
	int32 defense;
	int32 armor;

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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Interactable)
		class UTextRenderComponent* InteractableUI;

	FString UIText;
	void addGold();
	void UpdateGoldText(int32 gold);
	

	FORCEINLINE float getIncome() const { return income; };
	FORCEINLINE float getTimeHolder() const { return timeHolder; }
	FORCEINLINE int32 getGold() const { return gold; }
	FORCEINLINE float getHealth() const { return health; }
	FORCEINLINE int32 getAttack() const { return attack; }
	FORCEINLINE int32 getArmor() const { return armor; }

	FORCEINLINE void setIncome(float i) { income = i; }
	FORCEINLINE void setTimeHolder(float t) { timeHolder = t; }
	FORCEINLINE void setGold(int32 g) { gold = g; }
	FORCEINLINE void setHealth(float h) { health = h; }
	FORCEINLINE void setAttack(int32 a){ attack = a; }
	FORCEINLINE void setArmor(int32 a) { armor = a; }
};
