#include "Engine.h"
#include <Windows.h>

void Engine::Init()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT windowSize = { 0, 0, 120, 45 }; // 창 크기 설정 (좌상단, 우하단)
	SetConsoleWindowInfo(hConsole, TRUE, &windowSize); // 창 크기 조절

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