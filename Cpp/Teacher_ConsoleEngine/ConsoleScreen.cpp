#include "ConsoleScreen.h"
#include <iostream>
#include <Windows.h>
#include <assert.h>


void ConsoleScreen::CreateScreen(int _ScreenX, int _ScreenY)
{
	if (0 >= _ScreenX)
	{
		MsgBoxAssert("��ũ�� Xũ�Ⱑ 0�̱� ������ �ܼ� ��ũ���� ����� �����ϴ�");
	}

	if (0 >= _ScreenY)
	{
		MsgBoxAssert("��ũ�� Yũ�Ⱑ 0�̱� ������ �ܼ� ��ũ���� ����� �����ϴ�");
	}

	ScreenX = _ScreenX;
	ScreenY = _ScreenY;

	int ArrayCount = (ScreenX + 1) * ScreenY + 1;

	// 10~10�ϸ� 10
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
			// �̰� �� ������ �ڵ��ΰ�?
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

	// ���ڿ��� ��� ��� �˴ϱ�?
	// "**************\n
	//  **************\n
	//  **************\n
	//  **************\n
	//  **************\n
	//  **************\n
	//  **************"0
}
