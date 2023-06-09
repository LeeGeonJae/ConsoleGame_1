#include "Render.h"
#include <iostream>
#include <windows.h>

using namespace std;

void Render::Init()
{
    _setmode(_fileno(stdout), _O_U16TEXT);                                                                  // 유니코드 출력을 위한 설정
}

void Render::Update(Tick* _Tick, Input* _Input)
{
    if (GameNumber >= 0 && GameNumber < 10)                                                                 // 게임 시작 시에 오른쪽에 키 설명
    {
        _Stage->SetColor(yellow, black);
        _Input->Gotoxy(90, 3);
        wcout << L"\'W\' : 위";
        _Input->Gotoxy(90, 5);
        wcout << L"\'S\' : 아래";
        _Input->Gotoxy(90, 7);
        wcout << L"\'D\' : 오른쪽";
        _Input->Gotoxy(90, 9);
        wcout << L"\'A\' : 왼쪽";
        _Input->Gotoxy(90, 11);
        wcout << L"\'Space Bar\' : 리셋 및 선택";
        _Stage->SetColor(white, black);
    }

    if (GameNumber == 0)                                                                                    // Menu
    {
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // 나레이션 실행
        _Stage->Menu(_Input);
        PrintCountsPerSecond(_Tick, _Input);

        if (_Input->IsSpaceCmdOn())                                                                         // Space bar를 누르면 해당 항목 선택
        {
            _Input->Set(ESCAPE_KEY_INDEX, false);

            if (_Stage->y == 15)
            {
                _Stage->y = 15;
                GameNumber = 2;
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
    else if (GameNumber == 2)                                                                               // 스테이지1으로 이동
    {
        _Stage->StageOne(_Input, _Tick, &GameNumber);
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 3)
    {
        _Stage->StageTwo(_Input, _Tick, &GameNumber);                                                       // 스테이지2으로 이동
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 4)
    {
        _Stage->StageThree(_Input, _Tick, &GameNumber);                                                     // 스테이지3으로 이동
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // 나레이션 실행
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 5)
    {
        _Stage->StageFour(_Input, _Tick, &GameNumber);                                                      // 스테이지4으로 이동
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // 나레이션 실행
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 6)
    {
        _Stage->StageFive(_Input, _Tick, &GameNumber);                                                      // 스테이지5으로 이동
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // 나레이션 실행
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 7)
    {
        _Stage->StageSix(_Input, _Tick, &GameNumber);                                                      // 스테이지6으로 이동
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // 나레이션 실행
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 8)
    {
        _Stage->StageSeven(_Input, _Tick, &GameNumber);                                                      // 스테이지7으로 이동
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // 나레이션 실행
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 9)
    {
        _Stage->StageEight(_Input, _Tick, &GameNumber);                                                      // 스테이지8으로 이동
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // 나레이션 실행
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 10)
    {
        _Stage->GoodEnging(_Input, _Tick, &GameNumber, PlayTime);                                           // 엔딩으로 이동
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // 나레이션 실행
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 100)                                                                             // 게임 정보란으로 이동
    {
        _Stage->GameInformation(_Input);

        // 게임 정보란에서 스페이스바를 누르면 다시 돌아오기
        if (_Input->IsSpaceCmdOn())
        {
            _Input->Set(ESCAPE_KEY_INDEX, false);
            system("cls");
            narrationReset = true;
            _Stage->Once = false;

            GameNumber = 0;
            Sleep(200);
        }
    }

    if (_Stage->_word->GameNumber == 101)                                                                   // 플레이 도중 게임이 오버되면 실행
    {
        _Stage->GameOver(_Input, &GameNumber);
        _Stage->_word->GameNumber = 0;
    }
    else if (_Stage->_word->GameNumber == 102)                                                              // 이스터 에그를 찾았을 시에 살행
    {
        GameNumber = 20;
        for (int i = 0; i < 45; i++)                                                                        // 샌즈 그리기
        {
            for (int j = 0; j < 120; j++)
            {
                _Input->Gotoxy(j, i);
                wcout << Senz3[i][j];
            }
            wcout << endl;
        }
        _Input->Gotoxy(0, 47);
        _Stage->SetColor(lightblue, black);
        wcout << L"        이런! 이스터 에그를 찾아냈구나? 축하의 의미로 스페이스 바를 누르면 게임을 클리어 할 수 있게 보내줄게!" << endl;
        wcout << L"                  싫다고? 그러면 아무 방향의 화살표를 누르면 다시 메뉴 창으로 보내줄게!" << endl;

        if (_Input->IsSpaceCmdOn())                                                                         // Space bar를 누르면 해당 항목 선택
        {
            _Input->Set(ESCAPE_KEY_INDEX, false);
            _Stage->_word->GameNumber = 0;
            _Stage->Once = false;
            narrationReset = true;
            GameNumber = 10;
            system("cls");
        }
        else if (_Input->IsDownCmdOn() || _Input->IsLeftCmdOn() || _Input->IsRightCmdOn() || _Input->IsUpCmdOn())
        {
            _Input->Set(USER_CMD_LEFT, false);
            _Input->Set(USER_CMD_DOWN, false);
            _Input->Set(USER_CMD_RIGHT, false);
            _Input->Set(USER_CMD_UP, false);
            _Stage->Once = false;
            narrationReset = true;
            GameNumber = 0;
            PlayTime = 0;
            _Stage->_word->GameNumber = 0;
            system("cls");
        }
    }


}

// 1초마다 실행되어 화면에 출력하는 함수 ( 테스트 용이라 필요하진 않음 )
void Render::PrintCountsPerSecond(Tick* _Tick, Input* _Input)
{
    static ULONGLONG elapsedTime = 1000;
    static short senzX = 37;
    static short senzY = 19;
    static bool SenzFPS = true;

    elapsedTime += _Tick->GetDeltaTime();
    if (elapsedTime >= 1000)                // 0.1 초
    {
        // 게임을 시작했을 때, PlayTime 화면에 출력
        if (GameNumber >= 1 && GameNumber != 10)
        {
            PlayTime += 1;
            _Input->Gotoxy(90, 13);
            _Stage->SetColor(lightgreen, black);
            wcout << L"PlayTime : " << PlayTime << L" 초";
            _Stage->SetColor(white, black);
        }
        else
        {
            PlayTime = 0;                                   // 게임 도중이 아닐 시에 PlayTime 0으로 세팅
        }

        // 나레이션의 캐릭터 샌즈 그려주기 ( 2 프레임 )
        if (SenzFPS)
        {
            SenzFPS = false;
            wchar_t tempSenz;
            for (int i = 0; i < 16; i++)
            {
                for (int j = 0; j < 46; j++)
                {
                    _Input->Gotoxy(senzX + j, senzY + i);
                    _Stage->SetColor(black, lightgray);
                    tempSenz = Senz1[i][j];
                    wcout << tempSenz;
                    _Stage->SetColor(white, black);
                }
            }
        }
        else
        {
            SenzFPS = true;
            for (int i = 0; i < 16; i++)
            {
                for (int j = 0; j < 46; j++)
                {
                    _Input->Gotoxy(senzX + j, senzY + i);
					_Stage->SetColor(black, white);
                    wcout << Senz2[i][j];
                    _Stage->SetColor(white, black);
                }
            }
        }

        elapsedTime = 0;
        _Tick->updateCount = 0;
    }
}

// 나레이션 출력하는 함수
void Render::narration(const wchar_t* narration, Tick* _Tick, Input* _Input, int num)
{
    static int x = 58;
    static int y = 38;

    // NarrationReset : 맵이 달라지면 나레이션 초기화 하고 다음 스테이지의 나레이션으로 초기 세팅
    if (narrationReset || _Stage->Once == false)
    {
        narrationCount = 0;
        narrationNext = 0;
        narrationLCount = 0;
        narrationStop = true;
        narrationReset = false;
        for (int i = 0; i < 100; i++)
        {
            _narration[i] = L'\0';
        }
        _Tick->fixedUpdateCount = 0;
        for (int i = -1; i < 100; i++)
        {
            _Input->Gotoxy(i, y);
            wcout << " ";
        }
    }

    // 인자에 받은 나레이션의 배열값을 가져와서 복사하기
    if (num != narrationNext && narrationStop == true && narration != nullptr)
    {
        for (int i = 0; i < 100; i++)
        {
            _narration[i] = L'\0';

        }
        if (wcslen(narration) % 2 != 0)
            wmemcpy(_narration, narration, wcslen(narration) + 1);
        wmemcpy(_narration, narration, wcslen(narration));

        // 각 나레이션 길이 조절하는데 한글은 2칸 나머지는 1칸씩 차지해서 1칸씩 차지하는 문자 찾아서 1씩 증가
        narrationSettingLength = 0;
        for (int i = 0; i < wcslen(narration); i++)
        {
            if (_narration[i] >= L'가' && _narration[i] <= L'힣')
                i++;
            else
                narrationSettingLength++;
        }
        // 나레이션 자막 한 글자씩 그리기 ( fixedUpdateCount 사용함 )
        if (narrationCount != _Tick->fixedUpdateCount)
        {
            // 나레이션 대화창 만들기
            _Stage->SetColor(lightblue, lightblue);
            _Input->Gotoxy(2, y - 2);
            wcout << "######################################################################################################################";
            _Input->Gotoxy(2, y + 2);
            wcout << "######################################################################################################################";
            _Stage->SetColor(lightblue, black);
            
            // 나레이션 커서를 이동시키고 FixedUpdateCount가 1씩 증가할 때마다 출력이 되니 fixedUpdateCount의 수만큼 오른쪽으로 이동해서 단어 출력
			_Input->Gotoxy(x + (_Tick->fixedUpdateCount * 2) - wcslen(_narration) - narrationLCount + narrationSettingLength / 2, y);
            wcout << _narration[_Tick->fixedUpdateCount - 1];
            narrationCount = _Tick->fixedUpdateCount;
            _Stage->SetColor(white, black);

            // 한글이면 2칸 이동, 한글 아니면 1칸 이동
            if ((_narration[_Tick->fixedUpdateCount - 1] >= L'가' && _narration[_Tick->fixedUpdateCount - 1] <= L'힣') == false)
                narrationLCount++;

            // 단어의 길이가 fixedUpdateCount만큼 같아진다면 출력을 그만하기
            if (wcslen(_narration) == _Tick->fixedUpdateCount)
                narrationStop = false;

            // 나레이션을 다 지우고 다음 나레이션 배열로 이동해서 다음 나레이션 작동하기
            if (wcslen(_narration) < _Tick->fixedUpdateCount && wcslen(narration) != 0 && num != narrationNext)
            {
                narrationNext++;
                _Tick->fixedUpdateCount = 0;
                narrationLCount = 0;

                if (num != narrationNext)
                {
                    for (int i = -1; i < 100; i++)
                    {
                        _Input->Gotoxy(i, y);
                        wcout << " ";
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

void Render::GameInfomation(Tick* _Tick, Input* _Input)
{


}