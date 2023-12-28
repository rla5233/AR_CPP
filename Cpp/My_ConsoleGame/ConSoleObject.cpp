#include "ConSoleObject.h"

ConSoleObject::ConSoleObject()
{}

ConSoleObject::ConSoleObject(const int2& _StartPos, char _RenderChar)
	: Pos(_StartPos), RenderChar(_RenderChar)
{}

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
