// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyAIagent.generated.h"

UCLASS()
class MYPROJECT02_API AMyAIagent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyAIagent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	/** Test Value Property */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
	int TestValue;
};