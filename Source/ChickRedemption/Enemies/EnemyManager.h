// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyManager.generated.h"

UCLASS()
class CHICKREDEMPTION_API AEnemyManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//ADamageEntity* DamageVolumes;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Root")
		USceneComponent* Root;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Root")
		AActor* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn Location")
		int32 MinSpawnLoc;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn Location")
		int32 MaxLoc;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnemyBP")
		TSubclassOf<class ADamageEntity> EnemyInstance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn Location")
		int32 wave;
	
	bool inPlay;
	bool canSpawn;

	FTimerHandle _loopTimerHandle;

	UFUNCTION()
		void SpawnEnemies();

	UFUNCTION()
		FVector RandomLocation();

	UFUNCTION()
		FRotator RandomRotation();

	UFUNCTION()
		void ManageSpawn();

	UFUNCTION()
		int32 WaveUpdate();

	bool TrueSpawn();
	bool NotInPlay();

	
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Reference")
	//	AChickRedemptionCharacter* CharRef;
	
};
