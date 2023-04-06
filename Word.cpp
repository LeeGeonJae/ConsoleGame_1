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
			if (map[h][w] == '1')
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
			if (map[h][w] == '2')
				map[h][w] = '0';
		}
	}

	DrawWordMap = true;
}

// �� ������ �����
void Word::Close(char map[][80])
{
	for (int h = 0; h < 15; h++)
	{
		for (int w = 0; w < 80; w++)
		{
			if (map[h][w] == '2')
				map[h][w] = '3';
		}
	}

	DrawWordMap = true;
}

// ����
void Word::Set(char map[][80])
{

	DrawWordMap = true;
}

void Word::Blue(char map[][80])
{
	for (int h = 0; h < 15; h++)
	{
		for (int w = 0; w < 80; w++)
		{
			if (map[h][w] == 'b')
				map[h][w] = '0';
		}
	}

	DrawWordMap = true;
}

void Word::Red(char map[][80])
{
	for (int h = 0; h < 15; h++)
	{
		for (int w = 0; w < 80; w++)
		{
			if (map[h][w] == 'r')
				map[h][w] = '0';
		}
	}

	DrawWordMap = true;
}

void Word::Yellow(char map[][80])
{
	for (int h = 0; h < 15; h++)
	{
		for (int w = 0; w < 80; w++)
		{
			if (map[h][w] == 'y')
				map[h][w] = '0';
		}
	}

	DrawWordMap = true;
}

// �ܾ ã�� �� �ٿ� �ܾ �ش�Ǹ� �ش� �ܾ��� �Լ� ����
void Word::ChecktheWord(char map[][80], int y)
{
	string temp;
	size_t pos;

	for (int i = 0; i < 80; i++)
	{
		temp.push_back(map[y][i]);
	}

	if (temp.find("WALL") != string::npos)
	{
		pos = temp.find("WALL");
		for (int i = pos; i < pos + 4; i++)
			map[y][i] = '0';
		Wall(map);
	}
	else if (temp.find("ALL") != string::npos)
	{
		pos = temp.find("ALL");
		All();
	}
	else if (temp.find("OPEN") != string::npos)
	{
		pos = temp.find("OPEN");
		Open(map);
		for (int i = pos; i < pos + 4; i++)
			map[y][i] = '0';
	}
	else if (temp.find("CLOSE") != string::npos)
	{
		pos = temp.find("CLOSE");
		Close(map);
		for (int i = pos; i < pos + 5; i++)
			map[y][i] = '0';
	}
	else if (temp.find("SET") != string::npos)
	{
		pos = temp.find("SET");
		Set(map);
		for (int i = pos; i < pos + 3; i++)
			map[y][i] = '0';
	}
	else if (temp.find("BLUE") != string::npos)
	{
		pos = temp.find("BLUE");
		Blue(map);
		for (int i = pos; i < pos + 4; i++)
			map[y][i] = '0';
	}
	else if (temp.find("RED") != string::npos)
	{
		pos = temp.find("RED");
		Red(map);
		for (int i = pos; i < pos + 3; i++)
			map[y][i] = '0';
	}
	else if (temp.find("YELLOW") != string::npos)
	{
		pos = temp.find("YELLOW");
		Yellow(map);
		for (int i = pos; i < pos + 6; i++)
			map[y][i] = '0';
	}
}