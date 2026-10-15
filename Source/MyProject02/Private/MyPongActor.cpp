// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyPongActor.h"

// Sets default values
AMyPongActor::AMyPongActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyPongActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPongActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}