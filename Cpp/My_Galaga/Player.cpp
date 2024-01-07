#include "Player.h"

#include <conio.h>

void Player::KeyInput()
{
	m_IsFire = false;

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
		m_IsFire = true;
		break;
	default:
		break;
	}
}