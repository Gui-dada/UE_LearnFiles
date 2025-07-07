// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTextAsyncActor.h"
#include "FMyAsyncClass.h"
#include "Async/Async.h"
// Sets default values
AMyTextAsyncActor::AMyTextAsyncActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyTextAsyncActor::BeginPlay()
{
	Super::BeginPlay();
	// ����һ���첽����
	//FAutoDeleteAsyncTask<FMyAsyncClass>* MyAsyncTask = new FAutoDeleteAsyncTask<FMyAsyncClass>();
	// �����첽���� �̳߳�
	//MyAsyncTask->StartBackgroundTask();
	//�����첽���� ͬ���߳�
	//MyAsyncTask->StartSynchronousTask();
	// �����������ִ��һЩ�����Ĳ������������UI��


	Async(EAsyncExecution::LargeThreadPool,[]()
	{// �������첽�߳�ִ�еĴ���
		// �����������ִ��һЩ��ʱ�Ĳ��������������Դ���������ݵ�
		// ע�⣺������������첽�߳���ִ�еģ����Բ���ֱ�ӷ������̵߳�UIԪ��
		// �����ʹ��UE4�ṩ���̰߳�ȫ�ķ���������UI������ʹ��AsyncTask����FGraphEventRef��
		UE_LOG(LogTemp, Warning, TEXT("Async task is running......"));
	});
}
	

// Called every frame
void AMyTextAsyncActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

