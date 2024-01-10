#include "Player.h"
#include "Bullet.h"

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
		Bullet * NewBullet = new Bullet();
		NewBullet->SetPos({ GetPos().X, GetPos().Y });
		m_AllObjectPtr->push_back(NewBullet);
		break;
	}
	case '0':
		m_IsEnd = true;
		break;
	default:
		break;
	}
}