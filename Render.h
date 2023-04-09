﻿#pragma once
#include "Stage.h"
#include "Tick.h"
#include "Input.h"
#include <string>
#include <io.h>
#include <fcntl.h>

class Render
{
public:
	void Init();
	void Update(Tick* _Tick, Input* _Input);
	void PrintCountsPerSecond(Tick* _Tick, Input* _Input);
	void narration(const wchar_t* narration, Tick* _Tick, Input* _Input, int num);
	void GameInfomation(Tick* _Tick, Input* _Input);

public:
	Stage* _Stage = new Stage;
	int GameNumber = 0;
	int PlayTime = 0;

public:
	// 나레이션 관련 변수들
	wchar_t _narration[100];
	int narrationCount = 0;
	int narrationNext = 0;
	bool narrationStop = true;
	bool narrationReset = false;
	int NarrationDelay = 70;
	int narrationLCount = 0;
	int narrationSettingLength = 0;


	wchar_t Senz1[16][26] = {
	{L"@@@@@@@@@*;;;;*@@@@@@@@@@"},
	{L"@@@@@@@;.       !@@@@@@@@"},
	{L"@@@@@@,          .@@@@@@@"},
	{L"@@@@@@            ;@@@@@@"},
	{L"@@@@@@ -;;~  .;;:  @@@@@@"},
	{L"@@@@@@*@@#@  :$*@# @@@@@@"},
	{L"@@@@@@~@@#*,--$*@:;@@@@@@"},
	{L"@@@@@@, :*.!$ *=- @@@@@@@"},
	{L"@@@@@@  ;  ~;   = @@@@@@@"},
	{L"@@@@@@ ;-;;;;;;*$ @@@@@@@"},
	{L"@@@@;;* ,;$: ~*- !;,@@@@@"},
	{L"@@@#  $!. ~;;;  !: #@@@@@"},
	{L"@@@@@;-:@*:;;:*@$ ;@-$@@@"},
	{L"@@#*@;@#.;* .=!:;@@@@!@@@"},
	{L"@$*@@ @@--$*;=-@@@@@@#~@@"},
	{L"@*@@@ $=,,@ -=:@@*-@@@-$@"},
	};

	wchar_t Senz2[16][26]{
	{L"@@@@@@@@@@;;;;;@@@@@@@@@@"},
	{L"@@@@@@@@;       .=@@@@@@@"},
	{L"@@@@@@#           ;@@@@@@"},
	{L"@@@@@@~            @@@@@@"},
	{L"@@@@@@ ,:;;.  ~;;, @@@@@@"},
	{L"@@@@@@ @@*@:  @;@@ @@@@@@"},
	{L"@@@@@@~@@*@,: *;@@ @@@@@@"},
	{L"@@@@@@# -=: @~,$~ *@@@@@@"},
	{L"@@@@@@= $.  ;-  ,- @@@@@@"},
	{L"@@@@@@=:#::;;:;;@: @@@@@@"},
	{L"@@@@@;@  ~;:~ =#  @.:@@@@"},
	{L"@@@@  .@;  ;;;: .*  !@@@@"},
	{L"@@@@@@; *@;:;:;@@;~@@:#@@"},
	{L"@@@!@@@@!~$, ,#;.!@;@@;@@"},
	{L"@@;@@@@@@=~@;=:-@@@ @@*=@"},
	{L"@=$@@@*;;!*: !--@$- @@@,@"},
	};
};