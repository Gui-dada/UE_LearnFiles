// Fill out your copyright notice in the Description page of Project Settings.


#include "FMyAsyncClass.h"

FMyAsyncClass::FMyAsyncClass()
{
}

FMyAsyncClass::~FMyAsyncClass()
{
	UE_LOG(LogTemp, Warning, TEXT("FMyAsyncTask End......"));
}

void FMyAsyncClass::DoWork()
{
	// �������첽�߳�ִ�еĴ���
	// �����������ִ��һЩ��ʱ�Ĳ��������������Դ���������ݵ�
	// ע�⣺������������첽�߳���ִ�еģ����Բ���ֱ�ӷ������̵߳�UIԪ��
	// �����ʹ��UE4�ṩ���̰߳�ȫ�ķ���������UI������ʹ��AsyncTask����FGraphEventRef��
	UE_LOG(LogTemp, Warning, TEXT("FMyAsyncClass::DoWork() is running......"));

}


