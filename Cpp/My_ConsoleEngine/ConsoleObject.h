#pragma once
#include "ConsoleMath.h"

class ConsoleObject
{
	friend class EngineCore;

public:
	ConsoleObject();
	ConsoleObject(const int2& _StartPos, char _RenderChar);
	
	// 소멸자 virtual
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

	template<typename EnumType>
	ConsoleObject* Collision(EnumType _UpdateOrder)
	{
		return Collision(static_cast<int>(_UpdateOrder));
	}

	// 나랑 충돌한 오브젝트
	ConsoleObject* Collision(int _UpdateOrder);

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

