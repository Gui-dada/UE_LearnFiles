// Fill out your copyright notice in the Description page of Project Settings.


#include "MySoftReferenceActor.h"
#include "Engine/AssetManager.h"

// Sets default values
AMySoftReferenceActor::AMySoftReferenceActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AMySoftReferenceActor::BeginPlay()
{
	
	Super::BeginPlay();//继承父类BeginPlay函数
	//同步加载资源
	FSoftObjectPath Path1 = TEXT("/Script/Engine.Texture2D'/Game/StarterContent/Textures/T_Brick_Clay_Beveled_D.T_Brick_Clay_Beveled_D'");
	TSharedPtr<FStreamableHandle> SycStreamHandle1 = UAssetManager::GetStreamableManager().RequestSyncLoad(Path1);//请求同步加载资源
	if (SycStreamHandle1.IsValid())
	{
		SycStreamHandle1->WaitUntilComplete();//等待加载完成
		UTexture2D* Texture = Cast<UTexture2D>(SycStreamHandle1->GetLoadedAsset());//导入的资源
		if (Texture)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("SycStreamHandle1 : Texture->GetName : %s"), *Texture->GetName()));//添加屏幕调试信息
		}
		//释放资源
		SycStreamHandle1->ReleaseHandle();
	}
	//异步加载资源
	FSoftObjectPath Path2 = TEXT("/Script/Engine.Texture2D'/Game/StarterContent/Textures/T_Brick_Clay_Beveled_M.T_Brick_Clay_Beveled_M'");//资源路径
	TSharedPtr<FStreamableHandle> AsycStreamHandle1 = UAssetManager::GetStreamableManager().RequestAsyncLoad(Path2);//请求异步加载资源
	if (AsycStreamHandle1.IsValid())
	{
		AsycStreamHandle1->WaitUntilComplete();//等待加载完成
		UTexture2D* Texture = Cast<UTexture2D>(SycStreamHandle1->GetLoadedAsset());//导入的资源
		if (Texture)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("AsycStreamHandle1 : Texture->GetName : %s"), *Texture->GetName()));//添加屏幕调试信息
		}
		//释放资源
		AsycStreamHandle1->ReleaseHandle();
	}
}

// Called every frame
void AMySoftReferenceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);//继承父类Tick函数

}

