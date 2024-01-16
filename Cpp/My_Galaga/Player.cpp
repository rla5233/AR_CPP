#include "Player.h"
#include "Bullet.h"
#include "ContentsEnum.h"

#include <My_ConsoleEngine/EngineCore.h>
#include <conio.h>

void Player::Update()
{
	// 몬스터 확인
	// 엔진에서 값으로 가져오기 (깊은 복사) 가장 느린 방법이지만 직관적이다.
	std::list<ConsoleObject*> MonsterList = GetCore()->GetUpdateGroup(GalagaUpdateType::Monster);


	if (!_kbhit())
	{
		return;
	}

	int Select = _getch();
	switch (Select)
	{
	case 'A':
	case 'a':
		AddPos(Left);
		break;
	case 'S':
	case 's':
		AddPos(Down);
		break;
	case 'W':
	case 'w':
		AddPos(Up);
		break;
	case 'D':
	case 'd':
		AddPos(Right);
		break;
	case ' ':
	{
		Bullet* NewBullet = GetCore()->CreateObject<Bullet>(GalagaUpdateType::Bullet, GalagaRenderType::Bullet);
		NewBullet->SetPos(GetPos());
		break;
	}
	case '0':
		GetCore()->EngineEnd();
		break;
	default:
		break;
	}
}