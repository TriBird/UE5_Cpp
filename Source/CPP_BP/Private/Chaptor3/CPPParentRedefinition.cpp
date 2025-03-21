// Fill out your copyright notice in the Description page of Project Settings.


#include "Chaptor3/CPPParentRedefinition.h"

// Sets default values
ACPPParentRedefinition::ACPPParentRedefinition()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPParentRedefinition::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPPParentRedefinition::SetPoint(int myPoint)
{
	point = myPoint;
}

int ACPPParentRedefinition::GetPoint()
{
	return point;
}

// Called every frame
void ACPPParentRedefinition::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

