// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy_1.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


// Sets default values
AEnemy_1::AEnemy_1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("RootComponent");
	RootComponent = Root;

	BaseLocation = FVector(1220.f, -6740.f, 220.f);
	UE_LOG(LogTemp, Warning, TEXT("X: %d \t Y: %d \t Z: %d"), BaseLocation.X, BaseLocation.Y, BaseLocation.Z);

	
	CurrentLocation = BaseLocation;

	EnemyMesh = CreateDefaultSubobject<UStaticMeshComponent>("EnemyMesh");
	EnemyMesh->SetupAttachment(Root);

	FloorMesh = CreateDefaultSubobject<UStaticMeshComponent>("FloorMesh");
	FloorMesh->SetupAttachment(Root);

	FloorBase = FloorMesh->GetComponentLocation();
	//FloorMesh->SetStaticMesh();

}

// Called when the game starts or when spawned
void AEnemy_1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy_1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(CurrentLocation);
	CurrentLocation.Y += 120.f * DeltaTime;

	if (CurrentLocation.Y >= -5600) {
		SetActorLocation(BaseLocation);
		CurrentLocation = BaseLocation;
		UE_LOG(LogTemp, Warning, TEXT("X: %d \t Y: %d \t Z: %d"), BaseLocation.X, BaseLocation.Y, BaseLocation.Z);
	}
}

