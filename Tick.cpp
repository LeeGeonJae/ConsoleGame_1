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

// 0.1�ʸ��� ����Ǵ� FixedUpdate
void Tick::FixedUpdate(Input* _Input)
{
    static ULONGLONG elapsedTime;

    elapsedTime += GetDeltaTime();

    while (elapsedTime >= 100) //0.1��
    {
        fixedUpdateCount += 1;
        FixedCount++;
        fixedEnemyCount += 1;
        elapsedTime = 0;

        // �÷��̾ �̵��ϴ� ���̸� ����
        if (FixedCount >= 1 && FirstInput == false
            && (_Input->IsDownCmdOn() || _Input->IsLeftCmdOn() || _Input->IsRightCmdOn() || _Input->IsUpCmdOn()))
        {
            FixedCount = 0;
            PlayerMove = true;
            FirstInput = false;
        }
        else if (FixedCount >= 5)                       // �÷��̾ �Է��� ���� �ʾ��� ��
        {
            FixedCount = -3;
            FirstInput = true;
        }
    }
}