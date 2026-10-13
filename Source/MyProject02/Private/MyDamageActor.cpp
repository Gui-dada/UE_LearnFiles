// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDamageActor.h"
#include "GameFramework/Character.h"

// Sets default values
AMyDamageActor::AMyDamageActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyDamageActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyDamageActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// [AI] 添加 ApplyDamage 函数实现
void AMyDamageActor::ApplyDamage(AActor* TargetActor)
{
	if (TargetActor && DamageAmount > 0.0f)
	{
		// 检查目标是否为角色
		ACharacter* TargetCharacter = Cast<ACharacter>(TargetActor);
		if (TargetCharacter)
		{
			// 使用 TakeDamage 函数造成伤害
			//FDamageEvent DamageEvent;
			//TargetCharacter->TakeDamage(DamageAmount, DamageEvent, nullptr, this);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("TargetActor is not a character!"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid target or damage amount!"));
	}
}