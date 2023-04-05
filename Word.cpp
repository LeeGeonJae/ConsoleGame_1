#include "Word.h"
#include <string>

using namespace std;

// ���� ��� �� ���ֱ�
void Word::Wall(char map[][80])
{
	for (int h = 0; h < 15; h++)
	{
		for (int w = 0; w < 80; w++)
		{
			if (map[h][w] == '1' || map[h][w] == 'W' || map[h][w] == 'A' || map[h][w] == 'L')
				map[h][w] = '0';
		}
	}

	DrawWordMap = true;
}

// ���� ����
void Word::All()
{
	GameNumber = 101;
	system("cls");
}

// ������ �� ������ �����
void Word::Open(char map[][80])
{
	for (int h = 0; h < 15; h++)
	{
		for (int w = 0; w < 80; w++)
		{
			if (map[h][w] == '2' || map[h][w] == 'O' || map[h][w] == 'P' || map[h][w] == 'E' || map[h][w] == 'N')
				map[h][w] = '0';
		}
	}

	DrawWordMap = true;
}

// �� ������ �����
void Word::Close(char map[][80])
{

	DrawWordMap = true;
}

// ����
void Word::Set(char map[][80])
{

	DrawWordMap = true;
}

// �ܾ ã�� �� �ٿ� �ܾ �ش�Ǹ� �ش� �ܾ��� �Լ� ����
void Word::ChecktheWord(char map[][80], int y)
{
	string temp;
	int npos;

	for (int i = 0; i < 80; i++)
	{
		temp.push_back(map[y][i]);
	}

	npos = temp.find("WALL");

	if (npos != string::npos)
		Wall(map);
	else if (temp.find("ALL") != string::npos)
		All();
	else if (temp.find("OPEN") != string::npos)
		Open(map);
	else if (temp.find("CLOSE") != string::npos)
		Close(map);
	else if (temp.find("SET") != string::npos)
		Set(map);
}