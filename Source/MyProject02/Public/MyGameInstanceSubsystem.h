// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MyMulThreadClass.h"
#include "MyGameInstanceSubsystem.generated.h"

/**
 *
 */
UCLASS()
class MYPROJECT02_API UMyGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	//��������ʵ��ʱ��ʹ��static����������ʵ����ָ��
	static UMyGameInstanceSubsystem* MyGameInstance; //ȫ�ֵ�����Ҫstatic
	UFUNCTION(BlueprintCallable, Category = "MyGameInstanceSubsystem")
	static UMyGameInstanceSubsystem* GetMyGameInstance();
	UFUNCTION(BlueprintCallable, Category = "MyGameInstanceSubsystem")
	void startThread();
	UFUNCTION(BlueprintCallable, Category = "MyGameInstanceSubsystem")
	void stopThread();
private:
	//����ָ��
	TSharedPtr<FMyMulThreadClass> MyThreadPtr; //�߳���ָ��
	//FMyMulThreadClass* MyThread; //�߳���
	FRunnableThread* Thread; //�߳�
	//FThreadSafeBool bRunThread; //�̰߳�ȫ����ֵ

};
