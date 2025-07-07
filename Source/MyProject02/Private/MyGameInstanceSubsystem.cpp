// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstanceSubsystem.h"

UMyGameInstanceSubsystem* UMyGameInstanceSubsystem::MyGameInstance = nullptr;
bool UMyGameInstanceSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return true;
}

void UMyGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	MyGameInstance = this;
	UE_LOG(LogTemp, Warning, TEXT("MyGameInstanceSubsystem Initialized"));
}

void UMyGameInstanceSubsystem::Deinitialize()
{
	Super::Deinitialize();
	UE_LOG(LogTemp, Warning, TEXT("MyGameInstanceSubsystem Deinitialized"));
}
UMyGameInstanceSubsystem* UMyGameInstanceSubsystem::GetMyGameInstance()
{
	return MyGameInstance;
}

void UMyGameInstanceSubsystem::startThread()
{
	// ȷ���ַ���ת��Ϊ TCHAR ����  
	MyThreadPtr = MakeShared<FMyMulThreadClass>(TEXT("MyThreadPtr"));//text�е����ݻᱻת��ΪTCHAR����

	FString ThreadName = MyThreadPtr->ThreadName;
	Thread = FRunnableThread::Create(MyThreadPtr.Get(), *ThreadName);
	UE_LOG(LogTemp, Warning, TEXT("UMyGameInstanceSubsystem::startThread()"));

}

void UMyGameInstanceSubsystem::stopThread()
{
	if (MyThreadPtr.IsValid()) {
		MyThreadPtr->Stop();
	}
	if (Thread) {
		Thread->WaitForCompletion();//�ȴ��߳����
		delete Thread;//ɾ���߳�
		Thread = nullptr;//�ÿ��߳�ָ��
	}
	UE_LOG(LogTemp, Warning, TEXT("UMyGameInstanceSubsystem::stopThread() "));
}
