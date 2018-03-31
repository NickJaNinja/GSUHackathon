// Fill out your copyright notice in the Description page of Project Settings.

#include "DungeonTeleport.h"
#include "Components/BoxComponent.h"

// Sets default values
ADungeonTeleport::ADungeonTeleport()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	Collision->SetupAttachment(Root);
	Collision->SetWorldScale3D(FVector(5.0f, 1.0f, 1.0f));
	Collision->bGenerateOverlapEvents = true;

	Collision->OnComponentBeginOverlap.AddDynamic(this, &ADungeonTeleport::OnOverlapBegin);
	Collision->OnComponentEndOverlap.AddDynamic(this, &ADungeonTeleport::OnOverlapEnd);

}

// Called when the game starts or when spawned
void ADungeonTeleport::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADungeonTeleport::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (inRange == true)
	{

	}
}

void ADungeonTeleport::OnOverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	inRange = true;
	FVector playerLoc = OtherActor->GetActorLocation();
	playerLoc.Y = -6200;
	OtherActor->SetActorLocation(playerLoc);
}

void ADungeonTeleport::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	inRange = false;
}
