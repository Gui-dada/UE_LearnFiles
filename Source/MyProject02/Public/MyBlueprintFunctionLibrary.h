// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 *
 */
UCLASS()
class MYPROJECT02_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "FileLibrary")//�����ļ���Դ
		static bool LoadStringFromFile(const FString& FilePath, FString& RetString);
	UFUNCTION(BlueprintCallable, Category = "FileLibrary")//д���ļ���Դ
		static bool WriteStringToFile(TArray<FString> SaveArray, const FString& FilePath);
	UFUNCTION(BlueprintCallable, Category = "FileLibrary")//��ȡ�ļ�·��
		static FString GetFilePath(const FString& FileName);
	UFUNCTION(BlueprintCallable, Category = "FileLibrary")//��ȡ�ļ���
		static FString GetFileName(const FString& FilePath, bool bRemovePath);
	UFUNCTION(BlueprintCallable, Category = "FileLibrary")//��ȡ�ļ���׺
		static FString GetFileSuffix(const FString& FilePath);
	UFUNCTION(BlueprintCallable, Category = "FileLibrary")//�����ļ���
		static void CreateDirectory(const FString DirectoryPath);
	UFUNCTION(BlueprintCallable, Category = "FileLibrary")//ɾ���ļ���
		static void DeleteDirectory(const FString& DirectoryPath);
	UFUNCTION(BlueprintCallable, Category = "FileLibrary")//�ƶ��ļ���
		static bool MoveDirectory(const FString& SourceDirectory, const FString& DestinationDirectory);
	UFUNCTION(BlueprintCallable, Category = "FileLibrary")//�����ļ�Ŀ¼�������ļ�
		static TArray<FString> FindFilesInDirectory(const FString& DirectoryPath, const FString Filter,bool File,bool Directory);
	UFUNCTION(BlueprintCallable, Category = "Json")//
		static void JsonValue(FString JsonString);
		


};
