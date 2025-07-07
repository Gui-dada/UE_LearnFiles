// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));//�������ɱ�
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));//�������
	MyWidgetHealth = CreateDefaultSubobject<UWidgetComponent>(TEXT("MyWidgetHealth"));//����С�������
	MyWidgetHealth->SetupAttachment(RootComponent);//����С����������ӵ������
	static ConstructorHelpers::FClassFinder<UUserWidget> WidgetAsset(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UMGWidget.UMGWidget_C'"));//����С������ͼ
	if (WidgetAsset.Succeeded()) {
		MyWidgetHealth->SetWidgetClass(WidgetAsset.Class);//����С������
	}
	MyWidgetHealth->SetRelativeLocation(FVector(0, 0, 100));//����С����λ��
	MyWidgetHealth->SetWidgetSpace(EWidgetSpace::Screen);//����С�����ռ�
	MyWidgetHealth->SetDrawSize(FVector2D(400, 20));//����С������С
	SpringArm->TargetArmLength = 400;//�����������
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);//����������ӵ����ɱ�
	SpringArm->SetupAttachment(RootComponent);//���õ��ɱ۸��ӵ������
	SpringArm->bUsePawnControlRotation = true;//���õ��ɱ�ʹ��Pawn������ת

	bUseControllerRotationPitch = false;//���ÿ���������
	bUseControllerRotationRoll = false;//���ÿ���������
	bUseControllerRotationYaw = false;//���ÿ�����ƫ��

	GetCharacterMovement()->bOrientRotationToMovement = true;//���ý�ɫ�ƶ������ת���ƶ�����
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();//���ø����BeginPlay����
	if (Controller != nullptr)
	{
		if (APlayerController* pcp = Cast<APlayerController>(Controller))
		{
			if (UEnhancedInputLocalPlayerSubsystem* localsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(pcp->GetLocalPlayer()))
			{
				localsystem->AddMappingContext(InputMappingContext, 0);
			}
		}
	}
	Attack();//����
	CalculateBleed();//������Ѫ
	//���ö�ʱ�� (��� ,���� ,���ð󶨵ĺ���,ѭ��ʱ��,�Ƿ��ӡ)
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMyCharacter::TimerFunction, 1.0f, true);
	//������ʱ��
	if (TimerHandle.IsValid()) {
		GetWorldTimerManager().ClearTimer(TimerHandle);
	}
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	StartLocation = Camera->GetComponentLocation();//��ȡ���λ��
	ForwardVector = Camera->GetForwardVector();//��ȡ���ǰ����
	EndLocation = StartLocation + ForwardVector * 10000;//��ȡ����λ��
	//����ͨ����ⷵ�صĽ��
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility);//���߼��
	if(bHit)
	{
		AActor* HitActor = HitResult.GetActor();//��ȡ��ײ��actor
		FVector hitpoint = HitResult.ImpactPoint;//��ȡ��ײλ��
		FVector HitLocation = HitResult.ImpactPoint;//��ȡ��ײλ��
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("LineTraceSingleByChannel------*HitActor->GetName : %s"),*HitActor->GetName()));

	}

	//���ݶ����ⷵ�صĽ��
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
	bool bHit2 = GetWorld()->LineTraceSingleByObjectType(HitResult, StartLocation, EndLocation, ObjectQueryParams);//���߼��
	if (bHit2)
	{
		AActor* HitActor2 = HitResult.GetActor();//��ȡ��ײ��actor
		FVector hitpoint2 = HitResult.ImpactPoint;//��ȡ��ײλ��
		FVector HitLocation2 = HitResult.ImpactPoint;//��ȡ��ײλ��
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("LineTraceSingleByObjectType------*HitActor->GetName : %s"), *HitActor2->GetName()));
	}

	bool HitRetMulti = GetWorld()->LineTraceMultiByChannel(HitResults, StartLocation, EndLocation, ECC_Visibility);//���߼��
	if (HitRetMulti)
	{
		for (int32 i = 0; i < HitResults.Num(); i++)
		{
			AActor* HitActor3 = HitResults[i].GetActor();//��ȡ��ײ��actor
			FVector hitpoint3 = HitResults[i].ImpactPoint;//��ȡ��ײλ��
			FVector HitLocation3 = HitResults[i].ImpactPoint;//��ȡ��ײλ��
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("LineTraceMultiByChannel------*HitActor->GetName : %s"), *HitActor3->GetName()));
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("LineTraceMultiByChannel------No Hit")));
	}

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))//ǿ��ת��
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyCharacter::Move);//���ƶ�
		//EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyCharacter::Move);//���ƶ�
		//EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMyCharacter::Look);//�󶨲鿴
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMyCharacter::Look);//�󶨲鿴
	}
}

void AMyCharacter::Move(const FInputActionValue& value)
{
	FVector2D MoveMent = value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		const FRotator ControlRot = Controller->GetControlRotation();//��ȡ����������ת
		const FRotator ControlYawRot(0, ControlRot.Yaw, 0);//��ȡ��������ƫ����ת
		const FVector ForwardDirection = FRotationMatrix(ControlYawRot).GetUnitAxis(EAxis::X);//��ȡǰ��
		const FVector RightForward = FRotationMatrix(ControlYawRot).GetUnitAxis(EAxis::Y);//��ȡ����

		//AddMovementInput(Direction, MoveMent.X);
		//AddMovementInput(Direction, MoveMent.Y);
		AddMovementInput(RightForward, MoveMent.X);//���ǰ���ƶ�����
		AddMovementInput(ForwardDirection, MoveMent.Y);//��������ƶ�����

	}
}

void AMyCharacter::Look(const FInputActionValue& value)
{

	FVector2D LookAxisVector = value.Get<FVector2D>();
	if (Controller != nullptr) {
		AddControllerYawInput(LookAxisVector.X);//��ӿ�����x������
		AddControllerPitchInput(LookAxisVector.Y);//��ӿ�����y������
	}
}

void AMyCharacter::Attack()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT(" void AMyCharacter::Attack() ")));//�����Ļ������Ϣ
}

void AMyCharacter::CalculateBleed()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT(" void AMyCharacter::CalculateBleed() ")));//�����Ļ������Ϣ
}

void AMyCharacter::TimerFunction()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT(" void AMyCharacter::TimerFunction() ")));//�����Ļ������Ϣ
}

