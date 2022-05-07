// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerVehicle.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class TESTGAME1_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable)
   void SetCanEnterCar(APlayerVehicle* vehicle, FName seat);

   UFUNCTION(BlueprintCallable)
   bool CanEnterCar();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;





protected:
UPROPERTY(VisibleAnywhere)
APlayerVehicle*  enterableVehicle;

UPROPERTY(VisibleAnywhere)
FName currentSeat;




};
