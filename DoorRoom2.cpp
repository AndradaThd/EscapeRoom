


#include "DoorRoom2.h"
#include "Math/UnrealMathUtility.h"



UDoorRoom2::UDoorRoom2()
{
	PrimaryComponentTick.bCanEverTick = true;

}



void UDoorRoom2::BeginPlay()
{
	Super::BeginPlay();
	OriginalLocation = GetOwner()->GetActorLocation();
}


void UDoorRoom2::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector TargetLocation = OriginalLocation;
	if(ShouldMove)
	{
		TargetLocation = OriginalLocation + MoveOffset;
	}
	FVector CurrentLocation = GetOwner()->GetActorLocation();

	float Speed = MoveOffset.Length()/MoveTime;

	FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);

	GetOwner()->SetActorLocation(NewLocation);

}

void UDoorRoom2::SetShouldMove(bool NewShouldMove)
{
	ShouldMove = NewShouldMove;
}
