#include "ConsoleScreen.h"
#include <iostream>
#include <Windows.h>
#include <assert.h>

void ConsoleScreen::CreateScreen(int _ScreenX, int _ScreenY)
{
	if (_ScreenX <= 0)
	{
		MsgBosAssert("Wrong range : ScreenX");
	}

	if (_ScreenY <= 0)
	{
		MsgBosAssert("Wrong range : ScreenY");
	}

	ScreenX = _ScreenX;
	ScreenY = _ScreenY;

	int ArrCount = (ScreenX + 1) * ScreenY + 1;
	ScreenData = new char[ArrCount];

	int idx = 0;
	for (int y = 0; y < ScreenY; y++)
	{
		for (int x = 0; x < ScreenX; x++)
		{
			ScreenData[idx] = '*';
			++idx;
		}

		ScreenData[idx] = '\n';
		++idx;
	}
	
	ScreenData[ArrCount - 1] = '\0';
	printf_s(ScreenData);
}
