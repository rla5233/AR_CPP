#pragma once

// �������� ȭ���� ũ�⸦ �������ε����� �����Ͽ���.
// 

class ConsoleScreen
{
private:
	// Ŭ������ �����Ǹ�
	//int Value; // -> ��ٷ� �����ȴ�.
	//char* Ptr; // new int(); -> �̰� ���������� ���α׷��Ӱ� ���� �� �ִ�.

	int ScreenX = -1;
	int ScreenY = -1;
	
	char* ScreenData;

public:
	void CreateScreen(int _ScreenX, int _ScreenY);
};

