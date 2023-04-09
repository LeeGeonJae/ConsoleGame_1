#include "Render.h"
#include <iostream>
#include <windows.h>

using namespace std;

void Render::Init()
{
    _setmode(_fileno(stdout), _O_U16TEXT); // À¯´ÏÄÚµå Ãâ·ÂÀ» À§ÇÑ ¼³Á¤
}

void Render::Update(Tick* _Tick, Input* _Input)
{
    if (GameNumber >= 0 && GameNumber < 10)
    {
        _Stage->SetColor(yellow, black);
        _Input->Gotoxy(90, 3);
        wcout << L"\'W\' : À§";
        _Input->Gotoxy(90, 5);
        wcout << L"\'S\' : ¾Æ·¡";
        _Input->Gotoxy(90, 7);
        wcout << L"\'D\' : ¿À¸¥ÂÊ";
        _Input->Gotoxy(90, 9);
        wcout << L"\'A\' : ¿ÞÂÊ";
        _Input->Gotoxy(90, 11);
        wcout << L"\'Space Bar\' : ¸®¼Â ¹× ¼±ÅÃ";
        _Stage->SetColor(white, black);
    }

    if (GameNumber == 0)                                                                                    // Menu
    {
        _Stage->Menu(_Input);
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // ³ª·¹ÀÌ¼Ç ½ÇÇà
        PrintCountsPerSecond(_Tick, _Input);

        if (_Input->IsSpaceCmdOn())                                                                         // Space bar¸¦ ´©¸£¸é ÇØ´ç Ç×¸ñ ¼±ÅÃ
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
    else if (GameNumber == 2)                                                                               // ½ºÅ×ÀÌÁö1À¸·Î ÀÌµ¿
    {
        _Stage->StageOne(_Input, _Tick, &GameNumber);
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 3)
    {
        _Stage->StageTwo(_Input, _Tick, &GameNumber);                                                       // ½ºÅ×ÀÌÁö2À¸·Î ÀÌµ¿
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 4)
    {
        _Stage->StageThree(_Input, _Tick, &GameNumber);                                                     // ½ºÅ×ÀÌÁö3À¸·Î ÀÌµ¿
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // ³ª·¹ÀÌ¼Ç ½ÇÇà
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 5)
    {
        _Stage->StageFour(_Input, _Tick, &GameNumber);                                                      // ½ºÅ×ÀÌÁö4À¸·Î ÀÌµ¿
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // ³ª·¹ÀÌ¼Ç ½ÇÇà
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 6)
    {
        _Stage->StageFive(_Input, _Tick, &GameNumber);                                                      // ½ºÅ×ÀÌÁö5À¸·Î ÀÌµ¿
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // ³ª·¹ÀÌ¼Ç ½ÇÇà
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 7)
    {
        _Stage->StageSix(_Input, _Tick, &GameNumber);                                                      // ½ºÅ×ÀÌÁö6À¸·Î ÀÌµ¿
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // ³ª·¹ÀÌ¼Ç ½ÇÇà
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 8)
    {
        _Stage->StageSeven(_Input, _Tick, &GameNumber);                                                      // ½ºÅ×ÀÌÁö7À¸·Î ÀÌµ¿
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // ³ª·¹ÀÌ¼Ç ½ÇÇà
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 9)
    {
        _Stage->StageEight(_Input, _Tick, &GameNumber);                                                      // ½ºÅ×ÀÌÁö8À¸·Î ÀÌµ¿
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // ³ª·¹ÀÌ¼Ç ½ÇÇà
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 10)
    {
        _Stage->GoodEnging(_Input, _Tick, &GameNumber, PlayTime);                                                      // ½ºÅ×ÀÌÁö8À¸·Î ÀÌµ¿
        narration(_Stage->narrationarr[narrationNext], _Tick, _Input, _Stage->Narrationarrlen);             // ³ª·¹ÀÌ¼Ç ½ÇÇà
        PrintCountsPerSecond(_Tick, _Input);
    }
    else if (GameNumber == 100)                                                                             // °ÔÀÓ Á¤º¸¶õÀ¸·Î ÀÌµ¿
    {
        _Stage->GameInformation(_Input);

        // °ÔÀÓ Á¤º¸¶õ¿¡¼­ ½ºÆäÀÌ½º¹Ù¸¦ ´©¸£¸é ´Ù½Ã µ¹¾Æ¿À±â
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

    if (_Stage->_word->GameNumber == 101)                                                                   // ÇÃ·¹ÀÌ µµÁß °ÔÀÓÀÌ ¿À¹öµÇ¸é ½ÇÇà
    {
        _Stage->GameOver(_Input, &GameNumber);
        _Stage->_word->GameNumber = 0;
    }
    else if (GameNumber == 102)
    {

    }

    
}

// 1ÃÊ¸¶´Ù ½ÇÇàµÇ¾î È­¸é¿¡ Ãâ·ÂÇÏ´Â ÇÔ¼ö ( Å×½ºÆ® ¿ëÀÌ¶ó ÇÊ¿äÇÏÁø ¾ÊÀ½ )
void Render::PrintCountsPerSecond(Tick* _Tick, Input* _Input)
{
    static ULONGLONG elapsedTime = 1000;
    static short senzX = 47;
    static short senzY = 19;
    static bool SenzFPS = true;

    elapsedTime += _Tick->GetDeltaTime();
    if (elapsedTime >= 1000)                // 0.1 ÃÊ
    {
        if (GameNumber >= 1 && GameNumber != 10)
        {
            PlayTime += 1;
            _Input->Gotoxy(90, 13);
            _Stage->SetColor(lightgreen, black);
            wcout << L"PlayTime : " << PlayTime << L" ÃÊ";
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

// ³ª·¹ÀÌ¼Ç Ãâ·ÂÇÏ´Â ÇÔ¼ö
void Render::narration(const wchar_t* narration, Tick* _Tick, Input* _Input, int num)
{
    static int x = 58;
    static int y = 38;

    // NarrationReset : ¸ÊÀÌ ´Þ¶óÁö¸é ³ª·¹ÀÌ¼Ç ÃÊ±âÈ­ ÇÏ°í ´ÙÀ½ ½ºÅ×ÀÌÁöÀÇ ³ª·¹ÀÌ¼ÇÀ¸·Î ÃÊ±â ¼¼ÆÃ
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

    // ÀÎÀÚ¿¡ ¹ÞÀº ³ª·¹ÀÌ¼ÇÀÇ ¹è¿­°ªÀ» °¡Á®¿Í¼­ º¹»çÇÏ±â
    if (num != narrationNext && narrationStop == true && narration != nullptr)
    {
        for (int i = 0; i < 100; i++)
        {
            _narration[i] = L'\0';

        }
        if (wcslen(narration) % 2 != 0)
            wmemcpy(_narration, narration, wcslen(narration) + 1);
        wmemcpy(_narration, narration, wcslen(narration));

        // °¢ ³ª·¹ÀÌ¼Ç ±æÀÌ Á¶ÀýÇÏ´Âµ¥ ÇÑ±ÛÀº 2Ä­ ³ª¸ÓÁö´Â 1Ä­¾¿ Â÷ÁöÇØ¼­ 1Ä­¾¿ Â÷ÁöÇÏ´Â ¹®ÀÚ Ã£¾Æ¼­ 1¾¿ Áõ°¡
        narrationSettingLength = 0;
        for (int i = 0; i < wcslen(narration); i++)
        {
            if (_narration[i] >= L'°¡' && _narration[i] <= L'ÆR')
                i++;
            else
                narrationSettingLength++;
        }
        // ³ª·¹ÀÌ¼Ç ÀÚ¸· ÇÑ ±ÛÀÚ¾¿ ±×¸®±â ( fixedUpdateCount »ç¿ëÇÔ )
        if (narrationCount != _Tick->fixedUpdateCount)
        {
            // ³ª·¹ÀÌ¼Ç ´ëÈ­Ã¢ ¸¸µé±â
            _Stage->SetColor(blue, blue);
            _Input->Gotoxy(2, y - 2);
            wcout << "######################################################################################################################";
            _Input->Gotoxy(2, y + 2);
            wcout << "######################################################################################################################";
            _Stage->SetColor(blue, black);
            
            // ³ª·¹ÀÌ¼Ç Ä¿¼­¸¦ ÀÌµ¿½ÃÅ°°í FixedUpdateCount°¡ 1¾¿ Áõ°¡ÇÒ ¶§¸¶´Ù Ãâ·ÂÀÌ µÇ´Ï fixedUpdateCountÀÇ ¼ö¸¸Å­ ¿À¸¥ÂÊÀ¸·Î ÀÌµ¿ÇØ¼­ ´Ü¾î Ãâ·Â
			_Input->Gotoxy(x + (_Tick->fixedUpdateCount * 2) - wcslen(_narration) - narrationLCount + narrationSettingLength / 2, y);
            wcout << _narration[_Tick->fixedUpdateCount - 1];
            narrationCount = _Tick->fixedUpdateCount;
            _Stage->SetColor(white, black);

            // ÇÑ±ÛÀÌ¸é 2Ä­ ÀÌµ¿, ÇÑ±Û ¾Æ´Ï¸é 1Ä­ ÀÌµ¿
            if ((_narration[_Tick->fixedUpdateCount - 1] >= L'°¡' && _narration[_Tick->fixedUpdateCount - 1] <= L'ÆR') == false)
                narrationLCount++;

            // ´Ü¾îÀÇ ±æÀÌ°¡ fixedUpdateCount¸¸Å­ °°¾ÆÁø´Ù¸é Ãâ·ÂÀ» ±×¸¸ÇÏ±â
            if (wcslen(_narration) == _Tick->fixedUpdateCount)
                narrationStop = false;

            // ³ª·¹ÀÌ¼ÇÀ» ´Ù Áö¿ì°í ´ÙÀ½ ³ª·¹ÀÌ¼Ç ¹è¿­·Î ÀÌµ¿ÇØ¼­ ´ÙÀ½ ³ª·¹ÀÌ¼Ç ÀÛµ¿ÇÏ±â
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

    // NarrationDelay ½Ã°£µ¿¾È ±âÁ¸ n¹ø¿¡ ÀÖ´Â Narrationarr[n]À» Áö¿ìÁö ¾Ê°í ±â´Ù¸®±â
    if (_Tick->fixedUpdateCount == NarrationDelay)
    {
        narrationStop = true;
    }
}

void Render::GameInfomation(Tick* _Tick, Input* _Input)
{


}