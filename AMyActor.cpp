// Fill out your copyright notice in the Description page of Project Settings.
#include "AMyActor.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AAMyActor::AAMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Position = FVector2D(0.0f, 0.0f);
	totalDistance = 0.0f;
	eventCount = 0;

}

// Called when the game starts or when spawned
void AAMyActor::BeginPlay()
{
	Super::BeginPlay();

	Move();
	
	float distance = Distance(Position,Position);
	
}

// Called every frame
void AAMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


int32 AAMyActor::Step() {

	return FMath::RandRange(-1,1);
}

float AAMyActor::Distance(FVector2D first, FVector2D second) {
	  
	return FVector2D::Distance(first,second);
}

int32 AAMyActor::createEvent() {
	return FMath::RandRange(0, 1);
}

void AAMyActor::Move() {
	FVector2D first = Position;
	FVector2D second;

	for (int i = 0; i < 10; i++) {
	
		int32 stepX = Step();
		int32 stepY = Step();
		second = Position;

		Position.X += stepX;
		Position.Y += stepY;
		float distance = Distance(first, second);
		totalDistance += distance;
		
		if (createEvent() == 1) {
			eventCount++;
			UE_LOG(LogTemp, Warning, TEXT("Step %d : Event triggered : O , Position = (%f,%f) , Distance = %f "),i + 1 , Position.X , Position.Y, distance);
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Step %d : Event triggered : X , Position = (%f,%f) , Distance = %f "), i + 1, Position.X , Position.Y, distance);
		}

		first = second;
	}

	UE_LOG(LogTemp, Warning, TEXT("Total Distance : %f , Total Event : %d"), totalDistance, eventCount);
}

