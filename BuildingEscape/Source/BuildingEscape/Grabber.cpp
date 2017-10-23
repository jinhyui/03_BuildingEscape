// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include <Engine/World.h>
#include "Gameframework/Actor.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty"))	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get player view point this tick
	FVector PlayerLocation;
	FRotator PlayerRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerLocation,
		OUT PlayerRotation
	);
	// TODO Log out to test
	//UE_LOG(LogTemp, Warning, TEXT("Location: %s, Rotation: %s"),
	//	*PlayerLocation.ToString(),
	//	*PlayerRotation.ToString()
	//)

	FVector LineTraceEnd = PlayerLocation + PlayerRotation.Vector()*reach;

	// Draw a red trace in the world to visuasdfal
	DrawDebugLine(
		GetWorld(),
		PlayerLocation,
		LineTraceEnd,
		FColor(255, 0, 0),
		false,
		0.f,
		0.f,
		10.f
	);
}
