// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMaterialActor.h"
#include "Kismet/KismetSystemLibrary.h"
// Sets default values
AMyMaterialActor::AMyMaterialActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyScene = CreateDefaultSubobject<USceneComponent>(TEXT("MyScene"));//����һ���������
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));//����һ����̬�������
	RootComponent = MyScene;//��MyScene����Ϊ�����
	MyMesh->SetupAttachment(MyScene);//��MyMesh���ӵ�MyScene
	//��̬��������
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MyMeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Wedge_B.Shape_Wedge_B'"));
	if (MyMeshAsset.Succeeded())
	{
		MyMesh->SetStaticMesh(MyMeshAsset.Object);//���þ�̬����
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load mesh!"));//����ʧ��
	}
}

// Called when the game starts or when spawned
void AMyMaterialActor::BeginPlay()
{
	Super::BeginPlay();
	//��̬���ز���
	UMaterialInterface* MyMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("/Script/Engine.Material'/Game/TextMaterial.TextMaterial'"));
	if (MyMaterial)
	{
		MyMaterialInstance = MyMesh->CreateDynamicMaterialInstance(0, MyMaterial);//������̬����ʵ��
		MyMaterialInstance->SetVectorParameterValue("BaseColor", FLinearColor::Red);//���ò��ʲ���
		MyMaterialInstance->SetScalarParameterValue("BaseMetallic", 1);//���ò��ʲ���
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load material!"));//����ʧ��
	}
	//ʵ��delay����
	const FLatentActionInfo LatentInfo(0,FMath::Rand(),TEXT("DelayFunction"), this);
	UKismetSystemLibrary::Delay(this, 4.0f, LatentInfo);//�ӳ�2��
}

// Called every frame
void AMyMaterialActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyMaterialActor::DelayFunction(float DelayTime)
{
	//�ӳ�DelayTime���ӡ����
	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("DelayFunction called!"));//��ӡ����
	//�ӳ�DelayTime��
	//FTimerHandle TimerHandle;
	//GetWorld()->GetTimerManager().SetTimer(TimerHandle, [=]()
	//	{
	//		UE_LOG(LogTemp, Warning, TEXT("DelayFunction finished!"));
	//	}, DelayTime, false);
	//�ӳ���ɺ����LatentInfo
	
}

