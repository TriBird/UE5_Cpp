// Fill out your copyright notice in the Description page of Project Settings.


#include "Chaptor3/CPPAccessChild.h"

void ACPPAccessChild::BeginPlay()
{
	// Super::BeginPlay();

	// データメンバ(Public)を変更する
	VarPublicNum = 100;
	VarProtectedNum = 200;
	// VarPrivateNum = 300;

	// 基底クラスのメンバ関数(Public)を呼び出す
	CallPublicFunc();

	// 基底クラスのメンバ関数(Protected)を呼び出す
	CallProtectedFunc();

	// 基底クラスのメンバ関数(Private)を呼び出す
	// CallPrivateFunc();
}

// note.
// privateは派生クラスからでもアクセスできない。
// protectedは派生クラス以外からアクセスできないのでは
// publicはどこからでもOKなはず