#pragma once
#include "Render.h"
#include "Tick.h"
#include "Input.h"

class Engine
{
public:
	void Init();
	void Update();

public:
	// �ʿ��� Ŭ���� ������ ����
	Tick* _Tick = new Tick;
	Render* _Render = new Render;
	Input* _Input = new Input;
};