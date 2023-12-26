// 헤더에는 아래의 #pragma once를 꼭 넣어야 한다.
// #pragma once : 헤더중복 방지 전처리기
#pragma once
#include <conio.h>
#include "Math.h" // 이제 int2 사용가능

// 헤더에는 선언만 놓는다.
class Player
{
public:
	Player() {}

	Player(const int2& _StartPos, char _RenderChar)
		: Pos(_StartPos), RenderChar(_RenderChar)
	{

	}

	// 선언과 구현을 분리하면 inline이 되지 않는다.
	// 보통 굉장히 간단한 함수는 구현을 분리하지 않는다.
	// Get과 Set 함수 (Get만 하는 사람도 있다.)
	void Update();
	inline int2 GetPos() { return Pos; }
	inline char GetRenderChar()	{ return RenderChar; }
	void SetBulletFire(bool* _IsFire);

private:
	int2 Pos = { 0,0 };
	char RenderChar = 'A';
	bool* IsFire = nullptr;
};

