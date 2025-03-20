// Fill out your copyright notice in the Description page of Project Settings.

#include "CPPInputEvent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACPPInputEvent::ACPPInputEvent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPInputEvent::BeginPlay()
{
	Super::BeginPlay();
	
	SetupInput();
}

void ACPPInputEvent::SetupInput()
{
	// 入力を有効にする
	EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	// HキーのPressedとReleasedをバインドする
	InputComponent->BindKey(EKeys::H, IE_Pressed, this, &ACPPInputEvent::PressedH);
	InputComponent->BindKey(EKeys::H, IE_Released, this, &ACPPInputEvent::ReleasedH);

	UKismetSystemLibrary::PrintString(this, "bind sita yo-", true, true, FColor(50, 50, 255), 5.0f, TEXT("None"));
}

void ACPPInputEvent::PressedH(){
	UKismetSystemLibrary::PrintString(this, "Pressed H!", true, true, FColor(255, 50, 50), 5.0f, TEXT("None"));
}

void ACPPInputEvent::ReleasedH(){
	UKismetSystemLibrary::PrintString(this, "Released H!", true, true, FColor(50, 255, 50), 5.0f, TEXT("None"));
}

