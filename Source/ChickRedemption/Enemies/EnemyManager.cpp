// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyManager.h"
#include "DamageEntity.h"
#include "ChickRedemptionCharacter.h"
#include "Engine.h"



// Sets default values
AEnemyManager::AEnemyManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;
	Icon = CreateDefaultSubobject<AActor>("Icon");
	
	wave = 1;
}

// Called when the game starts or when spawned
void AEnemyManager::BeginPlay()
{
	Super::BeginPlay();

	canSpawn = true;
}

// Called every frame
void AEnemyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (inPlay == true && canSpawn == true)
	{
		ManageSpawn();
	}
}

void AEnemyManager::SpawnEnemies()
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "spawned enemy");

	FVector ActorLoc = RandomLocation();
	FRotator ActorRot = RandomRotation();
	FActorSpawnParameters SpawnParam;
	
	if (EnemyInstance != NULL)
	{
		GetWorld()->SpawnActor<ADamageEntity>(EnemyInstance, ActorLoc, ActorRot, SpawnParam);
	}

	canSpawn = true;
}

FVector AEnemyManager::RandomLocation()
{
	FVector Location = GetActorLocation();
	Location.Y = GetActorLocation().Y + FMath::RandRange(MinSpawnLoc, MaxLoc);
	return Location;
}

FRotator AEnemyManager::RandomRotation()
{
	FRotator Rot = GetActorRotation();
	Rot.Pitch = FMath::RandRange(0, 90);

	return Rot;
}

void AEnemyManager::ManageSpawn()
{
	canSpawn = false;
	GetWorld()->GetTimerManager().SetTimer(_loopTimerHandle, this, &AEnemyManager::SpawnEnemies, .6f, false);
}

int32 AEnemyManager::WaveUpdate()
{
	wave += 2;
	return wave;
}

bool AEnemyManager::TrueSpawn()
{
	inPlay = true;
	canSpawn = true;
	return canSpawn;
}

bool AEnemyManager::NotInPlay()
{
	inPlay = false;
	canSpawn = false;
	return inPlay;
}
