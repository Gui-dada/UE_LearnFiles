// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/TimelineComponent.h"//timeline ͷ�ļ�
#include "Components/BoxComponent.h"
#include "MyCharacter.h"
#include "GameFramework/Actor.h"
#include "MyTimelineActor.generated.h"

UCLASS()
class MYPROJECT02_API AMyTimelineActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyTimelineActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCurve")
	UCurveFloat* MyCurveFloat;//��������	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySceneComponent")
	UTimelineComponent* MyTimelineComponent;//ʱ�������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySceneComponent")
	USceneComponent* MySceneComponent;//�������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySceneComponent")
	UStaticMeshComponent* MyStaticMeshComponent;//��̬�������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySceneComponent")
	UBoxComponent* MyBoxComponent;//�������

	FOnTimelineFloat MyTimelineStartDelegate;//ʱ���ḡ�㷵�ش���
	FOnTimelineEvent MyTimelineFinishDelegate;//ʱ�����¼����ش���

	UFUNCTION()
	void TimelineStart(float value);//ʱ���Ὺʼ
	//UFUNCTION()
	//void TimelineUpdate(float value);//ʱ�������
	UFUNCTION()
	void TimelineFinish();//ʱ�������
	//��ײ�󶨺���
	UFUNCTION()
	void BeginOverlapFunc(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,const FHitResult& SweepResult);
	UFUNCTION()
	void EndOverlapFunc(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
