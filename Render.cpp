#include "Render.h"
#include <iostream>
#include <windows.h>

using namespace std;

void Render::Init()
{
}

void Render::Update(Tick* _Tick)
{
    narration(narrationarr[narrationNext], _Tick, 3);
}

void Render::PrintCountsPerSecond(Tick* _Tick, Input* _Input)
{
    static ULONGLONG elapsedTime;

    elapsedTime += _Tick->GetDeltaTime();
    if (elapsedTime >= 1000)
    {
        system("cls");

        cout << "elapsedTime : " << elapsedTime << endl;
        cout << "updateCount : " << _Tick->updateCount << endl;
        cout << "fixedUpdateCount : " << _Tick->fixedUpdateCount << endl;

        if (_Input->IsSpaceCmdOn())
        {
            _Input->Set(ESCAPE_KEY_INDEX, false);
            cout << "스페이스 입력" << endl;
        }
        if (_Input->IsLeftCmdOn())
        {
            _Input->Set(USER_CMD_LEFT, false);
            cout << "왼쪽 입력" << endl;
        }
        if (_Input->IsRightCmdOn())
        {
            _Input->Set(USER_CMD_RIGHT, false);
            cout << "오른쪽 입력" << endl;
        }
        if (_Input->IsUpCmdOn())
        {
            _Input->Set(USER_CMD_UP, false);
            cout << "위 입력" << endl;
        }
        if (_Input->IsDownCmdOn())
        {
            _Input->Set(USER_CMD_DOWN, false);
            cout << "아래 입력" << endl;
        }

        printf("%s\n", _narration);

        elapsedTime = 0;
        _Tick->updateCount = 0;
    }
}

void Render::narration(const char* narration, Tick* _Tick, int num)
{
    if (num != narrationNext)
    {
        strcpy_s(_narration, narration);

        if (narrationCount != _Tick->fixedUpdateCount)
        {
            cout << narration[_Tick->fixedUpdateCount - 1];
            narrationCount = _Tick->fixedUpdateCount;

            if (strlen(_narration) < _Tick->fixedUpdateCount && strlen(narration) != 0 && num != narrationNext)
            {
                narrationNext++;
                _Tick->fixedUpdateCount = 0;

                if (num != narrationNext)
                    system("cls");
            }
        }
    }
}
