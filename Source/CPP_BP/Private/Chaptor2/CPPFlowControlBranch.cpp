// Fill out your copyright notice in the Description page of Project Settings.


#include "Chaptor2/CPPFlowControlBranch.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h" // 追加
#include "Kismet/KismetMathLibrary.h" // 追加

// Sets default values
ACPPFlowControlBranch::ACPPFlowControlBranch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPFlowControlBranch::BeginPlay()
{
	Super::BeginPlay();
	
	if(IsPrintHello){
		UKismetSystemLibrary::PrintString(this, "Hello World", true, true, TextColor, Duration, TEXT("None"));
	}else{
		FString add = FString::Printf(TEXT("%d"), CalcVarA + CalcVarB);
		FString sub = FString::Printf(TEXT("%d"), CalcVarA - CalcVarB);
		FString product = FString::Printf(TEXT("%d"), CalcVarA * CalcVarB);
		FString divide = FString::Printf(TEXT("%f"), (float)CalcVarA / CalcVarB);
		UKismetSystemLibrary::PrintString(this, add, true, true, TextColor, Duration, TEXT("None"));
		UKismetSystemLibrary::PrintString(this, sub, true, true, TextColor, Duration, TEXT("None"));
		UKismetSystemLibrary::PrintString(this, product, true, true, TextColor, Duration, TEXT("None"));
		UKismetSystemLibrary::PrintString(this, divide, true, true, TextColor, Duration, TEXT("None"));
	}

	// note.
	// 比較演算子や三項演算子、論理演算子はC#と一緒
	// ここはばっちりなので割愛。
	
}
