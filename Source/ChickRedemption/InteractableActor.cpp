// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractableActor.h"
#include "Components/ShapeComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TextRenderComponent.h" //CHECK IF THIS IS RIGHT
#include "ChickRedemptionCharacter.h"
#include "Engine.h"



// Sets default values
AInteractableActor::AInteractableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>("RootComponent");
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(Root);

	Collision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	Collision->SetupAttachment(Root);
	Collision->SetWorldScale3D(FVector(5.0f, 1.0f, 1.0f));
	Collision->bGenerateOverlapEvents = true;

	Collision->OnComponentBeginOverlap.AddDynamic(this, &AInteractableActor::OnOverlapBegin);
	Collision->OnComponentEndOverlap.AddDynamic(this, &AInteractableActor::OnOverlapEnd);
	
	InteractableUI = CreateDefaultSubobject<UTextRenderComponent>("InteractableDetails");
	InteractableUI->SetupAttachment(Root);
	InteractableUI->AddLocalOffset(FVector(150.0f, 10.0f, 0));
	
	Test = 5;
	UIText = FString(TEXT("Press 'E' to upgrade. \n Damage Multiplier: %d"), Test);

	InteractableUI->SetText(UIText);

}

// Called when the game starts or when spawned
void AInteractableActor::BeginPlay()
{
	Super::BeginPlay();
	InteractableUI->SetHiddenInGame(true);
	
}

// Called every frame
void AInteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (inRange == true)
	{
		
	}

}

void AInteractableActor::OnOverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("BeginOverlap"));
	inRange = true;
	InteractableUI->SetHiddenInGame(false);

	AChickRedemptionCharacter* OverlappedChar = Cast<AChickRedemptionCharacter>(OtherActor);
	if (OverlappedChar->IsValidLowLevel())
	{
		OverlappedChar->OnInteract.AddDynamic(this, &AInteractableActor::Upgrade);
	}

}

void AInteractableActor::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("EndOverlap"));
	inRange = false;
	InteractableUI->SetHiddenInGame(true);

	AChickRedemptionCharacter* OverlappedChar = Cast<AChickRedemptionCharacter>(OtherActor);
	/*if (OverlappedChar->IsValidLowLevel())
	{
		Overlapped->OnInteract.
	}*/

}

void AInteractableActor::Upgrade(FVector Location)
{
	UE_LOG(LogTemp, Warning, TEXT("Upgrade!"));
}