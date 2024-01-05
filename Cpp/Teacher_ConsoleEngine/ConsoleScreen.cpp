#include "ConsoleScreen.h"
#include <iostream>
#include <Windows.h>
#include <assert.h>


void ConsoleScreen::CreateScreen(int _ScreenX, int _ScreenY)
{
	if (0 >= _ScreenX)
	{
		MsgBoxAssert("스크린 X크기가 0이기 때문에 콘솔 스크린을 만들수 없습니다");
	}

	if (0 >= _ScreenY)
	{
		MsgBoxAssert("스크린 Y크기가 0이기 때문에 콘솔 스크린을 만들수 없습니다");
	}

	ScreenX = _ScreenX;
	ScreenY = _ScreenY;

	int ArrayCount = (ScreenX + 1) * ScreenY + 1;

	// 10~10하면 10
	// 11 * 10
	ScreenData = new char[ArrayCount] {};

	for (int i = 0; i < ArrayCount; i++)
	{
		ScreenData[i] = 0;
	}


	for (int y = 0; y < ScreenY; y++)
	{
		for (int x = 0; x < ScreenX; x++)
		{
			// 이게 왜 괜찮은 코드인가?
			int Index = y * (ScreenX + 1) + x;
			ScreenData[Index] = '*';
		}

		int ReturnIndex = y * (ScreenX + 1) + ScreenX;
		ScreenData[ReturnIndex] = '\n';
	}

	ScreenData[ArrayCount - 1] = 0;

	printf_s(ScreenData);

	// [*][*][\n][*][*][\n][0]

	// **
	// **

	// 문자열은 어떻게 출력 됩니까?
	// "**************\n
	//  **************\n
	//  **************\n
	//  **************\n
	//  **************\n
	//  **************\n
	//  **************"0
}
