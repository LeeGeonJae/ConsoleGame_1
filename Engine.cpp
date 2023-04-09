#include "Engine.h"
#include <Windows.h>

void Engine::Init()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT windowSize = { 0, 0, 120, 45 }; // â ũ�� ���� (�»��, ���ϴ�)
	SetConsoleWindowInfo(hConsole, TRUE, &windowSize); // â ũ�� ����

	_Input->Init();
	_Tick->InitTime();
	_Render->Init();
}

void Engine::Update()
{
	_Input->UpdateInput(&(_Tick->FirstInput));
	_Tick->FixedUpdate(_Input);
	_Tick->UpdateTime();
	_Render->Update(_Tick, _Input);
	//_Render->PrintCountsPerSecond(_Tick, _Input);
}