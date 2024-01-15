#include "Player.h"
#include "Bullet.h"
#include "ContentsEnum.h"

#include <My_ConsoleEngine/EngineCore.h>
#include <conio.h>

void Player::Update()
{
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