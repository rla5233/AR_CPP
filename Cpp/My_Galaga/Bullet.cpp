#include "Bullet.h"

Bullet::Bullet()
{
	SetRenderChar('|');
}

void Bullet::Move()
{
	if (m_IsFire == false)
	{
		return;
	}

	AddPos(Down);
}