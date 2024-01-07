#pragma once
#include "EngineDebug.h"
#include "ConsoleMath.h"

// �������� ȭ���� ũ�⸦ �������ε����� �����Ͽ���.
// 

class ConsoleScreen
{
public:
	void CreateScreen(int _ScreenX, int _ScreenY);
	void ReleaseScreen();
	void PrintScreen();
	void ClearScreen();

	void SetChar(const class ConsoleObject& _Object);
	void SetChar(const class ConsoleObject* _Object);
	void SetChar(const int2& _Pos, char _Char);
	
private:
	// Ŭ������ �����Ǹ�
	//int Value; // -> ��ٷ� �����ȴ�.
	//char* Ptr; // new int(); -> �̰� ���������� ���α׷��Ӱ� ���� �� �ִ�.

	int m_ScreenX = -1;
	int m_ScreenY = -1;
	
	char** m_ScreenData = nullptr;
};

