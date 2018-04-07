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
	float income = 1.3;
	float gold;
	float health;
	float maxHealth = 30.0f;
	int32 attack;
	int32 defense;
	int32 armor;
	int32 waveIncomeBonus;
	bool isPlaying = false;

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

	//Player Events
	void Interact();


public:
	AChickRedemptionCharacter();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	UPROPERTY(VisibleAnywhere, BlueprintAssignable, Category = "Event Dispatcher")
		FOnInteract OnInteract;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
		class UTextRenderComponent* InteractableUI;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")
		class UBlendSpace1D* BlendSpace;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "EnemyManager")
		class AEnemyManager* EnemyManager;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn")
		AActor* Spawn;

	FORCEINLINE float getGold() const { return gold; }
	FORCEINLINE void setGold(float g) { gold = g; }
	FORCEINLINE float getIncome() const { return income; }
	FORCEINLINE void setIncome(float i) { income = i; }
	FORCEINLINE int32 getWaveIncomeBonus() const { return waveIncomeBonus; }
	FORCEINLINE void setWaveIncomeBonus(int32 w) { waveIncomeBonus = w; }

	FORCEINLINE float getTimeHolder() const { return timeHolder; }
	FORCEINLINE void setTimeHolder(float t) { timeHolder = t; }

	FORCEINLINE float getHealth() const { return health; }
	FORCEINLINE void setHealth(float h) { health = h; }
	FORCEINLINE float getMaxHealth() const { return maxHealth; }
	FORCEINLINE void setMaxHealth(float mh) { maxHealth = mh; }

	FORCEINLINE int32 getAttack() const { return attack; }
	FORCEINLINE void setAttack(int32 a) { attack = a; }

	FORCEINLINE int32 getArmor() const { return armor; }
	FORCEINLINE void setArmor(int32 a) { armor = a; }



	//Income Functions
	FString UICurrencyText;
	void addGold();
	void UpdateGoldText(float gold);

	//Health Functions
	void UpdateHealth(float inputHealth);

	//Gameplay Events
	void EnterPlay();
	void ExitPlay();
};
