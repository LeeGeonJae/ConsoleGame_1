#pragma once

enum
{
	ESCAPE_KEY_INDEX = 0,
	USER_CMD_LEFT,
	USER_CMD_RIGHT,
	USER_CMD_UP,
	USER_CMD_DOWN,
	MAX_KEY
};

class Input
{
public:
	void Init();
	void Set(const int keyIdx, bool bOn);
	bool IsSpaceCmdOn();
	bool IsLeftCmdOn();
	bool IsRightCmdOn();
	bool IsUpCmdOn();
	bool IsDownCmdOn();
	void UpdateInput();

public:
	bool inputKeyTable[MAX_KEY];
};

