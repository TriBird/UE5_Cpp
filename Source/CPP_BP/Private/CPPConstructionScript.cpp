// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPConstructionScript.h"
#include "Kismet/KismetSystemLibrary.h"

void ACPPConstructionScript::OnConstruction(const FTransform& Transform)
{
	// PointLightの表示・非表示を設定
	PointLight->SetVisibility(bIsVisible);

	// PointLightのLightColorを設定
	PointLight->SetLightColor(LightColor);

	// PointLightの強さを設定
	PointLight->SetIntensity(Intensity);
}

ACPPConstructionScript::ACPPConstructionScript()
{
	// SceneComponentをRootComponentに設定する。
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	// SceneComponentをRootComponentに設定する
	RootComponent = DefaultSceneRoot;

	// StaticMeshをLaodしてStaticMeshComponentのStaticMeshに設定する
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Game/CPP_BP/Meshes/SM_SampleCube"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(Mesh);
	StaticMesh->SetupAttachment(RootComponent);

	// ArrowComponentのアタッチ
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	Arrow->SetRelativeLocation(FVector(50.0f, 0.0f, 0.0f));
	Arrow->SetupAttachment(StaticMesh);

	// PointLightComponentのアタッチ
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComponent"));
	PointLight->SetRelativeLocation(FVector(130.0f, 0.0f, 0.0f));
	PointLight->SetupAttachment(StaticMesh);
}

// Called when the game starts or when spawned
void ACPPConstructionScript::BeginPlay()
{
	Super::BeginPlay();

	// 変数を作成する
	FString Message = "C++ Hello World!";

	// PrintStringノードと同じ処理
	// UKismetSystemLibraryクラスのPrintString関数を呼び出す
	UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration, TEXT("None"));
}