// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HAL/Runnable.h"//��ӿ�������ͷ�ļ�
#include "HAL/ThreadSafeBool.h"//����̰߳�ȫ����ֵͷ�ļ�


/**
 *
 */
class MYPROJECT02_API FMyMulThreadClass : public FRunnable
{
public:
	FMyMulThreadClass();
	FMyMulThreadClass(FString threadername)
		:ThreadName(threadername) {}; //���캯��
	~FMyMulThreadClass();
	virtual bool   Init() override; //��ʼ������
	virtual uint32 Run()  override; //���к���
	virtual void   Stop() override; //ֹͣ����
	FString ThreadName; //�߳�����
	bool bRunThread ; //�߳����б�־
	FCriticalSection ThreadLock; //�߳���
};
