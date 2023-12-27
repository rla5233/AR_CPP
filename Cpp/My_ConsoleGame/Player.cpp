#include "Player.h"
#include "Galaga.h"

extern const char Default_Player = 'A';

// 상하좌우 이동 다음과 같이 나타내는 방법이 있다.
extern const int2 Left = { -1, 0 };
extern const int2 Right = { 1, 0 };
extern const int2 Up = { 0, -1 };
extern const int2 Down = { 0, 1 };

Player::Player() 
{
}

Player::Player(const int2& _StartPos, char _RenderChar)
{
    Pos = _StartPos;
    RenderChar = _RenderChar;
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

void Player::SetBulletFire(bool* _IsFire)
{
    if (_IsFire == nullptr)
    {
        return;
    }

    IsFire = _IsFire;
}