// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPCalcType.h"
#include "GameFramework/Actor.h"
#include "CPPFunction.generated.h"

UCLASS()
class CPP_BP_API ACPPFunction : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPFunction();

	// 関数の作成
	int32 Sum(int32 A, int32 B);
	int32 Subtract(int32 A, int32 B);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// PrintString関数のDurationに設定する変数
	const float Duration = 100.0f;

	// PrintString関数のTextColorに設定する変数
	const FLinearColor TextColor = FColor(255, 255, 255);

	// 設定できるようにする
	UPROPERTY(EditAnywhere)
	ECPPCalcType cal_type = ECPPCalcType::Add;

};
