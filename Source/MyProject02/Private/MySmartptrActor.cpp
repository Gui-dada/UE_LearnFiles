// Fill out your copyright notice in the Description page of Project Settings.


#include "MySmartptrActor.h"

// Sets default values
AMySmartptrActor::AMySmartptrActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMySmartptrActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMySmartptrActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

