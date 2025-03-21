// Fill out your copyright notice in the Description page of Project Settings.


#include "Chaptor2/CPPVariable.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h"

// Called when the game starts or when spawned
void ACPPVariable::BeginPlay()
{
	Super::BeginPlay();

	FString message = "Hello World Cpp";

	duration = 3.0f;
	message = UKismetStringLibrary::Conv_DoubleToString(duration);

	UKismetSystemLibrary::PrintString(this, message, true, true, text_color, duration, TEXT("None"));
}



