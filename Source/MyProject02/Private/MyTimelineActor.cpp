// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTimelineActor.h"

// Sets default values
AMyTimelineActor::AMyTimelineActor()
{
		// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyTimelineComponent = CreateDefaultSubobject<UTimelineComponent>(TEXT("MyTimelineComponent"));//��ʼ��ʱ�������
	MySceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("MySceneComponent"));//��ʼ���������
	MyStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyStaticMeshComponent"));//��ʼ����̬�������
	MyBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("MyBoxComponent1"));//��ʼ���������
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MyStaticMeshObject(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Architecture/Wall_400x400.Wall_400x400'"));//��ʼ����������
	if (MyStaticMeshObject.Succeeded()) {
		MyStaticMeshComponent->SetStaticMesh(MyStaticMeshObject.Object);//���þ�̬����
	}
	RootComponent = MySceneComponent;//���ø����
	MyStaticMeshComponent->SetupAttachment(RootComponent);//���þ�̬�������
	MyBoxComponent->SetupAttachment(RootComponent);//���ú������
	MyBoxComponent->SetBoxExtent(FVector(200,100,100));//���ú��Ӵ�С
	MyBoxComponent->SetRelativeLocation(FVector(200, 0, 0));//���ú���λ��
}

// Called when the game starts or when spawned
void AMyTimelineActor::BeginPlay()
{
	Super::BeginPlay();
	MyTimelineStartDelegate.BindUFunction(this, FName("TimelineStart"));//�󶨿�ʼ
	MyTimelineFinishDelegate.BindUFunction(this, FName("TimelineFinish"));//�󶨽���	
	MyTimelineComponent->AddInterpFloat(MyCurveFloat, MyTimelineStartDelegate);//��Ӳ�ֵ����
	//MyTimelineComponent->SetLooping(false);//����ѭ��
	//MyTimelineComponent->PlayFromStart();//��ͷ��ʼ
	//MyTimelineComponent->Play();
	MyTimelineComponent->SetTimelineFinishedFunc(MyTimelineFinishDelegate);//����ʱ�����������
	//������ײ��

	MyBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AMyTimelineActor::BeginOverlapFunc);//��ʼ��ײ
	MyBoxComponent->OnComponentEndOverlap.AddDynamic(this, &AMyTimelineActor::EndOverlapFunc);//������ײ


}

// Called every frame
void AMyTimelineActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTimelineActor::TimelineStart(float value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT(" void AMyTimelineActor::TimelineStart() ")));//�����Ļ������Ϣ)
	//������ת
	float YawRotation = FMath::Lerp(0.0f, 90.0f, value);
	FRotator NewRotation = FRotator(0, YawRotation, 0);//������ת
	MyStaticMeshComponent->SetRelativeRotation(NewRotation);//������ת
}

void AMyTimelineActor::TimelineFinish()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("void AMyTimelineActor::TimelineFinish()")));//�����Ļ������Ϣ
}

void AMyTimelineActor::BeginOverlapFunc(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	AMyCharacter* TempMyCharacter = Cast<AMyCharacter>(OtherActor);
	if (TempMyCharacter != nullptr)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("void AMyTimelineActor::BeginOverlapFunc()")));//�����Ļ������Ϣ
		MyTimelineComponent->PlayFromStart();//��ͷ��ʼ
	}
}
void AMyTimelineActor::EndOverlapFunc(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AMyCharacter* TempMyCharacter = Cast<AMyCharacter>(OtherActor);
	if (TempMyCharacter != nullptr)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("void AMyTimelineActor::BeginOverlapFunc()")));//�����Ļ������Ϣ
		MyTimelineComponent->ReverseFromEnd();//���򲥷�
	}
}
