#include "ConsoleScreen.h"

// 콘솔 화면 상수 구현
extern const char ScreenBackGround = 'x';

//extern const int ScreenX = 40;
//extern const int ScreenY = 28;

extern const int ScreenXHalf = ScreenX / 2;
extern const int ScreenYHalf = ScreenY / 2;


ConsoleScreen::ConsoleScreen()
{
}

ConsoleScreen::ConsoleScreen(char _BaseChar)
{
    Base_C = _BaseChar;
}

void ConsoleScreen::PrintScreen()
{
    for (int y = 0; y < ScreenY; y++)
    {
        char* Ptr = Arr[y];
        printf_s(Ptr);
        printf_s("\n");
    }
}

// 모니터가 게임을 알고있지않다.
// 게임에서 화면(벽)을 출력해줘야 한다.
void ConsoleScreen::ClearScreen()
{
    system("cls");

    for (int y = 0; y < ScreenY; y++)
    {
        for (int x = 0; x < ScreenX - 1; x++)
        {
            Arr[y][x] = Base_C;
        }
    }
}

void ConsoleScreen::SetPixel(const int2& _Position, char _Char)
{
    SetPixel(_Position.X, _Position.Y, _Char);
}

void ConsoleScreen::SetPixel(int _X, int _Y, char _Char)
{
    Arr[_Y][_X] = _Char;
}

