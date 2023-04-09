#include "Render.h"
#include <iostream>
#include <windows.h>

using namespace std;

void Render::Init()
{
    _setmode(_fileno(stdout), _O_U16TEXT); // �����ڵ� ����� ���� ����
}

void Render::Update(Tick* _Tick, Input* _Input)
{
    if (GameNumber >= 0 && GameNumber < 10)
    {
        _Stage->SetColor(yellow, black);
        _Input->Gotoxy(90, 3);
        wcout << L"\'W\' : ��";
        _Input->Gotoxy(90, 5);
        wcout << L"\'S\' : �Ʒ�";
        _Input->Gotoxy(90, 7);
        wcout << L"\'D\' : ������";
        _Input->Gotoxy(90, 9);
        wcout << L"\'A\' : ����";
        _Input->Gotoxy(90, 11);
        wcout << L"\'Space Bar\' : ���� �� ����";
        _Stage->SetColor(white, black);
    }

    if (GameNumber == 0)                                                                                    // Menu
    {
        _Stage->Menu(_Input);
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // �����̼� ����
        PrintCountsPerSecond(_Tick, _Input);

        if (_Input->IsSpaceCmdOn())                                                                         // Space bar�� ������ �ش� �׸� ����
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
    else if (GameNumber == 2)                                                                               // ��������1���� �̵�
    {
        _Stage->StageOne(_Input, _Tick, &GameNumber);
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 3)
    {
        _Stage->StageTwo(_Input, _Tick, &GameNumber);                                                       // ��������2���� �̵�
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 4)
    {
        _Stage->StageThree(_Input, _Tick, &GameNumber);                                                     // ��������3���� �̵�
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // �����̼� ����
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 5)
    {
        _Stage->StageFour(_Input, _Tick, &GameNumber);                                                      // ��������4���� �̵�
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // �����̼� ����
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 6)
    {
        _Stage->StageFive(_Input, _Tick, &GameNumber);                                                      // ��������5���� �̵�
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // �����̼� ����
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 7)
    {
        _Stage->StageSix(_Input, _Tick, &GameNumber);                                                      // ��������6���� �̵�
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // �����̼� ����
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 8)
    {
        _Stage->StageSeven(_Input, _Tick, &GameNumber);                                                      // ��������7���� �̵�
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // �����̼� ����
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 9)
    {
        _Stage->StageEight(_Input, _Tick, &GameNumber);                                                      // ��������8���� �̵�
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // �����̼� ����
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 10)
    {
        _Stage->GoodEnging(_Input, _Tick, &GameNumber, PlayTime);                                                      // ��������8���� �̵�
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // �����̼� ����
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 100)                                                                             // ���� ���������� �̵�
    {
        _Stage->GameInformation(_Input);

        // ���� ���������� �����̽��ٸ� ������ �ٽ� ���ƿ���
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

    if (_Stage->_word->GameNumber == 101)                                                                   // �÷��� ���� ������ �����Ǹ� ����
    {
        _Stage->GameOver(_Input, &GameNumber);
        _Stage->_word->GameNumber = 0;
    }
    else if (GameNumber == 102)
    {

    }

    
}

// 1�ʸ��� ����Ǿ� ȭ�鿡 ����ϴ� �Լ� ( �׽�Ʈ ���̶� �ʿ����� ���� )
void Render::PrintCountsPerSecond(Tick* _Tick, Input* _Input)
{
    static ULONGLONG elapsedTime = 1000;
    static short senzX = 47;
    static short senzY = 19;
    static bool SenzFPS = true;

    elapsedTime += _Tick->GetDeltaTime();
    if (elapsedTime >= 1000)                // 0.1 ��
    {
        if (GameNumber >= 1 && GameNumber != 10)
        {
            PlayTime += 1;
            _Input->Gotoxy(90, 13);
            _Stage->SetColor(lightgreen, black);
            wcout << L"PlayTime : " << PlayTime << L" ��";
            _Stage->SetColor(white, black);
        }
        else
        {
            PlayTime = 0;
        }

        if (SenzFPS)
        {
            SenzFPS = false;
            wchar_t tempSenz;
            for (int i = 0; i < 16; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    _Input->Gotoxy(senzX + j, senzY + i);
                    _Stage->SetColor(blue, black);
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
                for (int j = 0; j < 26; j++)
                {
                    _Input->Gotoxy(senzX + j, senzY + i);
					_Stage->SetColor(blue, black);
                    wcout << Senz2[i][j];
                    _Stage->SetColor(white, black);
                }
            }
        }

        elapsedTime = 0;
        _Tick->updateCount = 0;
    }
}

// �����̼� ����ϴ� �Լ�
void Render::narration(const wchar_t* narration, Tick* _Tick, Input* _Input, int num)
{
    static int x = 58;
    static int y = 38;

    // NarrationReset : ���� �޶����� �����̼� �ʱ�ȭ �ϰ� ���� ���������� �����̼����� �ʱ� ����
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

    // ���ڿ� ���� �����̼��� �迭���� �����ͼ� �����ϱ�
    if (num != narrationNext && narrationStop == true && narration != nullptr)
    {
        for (int i = 0; i < 100; i++)
        {
            _narration[i] = L'\0';

        }
        if (wcslen(narration) % 2 != 0)
            wmemcpy(_narration, narration, wcslen(narration) + 1);
        wmemcpy(_narration, narration, wcslen(narration));

        // �� �����̼� ���� �����ϴµ� �ѱ��� 2ĭ �������� 1ĭ�� �����ؼ� 1ĭ�� �����ϴ� ���� ã�Ƽ� 1�� ����
        narrationSettingLength = 0;
        for (int i = 0; i < wcslen(narration); i++)
        {
            if (_narration[i] >= L'��' && _narration[i] <= L'�R')
                i++;
            else
                narrationSettingLength++;
        }
        // �����̼� �ڸ� �� ���ھ� �׸��� ( fixedUpdateCount ����� )
        if (narrationCount != _Tick->fixedUpdateCount)
        {
            // �����̼� ��ȭâ �����
            _Stage->SetColor(blue, blue);
            _Input->Gotoxy(2, y - 2);
            wcout << "######################################################################################################################";
            _Input->Gotoxy(2, y + 2);
            wcout << "######################################################################################################################";
            _Stage->SetColor(blue, black);
            
            // �����̼� Ŀ���� �̵���Ű�� FixedUpdateCount�� 1�� ������ ������ ����� �Ǵ� fixedUpdateCount�� ����ŭ ���������� �̵��ؼ� �ܾ� ���
			_Input->Gotoxy(x + (_Tick->fixedUpdateCount * 2) - wcslen(_narration) - narrationLCount + narrationSettingLength / 2, y);
            wcout << _narration[_Tick->fixedUpdateCount - 1];
            narrationCount = _Tick->fixedUpdateCount;
            _Stage->SetColor(white, black);

            // �ѱ��̸� 2ĭ �̵�, �ѱ� �ƴϸ� 1ĭ �̵�
            if ((_narration[_Tick->fixedUpdateCount - 1] >= L'��' && _narration[_Tick->fixedUpdateCount - 1] <= L'�R') == false)
                narrationLCount++;

            // �ܾ��� ���̰� fixedUpdateCount��ŭ �������ٸ� ����� �׸��ϱ�
            if (wcslen(_narration) == _Tick->fixedUpdateCount)
                narrationStop = false;

            // �����̼��� �� ����� ���� �����̼� �迭�� �̵��ؼ� ���� �����̼� �۵��ϱ�
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

    // NarrationDelay �ð����� ���� n���� �ִ� Narrationarr[n]�� ������ �ʰ� ��ٸ���
    if (_Tick->fixedUpdateCount == NarrationDelay)
    {
        narrationStop = true;
    }
}

void Render::GameInfomation(Tick* _Tick, Input* _Input)
{


}