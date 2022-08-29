

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DoorRoom2.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UDoorRoom2 : public UActorComponent
{
	GENERATED_BODY()

public:	
	UDoorRoom2();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void SetShouldMove(bool ShouldMove);

private:
	UPROPERTY(EditAnywhere)
	FVector MoveOffset;

	float MoveTime = 4;

	UPROPERTY(EditAnywhere)
	bool ShouldMove = false;

	FVector OriginalLocation;
		
};
