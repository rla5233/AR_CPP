#pragma once
#include "My_ConsoleEngine/ConsoleObject.h"

class Monster : public ConsoleObject
{
public:
	void Move();

	inline void SetXGroupSize(int _Size)
	{
		m_XGroupSize = _Size;
	}

protected:
	void Update() override;

private:
	int m_MoveCount = 0;
	int m_XGroupSize = 0;

	int m_MoveDelay = 1;
	int m_MoveTime = 0;

	int2 m_MoveDir = { 0, 0 };
};

