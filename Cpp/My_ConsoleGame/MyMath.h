#pragma once

// ���� �̷� ������ Ŭ������
// ����� ������ �и����� �ʽ��ϴ�.
// ���� �ٺ��� ����
// ex) ��ΰ� ���� ���������, ���� ��θ� ������� �ʾ�.
class int2
{
public:
	int X = 0;
	int Y = 0;

	// ����Ʈ ���Կ�����.
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