#include "Bullet.h"

extern const char Default_Bullet = '^';

Bullet::Bullet() 
{
}

Bullet::Bullet(const int2& _StartPos, char _RenderChar)
	: ConSoleObject(_StartPos, _RenderChar)
{
	//Pos = _StartPos;
	//RenderChar = _RenderChar;
}

bool& Bullet::GetIsFireRef() { return IsFire; }