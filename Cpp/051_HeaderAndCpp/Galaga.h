#pragma once
#include "ConsoleScreen.h"

// °¶·¯±× ¼¼ÆÃ
const char GalagWall = 'o';
const char GalagBackGround = '.';
const char Default_Bullet = '^';
const char Default_Player = 'A';

const int GameScreenStartX = 2;
const int GameScreenStartY = 1;

const int GameScreenX = ScreenX - GameScreenStartX - 1;
const int GameScreenY = ScreenY - GameScreenStartY;

class Galaga
{
public:
    Galaga() {};

    void GalagaMapDraw(ConsoleScreen& _Screen);

protected:

private:

};

