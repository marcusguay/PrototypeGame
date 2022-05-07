// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerVehicle.h"

APlayerVehicle::APlayerVehicle()
{
}

void APlayerVehicle::Tick(float DeltaTime)
{
   Super::Tick(DeltaTime);
}

void APlayerVehicle::setEnterCollisionBoxes(UBoxComponent *front, UBoxComponent *shotgun, UBoxComponent *backLeft, UBoxComponent *backRight)
{
   frontSeatTV = front;
   shotgunSeatTV = shotgun;
   backLeftSeatTV = backLeft;
   backRightSeatTV = backRight;
   frontSeatTV->OnComponentBeginOverlap.AddDynamic(this, &APlayerVehicle::OnOverlapBegin);
   frontSeatTV->OnComponentEndOverlap.AddDynamic(this, &APlayerVehicle::OnOverlapEnd);
}

void APlayerVehicle::OnOverlapBegin(class UPrimitiveComponent *OverlappedComp, class AActor *OtherActor, class UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{

   UE_LOG(LogTemp, Warning, TEXT("Player can now enter the front seat"));

   if (Cast<APlayerCharacter>(OtherActor))
   {
      if (Cast<UBoxComponent>(OverlappedComp))
      {
         if (OverlappedComp == frontSeatTV)
         {
            UE_LOG(LogTemp, Warning, TEXT("Player can now enter the front seat"));
            teleportActorToSeat(driverSocketName, OtherActor);
         }
         else if (OverlappedComp == shotgunSeatTV)
         {
            UE_LOG(LogTemp, Warning, TEXT("Player can now enter the shotgun seat"));
         }
         else if (OverlappedComp == backLeftSeatTV)
         {
            UE_LOG(LogTemp, Warning, TEXT("Player can now enter the back left seat"));
         }
         else if (OverlappedComp == backRightSeatTV)
         {
            UE_LOG(LogTemp, Warning, TEXT("Player can now enter the back right seat"));
         }
      }
   }
}

void APlayerVehicle::OnOverlapEnd(class UPrimitiveComponent *OverlappedComp, class AActor *OtherActor, class UPrimitiveComponent *OtherComp, int32 OtherBodyIndex)
{
   if (Cast<APlayerCharacter>(OtherActor))
   {
      if (Cast<UBoxComponent>(OverlappedComp))
      {
         if (OverlappedComp == frontSeatTV)
         {
            UE_LOG(LogTemp, Warning, TEXT("Player can no longer enter the front seat"));
         }
         else if (OverlappedComp == shotgunSeatTV)
         {
            UE_LOG(LogTemp, Warning, TEXT("Player can no longer enter the shotgun seat"));
         }
         else if (OverlappedComp == backLeftSeatTV)
         {
            UE_LOG(LogTemp, Warning, TEXT("Player can no longer enter the back left seat"));
         }
         else if (OverlappedComp == backRightSeatTV)
         {
            UE_LOG(LogTemp, Warning, TEXT("Player can no longer enter the back right seat"));
         }
      }
   }
}

void APlayerVehicle::setSocketNames(FName frontName, FName shotgunName, FName backLeftName, FName backRightName)
{
   driverSocketName = frontName;
   shotgunSocketName = shotgunName;
   backLeftSocketName = backLeftName;
   backRightSocketName = backRightName;
}

void APlayerVehicle::teleportActorToSeat(FName name,class AActor* OtherActor)
{
   
 
   OtherActor->SetActorEnableCollision(false);
   FTimerDelegate TimerDel;
   FTimerHandle TimerHandle;

   TimerDel.BindUFunction(this,FName("delayedFN"),OtherActor);
   GetWorld()->GetTimerManager().SetTimer(TimerHandle,TimerDel,0.1f,false);



   
}



void APlayerVehicle::delayedFN(AActor* OtherActor){
FVector newLocation = GetMesh()->GetSocketLocation(driverSocketName);
FAttachmentTransformRules rules = FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true);
OtherActor->SetActorLocation(newLocation, false, 0, ETeleportType::None);
OtherActor->AttachToActor(this, rules, driverSocketName);
UE_LOG(LogTemp,Warning,TEXT("%s"),*newLocation.ToString());
UE_LOG(LogTemp,Warning,TEXT("%s"),*OtherActor->GetActorLocation().ToString());

}