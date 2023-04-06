#pragma once
#include <windows.h>
#include "Input.h"

class Tick
{
public:
    void InitTime();
    void UpdateTime();
    void FixedUpdate(Input* _Input);
    ULONGLONG GetDeltaTime() { return deltaTime; }

public:
    ULONGLONG previousTime;
    ULONGLONG currentTime;
    ULONGLONG deltaTime;

    int updateCount;
    int fixedUpdateCount;
    int fixedEnemyCount;

    int FixedCount;
    bool PlayerMove = true;
    bool FirstInput = true;
};