#pragma once
#include "GlobalHeader.h"

// 콘솔 화면 상수 선언
extern const char ScreenBackGround;

const int ScreenX = 40;
const int ScreenY = 28;

extern const int ScreenXHalf;
extern const int ScreenYHalf;

class ConsoleScreen
{
public:
    // 생성자를 만든다는것 -> 내가 만든 생성자 형식으로만 생성해라
    // 따라서 컴파일러는 기본생성자를 만들지 않는다.
    ConsoleScreen();
    ConsoleScreen(char _BaseChar);

    void PrintScreen();
    void ClearScreen();

    void SetPixel(const int2& _Position, char _Char);
    void SetPixel(int _X, int _Y, char _Char);

protected:

private:
    char Arr[ScreenY][ScreenX] = { 0, };
    char Base_C = ' ';
};