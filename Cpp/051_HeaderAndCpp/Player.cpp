#include "Player.h"
#include "ConsoleScreen.h"
#include "Galaga.h"

const int2 Left = { -1, 0 };
const int2 Right = { 1, 0 };
const int2 Up = { 0, -1 };
const int2 Down = { 0, 1 };

void Player::SetBulletFire(bool* _IsFire)
{
	if (nullptr == _IsFire)
	{
		int a = 0;
		return;
	}

	IsFire = _IsFire;
}

void Player::Update()
{
    char input = _getch();

    switch (input)
    {
        case 'w':
        case 'W':
        {
            if ((Pos + Up).Y != GameScreenStartY)
            {
                Pos += Up;;
            }

            break;
        }
        case 'a':
        case 'A':
        {
            if ((Pos + Left).X != GameScreenStartX)
            {
                Pos += Left;
            }

            break;
        }
        case 's':
        case 'S':
        {
            if ((Pos + Down).Y != GameScreenY - 1)
            {
                Pos += Down;
            }

            break;
        }
        case 'd':
        case 'D':
        {
            if ((Pos + Right).X < GameScreenX - 1)
            {
                Pos += Right;
            }

            break;
        }
        case ' ':
        {
            if (IsFire != nullptr)
            {
                *IsFire = true;
            }

            break;
        }
    }
}
