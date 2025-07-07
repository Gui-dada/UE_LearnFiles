// Fill out your copyright notice in the Description page of Project Settings.


#include "MyStringActor.h"
#include "Kismet/KismetStringLibrary.h"
// ����Ĭ��ֵ
AMyStringActor::AMyStringActor()
{
	// �������Actor�Ƿ���Ա���������������Ƿ���Ա��������
	PrimaryActorTick.bCanEverTick = true;

}

// ����Ϸ��ʼ������ʱ����
void AMyStringActor::BeginPlay()
{
	Super::BeginPlay();
	
}

//  ��ÿһ֡����
void AMyStringActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyStringActor::MyStringOperation(FString MyString)
{
	//�ж��ַ����Ƿ�������ַ���
	bool isFind1 = MyString.Contains("b",ESearchCase::IgnoreCase,ESearchDir::FromStart);
	bool isFind2 = UKismetStringLibrary::Contains(MyString, "b", ESearchCase::IgnoreCase, ESearchDir::FromStart);
	//�ж��ַ����Ƿ����
	bool isEquals1 = MyString.Equals("abcd_1234",ESearchCase::IgnoreCase);
	bool isEquals2 = UKismetStringLibrary::EqualEqual_StrStr(MyString, "abcd_1234");
	//ƴ���ַ���
	FString MyString1 = MyString + TEXT("efgh_5678");
	FString MyString2 = UKismetStringLibrary::Concat_StrStr(MyString, TEXT("efgh_5678"));
	//�鿴����
	int32 MyStringLength1 = MyString.Len();
	int32 MyStringLength2 = UKismetStringLibrary::Len(MyString);//�ַ��������ⷽ��
	//�ж�Ϊ��
	bool isNull1 = MyString.IsEmpty();
	bool isNull2 = UKismetStringLibrary::IsEmpty(MyString);
	//��ȡ���ַ���
	FString MySubString1 = MyString.Mid(0, 4);
	FString MySubString2 = UKismetStringLibrary::GetSubstring(MyString, 0, 4);
	//��ȡ���ַ����ĳ���
	int32 MySubStringLength1 = MySubString1.Len();
	int32 MySubStringLength2 = UKismetStringLibrary::Len(MySubString2);
	//
}

