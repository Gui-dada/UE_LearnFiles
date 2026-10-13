// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyHelper.h"

// Sets default values
AMyHelper::AMyHelper()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyHelper::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyHelper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}