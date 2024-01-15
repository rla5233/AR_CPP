#include "Monster.h"
#include "ContentsEnum.h"

void Monster::Update()
{
	ConsoleObject* CollisionObject = Collision(GalagaUpdateType::Bullet);

	if (CollisionObject != nullptr)
	{
		Destroy();
		CollisionObject->Destroy();
	}
}
