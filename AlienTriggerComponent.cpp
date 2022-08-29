// An Andromeda Production


#include "AlienTriggerComponent.h"
#include "Engine/World.h"


UAlienTriggerComponent::UAlienTriggerComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UAlienTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAlienTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    AActor* Actor = GetAcceptableActor();
    if(Actor != nullptr)
    {
        UPrimitiveComponent* Component =Cast<UPrimitiveComponent>(Actor->GetRootComponent());  //check if it is a primitive component
        if(Component != nullptr)
        {
            Component->SetSimulatePhysics(false);
        }
        Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
        DoorRoom2->SetShouldMove(true);
    }
    else
    {
        DoorRoom2->SetShouldMove(false);
    }
    
}

void UAlienTriggerComponent::SetDoorRoom2(UDoorRoom2*  NewDoorMover)
{
    DoorRoom2 = NewDoorMover;
}

AActor* UAlienTriggerComponent::GetAcceptableActor() const
{
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);

    for(AActor* Actor: Actors)
    {
        bool HasAcceptableTag = Actor->ActorHasTag(KeyTag);
        bool IsGrabbed = Actor->ActorHasTag("Grabbed");

        if(HasAcceptableTag && !IsGrabbed)
        {
            return Actor;
        }
    }
    return nullptr;
}
