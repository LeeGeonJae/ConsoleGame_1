#pragma once
#include "Stage.h"
#include "Tick.h"
#include "Input.h"
#include <string>

class Render
{
public:
	void Init();
	void Update(Tick* _Tick, Input* _Input);
	void PrintCountsPerSecond(Tick* _Tick, Input* _Input);
	void narration(const char* narration, Tick* _Tick, Input* _Input, int num);

public:
	Stage* _Stage = new Stage;
	int GameNumber = 0;

public:
	// 나레이션 관련 변수들
	char _narration[100];
	int narrationCount = 0;
	int narrationNext = 0;
	bool narrationStop = true;
	bool narrationReset = false;
	int NarrationDelay = 70;

};