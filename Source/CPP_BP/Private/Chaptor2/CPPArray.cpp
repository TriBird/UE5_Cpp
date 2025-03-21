// Fill out your copyright notice in the Description page of Project Settings.


#include "Chaptor2/CPPArray.h"
#include <Kismet/KismetSystemLibrary.h>

// Sets default values
ACPPArray::ACPPArray()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPArray::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<FString> message_array = {
		TEXT("C++ Hello World!"),
		TEXT("你好 世界!"),
		TEXT("Bonjour le monde!"),
		TEXT("Hallo Welt!"), 
		TEXT("こんにちは世界!")
	};

	int color_r = 50;
	for (FString message : message_array){
		UKismetSystemLibrary::PrintString(this, message, true, true, FColor(color_r, 255, 255), 5.0f, TEXT("None"));
		color_r += 20;
	}

	int color_b = 50;
	for (int i=0; i<message_array.Num(); i++){
		UKismetSystemLibrary::PrintString(this, message_array[i], true, true, FColor(255, color_b, 255), 5.0f, TEXT("None"));
		color_b += 20;

		// これで抜ける、C#と同じ
		if(i != 0) break;
	}

	// 配列削除しながらなくなるまでprintし続ける
	while(message_array.Num() != 0){
		UKismetSystemLibrary::PrintString(this, message_array[0], true, true, FColor(255, 255, 50+(message_array.Num()*20)), 5.0f, TEXT("None"));
		message_array.RemoveAt(0);
	}

}

// Called every frame
void ACPPArray::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// note.
// TArrayは動的配列
// TEXTマクロを使わないと2Byte文字が文字化けする
// foreachで全部の要素に対して処理したいときは？追加・削除は？
// > refer. https://zenn.dev/posita33/books/ue5_starter_cpp_and_bp_001/viewer/chap_90_cpp-array_control#イテレーション

// note. 
// Unityでは無限ループを組むとエディタがフリーズするが、UE5はどうなん
// > GPT: UE5でもスレッドロックは発生し、エディタごと落ちるらしい

// note.
// 構造体はC#でもあまり使ったことないので割愛。
// structのメリットは？
// > GPT: 継承なしのシンプルなデータ構造に適しており、メモリ効率がよい
