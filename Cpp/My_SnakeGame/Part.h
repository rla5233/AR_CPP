#pragma once
#include <My_ConsoleEngine/ConsoleObject.h>

class Part : public ConsoleObject
{
public:

private:
	Part* m_Prev = nullptr;
	Part* m_Next = nullptr;
};

