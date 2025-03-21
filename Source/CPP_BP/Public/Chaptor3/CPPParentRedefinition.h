// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPParentRedefinition.generated.h"

UCLASS()
class CPP_BP_API ACPPParentRedefinition : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPParentRedefinition();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int point;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetPoint(int myPoint);
	int GetPoint();
	
};
