#pragma once
class Word
{
public:
	void Wall(char map[][80]);
	void All();
	void Open(char map[][80]);
	void Close(char map[][80]);
	void Set(char map[][80]);
	void Blue(char map[][80]);
	void Red(char map[][80]);
	void Yellow(char map[][80]);
	void NG();
	void ChecktheWord(char map[][80], int y, int x);
	void SetColor(int forground, int background);

public:
	bool DrawWordMap = false;
	int GameNumber = 0;

};