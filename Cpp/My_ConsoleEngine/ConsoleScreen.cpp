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

	// 함수가 실행되면 스택에 그 함수 이름의 메모리를 그리면
	// 맴버함수는 실행되면 내부에 this가 있다는것을 기억해야 한다.

	for (int y = 0; y < ScreenY; y++)
	{
		printf_s(ScreenData[y]);
	}
}

void ConsoleScreen::ReleaseScreen()
{
	// 지울 때는 역순으로 지운다.
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
