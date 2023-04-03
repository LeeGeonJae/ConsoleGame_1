#pragma once
#include "Stage.h"
#include "Tick.h"
#include "Input.h"
#include <string>

class Render
{
public:
	void Init();
	void Update(Tick* _Tick);
	void PrintCountsPerSecond(Tick* _Tick, Input* _Input);
	void narration(const char* narration, Tick* _Tick, int num);

public:
	Stage* _Stage = new Stage;
	char _narration[50];
	int narrationCount = 0;
	int narrationNext = 0;

	const char* narrationarr[5] = { "�ȳ��ϼ���", "����Դϴ�", "�׽�Ʈ �ϰ� �ֽ��ϴ�" };
};

