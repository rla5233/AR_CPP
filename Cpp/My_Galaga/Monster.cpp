#include "Monster.h"
#include <My_ConsoleEngine/ConsoleScreen.h>
#include <My_ConsoleEngine/EngineCore.h>

#include "ContentsEnum.h"

void Monster::Move()
{
	int MoveX = GetCore()->m_Screen.GetScreenX() - m_XGroupSize;
	int MoveY = GetCore()->m_Screen.GetScreenY();

	if (m_MoveCount < MoveX)
	{
		AddPos(m_MoveDir);
		++m_MoveCount;
	}
	else
	{
		AddPos(Down);
		m_MoveDir.X *= -1;
		m_MoveCount = 0;
	}

	if (GetPos().Y >= MoveY)
	{
		GetCore()->EngineEnd();
	}
}

void Monster::Update()
{
	if (m_MoveTime == 0)
	{
		Move();
	}
	m_MoveTime = (m_MoveTime + 1) % m_MoveDelay;

	ConsoleObject* CollisionObject = Collision(GalagaUpdateType::Bullet);

	if (CollisionObject != nullptr)
	{
		Destroy();
		CollisionObject->Destroy();
	}	
}