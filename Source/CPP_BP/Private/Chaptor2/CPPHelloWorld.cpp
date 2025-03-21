// Fill out your copyright notice in the Description page of Project Settings.


#include "Chaptor2/CPPHelloWorld.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
// UnityのUpdateに対応
ACPPHelloWorld::ACPPHelloWorld()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
// UnityのStartに該当
void ACPPHelloWorld::BeginPlay()
{
	Super::BeginPlay();
	UKismetSystemLibrary::PrintString(this, "C++ Hello World!", true, true, FColor::Cyan, 2.f, TEXT("None"));

	// print
	UE_LOG(LogTemp, Display, TEXT("Display message"));
	UE_LOG(LogTemp, Warning, TEXT("Display message"));
	UE_LOG(LogTemp, Error, TEXT("Display message"));

	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::White, "C++ Hello World!", true, FVector2D(2.0f, 2.0f));

}

// Called every frame
void ACPPHelloWorld::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

