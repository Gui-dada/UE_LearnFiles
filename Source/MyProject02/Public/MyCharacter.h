// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Controller.h"//������
#include "GameFramework/Character.h"//
#include "GameFramework/SpringArmComponent.h"//���ɱ�
#include "Camera/CameraComponent.h"//�����
#include "GameFramework/CharacterMovementComponent.h"//��ɫ�ƶ����
#include "MyInterface.h"//�ӿ�
#include "TimerManager.h"
#include "Components/WidgetComponent.h"
#include "MyCharacter.generated.h"

UCLASS()
class MYPROJECT02_API AMyCharacter : public ACharacter, public IMyInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MySceneComponent")
		USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MySceneComponent")
		UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		class UInputMappingContext* InputMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		class UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		class UInputAction* LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MySceneComponent")
	    UWidgetComponent* MyWidgetHealth;


	void Move(const FInputActionValue& value);
	void Look(const FInputActionValue& value);

	//��д�ӿں���
	virtual void Attack() override;
	virtual void CalculateBleed() override;
	

	FTimerHandle TimerHandle;//��ʱ�����
	void TimerFunction();//��ʱ������

	//����
	FVector StartLocation;
	FVector ForwardVector;
	FVector EndLocation;
	FHitResult HitResult;
	TArray <FHitResult> HitResults;//

	
};