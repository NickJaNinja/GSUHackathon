// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamageEntity.generated.h"

UCLASS()
class CHICKREDEMPTION_API ADamageEntity : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADamageEntity();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interactable)
		USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interactable)
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interactable)
		UShapeComponent* Collision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
		float waveLevel;

	int32 speed;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult &SweepResult);


	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp,
			class AActor* OtherActor,
			class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);

	UFUNCTION()
		void addDisplacement(int32 speed);
	
	UFUNCTION()
		int32 getRandomSpeed();

	UFUNCTION()
		void Expire();

	UFUNCTION()
		void SetWave(int32 wave);

	FTimerHandle timerHandle;

	float GetDamage(float waveMultiplier);

};
