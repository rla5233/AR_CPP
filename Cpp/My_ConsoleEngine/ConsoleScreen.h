#pragma once
#include "EngineDebug.h"

// 기존에는 화면의 크기를 정적바인딩으로 설정하였다.
// 

class ConsoleScreen
{
private:
	// 클래스가 생성되면
	//int Value; // -> 곧바로 생성된다.
	//char* Ptr; // new int(); -> 이걸 언제할지를 프로그래머가 정할 수 있다.

	int ScreenX = -1;
	int ScreenY = -1;
	
	char** ScreenData = nullptr;

public:
	void CreateScreen(int _ScreenX, int _ScreenY);
};

