#pragma once
#include "GlobalHeader.h"

// �ܼ� ȭ�� ��� ����
extern const char ScreenBackGround;

const int ScreenX = 40;
const int ScreenY = 28;

extern const int ScreenXHalf;
extern const int ScreenYHalf;

class ConsoleScreen
{
public:
    // �����ڸ� ����ٴ°� -> ���� ���� ������ �������θ� �����ض�
    // ���� �����Ϸ��� �⺻�����ڸ� ������ �ʴ´�.
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