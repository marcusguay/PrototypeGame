// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyWheeledVehicle.h"
#include "Components/BoxComponent.h"
#include "PlayerCharacter.h"
#include "UObject/NameTypes.h"
#include "PlayerVehicle.generated.h"

/**
 *
 */
UCLASS()
class TESTGAME1_API APlayerVehicle : public AMyWheeledVehicle
{
    GENERATED_BODY()

protected:
    UFUNCTION(BlueprintCallable)
    virtual void Tick(float DeltaTime) override;

public:
    APlayerVehicle();

protected:
    UPROPERTY(EditAnywhere)
    UBoxComponent *frontSeatTV = nullptr;

    UPROPERTY(EditAnywhere)
    UBoxComponent *shotgunSeatTV = nullptr;

    UPROPERTY(EditAnywhere)
    UBoxComponent *backLeftSeatTV = nullptr;

    UPROPERTY(EditAnywhere)
    UBoxComponent *backRightSeatTV = nullptr;

    UPROPERTY(EditAnywhere)
    FName driverSocketName;
    
    UPROPERTY(EditAnywhere)
    FName shotgunSocketName;

 UPROPERTY(EditAnywhere)
    FName backLeftSocketName;

    UPROPERTY(EditAnywhere)
    FName backRightSocketName;

    UFUNCTION(BlueprintCallable)
    void setEnterCollisionBoxes(UBoxComponent *front, UBoxComponent *shotgun, UBoxComponent *BackLeft, UBoxComponent *BackRight);

    UFUNCTION()
    void OnOverlapBegin(class UPrimitiveComponent *OverlappedComp, class AActor *OtherActor, class UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

    UFUNCTION()
    void OnOverlapEnd(class UPrimitiveComponent *OverlappedComp, class AActor *OtherActor, class UPrimitiveComponent *OtherComp, int32 OtherBodyIndex);


     UFUNCTION()
     void teleportActorToSeat(FName name, class AActor* OtherActor);

         
    UFUNCTION()
    void delayedFN(AActor* OtherActor);


    UFUNCTION(BlueprintCallable)
    void setSocketNames(FName frontName, FName shotgunName, FName backLeftName, FName backRightName);


    

private:
    bool frontCharacterOverlap = false;
    
};
