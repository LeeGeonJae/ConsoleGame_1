#pragma once
#include <windows.h>
#include <conio.h>
#include "Input.h"
#include "Tick.h"
#include "Word.h"

class Player
{
public:
	void Init(int x, int y, Input* _Input);
	void DrawPlayer(Input* _Input);
	void Move(char map[][80], Input* _Input, Tick* _Tick, Word* _Word);
	bool CanMove(char map[][80], Input* _Input, Word* _Word);
	bool CanMoveWord(char map[][80], Input* _Input, Word* _Word);

public:
	COORD PlayerCurrentPosition;
	COORD PlayerNextPosition;
	bool Clear;
};