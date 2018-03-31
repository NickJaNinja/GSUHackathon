// Fill out your copyright notice in the Description page of Project Settings.

#include "DamageEntity.h"
#include "Components/ShapeComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ChickRedemptionCharacter.h"
#include "Engine.h"


// Sets default values
ADamageEntity::ADamageEntity()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(Root);
	Collision = CreateDefaultSubobject<UBoxComponent>("Collision");
	Collision->SetupAttachment(Root);
	Collision->SetWorldScale3D(FVector(5.0f, 3.0f, 3.0f));
	Collision->bGenerateOverlapEvents = true;

	Collision->OnComponentBeginOverlap.AddDynamic(this, &ADamageEntity::OnOverlapBegin);
	Collision->OnComponentEndOverlap.AddDynamic(this, &ADamageEntity::OnOverlapEnd);


}

// Called when the game starts or when spawned
void ADamageEntity::BeginPlay()
{
	Super::BeginPlay();
	speed = getRandomSpeed();
}

// Called every frame
void ADamageEntity::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	addDisplacement(speed);
	//Give it displacement

}

void ADamageEntity::OnOverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AChickRedemptionCharacter* OverlappedChar = Cast<AChickRedemptionCharacter>(OtherActor);
	if (OverlappedChar->IsValidLowLevel())
	{
		OverlappedChar->UpdateHealth(GetDamage(waveLevel));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Dmg Overlap");
	}
	
}

void ADamageEntity::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
}

void ADamageEntity::addDisplacement(int32 speed)
{
	FVector ref = GetActorLocation();
	ref.Y += speed;
	SetActorLocation(ref);
}

int32 ADamageEntity::getRandomSpeed()
{
	int32 random = FMath::RandRange(25, 50);
	return random;
}

float ADamageEntity::GetDamage(float waveMultiplier)
{
	return waveMultiplier * -10;
}

