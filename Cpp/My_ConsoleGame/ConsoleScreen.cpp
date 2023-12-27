#include "ConsoleScreen.h"

// �ܼ� ȭ�� ��� ����
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

// ����Ͱ� ������ �˰������ʴ�.
// ���ӿ��� ȭ��(��)�� �������� �Ѵ�.
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

