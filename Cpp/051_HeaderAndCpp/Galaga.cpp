#include "Galaga.h"

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