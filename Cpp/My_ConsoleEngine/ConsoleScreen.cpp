#include "ConsoleScreen.h"
#include <iostream>

void ConsoleScreen::CreateScreen(int _ScreenX, int _ScreenY)
{
	ReleaseScreen();

	if (_ScreenX <= 0)
	{
		MsgBoxAssert("Wrong range : ScreenX");
	}

	if (_ScreenY <= 0)
	{
		MsgBoxAssert("Wrong range : ScreenY");
	}

	ScreenX = _ScreenX;
	ScreenY = _ScreenY;

	if (ScreenData != nullptr)
	{
		MsgBoxAssert("Alreay Exist Memory");
	}

	ScreenData = new char* [ScreenY];

	if (ScreenData == nullptr)
	{
		MsgBoxAssert("Failed Create Memory");
	}

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

void ConsoleScreen::ReleaseScreen()
{
	// ���� ���� �������� �����.
	for (int y = 0; y < ScreenY; y++)
	{
		if (ScreenData[y] != nullptr)
		{
			delete[] ScreenData[y];
		}
	}

	if (ScreenData != nullptr)
	{
		delete ScreenData;
	}
}
