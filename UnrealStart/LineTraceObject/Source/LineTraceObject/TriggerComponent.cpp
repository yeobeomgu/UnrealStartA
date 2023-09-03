// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"



UTriggerComponent::UTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UTriggerComponent::BeginPlay()
{
	
	Super::BeginPlay();
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* Actor = GetAcceptableActor();
	if (Actor != nullptr)
	{
		//UE_LOG(LogTemp, Display, TEXT("Unlocking"));

		UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
		if (Component != nullptr)
		{
			Component->SetSimulatePhysics(false);
		}
		Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);

		Mover->SetShouldMove(true);

	}
	else
	{
		//UE_LOG(LogTemp, Display, TEXT("Relocking"));

		Mover->SetShouldMove(false);
	}
	

}

void UTriggerComponent::SetMover(UMover* NewMover)
{
	Mover = NewMover;
}

AActor* UTriggerComponent::GetAcceptableActor() const
{
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);

	//TArray�� ��� ���͸� ��ȸ�ϴ� �ڵ�
	for (AActor* Actor : Actors)
	{
		//�Ҹ��� ��������
		// ture && false = false
		//true || false == true
		bool HasAcceptableTag = Actor->ActorHasTag(AcceptableActorTag);
		bool IsGrabbed = Actor->ActorHasTag("Grabbed");
		if (HasAcceptableTag && !IsGrabbed)
		{
			UE_LOG(LogTemp, Error, TEXT("Let's Go"));
			return Actor;
		}
	}

	return nullptr;
}
