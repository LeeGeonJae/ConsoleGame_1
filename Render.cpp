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

        if (_Input->IsSpaceCmdOn())                                             // Space bar�� ������ �ش� �׸� ����
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
    else if (GameNumber == 1)                                                   // ��������1���� �̵�
    {
        _Stage->StageOne(_Input);

    }
    else if (GameNumber == 100)                                                 // ���� ���������� �̵�
    {
        _Stage->GameInformation(_Input);

        if (_Input->IsSpaceCmdOn())                                             // ���� ���������� �����̽��ٸ� ������ �ٽ� ���ƿ���
        {
            _Input->Set(ESCAPE_KEY_INDEX, false);
            system("cls");
            narrationReset = true;
            _Stage->Once = false;

            GameNumber = 0;
            Sleep(200);
        }
    }


    narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // �����̼� ����
}

// 1�ʸ��� ����Ǿ� ȭ�鿡 ����ϴ� �Լ�
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
            cout << "�����̽� �Է�" << endl;
        }
        if (_Input->IsLeftCmdOn())
        {
            _Input->Set(USER_CMD_LEFT, false);
            cout << "���� �Է�" << endl;
        }
        if (_Input->IsRightCmdOn())
        {
            _Input->Set(USER_CMD_RIGHT, false);
            cout << "������ �Է�" << endl;
        }
        if (_Input->IsUpCmdOn())
        {
            _Input->Set(USER_CMD_UP, false);
            cout << "�� �Է�" << endl;
        }
        if (_Input->IsDownCmdOn())
        {
            _Input->Set(USER_CMD_DOWN, false);
            cout << "�Ʒ� �Է�" << endl;
        }

        elapsedTime = 0;
        _Tick->updateCount = 0;
    }
}

void Render::narration(const char* narration, Tick* _Tick, Input* _Input, int num)
{
    static int x = 35;
    static int y = 24;

    // NarrationReset : ���� �޶����� �����̼� �ʱ�ȭ �ϰ� ���� ���������� �����̼����� �ʱ� ����
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

    // ���ڿ� ���� �����̼��� �迭���� �����ͼ� �����ϱ�
    if (num != narrationNext && narrationStop == true)
    {
        strcpy_s(_narration, narration);

        // �����̼� �ڸ� �� ���ھ� �׸��� ( fixedUpdateCount ����� )
        if (narrationCount != _Tick->fixedUpdateCount)
        {
            // �����̼� ��ȭâ �����
            _Input->Gotoxy(2, 22);
            cout << "#############################################################################";
            _Input->Gotoxy(2, 26);
            cout << "#############################################################################";

            _Input->Gotoxy(x + _Tick->fixedUpdateCount - strlen(_narration) / 2, y);
            cout << _narration[_Tick->fixedUpdateCount - 1];
            narrationCount = _Tick->fixedUpdateCount;

            if (strlen(_narration) == _Tick->fixedUpdateCount)
                narrationStop = false;

            // �����̼��� �� ����� ���� �����̼� �迭�� �̵��ؼ� ���� �����̼� �۵��ϱ�
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

    // NarrationDelay �ð����� ���� n���� �ִ� Narrationarr[n]�� ������ �ʰ� ��ٸ���
    if (_Tick->fixedUpdateCount == NarrationDelay)
    {
        narrationStop = true;
    }
}