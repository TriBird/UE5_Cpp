// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPEventDispatcher.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACPPEventDispatcher::ACPPEventDispatcher()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// デリゲートにバインド
	OnPrintHello.AddDynamic(this, &ACPPEventDispatcher::PrintHello);
	OnPrintHello.AddDynamic(this, &ACPPEventDispatcher::PrintSeeya);
}

// Called when the game starts or when spawned
void ACPPEventDispatcher::BeginPlay()
{
	Super::BeginPlay();
	
	// 入力を有効にする
	EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	// HキーのPressedとReleasedをバインドする
	InputComponent->BindKey(EKeys::H, IE_Pressed, this, &ACPPEventDispatcher::PressedH);
}

// Called every frame
void ACPPEventDispatcher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Hキー押されたときに発火するイベント
void ACPPEventDispatcher::PressedH(){
	OnPrintHello.Broadcast();
}

// ブロードキャスト先１
void ACPPEventDispatcher::PrintHello(){
	UKismetSystemLibrary::PrintString(this, "Hello Event Dispatcher", true, true, FColor(255, 50, 50), 5.0f, TEXT("None"));
}
// ブロードキャスト先２
void ACPPEventDispatcher::PrintSeeya(){
	UKismetSystemLibrary::PrintString(this, "See you dispatcher", true, true, FColor(50, 255, 50), 5.0f, TEXT("None"));
}

// note.
// イベント発火をブロードキャストできるが、あんまり使い道が分からない
// PrintHello(); PrintSeeya();となにが違う？
// > 実行時に関数を追加・変更したい場合は強い

