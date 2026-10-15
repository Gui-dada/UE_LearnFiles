// Copyright Epic Games, Inc. All Rights Reserved.
#include "MyHttpClient.h"

#include "Dom/JsonObject.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"

UMyHttpClient::UMyHttpClient()
{
    BaseUrl = TEXT("http://localhost:8000");
}

void UMyHttpClient::SaveScore(const FString& PlayerId, int32 Value)
{
    // 构造 JSON body
    TSharedPtr<FJsonObject> Json = MakeShared<FJsonObject>();
    Json->SetStringField(TEXT("player_id"), PlayerId);
    Json->SetNumberField(TEXT("value"), Value);

    FString BodyStr;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&BodyStr);
    FJsonSerializer::Serialize(Json.ToSharedRef(), Writer);

    // 发请求
    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request =
        FHttpModule::Get().CreateRequest();
    Request->SetURL(BaseUrl + TEXT("/save"));
    Request->SetVerb(TEXT("POST"));
    Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    Request->SetContentAsString(BodyStr);

    // ★ 用 TWeakObjectPtr 防止 UObject 销毁后回调访问野指针
    TWeakObjectPtr<UMyHttpClient> WeakThis(this);
    Request->OnProcessRequestComplete().BindLambda(
        [WeakThis](FHttpRequestPtr /*Req*/, FHttpResponsePtr Resp, bool bOk)
        {
            if (!WeakThis.IsValid())
            {
                return;
            }
            const bool bSuccess =
                bOk && Resp.IsValid() && Resp->GetResponseCode() == 200;
            const FString ResponseBody =
                Resp.IsValid() ? Resp->GetContentAsString() : TEXT("");
            WeakThis->OnSaveResponse.Broadcast(bSuccess, ResponseBody);
        }
    );
    Request->ProcessRequest();
}

void UMyHttpClient::LoadScore(const FString& PlayerId)
{
    const FString Url = BaseUrl + TEXT("/load/") + PlayerId;

    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request =
        FHttpModule::Get().CreateRequest();
    Request->SetURL(Url);
    Request->SetVerb(TEXT("GET"));

    TWeakObjectPtr<UMyHttpClient> WeakThis(this);
    Request->OnProcessRequestComplete().BindLambda(
        [WeakThis](FHttpRequestPtr /*Req*/, FHttpResponsePtr Resp, bool bOk)
        {
            if (!WeakThis.IsValid())
            {
                return;
            }
            const bool bSuccess =
                bOk && Resp.IsValid() && Resp->GetResponseCode() == 200;
            const FString ResponseBody =
                Resp.IsValid() ? Resp->GetContentAsString() : TEXT("");
            WeakThis->OnLoadResponse.Broadcast(bSuccess, ResponseBody);
        }
    );
    Request->ProcessRequest();
}