#pragma once
#include "ConsoleMath.h"

class ConsoleObject
{
	friend class Enginecore;

public:
	ConsoleObject();
	ConsoleObject(const int2& _StartPos, char _RenderChar);
	
	// ¼Ò¸êÀÚ virtual
	virtual ~ConsoleObject();

	inline int2 GetPos() const 
	{ 
		return m_Pos; 
	}

	inline char GetRenderChar() const 
	{ 
		return m_RenderChar; 
	}

	inline void SetRenderChar(char _Ch) 
	{
		m_RenderChar = _Ch; 
	}

	inline void SetPos(const int2& _Pos) 
	{ 
		m_Pos = _Pos; 
	}

	inline void AddPos(const int2& _Dir) 
	{ 
		m_Pos += _Dir; 
	}

	virtual void Update()
	{

	}

	void Destroy()
	{
		m_DestroyValue = true;
	}

	bool IsPendingKill()
	{
		return m_DestroyValue;
	}

	class EngineCore* GetCore()
	{
		return Core;
	}

private:
	bool m_DestroyValue = false;

	int2 m_Pos = { 0,0 };
	char m_RenderChar = 'A';

	class EngineCore* Core = nullptr;
	void SetCore(EngineCore* _Core)
	{
		Core = _Core;
	}
};

