// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy_1.generated.h"

UCLASS()
class CHICKREDEMPTION_API AEnemy_1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy_1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interactable)
		USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interactable)
		UStaticMeshComponent* EnemyMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interactable)
		UStaticMeshComponent* FloorMesh;

	FVector BaseLocation;
	FVector CurrentLocation;

	FVector FloorBase;
};
