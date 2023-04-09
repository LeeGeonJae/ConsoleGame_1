#pragma once
#include <iostream>
#include <Windows.h>
#include "Engine.h"

using namespace std;

int main()
{
    // Engine 클래스 생성
    Engine* _Engine = new Engine;

    // Init
    _Engine->Init();

    while (_Engine->_Render->GameNumber != -1)
    {
        // Update
        _Engine->Update();
    }
    system("cls");

    _Engine->_Input->Gotoxy(48, 15);
    wcout << L"게임을 종료하셨습니다" << endl;

    return 0;
}