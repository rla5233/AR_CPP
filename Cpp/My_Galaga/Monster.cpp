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
		m_MoveDir = Right;
	}

	if (m_MoveCount > MoveX)
	{
		m_MoveDir = Left;
	}

	if (m_MoveCount == MoveX || m_MoveCount == 2 * MoveX + 1)
	{
		m_MoveDir = Down;
	}

	if (GetPos().Y >= MoveY)
	{
		GetCore()->EngineEnd();
	}

	AddPos(m_MoveDir);
	m_MoveCount = (m_MoveCount + 1) % (MoveX * 2 + 2);
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