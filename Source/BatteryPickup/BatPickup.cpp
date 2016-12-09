// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryPickup.h"
#include "BatPickup.h"

//set default value
ABatPickup::ABatPickup()
{
	GetMesh()->SetSimulatePhysics(true);
	PrimaryActorTick.bCanEverTick = true;
}

void ABatPickup::Tick(float DeltaTime)
{
	FVector NewLocation = GetActorLocation();
	FString Name = GetName();

	ACharacter* myCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	FVector Location1 = myCharacter->GetActorLocation();

	float x1, y1;
	FVector test;

	x1 = (Location1.X - NewLocation.X)*0.1;
	y1 = (Location1.Y - NewLocation.Y)*0.1;

	test.X = NewLocation.X + x1;
	test.Y = NewLocation.Y + y1;
	test.Z = NewLocation.Z;
	
	íf (x1*10 > 1.0 || y1*10 > 1.0)
	{
		SetActorLocation(test);
	}

		
	SetActorLocation(test);

	UE_LOG(LogTemp, Warning, TEXT("Location Coordinations: %d %d %d"), NewLocation.X, NewLocation.Y, NewLocation.Z);
	UE_LOG(LogTemp, Warning, TEXT("mylocation is: %d %d %d"), Location1.X, Location1.Y, Location1.Z);
	UE_LOG(LogTemp, Error, TEXT("The name of the object is %s"), *Name);

}


