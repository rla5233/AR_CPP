#pragma once
#include "GlobalHeader.h"
#include "ConSoleObject.h"

extern const char Default_Player;

// 상하좌우 이동 다음과 같이 나타내는 방법이 있다.
extern const int2 Left;
extern const int2 Right;
extern const int2 Up;
extern const int2 Down;

class Player : public ConSoleObject
{
public:
    Player();
    Player(const int2& _StartPos, char _RenderChar);

    void Update();
    void SetBulletFire(bool* _IsFire);

private:
    // 이런거 좋지 않다. (총알과 플레이어가 뗄 수 없는 관계가 됨)
    // Bullet Bullet = Bullet(Bullet_C);

    bool* IsFire = nullptr;
};