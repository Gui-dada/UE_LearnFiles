// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyPingActor.h"

// Sets default values
AMyPingActor::AMyPingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}