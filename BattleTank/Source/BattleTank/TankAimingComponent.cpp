// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false; // TODO

}

void UTankAimingComponent::Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	Turret = TurretToSet;
	Barrel = BarrelToSet;
}

// void  UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) // we've set the barrel
// {
// 	if(!BarrelToSet) {return;}// protect Barrel pointer
// 	Barrel = BarrelToSet;

// }
// void  UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
// {
// 	if(!TurretToSet) {return;}
// 	Turret = TurretToSet;
// }

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{

//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s"), *GetOwner()->GetName(), *HitLocation.ToString(), *Barrel->GetComponentLocation().ToString() );
	//UE_LOG(LogTemp, Warning, TEXT("Firing at: %f"), LaunchSpeed); //prove launch speed is making it all the way to the component

	if(!Barrel) {return;}
	 //FVector OutLaunchVelocity; // OUT from the function
	FVector OutLaunchVelocity;// initialise to zero to output 0,0,0
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile")); // more accurate than just component
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
			( // DEBUG - NEED ALL PARAMETERS EVEN THE DEFAULT ONES // ADD FALSE, 0,0 BACK IN & ESuggestProjVelocityTraceOption::DoNotTrace
				this, //ref to this tankaiming component
				OutLaunchVelocity,
				StartLocation,
				HitLocation,
				LaunchSpeed,
				false, //debug
				0,//debug
				0,//debug
				ESuggestProjVelocityTraceOption::DoNotTrace //debug trace // caution don't put , at end
			);
	if	(bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal(); //outputs the unit vector from FVector
		//UE_LOG(LogTemp, Warning, TEXT("Tank %s aiming at: %s"), *GetOwner()->GetName(), *AimDirection.ToString()); 
		// return true; // don't need as not setting a false statement after
		MoveBarrelTowards(AimDirection);
		//UE_LOG(LogTemp, Warning, TEXT("%f: Aim Found"),GetWorld()->GetTimeSeconds());
	}
	// else 
	// {
	// 	UE_LOG(LogTemp, Warning, TEXT("%f: NO Aim Found"),GetWorld()->GetTimeSeconds());
	// }
	
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	if(!Turret || !Barrel) {return;}
	//MOve barrel towards an aimdirection by:
	//work out difference between current rotation and aim direction
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();  // gives roll pitch and yaw of barrel //GetForwardVector  =  direction of barrel // Rotation() turn into a struct FRotator, roll pitch Yaw
	auto AimAsRotator = AimDirection.Rotation();
	//UE_LOG(LogTemp, Warning, TEXT("AimasRotator: %s"), *AimAsRotator.ToString()); // see what it kicks out
	auto DeltaRotator = AimAsRotator - BarrelRotator; // difference
	
	// create TankBarrel class for this: //move barrel correct amount this frame //Set max elevation speed // given max speed and frame time (framerate independant)
	
	Barrel->Elevate(DeltaRotator.Pitch); // removed magic number
	Turret->RotateT(DeltaRotator.Yaw);
}

// void UTankAimingComponent::MoveTurretTowards(FVector AimDirection)
// {
// 	//auto TurretRotator = Turret->GetForwardVector().Rotation();
// 	//UE_LOG(LogTemp, Warning, TEXT("TurretRotator: %s"), *TurretRotator.ToString());
// 	// auto AimAsRotator = AimRotation.Rotation();
// 	// //UE_LOG(LogTemp, Warning, TEXT("AimasRotator: %s"), *AimAsRotator.ToString());
// 	// auto DeltaRotator = AimAsRotator - TurretRotator;
// 	// Turret->RotateT(DeltaRotator.Yaw);
// }