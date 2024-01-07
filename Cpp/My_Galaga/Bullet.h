#pragma once
#include <My_ConsoleEngine/ConsoleObject.h>

class Bullet : public ConsoleObject
{
public:
	Bullet();
	void Move();

	inline void Fire() { m_IsFire = true; }

	inline bool GetIsFire() { return m_IsFire; }

private:
	bool m_IsFire = false;
};

