// Fill out your copyright notice in the Description page of Project Settings.


#include "Chaptor2/CPPCalculation.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h" // 追加
#include "Kismet/KismetMathLibrary.h" // 追加

// Called when the game starts or when spawned
void ACPPCalculation::BeginPlay()
{
	Super::BeginPlay();

	// 変数を作成する
	FString Message = "C++ Hello World!";

	FString add = FString::Printf(TEXT("%d"), CalcVarA + CalcVarB);
	FString sub = FString::Printf(TEXT("%d"), CalcVarA - CalcVarB);
	FString product = FString::Printf(TEXT("%d"), CalcVarA * CalcVarB);
	FString divide = FString::Printf(TEXT("%f"), (float)CalcVarA / CalcVarB);

	// PrintStringノードと同じ処理
	// UKismetSystemLibraryクラスのPrintString関数を呼び出す
	UKismetSystemLibrary::PrintString(this, add, true, true, TextColor, Duration, TEXT("None"));
	UKismetSystemLibrary::PrintString(this, sub, true, true, TextColor, Duration, TEXT("None"));
	UKismetSystemLibrary::PrintString(this, product, true, true, TextColor, Duration, TEXT("None"));
	UKismetSystemLibrary::PrintString(this, divide, true, true, TextColor, Duration, TEXT("None"));

}
