#pragma once
#include <My_ConsoleEngine/ConsoleObject.h>

class Player : public ConsoleObject
{
public:	
	void KeyInput();

	inline bool GetIsFire() const 
	{	
		return m_IsFire; 
	}

	inline bool GetIsEnd() const 
	{	
		return m_IsEnd; 
	}

private:
	bool m_IsFire = false;
	bool m_IsEnd = false;
};

