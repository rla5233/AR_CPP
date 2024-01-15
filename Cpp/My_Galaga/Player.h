#pragma once
#include <My_ConsoleEngine/ConsoleObject.h>
#include <list>
#include <map>

#include "ContentsEnum.h"

class Player : public ConsoleObject
{
public:
	inline bool GetIsEnd() const 
	{	
		return m_IsEnd; 
	}

	void SetAllObject(std::map<ContentsObjectType, std::list<ConsoleObject*>>* _AllObjectPtr)
	{
		m_AllObjectPtr = _AllObjectPtr;
	}

protected:
	void Update() override;

private:
	bool m_IsEnd = false;

	std::map<ContentsObjectType, std::list<ConsoleObject*>>* m_AllObjectPtr = nullptr;
};

