// ������� �Ʒ��� #pragma once�� �� �־�� �Ѵ�.
// #pragma once : ����ߺ� ���� ��ó����
#pragma once
#include <conio.h>
#include "Math.h" // ���� int2 ��밡��

// ������� ���� ���´�.
class Player
{
public:
	Player() {}

	Player(const int2& _StartPos, char _RenderChar)
		: Pos(_StartPos), RenderChar(_RenderChar)
	{

	}

	// ����� ������ �и��ϸ� inline�� ���� �ʴ´�.
	// ���� ������ ������ �Լ��� ������ �и����� �ʴ´�.
	// Get�� Set �Լ� (Get�� �ϴ� ����� �ִ�.)
	void Update();
	inline int2 GetPos() { return Pos; }
	inline char GetRenderChar()	{ return RenderChar; }
	void SetBulletFire(bool* _IsFire);

private:
	int2 Pos = { 0,0 };
	char RenderChar = 'A';
	bool* IsFire = nullptr;
};

