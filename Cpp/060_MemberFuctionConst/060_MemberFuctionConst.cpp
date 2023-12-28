// 060_MemberFuctionConst.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class FightUnit
{
public:
    Player* Test; // <- 역적 (이미 구조가 망가진것)
};

class Player
{
public:
    // 함수 뒤에 const를 붙이는 것은
    // this를 const Player* const this
    // 로 변환하겠다는 의미이다.
    int GetHp(/*Plyaer* this*/) const
    {
        /*this->*///m_Hp = 300; 오류!
        return m_Hp;
    }

private:
    int m_Hp = 100;
};

int main()
{
    
}