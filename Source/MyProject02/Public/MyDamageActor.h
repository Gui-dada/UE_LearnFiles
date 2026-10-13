// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyDamageActor.generated.h"

UCLASS()
class MYPROJECT02_API AMyDamageActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyDamageActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// [AI] 添加伤害属性
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float DamageAmount;

	// [AI] 添加 ApplyDamage 函数
	UFUNCTION(BlueprintCallable, Category = "Damage")
	void ApplyDamage(AActor* TargetActor);
};