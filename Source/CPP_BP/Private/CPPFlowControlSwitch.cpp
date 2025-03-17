// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPFlowControlSwitch.h"

// Sets default values
ACPPFlowControlSwitch::ACPPFlowControlSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPFlowControlSwitch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPPFlowControlSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// chaptor34. note.
// switchの説明なので割愛。C#と一緒。
// case 1: { ... }のように中括弧が必要なくらい。

// chaptor35. note.
// 列挙型についてもコンセプトはC#と一緒
// 文法ちょっと違うが、調べれば分かるはず。
// UMETAを指定するとBluePrintで表示されるキー名を変えられるくらい