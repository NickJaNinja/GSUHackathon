// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ChickRedemptionCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Engine.h"


AChickRedemptionCharacter::AChickRedemptionCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f,0.f,75.f);
	CameraBoom->RelativeRotation = FRotator(0.f,180.f,0.f);

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	InteractableUI = CreateDefaultSubobject<UTextRenderComponent>("InteractableDetails");
	InteractableUI->SetupAttachment(SideViewCameraComponent);
	InteractableUI->AddLocalOffset(FVector(400.0f, -40.0f, 0.0f));
	InteractableUI->AddLocalRotation(FRotator(0.0f, 180.0f, 0.0f));

	PrimaryActorTick.bCanEverTick = true;

	

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void AChickRedemptionCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AChickRedemptionCharacter::Interact);

	PlayerInputComponent->BindAxis("MoveRight", this, &AChickRedemptionCharacter::MoveRight);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &AChickRedemptionCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AChickRedemptionCharacter::TouchStopped);
}

void AChickRedemptionCharacter::MoveRight(float Value)
{
	// add movement in that direction
	if (isPlaying == false)
	{
		AddMovementInput(FVector(0.f, -1.f, 0.f), Value);
	}
}

void AChickRedemptionCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	Jump();
}

void AChickRedemptionCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	StopJumping();
}

void AChickRedemptionCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	setTimeHolder(getTimeHolder() + 0.1f);

	if (getTimeHolder() >= 3)
	{
		addGold();
		setTimeHolder(0.f);		
		UpdateGoldText(gold);
	}
	
}

void AChickRedemptionCharacter::Interact()
{
	AChickRedemptionCharacter* StatsRef = this;
	OnInteract.Broadcast(StatsRef);
	
	UE_LOG(LogTemp, Warning, TEXT("CharacterInteractInput"));
}


void AChickRedemptionCharacter::addGold() 
{
	if (isPlaying){
		setGold(getGold() + getIncome() + getWaveIncomeBonus());
	}
	else {
		setGold(getGold() + getIncome());
	}
	
}

void AChickRedemptionCharacter::UpdateGoldText(float gold)
{
	float RoundedGold = FMath::RoundHalfToZero(gold);
	FString FloatAsString = FString::SanitizeFloat(RoundedGold);
	FString StationName = ("Gold: " + FloatAsString);
	UICurrencyText = StationName;
	InteractableUI->SetText(UICurrencyText);
}

void AChickRedemptionCharacter::EnterPlay()
{
	isPlaying = true;
	//Start player animation
	
}

void AChickRedemptionCharacter::ExitPlay()
{
	isPlaying = false;
}