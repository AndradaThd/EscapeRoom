

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "DoorRoom2.h"
#include "AlienTriggerComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CRYPTRAIDER_API UAlienTriggerComponent : public UBoxComponent
{
	GENERATED_BODY()

public:
	UAlienTriggerComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	UFUNCTION(BluePrintCallable)
	void SetDoorRoom2(UDoorRoom2*  DoorRoom2);

private:
	UPROPERTY(EditAnywhere)
	FName KeyTag;

	UDoorRoom2* DoorRoom2;

	AActor* GetAcceptableActor() const;
};

