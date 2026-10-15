// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MyHttpClient.generated.h"

// ★ DYNAMIC 委托必须在 UCLASS 外声明（UE 反射硬规则）
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FOnHttpResponse,
    bool, bSuccess,
    const FString&, Body
);

UCLASS()
class MYPROJECT02_API UMyHttpClient : public UObject
{
    GENERATED_BODY()

public:
    UMyHttpClient();

    // 存分数：POST /save
    UFUNCTION(BlueprintCallable, Category="MyHttpClient")
    void SaveScore(const FString& PlayerId, int32 Value);

    // 读分数：GET /load/{player_id}
    UFUNCTION(BlueprintCallable, Category="MyHttpClient")
    void LoadScore(const FString& PlayerId);

    UPROPERTY(BlueprintAssignable, Category="MyHttpClient")
    FOnHttpResponse OnSaveResponse;

    UPROPERTY(BlueprintAssignable, Category="MyHttpClient")
    FOnHttpResponse OnLoadResponse;

private:
    FString BaseUrl;
};