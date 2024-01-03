// 063_VPTRTable.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class FightUnit
{
public:
    FightUnit()
    {
        this;
        int a = 0;
    }

    virtual void Damage()
    {

    }

    virtual void StatusRender()
    {

    }
};

class Player : public FightUnit
{
public:
    Player()
    {
        this;
        int a = 0;
    }

    void Damage() override
    {

    }
};

class A
{

};

class B : public A
{

};

int main()
{
    // C++ 관련 면접 단골질문.
    {
        int Size0 = sizeof(FightUnit);
        int Size1 = sizeof(B);
        int Size2 = sizeof(Player);

        B NewTest;

        Player NewPlayer;

        int a = 0;
    }

    // virtual 함수가 존재하는 클래스는 vfptr라는 
    // 가상함수 포인터라는 것을 가지고 있다.
    // 가상함수 테이블 이라고 한다.

}