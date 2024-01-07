#pragma once
#include <My_ConsoleEngine/ConsoleObject.h>

class Player : public ConsoleObject
{
public:	
	void KeyInput();

	inline bool GetIsFire() const {	return m_IsFire; }

private:
	bool m_IsFire = false;
};

