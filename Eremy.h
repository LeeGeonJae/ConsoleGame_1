#pragma once
#include <iostream>
#include <Windows.h>
#include "Tick.h"

class Eremy
{
public:
	void Init(int x, int y, Input* _Input);
	void Move(char map[][80], Tick* _Tick, Input* _Input, int Speed);
	void DrawEremy(Input* _Input);

public:
	COORD EremyCurrentPosition;
	COORD EremyNextPosition;
	bool Delete;
};

