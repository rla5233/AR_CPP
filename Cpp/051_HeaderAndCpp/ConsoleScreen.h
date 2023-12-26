#pragma once
#include <iostream>
#include "Math.h"

// 콘솔 화면 상수 세팅
const char ScreenBackGround = 'x';

const int ScreenX = 40;
const int ScreenY = 28;

const int ScreenXHalf = ScreenX / 2;
const int ScreenYHalf = ScreenY / 2;

class ConsoleScreen
{
public:
    ConsoleScreen(char _BaseChar)
    {
        Base_C = _BaseChar;
    }

    void PrintScreen();
    void ClearScreen();
    void SetPixel(const int2& _Position, char _Char);
    void SetPixel(int _X, int _Y, char _Char);

protected:

private:
    char Arr[ScreenY][ScreenX] = { 0, };
    char Base_C = ' ';
};

