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

	ScreenData = new char* [ScreenY];

	for (int y = 0; y < ScreenY; y++)
	{
		ScreenData[y] = new char[ScreenX + 2] { 0, };

		for (int x = 0; x < ScreenX; x++)
		{
			ScreenData[y][x] = '*';
		}

		ScreenData[y][ScreenX] = '\n';
	}

	// �Լ��� ����Ǹ� ���ÿ� �� �Լ� �̸��� �޸𸮸� �׸���
	// �ɹ��Լ��� ����Ǹ� ���ο� this�� �ִٴ°��� ����ؾ� �Ѵ�.

	for (int y = 0; y < ScreenY; y++)
	{
		printf_s(ScreenData[y]);
	}
}
