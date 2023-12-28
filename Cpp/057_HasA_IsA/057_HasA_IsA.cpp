// 057_HasA_IsA.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 플레이어
// 플레이어 is a 싸우는애
// 플레이어는 싸우는 애다
// 그걸 표현하는 문법이 상속

// 장비
// 플레이어 has a 장비
// 장비는 플레이어가 가져야할 요소는 맞지만
// 장비 != 플레이어

class Item
{
public:

protected:
    int m_Cost = 0;
};

class Potion : public Item
{

};

class Sword : public Item
{

};

class FightUnit
{
public:
    int MAtt;
    int Hp;
    int Def;
    int Cri;

public:
    // 인자가 많아지면 너무 복잡해질것이다.
    //void Damage(int _Att, int _Cri)
    //{

    //}

    // 포인터, 참조를 통해 접근이 가능하다!
    void Damage(const FightUnit* _AttUnit)
    {
        Hp -= _AttUnit->MAtt;
    }

    void Damage(const FightUnit& _AttUnit)
    {
        Hp -= _AttUnit.MAtt;
    }
};

// 멤버변수로 다른 클래스를 가지면
// 플레이어 has a sword

class Player : public FightUnit
{
private:
    Sword m_Sword;
};

class Monster : public FightUnit
{
private:
    Sword m_Sword;
};

class NPC : public FightUnit
{

};

int main()
{
    {
        // 업캐스팅
        // - 자식 클래스의 객체는 언제든 부모 클래스의 참조형이 될 수 있다.
        // 굉장히 건강하고 권장되는 암시적 형변환.
        Player NewPlayer;
        FightUnit* Unit = &NewPlayer;

        Monster NewMonster;

        NewPlayer.Damage(NewMonster);
        NewMonster.Damage(NewPlayer);
    }
    
}