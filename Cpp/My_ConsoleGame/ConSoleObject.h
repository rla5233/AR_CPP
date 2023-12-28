#pragma once
#include "GlobalHeader.h"

class ConSoleObject
{
public:
	ConSoleObject();
	ConSoleObject(const int2& _StartPos, char _RenderChar);

	int2 GetPos();
	char GetRenderChar();
	void SetPos(const int2& _Pos);

protected:
	int2 Pos = { 0, 0 };
	char RenderChar = ' ';
};

