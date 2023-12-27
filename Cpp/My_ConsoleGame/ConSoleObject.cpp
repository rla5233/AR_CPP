#include "ConSoleObject.h"

int2 ConSoleObject::GetPos()
{
	return Pos;
}

char ConSoleObject::GetRenderChar()
{
	return RenderChar;
}

void ConSoleObject::SetPos(const int2& _Pos)
{
	Pos = _Pos;
}
