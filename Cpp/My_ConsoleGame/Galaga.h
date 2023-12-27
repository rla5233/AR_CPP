#pragma once
#include "GlobalHeader.h"
#include "ConsoleScreen.h"

// °¶·¯±× ¼¼ÆÃ
extern const char GalagWall;
extern const char GalagBackGround;

extern const int GameScreenStartX;
extern const int GameScreenStartY;

extern const int GameScreenX;
extern const int GameScreenY;

class Galaga
{
public:
    Galaga();

    void GalagaMapDraw(ConsoleScreen& _Screen);

protected:

private:

};