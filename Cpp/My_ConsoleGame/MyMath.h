#pragma once

// 보통 이런 수학적 클래스는
// 선언과 구현을 분리하지 않습니다.
// 가장 근본인 개념
// ex) 모두가 나를 사용하지만, 나는 모두를 사용하지 않아.
class int2
{
public:
	int X = 0;
	int Y = 0;

	// 디폴트 대입연산자.
	void operator=(const int2& _Other)
	{
		X = _Other.X;
		Y = _Other.Y;
	}

	int2 operator+(const int2& _Other)
	{
		return { X + _Other.X, Y + _Other.Y };
	}

	void operator+=(const int2& _Other)
	{
		X += _Other.X;
		Y += _Other.Y;
	}
};