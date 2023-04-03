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
	_Render->Update(_Tick);
	_Tick->UpdateTime();
	//_Render->PrintCountsPerSecond(_Tick, _Input);
}