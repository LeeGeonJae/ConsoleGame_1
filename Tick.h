#pragma once
#include <windows.h>

class Tick
{
public:
    void InitTime();
    void UpdateTime();
    void FixedUpdate();
    ULONGLONG GetDeltaTime() { return deltaTime; }

public:
    ULONGLONG previousTime;
    ULONGLONG currentTime;
    ULONGLONG deltaTime;

    int updateCount;
    int fixedUpdateCount;
};

