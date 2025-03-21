// Fill out your copyright notice in the Description page of Project Settings.


#include "Chaptor3/CPPAccessParent.h"
#include "Chaptor3/CPPAccessOther.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACPPAccessOther::ACPPAccessOther()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPAccessOther::BeginPlay()
{
	Super::BeginPlay();
	
	// ViewportにあるACPPAccessParentを探す
	AActor* FoundActor = UGameplayStatics::GetActorOfClass(GetWorld(),ACPPAccessParent::StaticClass());
	ACPPAccessParent* CPPAccessParent = Cast<ACPPAccessParent>(FoundActor);

	// CPPAccessParentのデータメンバ(Public)を変更する
	CPPAccessParent->VarPublicNum = 1000;
	// CPPAccessParent->VarProtectedNum = 2000;
	// CPPAccessParent->VarPrivateNum = 3000;

	// CPPAccessParentのメンバ関数(Public)を呼び出す
	CPPAccessParent->CallPublicFunc();
	// CPPAccessParent->CallProtectedFunc();
	// CPPAccessParent->CallPrivateFunc();
}

// Called every frame
void ACPPAccessOther::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// note.
// GameObject.Find().GetComponent()的な?
// UGameplayStatics::GetActorOfClass + Cast<ACPPAccessParent>