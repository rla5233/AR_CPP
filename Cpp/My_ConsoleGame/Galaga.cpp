#include "Galaga.h"
//#include "ConsoleScreen.h"

// ������ ����
extern const char GalagWall = 'o';
extern const char GalagBackGround = '.';

extern const int GameScreenStartX = 2;
extern const int GameScreenStartY = 1;

extern const int GameScreenX = ScreenX - GameScreenStartX - 1;
extern const int GameScreenY = ScreenY - GameScreenStartY;


Galaga::Galaga() 
{
}

// ������ �� �׸��� (�ܼ�ȭ�� ��ü�� �����Ѵ�.)
void Galaga::GalagaMapDraw(ConsoleScreen& _Screen)
{
    for (int y = GameScreenStartY; y < GameScreenY; y++)
    {
        for (int x = GameScreenStartX; x < GameScreenX; x++)
        {
            if (y == GameScreenStartY || y == GameScreenY - 1 ||
                x == GameScreenStartX || x == GameScreenX - 1)
            {
                _Screen.SetPixel({ x,  y }, GalagWall);
            }
            else
            {
                _Screen.SetPixel({ x,  y }, GalagBackGround);
            }
        }
    }
}