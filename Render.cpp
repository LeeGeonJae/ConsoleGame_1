#include "Render.h"
#include <iostream>
#include <windows.h>

using namespace std;

void Render::Init()
{
}

void Render::Update(Tick* _Tick, Input* _Input)
{
    if (GameNumber == 0)                                                        // Menu
    {
        _Stage->Menu(_Input);

        if (_Input->IsSpaceCmdOn())                                             // Space bar를 누르면 해당 항목 선택
        {
            _Input->Set(ESCAPE_KEY_INDEX, false);
            if (_Stage->y == 15)
            {
                _Stage->y = 15;
                GameNumber = 1;
                system("cls");
            }
            else if (_Stage->y == 16)
            {
                _Stage->y = 15;
                GameNumber = 100;
                system("cls");
            }
            else if (_Stage->y == 17)
                GameNumber = -1;

            _Stage->Once = false;
            narrationReset = true;

            Sleep(150);
        }
    }
    else if (GameNumber == 1)                                                   // 스테이지1으로 이동
    {
        _Stage->StageOne(_Input);

    }
    else if (GameNumber == 100)                                                 // 게임 정보란으로 이동
    {
        _Stage->GameInformation(_Input);

        if (_Input->IsSpaceCmdOn())                                             // 게임 정보란에서 스페이스바를 누르면 다시 돌아오기
        {
            _Input->Set(ESCAPE_KEY_INDEX, false);
            system("cls");
            narrationReset = true;
            _Stage->Once = false;

            GameNumber = 0;
            Sleep(200);
        }
    }


    narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // 나레이션 실행
}

// 1초마다 실행되어 화면에 출력하는 함수
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

        elapsedTime = 0;
        _Tick->updateCount = 0;
    }
}

void Render::narration(const char* narration, Tick* _Tick, Input* _Input, int num)
{
    static int x = 35;
    static int y = 24;

    // NarrationReset : 맵이 달라지면 나레이션 초기화 하고 다음 스테이지의 나레이션으로 초기 세팅
    if (narrationReset)
    {
        narrationCount = 0;
        narrationNext = 0;
        narrationStop = true;
        narrationReset = false;
        _Tick->fixedUpdateCount = 0;
        for (int i = -1; i < 100; i++)
        {
            _Input->Gotoxy(i, y);
            cout << " ";
        }
    }

    // 인자에 받은 나레이션의 배열값을 가져와서 복사하기
    if (num != narrationNext && narrationStop == true)
    {
        strcpy_s(_narration, narration);

        // 나레이션 자막 한 글자씩 그리기 ( fixedUpdateCount 사용함 )
        if (narrationCount != _Tick->fixedUpdateCount)
        {
            // 나레이션 대화창 만들기
            _Input->Gotoxy(2, 22);
            cout << "#############################################################################";
            _Input->Gotoxy(2, 26);
            cout << "#############################################################################";

            _Input->Gotoxy(x + _Tick->fixedUpdateCount - strlen(_narration) / 2, y);
            cout << _narration[_Tick->fixedUpdateCount - 1];
            narrationCount = _Tick->fixedUpdateCount;

            if (strlen(_narration) == _Tick->fixedUpdateCount)
                narrationStop = false;

            // 나레이션을 다 지우고 다음 나레이션 배열로 이동해서 다음 나레이션 작동하기
            if (strlen(_narration) < _Tick->fixedUpdateCount && strlen(narration) != 0 && num != narrationNext)
            {
                narrationNext++;
                _Tick->fixedUpdateCount = 0;

                if (num != narrationNext)
                {
                    for (int i = -1; i < 100; i++)
                    {
                        _Input->Gotoxy(i, y);
                        cout << " ";
                    }
                }
            }
        }
    }

    // NarrationDelay 시간동안 기존 n번에 있는 Narrationarr[n]을 지우지 않고 기다리기
    if (_Tick->fixedUpdateCount == NarrationDelay)
    {
        narrationStop = true;
    }
}