#pragma once
#include <My_ConsoleEngine/ConsoleObject.h>
#include <vector>

class Player : public ConsoleObject
{
public:	
	inline bool GetIsFire() const 
	{	
		return m_IsFire; 
	}

	inline bool GetIsEnd() const 
	{	
		return m_IsEnd; 
	}

	void SetAllObject(std::vector<ConsoleObject*>* _AllObjectPtr)
	{
		m_AllObjectPtr = _AllObjectPtr;
	}

protected:
	void Update() override;

private:
	bool m_IsEnd = false;

	std::vector<ConsoleObject*>* m_AllObjectPtr = nullptr;
};

