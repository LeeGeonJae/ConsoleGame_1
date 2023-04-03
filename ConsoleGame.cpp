#pragma once
#include <iostream>
#include <Windows.h>
#include "Engine.h"

using namespace std;

int main()
{
    Engine* _Engine = new Engine;

    _Engine->Init();

    while (1)
    {
        _Engine->Update();
    }

    return 0;
}
