#include "Tick.h"
#include <iostream>

using namespace std;

void Tick::InitTime()
{
    currentTime = previousTime = GetTickCount64();
    updateCount = 0;
    fixedUpdateCount = 0;
    fixedEnemyCount = 0;
    FixedCount = 0;
}

void Tick::UpdateTime()
{
    previousTime = currentTime;
    currentTime = GetTickCount64();

    deltaTime = currentTime - previousTime;
    updateCount += 1;
}

// 0.1초마다 실행되는 FixedUpdate
void Tick::FixedUpdate(Input* _Input)
{
    static ULONGLONG elapsedTime;

    elapsedTime += GetDeltaTime();

    while (elapsedTime >= 100) //0.1초
    {
        fixedUpdateCount += 1;
        FixedCount++;
        fixedEnemyCount += 1;
        elapsedTime = 0;

        // 플레이어가 이동하는 중이면 실행
        if (FixedCount >= 1 && FirstInput == false
            && (_Input->IsDownCmdOn() || _Input->IsLeftCmdOn() || _Input->IsRightCmdOn() || _Input->IsUpCmdOn()))
        {
            FixedCount = 0;
            PlayerMove = true;
            FirstInput = false;
        }
        else if (FixedCount >= 5)                       // 플레이어가 입력을 하지 않았을 때
        {
            FixedCount = -3;
            FirstInput = true;
        }
    }
}