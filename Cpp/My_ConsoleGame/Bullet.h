#pragma once
#include "GlobalHeader.h"
#include "ConSoleObject.h"

extern const char Default_Bullet;

class Bullet : public ConSoleObject
{
public:
    Bullet();
    Bullet(const int2& _StartPos, char _RenderChar);

    bool& GetIsFireRef();

protected:

private:
    bool IsFire = false;
};