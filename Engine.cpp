#include "Engine.h"
#include <Windows.h>

void Engine::Init()
{
	_Input->Init();
	_Tick->InitTime();
	_Render->Init();
}

void Engine::Update()
{
	_Input->UpdateInput();
	_Tick->FixedUpdate();
	_Tick->UpdateTime();
	_Render->Update(_Tick, _Input);
	//_Render->PrintCountsPerSecond(_Tick, _Input);
}