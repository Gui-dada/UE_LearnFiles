// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Async/AsyncWork.h"

/**
 * 
 */
class MYPROJECT03_API FMyAsyncClass : public FNonAbandonableTask
{
	friend class FAutoDeleteAsyncTask<FMyAsyncClass>;//��Ԫ��
public:
	FMyAsyncClass();
	~FMyAsyncClass();
public:
	// ����������첽�߳�ִ�еĺ���
	void DoWork();
	// ������������߳�ִ�еĺ���
	FORCEINLINE TStatId GetStatId() const
	{
		//��һ��������ͳ��ID���ڶ���������ͳ����
		RETURN_QUICK_DECLARE_CYCLE_STAT(FMyAsyncClass, STATGROUP_ThreadPoolAsyncTasks);
	}
	FORCEINLINE static const TCHAR* GetStatName()
	{
		return TEXT("FMyAsyncClass");
	}
};
