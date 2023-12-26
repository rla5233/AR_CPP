#pragma once
#include "Math.h"

class Bullet
{
public:
    Bullet() {}
    Bullet(const int2& _StartPos, char _RenderChar)
        : Pos(_StartPos), RenderChar(_RenderChar)
    {}

    void SetPos(int _PosX, int _PosY);

    inline int2 GetPos() { return Pos; }
    inline char GetRenderChar() { return RenderChar; }
    bool& GetIsFireRef() { return IsFire; }

protected:

private:
    int2 Pos = { 0, 0 };
    char RenderChar = ' ';
    bool IsFire = false;
};

