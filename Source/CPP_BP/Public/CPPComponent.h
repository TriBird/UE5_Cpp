// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "Components/PointLightComponent.h"
#include "CPPComponent.generated.h"

UCLASS()
class CPP_BP_API ACPPComponent : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// PrintString関数のDurationに設定する変数
	const float Duration = 10.0f;

	// PrintString関数のTextColorに設定する変数
	const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0);

	// root component
	UPROPERTY(EditAnywhere)
	TObjectPtr<USceneComponent> DefaultSceneRoot;

	// static mesh
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> StaticMesh;

	// PointLightComponent Component
	UPROPERTY(EditAnywhere)
	TObjectPtr<UPointLightComponent> PointLight;

	// Arrow Component
	// プロパティは表示されるが、設定を変更できないようにする設定
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UArrowComponent> Arrow;

	// component applied
	ACPPComponent();
};
