#include "Stage.h"
#include <Windows.h>
#include <iostream>

using namespace std;

// �޴� �׸���
void Stage::Menu(Input* _Input)
{
	// �����̼� �迭 ����
	Narrationarrlen = 4;

	// �����̼� ���� ( ��� ���� )
	narrationarr[0] = L"�ȳ�? ���� Ʃ�丮���� �����̾�!";
	narrationarr[1] = L"���� �װ� ���� �߿� �ɽ����� �ʰ� ���������� �˷��� �����̾�!";
	narrationarr[2] = L"\'W\'�� ��, \'S\'�� �Ʒ�, \'Space bar\'�� �����̾�!";
	narrationarr[3] = L"�� ������ ����� ����־����� ��!";

	// ���� Ÿ��Ʋ ����
	_Input->Gotoxy(0, 3);

	SetColor(white, white);
	wcout << "                                                                               " << endl << endl; SetColor(white, black);
	wcout << "     #     #                         #     # ###                               " << endl;
	wcout << "     #  #  #: ####  #####  #####     #  #  #  #  ######   ##   #####  #####    " << endl;
	wcout << "     #  #  # #    # #    # #    #    #  #  #  #      #   #  #  #    # #    #   " << endl;
	wcout << "     #  #  # #    # #    # #    #    #  #  #  #     #   #    # #    # #    #   " << endl;
	wcout << "     #  #  # #    # #####  #    #    #  #  #  #    #    ###### #####  #    #   " << endl;
	wcout << "     #  #  # #    # #    # #    #    #  #  #  #   #     #    # #   #  #    #   " << endl;
	wcout << "      ## ##   ####  #    # #####      ## ##  ### ###### #    # #    # #####    " << endl << endl; SetColor(white, white);
	wcout << "                                                                               " << endl;
	SetColor(white, black);

	// ���� ó�� ����
	if (Once == false)
	{
		_Input->Gotoxy(x - 2, 15);
		wcout << L"> ���� ����";
		_Input->Gotoxy(x, 16);
		wcout << L"���� ����";
		_Input->Gotoxy(x, 17);
		wcout << L"  ����  ";

		Once = true;
	}

	// ���� �ö󰡱�
	if (_Input->IsUpCmdOn())
	{
		_Input->Set(USER_CMD_UP, false);

		if (y > 15)
		{
			_Input->Gotoxy(x - 2, y);
			wcout << " ";
			_Input->Gotoxy(x - 2, --y);
			wcout << ">";
			Sleep(150);
		}
	}

	// �Ʒ��� ��������
	if (_Input->IsDownCmdOn())
	{
		_Input->Set(USER_CMD_DOWN, false);

		if (y < 17)
		{
			_Input->Gotoxy(x - 2, y);
			wcout << " ";
			_Input->Gotoxy(x - 2, ++y);
			wcout << ">";
			Sleep(150);
		}
	}
}

// ���� ����
void Stage::GameOver(Input* _Input, int* GameNumber)
{
	system("cls");

	SetColor(yellow, black);
	wcout << L"####################################$$======***!*!!!!!!!!!!!!!!!!*****= *= ====== =@@@@@@@##########@@@@@@@@@@@@@@@@@###" << endl;
	wcout << L"###################################$$==== = ****!!!;;;;;;;;;;;;;; !!!!!*****= ======####################################" << endl;
	wcout << L"#################################$$$====****!!!!!;;;;; ::;; :;;;;; !!!!!!!****= = *= =##################################" << endl;
	wcout << L"################################$$$ == = ****!!!!;;;;; :::::::::::;;; !!!!!!!****= **=##################################" << endl;
	wcout << L"################################$$$ == ****!!!;;;;; :::~~~~~~~~~:: : ;;; !!!!!********##################################" << endl;
	wcout << L"##############################$$$====****!!!;;; :::~~~~~--~~~~~::::;; !!!!!!******######################################" << endl;
	wcout << L"##############################$$$====**!!!!!;; ::~~~-------- - ~- ~~:::;;; !!!!***!**###################################" << endl;
	wcout << L"##############################$$$ == = ***!!!;;; ::~~~-- - , -, -- - , -- - ~~::;;;; !!!!*!!**##########################" << endl;
	wcout << L"##############################$$====**!!!;;; ::~~----, , , , , ., , , -- - ~~:::;;;; !!!!!!!############################" << endl;
	wcout << L"##############################$$ == = ***!!!;; ::~---- - , , , ., ., , , , , , --~~:::;;; !!!!!!!#######################" << endl;
	wcout << L"##############################$$ == ****!;;; :::~-- - , , , , , , ., , , , , , , -- - ~~:: : ;;; !!!!!*#################" << endl;
	wcout << L"##############################$ == = ***!!;;; ::~~--, , , , , .   ..., , , , , -~~~::;; !!!!***#########################" << endl;
	wcout << L"##############################$ == = ***!!;; ::~-- - , , , , , .       ., ., , --~~::;;; !!!***#########################" << endl;
	wcout << L"##############################====***!!; ::~~-- - , .           ...., , --~~::;; !!!***#################################" << endl;
	wcout << L"#############################====***!!; ::~---- .��� ���� �����߽��ϴ�., , --~~::;; !!!***#############################" << endl;
	wcout << L"##############################====**!!;; ::~-- - , . .    ., , -~~::;; !!!***###########################################" << endl;
	wcout << L"##############################====***!;; :~~- , .         .., .    . ., -~~::;; !!***=##################################" << endl;
	wcout << L"##############################====***!;; ::~- .  . .  . .....    .  --~~::;; !!**= =####################################" << endl;
	wcout << L"##############################$====**!;; ::~- ........., -~~:;;; !***= =      ##########################################" << endl;
	wcout << L"##############################$====**!;; ::~, ..  ..., ., ....., .  ., -~::;; !!**= ==##################################" << endl;
	wcout << L"##############################$====**!!;; :~- , .., , , ., ., .. .. - . - ~::;; !!**= ==################################" << endl;
	wcout << L"##############################$$ == = ***!;;; :, , ., , , -, .., .. .., ...  . - ~: ;; !!!**= ==########################" << endl;
	wcout << L"##############################$$====**!!;; :-, , , -- - , , ., ...   ....   ~::;; !!**= == =############################" << endl;
	wcout << L"##############################$$$====*!!!;;; --, --, , , , ...   ...., ~::; !!!*= ====##################################" << endl;
	wcout << L"##############################$$$====**!!!;; :, ~- , . - . .      . . ., ~::;; !!*= == = $$#############################" << endl;
	wcout << L"##############################$$$$====**!!; !:-- - , ., . . .      ., -~: ;; !!!*= == $$$###############################" << endl;
	wcout << L"################################$$$ == = ***!!!; ~-- - , ..   .    .., , , , :;; !!*= == = $$$##########################" << endl;
	wcout << L"################################$$$$ == = ****!!; :: - , .    .    ., , .~~~;; !!**= == = $$$###########################" << endl;
	wcout << L"#################################$$$====*****!::, , ...  .    .., .:;; !!!**= = $$$$$###################################" << endl;
	wcout << L"##################################$$$====****!:-, -., , ., ~;; !!**= == $$$$$###########################################" << endl;
	wcout << L"###################################$$$ == = ****~~, -.--., ~- ., , ;; !**= == $$$$#$####################################" << endl;
	wcout << L"###################################$$$====*!-------- . ., -. .. - ; !!*= == = $$$$######################################" << endl;
	wcout << L"#################################$$$$ = $ == **~, . :., -, , -.   . .., , ; !**= = $$$$$$###############################" << endl;
	wcout << L"################################# = -~~~--; !. .--.. . ..           ..!~*= == = -$, ####################################" << endl;
	wcout << L"#################################~; ~, :, , , --. ..     .~., ., .   . : , -~*: -. - .~#################################" << endl;
	wcout << L"################################$!; *~!~- , , . .  ., . - ~; -~~~~- , ., , -, ., ~; #$##################################\n\n\n" << endl;
	SetColor(white, black);

	SetColor(white, white);
	wcout << L"########################################################################################################################" << endl; SetColor(white, black);
	wcout << L"                                   ����� �����̽��ϴ� 5�� �Ŀ� �޴��� ���ư��ϴ�                " << endl; SetColor(white, white);
	wcout << L"########################################################################################################################" << endl;
	SetColor(white, black);

	Sleep(5000);
	system("cls");
	Once = false;
	*GameNumber = 0;
}

// ���� ����
void Stage::GameInformation(Input* _Input)
{
	if (Once == false)
	{
		system("cls");
		Narrationarrlen = 0;
		Once = true;

		_Input->Gotoxy(1, 10);
		SetColor(lightgreen, black);
		wcout << "\n\n";
		wcout << L"                                --��������� 5�� ���α׷��� �а� �̴� �ܼ� ���� ������Ʈ--    " << endl;
		wcout << L"                                                   [ �� �� �� ]                          " << endl;
		wcout << L"                                                �� �� : W, A, S, D                       " << endl;
		wcout << L"                                             ���� �� ���� : �����̽� ��                       " << endl;
		wcout << L"                                              �� �� �� : Lee Geon Jae                     " << endl << endl;
		wcout << L"                                     �� ������ baba is you�� ��Ƽ��� ����������ϴ�         " << endl;
		wcout << L"                                      �����̽� �ٸ� ������ ���� ȭ������ ���ư��ϴ�          " << endl;
		SetColor(white, black);
	}
}

// ��������1
void Stage::StageOne(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// �����̼� �迭 ����
	Narrationarrlen = 5;

	// �����̼� ���� ( ��� ���� )
	narrationarr[0] = L"ù��° ���������� �� ���� ȯ����!";
	narrationarr[1] = L"\'w\':��, \'s\':�Ʒ�, \'d\':������, \'a\':�����̾�!";
	narrationarr[2] = L"�׸��� �����̽� �ٸ� ������ ���� �����̾�!";
	narrationarr[3] = L"���� ���������� ��� ���İ�?";
	narrationarr[4] = L"�ѹ� �����غ�!";

	SettingMap(_Input, _Tick, GameNumber, StageOneMap);
}

// ��������2
void Stage::StageTwo(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// �����̼� �迭 ����
	Narrationarrlen = 5;

	// �����̼� ���� ( ��� ���� )
	narrationarr[0] = L"�Ǹ���! �ʴ� ù��° ���������� ����߾�!";
	narrationarr[1] = L"�ٵ� �ʿ� �ִ� �� ���ĺ����� �����ϱ�?";
	narrationarr[2] = L"�� ���ĺ���� ���� �ϵ��� �� �� ������?";
	narrationarr[3] = L"�ñ����� �ʾ�?";
	narrationarr[4] = L"�ܾ �� �� �ϼ��غ�!";

	SettingMap(_Input, _Tick, GameNumber, StageTwoMap);
}

// ��������3
void Stage::StageThree(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// �����̼� �迭 ����
	Narrationarrlen = 6;

	// �����̼� ���� ( ��� ���� )
	narrationarr[0] = L"��! �� ���� ���ĺ����� �����ϱ�?";
	narrationarr[1] = L"���������� ����ϱ� ���� �ʴ� �� ���� �ܾ���� �����ؾ���!";
	narrationarr[2] = L"�ʿ� �����ϴ� \'*\'����� \'��\'�̶�� �����ϸ� ����!";
	narrationarr[3] = L"�װ� �� ���� ����Ϸ��� ��� �ؾ��ұ�?";
	narrationarr[4] = L"���� ����� ���� ������?";
	narrationarr[5] = L"�ݴ��� �ݴ�Ǵ� ���� �����ϱ�?";

	SettingMap(_Input, _Tick, GameNumber, StageThreeMap);
}

void Stage::StageFour(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// �����̼� �迭 ����
	Narrationarrlen = 5;

	// �����̼� ���� ( ��� ���� )
	narrationarr[0] = L"��! �� �� �Ʒ��� �����ϴ� ���� ����?";
	narrationarr[1] = L"���� ���� ���������� ���ϴ� ��θ� ���� �޸��� �־�!";
	narrationarr[2] = L"���� ���� ���������� ���� ���ƾ� �� �� ����!";
	narrationarr[3] = L"�Ϲ� \'*\'����� ������ ���� �� ����!";
	narrationarr[4] = L"�� ������� �ٲ㼭 ������ ���ƾ� ��!";

	if (Once == false)
	{
		_Eremy->Init(5, 12, _Input);
	}

	_Eremy->Move(tempMap, _Tick, _Input, 10);

	SettingMap(_Input, _Tick, GameNumber, StageFourMap);
}

void Stage::StageFive(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// �����̼� �迭 ����
	Narrationarrlen = 5;

	// �����̼� ���� ( ��� ���� )
	narrationarr[0] = L"��! ���� ��û �˷ϴ޷�������!";
	narrationarr[1] = L"���� ����� �Ķ��� ����������, �������� ������!";
	narrationarr[2] = L"�װ� �����ϴ� ���� �����̴�?";
	narrationarr[3] = L"�Ķ�, ���, �������� ���� ���� �Ƹ��ٿ�!";
	narrationarr[4] = L"���� ���� �˷ϴ޷��� �ɵ��� ���� ������!";

	SettingMap(_Input, _Tick, GameNumber, StageFiveMap);
}

void Stage::StageSix(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// �����̼� �迭 ����
	Narrationarrlen = 6;

	// �����̼� ���� ( ��� ���� )
	narrationarr[0] = L"�̹� �ð�����, �װ� ����� �͵��� �� �� Ȱ���غ� �ð��̾�!";
	narrationarr[1] = L"�װ� ������ ������ ���ȿ� ���� ����� �ѹ� �غ��� ��!";
	narrationarr[2] = L"��¼�� �� �̾߱� �߿��� ��Ʈ�� ã�� �� �������� ����?";
	narrationarr[3] = L"�� ������ ����� ��Ʈ���� �䱸�Ѵٰ� ���� �˰� �־�";
	narrationarr[4] = L"��¼�� ���� �����ڰ� ������ ���� ����?";
	narrationarr[5] = L"�װ� ����ϰ� ������ ������� ��������!";

	if (Once == false)
	{
		_Eremy->Init(5, 12, _Input);
	}

	_Eremy->Move(tempMap, _Tick, _Input, 30);

	SettingMap(_Input, _Tick, GameNumber, StageSixMap);
}

void Stage::StageSeven(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// �����̼� �迭 ����
	Narrationarrlen = 7;

	// �����̼� ���� ( ��� ���� )
	narrationarr[0] = L"�װ� �����ϴ� å�̳� ��ȭ�� �־�?";
	narrationarr[1] = L"������� ���ϱ� å�� ������ ����̶��� ����!";
	narrationarr[2] = L"�׸��� ������ �ܼ��� �����Ÿ��� �Ұ��ϴٰ� ��";
	narrationarr[3] = L"�����Ÿ��� ��ſ��� �߱��ϴ� ���ݾ�?";
	narrationarr[4] = L"��ſ��� �߱��ϴ� ���� ���۰� �ƴϾ�";
	narrationarr[5] = L"�츮�� �ٻڰ� �ؾ��� �͵��� ������ �޽��� �ʿ��� ��,";
	narrationarr[6] = L"������ ����� �޽İŸ��� �� �ž�!";

	SettingMap(_Input, _Tick, GameNumber, StageSevenMap);
}

void Stage::StageEight(Input* _Input, Tick* _Tick, int* GameNumber)
{
	// �����̼� �迭 ����
	Narrationarrlen = 6;

	// �����̼� ���� ( ��� ���� )
	narrationarr[0] = L"���� ��ħ�� �Ծ���?";
	narrationarr[1] = L"�и� ������ ���� ������ ��ħ�� �Դ� ���� �ǰ��� ����!";
	narrationarr[2] = L"���� �ٻڰ� ���ϴٺ��� ����� ���� ���� ���� �ְ���";
	narrationarr[3] = L"�׳��ڳ� ������ ����ϰ� ���� �־�?";
	narrationarr[4] = L"���� �װ� ����� ������� ��������";
	narrationarr[5] = L"�װ� �׷��� ������ ���Ѵٸ� �װ� �Ƹ� ���� �߸��̰���";

	SettingMap(_Input, _Tick, GameNumber, StageEightMap);
}

void Stage::GoodEnging(Input* _Input, Tick* _Tick, int* GameNumber, int PlayTime)
{
	// �����̼� �迭 ����
	Narrationarrlen = 2;

	// �����̼� ���� ( ��� ���� )
	narrationarr[0] = L"������! �ʴ� ������ Ŭ���� �߾�!";
	narrationarr[1] = L"�����̽� �ٸ� ������ ������ ����ɰž�!";

	if(Once == false)
	{
		_Input->Gotoxy(1, 1);
		Once = true;
		wcout << L"\n\n\n"; SetColor(lightgreen, black);
		wcout << L"                                                       PlayTime : " << PlayTime << "\n\n\n"; SetColor(white, black);
		wcout << L"                             ##    ##  #######  ##     ##    ##      ## #### ##    ## #### #### " << endl;
		wcout << L"                              ##  ##  ##     ## ##     ##    ##  ##  ##  ##  ###   ## #### ####" << endl;
		wcout << L"                               ####   ##     ## ##     ##    ##  ##  ##  ##  ####  ## #### ####" << endl;
		wcout << L"                                ##    ##     ## ##     ##    ##  ##  ##  ##  ## ## ##  ##   ##" << endl;
		wcout << L"                                ##    ##     ## ##     ##    ##  ##  ##  ##  ##  ####" << endl;
		wcout << L"                                ##    ##     ## ##     ##    ##  ##  ##  ##  ##   ### #### ####" << endl;
		wcout << L"                                ##     #######   #######      ###  ###  #### ##    ## #### ####" << endl;
	}

	if (_Input->IsSpaceCmdOn())
		*GameNumber = -1;
}

// �� �����ϱ�
void Stage::SetColor(int forground, int background)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}

// �� �׸���
void Stage::DrawMap(int x, int y, char Map[][80], Input* _Input)
{
	int h, w;
	for (h = 0; h < y; h++)
	{
		for (w = 0; w < x; w++)
		{
			// ���� �ش� ��ǥ�� �÷��̾ ������ �ٽ� �׸��� �ʱ�
			if (_player->PlayerCurrentPosition.X == w && _player->PlayerCurrentPosition.Y == h)
				continue;
			if (_Eremy->EremyCurrentPosition.X == w && _Eremy->EremyCurrentPosition.Y == h && _Eremy->Delete != true)
				continue;

			// �ش� ��ǥ�� ���� �� �׸���
			_Input->Gotoxy(w, h);
			char temp = Map[h][w];
			if (temp == '0')					// �� ����
				wcout << " ";
			else if (temp == '1')				// Wall
			{
				SetColor(white, white);
				wcout << "#";
				SetColor(white, black);
			}
			else if (temp == '2')				// Closed Door
				wcout << "*";
			else if (temp == '3')				// Closed Door (2) 
				wcout << "��";
			else if (temp == 'r')				// RED
			{
				SetColor(red, black);
				wcout << "r";
				SetColor(white, black);
			}
			else if (temp == 'b')				// BLUE
			{
				SetColor(lightblue, black);
				wcout << "b";
				SetColor(white, black);
			}
			else if (temp == 'y')				// YELLOW
			{
				SetColor(yellow, black);
				wcout << "y";
				SetColor(white, black);
			}
			else if (temp == 'G')
				wcout << "G";
			else if (temp == 'W')
				wcout << "W";
			else if (temp == 'A')
				wcout << "A";
			else if (temp == 'L')
				wcout << "L";
			else if (temp == 'O')
				wcout << "O";
			else if (temp == 'P')
				wcout << "P";
			else if (temp == 'E')
				wcout << "E";
			else if (temp == 'N')
				wcout << "N";
			else if (temp == 'C')
				wcout << "C";
			else if (temp == 'S')
				wcout << "S";
			else if (temp == 'B')
				wcout << "B";
			else if (temp == 'U')
				wcout << "U";
			else if (temp == 'R')
				wcout << "R";
			else if (temp == 'D')
				wcout << "D";
			else if (temp == 'Y')
				wcout << "Y";
		}
	}
}

// �������� �� �����ϱ�
void Stage::TempMap(char map[][80])
{
	for (int y = 0; y < 15; y++)
	{
		for (int x = 0; x < 80; x++)
		{
			tempMap[y][x] = map[y][x];
		}
	}
}

// �� �����ϱ�
void Stage::SettingMap(Input* _Input, Tick* _Tick, int* GameNumber, char map[][80])
{
	// ó�� �� ����
	if (Once == false)
	{
		TempMap(map);
		_player->Init(40, 5, _Input);
		DrawMap(MapY, MapX, tempMap, _Input);

		Once = true;
	}

	// �ܾ� �ϼ��Ǹ� �� �ٽ� �׸���
	if (_word->DrawWordMap == true)
	{
		DrawMap(MapY, MapX, tempMap, _Input);
	}

	// �÷��̾� �����̱�
	_player->Move(tempMap, _Input, _Tick, _word);

	// �÷��̾ Ŭ���� �ϸ� �̵��ϱ�
	if (_player->Clear == true)
	{
		_player->Clear = false;
		Once = false;
		system("cls");
		(*GameNumber)++;

		//if (*GameNumber == 10)
		//	*GameNumber = 0;
	}

	// Space bar�� ������ �� �ٽ� ����
	if (_Input->IsSpaceCmdOn())
	{
		_Input->Set(ESCAPE_KEY_INDEX, false);
		Once = false;
	}
}