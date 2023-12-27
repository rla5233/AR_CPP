#pragma once
#include "GlobalHeader.h"
#include "ConSoleObject.h"

extern const char Default_Player;

// �����¿� �̵� ������ ���� ��Ÿ���� ����� �ִ�.
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
    // �̷��� ���� �ʴ�. (�Ѿ˰� �÷��̾ �� �� ���� ���谡 ��)
    // Bullet Bullet = Bullet(Bullet_C);

    bool* IsFire = nullptr;
};