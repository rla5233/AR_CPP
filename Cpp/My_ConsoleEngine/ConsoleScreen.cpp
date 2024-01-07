#include "ConsoleScreen.h"

#include <iostream>

#include "ConsoleObject.h"

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

	m_ScreenX = _ScreenX;
	m_ScreenY = _ScreenY;

	if (m_ScreenData != nullptr)
	{
		MsgBoxAssert("Alreay Exist Memory");
	}

	m_ScreenData = new char* [m_ScreenY];

	if (m_ScreenData == nullptr)
	{
		MsgBoxAssert("Failed Create Memory");
	}

	for (int y = 0; y < m_ScreenY; y++)
	{
		m_ScreenData[y] = new char[m_ScreenX + 2] { 0, };

		for (int x = 0; x < m_ScreenX; x++)
		{
			m_ScreenData[y][x] = '*';
		}

		m_ScreenData[y][m_ScreenX] = '\n';
	}

	// �Լ��� ����Ǹ� ���ÿ� �� �Լ� �̸��� �޸𸮸� �׸���
	// �ɹ��Լ��� ����Ǹ� ���ο� this�� �ִٴ°��� ����ؾ� �Ѵ�.

	for (int y = 0; y < m_ScreenY; y++)
	{
		printf_s(m_ScreenData[y]);
	}
}

void ConsoleScreen::ReleaseScreen()
{
	// ���� ���� �������� �����.
	for (int y = 0; y < m_ScreenY; y++)
	{
		if (m_ScreenData[y] != nullptr)
		{
			delete[] m_ScreenData[y];
		}
	}

	if (m_ScreenData != nullptr)
	{
		delete m_ScreenData;
	}
}
