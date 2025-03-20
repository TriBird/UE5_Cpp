// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPEventDispatcher.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPrintHelloDelegate);

UCLASS()
class CPP_BP_API ACPPEventDispatcher : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPEventDispatcher();

	FPrintHelloDelegate OnPrintHello;

	// Custom Event[PrintHello] 
	UFUNCTION()
	void PrintHello();
	UFUNCTION()
	void PrintSeeya();

	void PressedH();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
