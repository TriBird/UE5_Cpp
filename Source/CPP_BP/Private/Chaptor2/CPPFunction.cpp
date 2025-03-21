// Fill out your copyright notice in the Description page of Project Settings.


#include "Chaptor2/CPPFunction.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h" // 追加
#include "Kismet/KismetMathLibrary.h" // 追加

// Sets default values
ACPPFunction::ACPPFunction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPFunction::BeginPlay()
{
	Super::BeginPlay();
	

	switch(cal_type){
		case ECPPCalcType::Add: {
			FString result = FString::Printf(TEXT("%d"), Sum(3, 5));
			UKismetSystemLibrary::PrintString(this, result, true, true, TextColor, Duration, TEXT("None"));
			break;
		}
		case ECPPCalcType::Subtract: {
			FString result = FString::Printf(TEXT("%d"), Subtract(3, 5));
			UKismetSystemLibrary::PrintString(this, result, true, true, TextColor, Duration, TEXT("None"));
			break;
		}
	}
	
}

// Called every frame
void ACPPFunction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 ACPPFunction::Sum(int32 A, int32 B)
{
	return A + B;
}

int32 ACPPFunction::Subtract(int32 A, int32 B)
{
	return A - B;
}

// note.
// 関数内のローカルスコープの感覚は大体Ｃ＃と一緒
// 関数の引数における参照渡しは&をつける。 int32 ACPPFunc::Add(int32& a)みたいな。
// 配列や関数を渡す場合も&をつけるのか？
// > gptの回答: 配列そのものを参照渡ししたい場合は&を明示的に付ける必要があります。
// 参照渡しとポインタはどう違うのか？
// > gptの回答: nullptrを渡せるか or 動的に変更できるか、など