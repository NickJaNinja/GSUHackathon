// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableActor.generated.h"


UCLASS()
class CHICKREDEMPTION_API AInteractableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool inRange;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interactable)
		USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interactable)
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interactable)
		UShapeComponent* Collision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interactable)
		AActor* SpecificActor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Interactable)
		class UTextRenderComponent* InteractableUI;

	class AChickRedemptionCharacter* LocalRef;

	//Call bakc or event
		//When actor is spawned, (post-init), then look for the actor

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

	int32 Test;
	FString UIText; 
	

};
