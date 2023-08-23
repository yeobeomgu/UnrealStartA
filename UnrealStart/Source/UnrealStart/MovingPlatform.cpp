// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
	SetActorLocation(CurrentLocation);
	
	// ::을 입력해서 그 클래스 내부에 있는 함수 중 어떤 함수를 사용할 수 있는지
	float DistanceMoved = FVector::Distance(StartLocation, CurrentLocation);
	if(DistancMoved > MoveDistance)
	{
		PlatformVelecity = -PlatformVelocity;
		StartLocation = CurrentLocation;
	}


}

