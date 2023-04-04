#include "Tick.h"
#include <iostream>

using namespace std;

void Tick::InitTime()
{
    currentTime = previousTime = GetTickCount64();
    updateCount = 0;
    fixedUpdateCount = 0;
}

void Tick::UpdateTime()
{
    previousTime = currentTime;
    currentTime = GetTickCount64();

    deltaTime = currentTime - previousTime;
    updateCount += 1;
}

// 0.1�ʸ��� ����Ǵ� FixedUpdate
void Tick::FixedUpdate()
{
    static ULONGLONG elapsedTime;

    elapsedTime += GetDeltaTime();

    while (elapsedTime >= 100) //0.1��
    {
        fixedUpdateCount += 1;

        elapsedTime = 0;
    }
}